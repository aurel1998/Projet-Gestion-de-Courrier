#ifndef CONNEXION_BDD_H
#define CONNEXION_BDD_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QMessageBox>
#include <QtSql/QSqlError>


 static bool etablir_connexion()
{
     QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("corex_bdd");
    db.setUserName("root");
    db.setPassword(" ");
    db.setPort(3306);
    db.open();


     if(!db.open())
    {
        QString ErrorMsg="impossible de se connecter !";
        ErrorMsg.append(db.lastError().text());
        ErrorMsg.append("\n  Cliquer sur \"Cancel  \"pour sortir");
        QMessageBox::critical(0,"Erreur de connexion ",ErrorMsg ,QMessageBox::Cancel);

        return false;
    }



    return true;

}

#endif // CONNEXION_BDD_H

