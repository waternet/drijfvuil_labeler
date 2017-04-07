#ifndef DIALOGSETTINGS_H
#define DIALOGSETTINGS_H

#include <QDialog>

namespace Ui {
class DialogSettings;
}

class DialogSettings : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSettings(QWidget *parent = 0);
    ~DialogSettings();

    void setRawPath(const QString value);
    void setDebrisPath(const QString value);
    void setNoDebrisPath(const QString value);

    QString getRawPath() {return m_raw_path;}
    QString getDebrisPath() {return m_debris_path;}
    QString getNoDebrisPath() {return m_nodebris_path;}

private slots:
    void on_pbRaw_clicked();

    void on_pbDebris_clicked();

    void on_pbNoDebris_clicked();

private:
    Ui::DialogSettings *ui;

    QString m_raw_path;
    QString m_debris_path;
    QString m_nodebris_path;
};

#endif // DIALOGSETTINGS_H
