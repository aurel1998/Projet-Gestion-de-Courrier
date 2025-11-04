#include "corex.h"
#include "ui_corex.h"
#include  "accueil.h"
#include "connexion_bdd.h"
#include <QtSql/QSqlRecord>


Corex::Corex(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Corex)
{
    ui->setupUi(this);
    this->setFixedHeight(341);
    this->setFixedWidth(455);

    ui->chmdp->setEchoMode(QLineEdit::Password);
    connect(ui->bntconn,SIGNAL(clicked(bool)),this,SLOT(etablir_connexion()));
    connect(ui->bntann,SIGNAL(clicked(bool)),qApp,SLOT(quit()));
    connect(ui->bntaffichamdp,SIGNAL(pressed()),this,SLOT(affiche_le_mot_de_passe()));
    connect(ui->bntaffichamdp,SIGNAL(released()),this,SLOT(cache_le_mot_de_passe()));
}

Corex::~Corex()
{
    delete ui;
}



void Corex:: etablir_connexion()
{
    if(ui->chnumag->text().isEmpty()   || ui->chpsed->text().isEmpty() || ui->chmdp->text().isEmpty())
    {
        QMessageBox::warning(ui->form, "Avertissement","Veillez renseigner les champs svp!!!");
    }
    else
    {
        QSqlQuery requete;
             requete.exec("    Select numagent,pseudoagent,mdpagent, count(numagent) from table_agent where numagent='"+ui->chnumag->text()+"' "
                              " and pseudoagent='"+ui->chpsed->text()+"'   "
                              "and mdpagent='"+ui->chmdp->text()+"'  ");
             QSqlQueryModel *model= new QSqlQueryModel;
             model->setQuery(requete);

             if(model->record(0).value(3).toInt()==0)
                              {
                              QString erreur;
                              erreur.append(requete.lastError().text());
                                QMessageBox::critical(this,"Erreur","Une erreur s'est produite, Vérifiez que les informations entrées sont correctes et reessayer \n '"+erreur+"'");
                              }
             else if(model->record(0).value(3).toInt()>2)
                        {
                         QMessageBox::warning(0,"Erreur","Un problème est survenu, Veillez contacter votre administrateur");
                         }
             else  if(model->record(0).value(3).toInt()==2)
                    {
                        if(ui->chnumag->text()== (model->record(0).value(1).toString())
                                      && ui->chpsed->text()== (model->record(0).value(4).toString())
                                      && ui->chmdp->text()==(model->record(0).value(5).toString()))
                             {
                                 Accueil *fenetre_principale = new Accueil;
                                   fenetre_principale->show();
                                    this->close();
                               }else{
                                      QMessageBox::critical(0,"Erreur","Erreur!!! L'une des informations entrées est incorrecte");
                                       }
                      }
         }
 }


void Corex::affiche_le_mot_de_passe()
 {
     ui->chmdp->setEchoMode(QLineEdit::Normal);
 }

void Corex::cache_le_mot_de_passe()
 {
     ui->chmdp->setEchoMode(QLineEdit::Password);
 }
void Corex::on_bntconn_clicked()
{
    Accueil *f = new Accueil;
      f->show();
      this->close();
}
