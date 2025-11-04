#include "parametre.h"
#include "ui_parametre.h"


parametre::parametre(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::parametre)
{
    ui->setupUi(this);

    fen_reglage_courrier = new reglages_courriers(ui->frameparametregene);
    fen_changer_mdp = new changer_mot_de_passe(ui->frameparametregene);
    fen_ajout_agent = new ajouter_un_agent(ui->frameparametregene);
    fen_liste_gene_user = new infogeneralutilisateurs(ui->frameparametregene);
    cacher_sous_fenetre_parametre();
}

parametre::~parametre()
{
    delete ui;
}
void parametre::cacher_sous_fenetre_parametre()
{
    fen_ajout_agent->hide();
    fen_changer_mdp->hide();
    fen_liste_gene_user->hide();
    fen_reglage_courrier->hide();
}

void parametre::on_bntretparagene_clicked()
{
    cacher_sous_fenetre_parametre();
    this->close();
}

void parametre::on_bntregcour_clicked()
{
    cacher_sous_fenetre_parametre();
    fen_reglage_courrier->show();
}

void parametre::on_bntmdppara_clicked()
{
    cacher_sous_fenetre_parametre();
    fen_changer_mdp->show();

}

void parametre::on_bntaddusers_clicked()
{
    cacher_sous_fenetre_parametre();
    fen_ajout_agent->show();
}

void parametre::on_bntinfogeneusers_clicked()
{
    fen_liste_gene_user->show();

}
