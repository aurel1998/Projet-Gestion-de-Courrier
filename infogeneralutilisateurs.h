#ifndef INFOGENERALUTILISATEURS_H
#define INFOGENERALUTILISATEURS_H

#include <QWidget>
#include <QSqlQuery>
#include <QSqlQueryModel>

namespace Ui {
class infogeneralutilisateurs;
}

class infogeneralutilisateurs : public QWidget
{
    Q_OBJECT

public:
    explicit infogeneralutilisateurs(QWidget *parent = 0);
    ~infogeneralutilisateurs();

private slots:
    void on_bntanrech_clicked();

private:
    Ui::infogeneralutilisateurs *ui;
    QSqlQuery req;
    QSqlQueryModel *modele;

};


#endif // INFOGENERALUTILISATEURS_H
