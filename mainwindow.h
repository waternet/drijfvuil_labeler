#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pbYes_clicked();
    void on_pbDiscard_clicked();
    void on_pbNo_clicked();

    void on_actionInstellingen_triggered();

private:
    Ui::MainWindow *ui;
    QStringList m_filenames;
    QPixmap m_selection;

    QString m_raw_path;
    QString m_debris_path;
    QString m_nodebris_path;

    void init();
    void showNextImage();
    void initImages();
};

#endif // MAINWINDOW_H
