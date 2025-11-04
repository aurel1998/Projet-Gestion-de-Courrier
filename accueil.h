#ifndef ACCUEIL_H
#define ACCUEIL_H

#include <QMainWindow>
#include "agent.h"
#include "section_courriers.h"
#include "documentez_vous.h"
#include "parametre.h"
#include "archives.h"


namespace Ui {
class Accueil;
}

class Accueil : public QMainWindow
{
    Q_OBJECT

public:
    explicit Accueil(QWidget *parent = 0);
    ~Accueil();

private slots:
    void on_bntcourrier_clicked();
    void on_bntdoc_clicked();
    void on_bntparametre_clicked();
    void on_bntagent_clicked();
    void on_bntarchives_clicked();
    void cacher_fenetre();


private:
    Ui::Accueil *ui;
    section_courriers *a;
    documentez_vous *b;
    parametre  *c ;
    agent *d;
    Archives *e;

};

#endif // ACCUEIL_H
