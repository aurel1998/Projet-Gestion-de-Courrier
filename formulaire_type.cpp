#include "formulaire_type.h"
#include "ui_formulaire_type.h"
#include "section_courriers.h"
#include "QFileDialog"
#include "QString"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include "reglages_courriers.h"

formulaire_type::formulaire_type(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::formulaire_type)
{
    ui->setupUi(this);

    connect(ui->bntvalider,SIGNAL(clicked(bool)),SLOT(enregistrement()));
}

formulaire_type::~formulaire_type()
{
    delete ui;
}

void formulaire_type::on_bntannuler_clicked()
{
   this->close();
}

void formulaire_type::on_btncontenu_clicked()
{
    QString fichier = QFileDialog::getSaveFileName(this,"Choisissez un fichier ",QString(),"Documents(*.docx )");

}

void formulaire_type::enregistrement()
{
    QSqlQuery requete_valider;
    if(ui->chpcourrier->text().isEmpty()  ||   ui->dateEditcourrier->text().isEmpty()  || ui->timeEditcourrier->text().isEmpty()
            ||  ui->chprefemet->text().isEmpty()  ||  ui->chpnumagent->text().isEmpty()   || ui->chpcmmentaire->text().isEmpty())
{

        QMessageBox::warning(ui->gbformultyp,"Attention","Renseignez les champs  vide svp!!!");
    }
    else if(ui->combonature->currentText()=="Courrier arrivée")
    {
    requete_valider.exec("insert into table_courrier_arrive (ref_cour_arrive, contenu_cour_arrive, "
                         "date_enr_cour_arrive, heure_enr_cour_arrive, ref_emet, numagent, cod_obj, commentaire_cour_arrive) "
                         "Values ('"+ui->chpcourrier->text()+"', '"+ui->lineEdit->text()+"',  '"+ui->dateEditcourrier->text()+"',"
                          " '"+ui->timeEditcourrier->text()+"','"+ui->chprefemet->text()+"','"+ui->chpnumagent->text()+"',"
                         " '"+ui->combocodobj->currentText()+"','"+ui->chpcmmentaire->text()+"')");
    QMessageBox::information(this,"Operation Réussite","L'enregistrement a connu un succès !!!");
    ui->chpcourrier->clear();
    ui->chprefemet->clear();
    ui->chpnumagent->clear();
    ui->chpcmmentaire->clear();
    }
    else if(ui->combonature->currentText()=="Courrier départ")
    {
    requete_valider.exec("INSERT INTO `table_courrier_emis` (`ref_cour_em`, `contenu_cour_em`, "
                         "`date_cour_em`, `heure_cour_em`, `cod_obj`,`commentaire_cour_em`) "
                         "VALUES ('"+ui->chpcourrier->text()+"', '"+ui->lineEdit->text()+"',  '"+ui->dateEditcourrier->text()+"', '"+ui->timeEditcourrier->text()+"',"
                         " '"+ui->combocodobj->currentText()+"','"+ui->chpcmmentaire->text()+"')");
    QMessageBox::information(this,"Operation Réussite","L'enregistrement a connu un succès !!!");
    ui->chpcourrier->clear();
    ui->chprefemet->clear();
    ui->chpnumagent->clear();
    ui->chpcmmentaire->clear();
    }
    else if(ui->combonature->currentText()=="Circulaire" || ui->combonature->currentText()=="Note de service")
    {
    requete_valider.exec("INSERT INTO `table_autre_courrier` (`ref_autre_courrier`, `contenu_autre_courrier`, "
                         "`date_enr_autre_courrier`, `heure_enr_autre_courrier` ,`cod_obj`, `commentaire_autre_courrier`,`ref_emet` ) "
                         "VALUES ('"+ui->chpcourrier->text()+"', '"+ui->lineEdit->text()+"',  '"+ui->dateEditcourrier->text()+"', '"+ui->timeEditcourrier->text()+"','"+ui->combocodobj->currentText()+"',"
                         "'"+ui->chpcmmentaire->text()+"','"+ui->chprefemet->text()+"')");
     QMessageBox::information(this,"Operation Réussite","L'enregistrement a connu un succès !!!");
     ui->chpcourrier->clear();
     ui->chprefemet->clear();
     ui->chpnumagent->clear();
     ui->chpcmmentaire->clear();
     }
    else{
        QString Error;
       // Error.append(requete_valider.lastError().text());
        QMessageBox::critical(this,"Erreur d'enregistrement","Les informations entrées n'ont pas été enregistrées");
    }

}
