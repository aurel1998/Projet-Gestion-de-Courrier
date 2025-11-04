#include "rechercher_un_agent.h"
#include "ui_rechercher_un_agent.h"


rechercher_un_agent::rechercher_un_agent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::rechercher_un_agent)
{
    ui->setupUi(this);
    connect(ui->btnrech,SIGNAL(clicked(bool)), this, SLOT(recherche_agent()));
}

rechercher_un_agent::~rechercher_un_agent()
{
    delete ui;
}


void rechercher_un_agent::liste_actions()
{
/*
    QMenu *Menu = menu->addMenu("&Actions", this);
    Menu->addAction("Modifier les informations");
    Menu->addAction("Retirer de la liste");
    Menu->addAction("Quitter");
*/
}

    void rechercher_un_agent::on_bntanrech_clicked()
{
    this->close();
}

void rechercher_un_agent::recherche_agent()
{
    if(ui->chpnom->text().isEmpty()  || ui->chpprenom->text().isEmpty())
    {
        QMessageBox::warning(ui->form,"Attention","Renseignez les champs  vide svp!!!");
    }
    else if(!(ui->chpnom->text().isEmpty()  && ui->chpprenom->text().isEmpty()))
    {
      requete_recherche_agent.exec("SELECT * FROM  `table_agent` WHERE  `nomagent`='"+ui->chpnom->text()+"' "
                                   "AND `prenomagent`='"+ui->chpprenom->text()+"' ");

      modele= new QSqlQueryModel;
      modele->setQuery(requete_recherche_agent);

      ui->treeView->setModel(modele);
     // ui->treeView->setModelColumn(5);

      ui->chpnom->clear();
      ui->chpprenom->clear();

    }
    else
    {
         QMessageBox::information(this, tr("Echec de l'opération"),
           tr("Les informations spécifiées sont incorrectes"));
    }

}

void rechercher_un_agent::acceder_liste_agent()
{
    ui->form->hide();
    ui->chpnom->hide();
    ui->chpprenom->hide();
    ui->btnrech->hide();
    requete_lister_agent.exec("SELECT * FROM  `table_agent` order by numagent");

    modele1=new QSqlQueryModel;
    modele1->setQuery(requete_lister_agent);

    ui->treeView->setModel(modele);

}
