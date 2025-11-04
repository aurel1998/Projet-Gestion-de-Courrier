#include "accueil.h"
#include "ui_accueil.h"


Accueil::Accueil(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Accueil)

{
    ui->setupUi(this);

    connect(ui->actionCourrier,SIGNAL(triggered(bool)),this,SLOT(on_bntcourrier_clicked()));
    connect(ui->actionAgent,SIGNAL(triggered(bool)),this,SLOT(on_bntagent_clicked()));
    connect(ui->actionDocumentation,SIGNAL(triggered(bool)),this,SLOT(on_bntdoc_clicked()));
    connect(ui->actionArchives,SIGNAL(triggered(bool)),this,SLOT(on_bntarchives_clicked()));
    connect(ui->actionParam_tres_g_n_raux,SIGNAL(triggered(bool)),this,SLOT(on_bntparametre_clicked()));
    connect(ui->actionFermer,SIGNAL(triggered(bool)),this,SLOT(ui->menuAccueil->close()));

    connect(ui->actionEnr_gistrer_un_courrier,SIGNAL(triggered(bool)),this,SLOT(section_courriers::on_bntenregistrement_clicked()));
    connect(ui->actionRechercher_un_courrier,SIGNAL(triggered(bool)),this,SLOT(section_courriers::on_bntrecherche_clicked()));


    a = new section_courriers(ui->labelaccueil);
    b = new documentez_vous(ui->labelaccueil);
    c = new parametre(ui->labelaccueil);
    d = new agent(ui->labelaccueil);
    e = new Archives(ui->labelaccueil);
    cacher_fenetre();

}

Accueil::~Accueil()
{
    delete ui;
}


void Accueil::cacher_fenetre()
{
   a->hide();
   b->hide();
   c->hide();
   d->hide();
   e->hide();
}

void Accueil::on_bntcourrier_clicked()
{
    cacher_fenetre();
    a->show();
}

void Accueil::on_bntdoc_clicked()
{
    cacher_fenetre();
    b->show();
}

void Accueil::on_bntparametre_clicked()
{
    cacher_fenetre();
    c->show();
}

void Accueil::on_bntagent_clicked()
{
    cacher_fenetre();
    d->show();
}

void Accueil::on_bntarchives_clicked()
{
    cacher_fenetre();
    e->show();
}
