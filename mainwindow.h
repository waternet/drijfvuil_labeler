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

private:
    Ui::MainWindow *ui;
    QStringList m_filenames;
    QPixmap m_selection;

    void init();
    void showNextImage();
};

#endif // MAINWINDOW_H
