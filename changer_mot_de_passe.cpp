#include "changer_mot_de_passe.h"
#include "ui_changer_mot_de_passe.h"
#include "parametre.h"
#include <QMessageBox>
#include "accueil.h"

changer_mot_de_passe::changer_mot_de_passe(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::changer_mot_de_passe)
{
    ui->setupUi(this);

    ui->chpconfnewmdp->setEchoMode(QLineEdit::Password);
    ui->chpmdpactuel->setEchoMode(QLineEdit::Password);
    ui->chpnewmdp->setEchoMode(QLineEdit::Password);
     connect(ui->btnenregistrer,SIGNAL(clicked(bool)),this,SLOT(changement_mot_de_passe()));
}

changer_mot_de_passe::~changer_mot_de_passe()
{
    delete ui;
}

void changer_mot_de_passe::on_bntannmdp_clicked()
{
    this->close();
}

void changer_mot_de_passe::changement_mot_de_passe()
{
    if(ui->chpmdpactuel->text().isEmpty()   || ui->chpnewmdp->text().isEmpty() || ui->chpconfnewmdp->text().isEmpty())
    {
        QMessageBox::warning(ui->gbmdp, "Attention","Veillez renseigner les champs svp!!!");
    }
    else
      {
        if(!(ui->chpmdpactuel->text().isEmpty() && ui->chpnewmdp->text().isEmpty() && ui->chpconfnewmdp->text().isEmpty()))
        {
        mod1.exec("Select mdpagent from table_agent where numagent='"+ui->chpnumagent->text()+"' ");

        if(ui->chpnewmdp->text()!=ui->chpconfnewmdp->text())
        {
           QMessageBox::warning(ui->gbmdp, "Attention","Données incorrectes. \n "
                                                       "Vérifier que les données entrées sont conformes");
        }
        else
        {
            mod2.exec("UPDATE  table_agent SET mdpagent='"+ui->chpnewmdp->text()+"' where numagent='"+ui->chpnumagent->text()+"' ");
            QMessageBox::information(this, tr("Operation Réussite"), tr("Votre mot de passe a été modifié avec sucses"));
            ui->chpconfnewmdp->clear();
            ui->chpmdpactuel->clear();
            ui->chpnewmdp->clear();
            ui->chpnumagent->clear();
        }

    }else
        QMessageBox::warning(ui->gbmdp, "Echec de l'opération","Les informations renseignées ne sont pas correctes."
                      " \n Vérifiez que les informations entrées sont correctes puis continuez. ");
    }

}
