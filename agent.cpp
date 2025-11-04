#include "agent.h"
#include "ui_agent.h"

agent::agent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::agent)
{
    ui->setupUi(this);
    this->setFixedHeight(705);
    this->setFixedWidth(1320);


    fen_rech_agent = new rechercher_un_agent(ui->frameagent);
    fen_liste_user= new rechercher_un_agent(ui->frameagent);
    fen_add_user = new ajouter_un_agent(ui->frameagent);
    cacher_sous_fenetre_agent();

    connect(ui->bntlisteusers,SIGNAL(clicked(bool)), this, SLOT(rechercher_un_agent::acceder_liste_agent()));
}

agent::~agent()
{
    delete ui;
}

void agent:: cacher_sous_fenetre_agent()
{
    fen_add_user->hide();
    fen_liste_user->hide();
    fen_rech_agent->hide();
}

void agent::on_bntretcour_clicked()
{
  this->close();
}

void agent::on_bntrecherche_clicked()
{
    cacher_sous_fenetre_agent();
   fen_rech_agent->show();
}


void agent::on_bntlisteusers_clicked()
{
    cacher_sous_fenetre_agent();
    fen_liste_user->show();
}

void agent::on_bntadduser_clicked()
{
    cacher_sous_fenetre_agent();
    fen_add_user->show();
}
