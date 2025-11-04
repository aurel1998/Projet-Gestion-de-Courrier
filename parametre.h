#ifndef PARAMETRE_H
#define PARAMETRE_H

#include <QWidget>
#include "reglages_courriers.h"
#include "changer_mot_de_passe.h"
#include "infogeneralutilisateurs.h"
#include "ajouter_un_agent.h"

namespace Ui {
class parametre;
}

class parametre : public QWidget
{
    Q_OBJECT

public:
    explicit parametre(QWidget *parent = 0);
    ~parametre();

private slots:
    void on_bntretparagene_clicked();
    void on_bntregcour_clicked();
    void on_bntmdppara_clicked();
    void on_bntaddusers_clicked();
    void on_bntinfogeneusers_clicked();
    void cacher_sous_fenetre_parametre();

private:
    Ui::parametre *ui;
    reglages_courriers *fen_reglage_courrier;
    changer_mot_de_passe *fen_changer_mdp;
    ajouter_un_agent *fen_ajout_agent;
    infogeneralutilisateurs *fen_liste_gene_user;
};

#endif // PARAMETRE_H
