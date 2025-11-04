#ifndef SECTION_COURRIERS_H
#define SECTION_COURRIERS_H

#include <QWidget>
#include "formulaire_type.h"
#include "recherche_de_courriers.h"
#include "reglages_courriers.h"

namespace Ui {
class section_courriers;
}

class section_courriers : public QWidget
{
    Q_OBJECT

public:
    explicit section_courriers(QWidget *parent = 0);
    ~section_courriers();

private slots:
    void on_bntretcour_clicked();
    void on_bntenregistrement_clicked();
    void on_bntrecherche_clicked();
    void on_bntparametre_clicked();
    void cacher_sous_fenetre_courrier();

private:
    Ui::section_courriers *ui;
    formulaire_type  *formulaire;
    recherche_de_courriers *recherche;
    reglages_courriers *reglage_cour ;
};

#endif // SECTION_COURRIERS_H
