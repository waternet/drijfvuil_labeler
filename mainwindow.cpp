#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDir>
#include <QImageReader>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QDateTime>
#include <QSettings>

#include "dialogsettings.h"

const int IMAGE_WIDTH = 200;
const int IMAGE_HEIGHT = 200;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();
}

MainWindow::~MainWindow()
{
    QSettings settings;
    settings.setValue("raw_path", m_raw_path);
    settings.setValue("debris_path", m_debris_path);
    settings.setValue("no_debris_path", m_nodebris_path);
    delete ui;
}

void MainWindow::init()
{
    qsrand(QDateTime::currentDateTime().toTime_t()); //zeker weten dat we ECHT random beginnen

    QSettings settings;
    m_raw_path = settings.value("raw_path").toString();
    m_debris_path = settings.value("debris_path").toString();
    m_nodebris_path = settings.value("no_debris_path").toString();

    initImages();
}

void MainWindow::showNextImage()
{
    if(m_filenames.count()==0) return;

    int index = qrand() % (m_filenames.count());

    QImage* img = new QImage();
    img->load(QDir::cleanPath(m_raw_path + QDir::separator() + m_filenames[index]));
    QPixmap pix = QPixmap::fromImage(*img);

    int wmax = pix.width() - IMAGE_WIDTH;
    int hmax = pix.height() - IMAGE_HEIGHT;
    int x = qrand() % wmax;
    int y = qrand() % hmax;
    m_selection = pix.copy(x,y,IMAGE_WIDTH,IMAGE_HEIGHT);

    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->addPixmap(m_selection);
    scene->setSceneRect(m_selection.rect());
    ui->graphicsView->setScene(scene);
}

void MainWindow::initImages()
{
    QDir dir(m_raw_path);
    dir.setFilter(QDir::Files);
    m_filenames = dir.entryList(QStringList()<<"*.png");
    showNextImage();
}

void MainWindow::on_pbYes_clicked()
{
    //generate random name;
    QString filename = QString("%1.png").arg(QDateTime::currentMSecsSinceEpoch());
    m_selection.save(m_debris_path + QDir::separator() + filename);
    showNextImage();
}

void MainWindow::on_pbDiscard_clicked()
{
    showNextImage();
}

void MainWindow::on_pbNo_clicked()
{
    QString filename = QString("%1.png").arg(QDateTime::currentMSecsSinceEpoch());
    m_selection.save(m_nodebris_path + QDir::separator() + filename);
    showNextImage();
}

void MainWindow::on_actionInstellingen_triggered()
{
    DialogSettings *dlg = new DialogSettings();
    dlg->setRawPath(m_raw_path);
    dlg->setDebrisPath(m_debris_path);
    dlg->setNoDebrisPath(m_nodebris_path);

    if(dlg->exec() == QDialog::Accepted){
        m_raw_path = dlg->getRawPath();
        m_debris_path = dlg->getDebrisPath();
        m_nodebris_path = dlg->getNoDebrisPath();
        showNextImage();
    }
}
