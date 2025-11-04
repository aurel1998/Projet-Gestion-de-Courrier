#ifndef CHANGER_MOT_DE_PASSE_H
#define CHANGER_MOT_DE_PASSE_H

#include <QWidget>
#include <QSqlQuery>
#include <QSqlQueryModel>

namespace Ui {
class changer_mot_de_passe;
}

class changer_mot_de_passe : public QWidget
{
    Q_OBJECT

public:
    explicit changer_mot_de_passe(QWidget *parent = 0);
    ~changer_mot_de_passe();

public slots:
    void changement_mot_de_passe();


private slots:
    void on_bntannmdp_clicked();


private:
    Ui::changer_mot_de_passe *ui;
    QSqlQuery mod1, mod2;
    QSqlQueryModel *modvue;
};

#endif // CHANGER_MOT_DE_PASSE_H
