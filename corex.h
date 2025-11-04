#ifndef COREX_H
#define COREX_H

#include <QMainWindow>

#include "QSqlQueryModel"
#include  "accueil.h"
#include "connexion_bdd.h"

#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QtSql/QSqlRecord>


namespace Ui {
class Corex;
}

class Corex : public QMainWindow
{
    Q_OBJECT

public slots:
    void etablir_connexion();
    void affiche_le_mot_de_passe();
    void cache_le_mot_de_passe();


public:
    explicit Corex(QWidget *parent = 0);
    ~Corex();


private slots:
    void on_bntconn_clicked();

private:
    Ui::Corex *ui;

};

#endif // COREX_H
