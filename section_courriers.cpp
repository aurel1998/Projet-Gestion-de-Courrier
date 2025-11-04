#include "section_courriers.h"
#include "ui_section_courriers.h"


section_courriers::section_courriers(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::section_courriers)
{
    ui->setupUi(this);

    formulaire= new formulaire_type(ui->frameesc_courrier);
    recherche= new recherche_de_courriers(ui->frameesc_courrier);
    reglage_cour= new reglages_courriers(ui->frameesc_courrier);

    cacher_sous_fenetre_courrier();
}

section_courriers::~section_courriers()
{
    delete ui;
}


void section_courriers::cacher_sous_fenetre_courrier()
{
 formulaire->hide();
 recherche->hide();
 reglage_cour->hide();
}

void section_courriers::on_bntretcour_clicked()
{
    this->close();
}

void section_courriers::on_bntenregistrement_clicked()
{
    cacher_sous_fenetre_courrier();
    formulaire->show();
}

void section_courriers::on_bntrecherche_clicked()
{
    cacher_sous_fenetre_courrier();
    recherche->show();

}

void section_courriers::on_bntparametre_clicked()
{
    cacher_sous_fenetre_courrier();
    reglage_cour->show();

}
