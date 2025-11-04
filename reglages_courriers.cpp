#include "reglages_courriers.h"
#include "ui_reglages_courriers.h"
#include "parametre.h"
#include <QSqlQuery>
#include <QMessageBox>

reglages_courriers::reglages_courriers(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::reglages_courriers)
{
    ui->setupUi(this);
}

reglages_courriers::~reglages_courriers()
{
    delete ui;
}

void reglages_courriers::on_bntannrecour_clicked()
{
    this->close();
}

void reglages_courriers::on_bntenregreglagecour_clicked()
{
    QSqlQuery requete;
    requete.exec("insert into table_parametre_courrier "
    "(nombre_cour_av_archivage,delai_av_archivage,marge_d_heur_enr_cour_ds_journee)"
    "values('"+ui->spinBoxnbrecourrier->text()+"','"+ui->comboBoxsequencedarchivage->currentText()+"',"
    "'"+ui->timeEditmarges->text()+"')");
    QMessageBox::information(this,"BRAVO","Parametres modifiées avec succès !!!");
}
