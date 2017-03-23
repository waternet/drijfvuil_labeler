#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDir>
#include <QImageReader>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QDateTime>

const QString AFBEELDINGSMAP = "/home/breinbaas/programmeren/python/debris_detection/data/raw_images";
const QString LABEL_DRIJFVUIL_MAP = "/home/breinbaas/programmeren/python/debris_detection/data/labeled/debris";
const QString LABEL_GEENDRIJFVUIL_MAP = "/home/breinbaas/programmeren/python/debris_detection/data/labeled/no_debris";
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
    delete ui;
}

void MainWindow::init()
{
    qsrand(QDateTime::currentDateTime().toTime_t()); //zeker weten dat we ECHT random beginnen
    QDir dir(AFBEELDINGSMAP);
    dir.setFilter(QDir::Files);
    m_filenames = dir.entryList(QStringList()<<"*.png");
    showNextImage();
}

void MainWindow::showNextImage()
{
    int index = qrand() % (m_filenames.count());

    QImage* img = new QImage();
    img->load(QDir::cleanPath(AFBEELDINGSMAP + QDir::separator() + m_filenames[index]));
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

void MainWindow::on_pbYes_clicked()
{
    //generate random name;
    QString filename = QString("%1.png").arg(QDateTime::currentMSecsSinceEpoch());
    m_selection.save(LABEL_DRIJFVUIL_MAP + QDir::separator() + filename);
    showNextImage();
}

void MainWindow::on_pbDiscard_clicked()
{
    showNextImage();
}

void MainWindow::on_pbNo_clicked()
{
    QString filename = QString("%1.png").arg(QDateTime::currentMSecsSinceEpoch());
    m_selection.save(LABEL_GEENDRIJFVUIL_MAP + QDir::separator() + filename);
    showNextImage();
}
