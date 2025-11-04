#ifndef AGENT_H
#define AGENT_H

#include <QWidget>
//#include "enregistrement.h"
#include "rechercher_un_agent.h"
#include "ajouter_un_agent.h"


namespace Ui {
class agent;
}

class agent : public QWidget
{
    Q_OBJECT

public:
    explicit agent(QWidget *parent = 0);
    ~agent();

private slots:

    void on_bntretcour_clicked();
    void on_bntrecherche_clicked();
    void on_bntlisteusers_clicked();
    void on_bntadduser_clicked();
    void cacher_sous_fenetre_agent();

private:
    Ui::agent *ui;
    rechercher_un_agent *fen_rech_agent, *fen_liste_user;
    ajouter_un_agent *fen_add_user;
};

#endif // AGENT_H
