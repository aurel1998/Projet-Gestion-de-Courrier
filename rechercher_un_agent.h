#ifndef RECHERCHER_UN_AGENT_H
#define RECHERCHER_UN_AGENT_H

#include <QWidget>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QMessageBox>
#include <QModelIndex>

namespace Ui {
class rechercher_un_agent;
}

class rechercher_un_agent : public QWidget
{
    Q_OBJECT

public:
    explicit rechercher_un_agent(QWidget *parent = 0);
    ~rechercher_un_agent();

public slots:
    void recherche_agent();

public slots:
    void liste_actions();
    void acceder_liste_agent();

private slots:
    void on_bntanrech_clicked();


private:
    Ui::rechercher_un_agent *ui;
    QSqlQueryModel *modele, *modele1;
    QSqlQuery requete_recherche_agent, requete_lister_agent;
    QModelIndex index;
    int ligne;
};

#endif // RECHERCHER_UN_AGENT_H
