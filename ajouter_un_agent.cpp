#include "ajouter_un_agent.h"
#include "ui_ajouter_un_agent.h"
#include "parametre.h"
#include "QSqlQuery"
#include <QSqlQueryModel>
#include <QSqlError>
#include <QMessageBox>

ajouter_un_agent::ajouter_un_agent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ajouter_un_agent)
{
    ui->setupUi(this);
    connect(ui->bntsaauveenreagent,SIGNAL(clicked(bool)),this,SLOT(adduser()));
}

ajouter_un_agent::~ajouter_un_agent()
{
    delete ui;
}


void ajouter_un_agent::on_bntannuler_clicked()
{
    this->close();
}

void ajouter_un_agent::adduser()
{
    QSqlQuery requete_saveposte, requete_saveuser;
       if(ui->chnumagent->text().isEmpty()  || ui->chpnomagent->text().isEmpty() ||
                 ui->chprenomagent->text().isEmpty()  || ui->chppseudoagent->text().isEmpty())
        {
            QMessageBox::warning(ui->gbadduser,"Attention","Renseignez les champs  vide svp!!!");
        }
         else
       {if(!(ui->chnumagent->text().isEmpty()  || ui->chpnomagent->text().isEmpty() ||
                   ui->chprenomagent->text().isEmpty()  ||
                  ui->chppseudoagent->text().isEmpty()))
        {
            requete_saveposte.exec("INSERT INTO `table_poste` (`idposte`, `lib_poste`, ) "
                                 "VALUES ('"+ui->comboidposte->currentText()+"', '"+ui->combolibposte->currentText()+"')");

            requete_saveuser.exec("INSERT INTO `table_agent` (`numagent`, `nomagent`, "
                             "`prenomagent`, `sexeagent`, `pseudoagent`, `idposte`)"
                             " VALUES ('"+ui->chnumagent->text()+"', '"+ui->chpnomagent->text()+"', '"+ui->chprenomagent->text()+"', '"+ui->Combosexeagent->currentText()+"'"
                             ",'"+ui->chppseudoagent->text()+"','"+ui->comboidposte->currentText()+"')");
           QMessageBox::information(this, tr("Operation Réussite"), tr("L'enregistrement a connu un succès !!!"));
           ui->chnumagent->clear();
           ui->chpnomagent->clear();
           ui->chppseudoagent->clear();
           ui->chprenomagent->clear();
           ui->gbadduser->clearMask();
        }else
        {
            QMessageBox::warning(ui->gbadduser,"Echec de l'opération","L'opération d'enrégistrement a échoué");
        }
       }

}

void ajouter_un_agent::on_bntsaauveenreagent_clicked()
{

}
