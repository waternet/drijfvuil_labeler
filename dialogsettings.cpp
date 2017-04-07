#include "dialogsettings.h"
#include "ui_dialogsettings.h"

#include <QFileDialog>
#include <QDir>

DialogSettings::DialogSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSettings)
{
    ui->setupUi(this);
}

DialogSettings::~DialogSettings()
{
    delete ui;
}

void DialogSettings::setRawPath(const QString value)
{
    m_raw_path = value;
    ui->leRaw->setText(value);
}

void DialogSettings::setDebrisPath(const QString value)
{
    m_debris_path = value;
    ui->leDebris->setText(value);
}

void DialogSettings::setNoDebrisPath(const QString value)
{
    m_nodebris_path = value;
    ui->leNoDebris->setText(m_nodebris_path);
}

void DialogSettings::on_pbRaw_clicked()
{
    m_raw_path = QFileDialog::getExistingDirectory(this,
                                                   "Selecteer het pad naar de afbeeldingen",
                                                   QDir::currentPath(),
                                                   QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    ui->leRaw->setText(m_raw_path);
}

void DialogSettings::on_pbDebris_clicked()
{
    m_debris_path = QFileDialog::getExistingDirectory(this,
                                                   "Selecteer het pad naar de drijfaval afbeeldingen",
                                                   QDir::currentPath(),
                                                   QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    ui->leDebris->setText(m_debris_path);
}

void DialogSettings::on_pbNoDebris_clicked()
{
    m_nodebris_path = QFileDialog::getExistingDirectory(this,
                                                   "Selecteer het pad naar de NIET drijfaval afbeeldingen",
                                                   QDir::currentPath(),
                                                   QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    ui->leNoDebris->setText(m_nodebris_path);
}
