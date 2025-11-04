#include "recherche_de_courriers.h"
#include "ui_recherche_de_courriers.h"
#include "section_courriers.h"
#include <QSqlQuery>
#include <QSqlQueryModel>


recherche_de_courriers::recherche_de_courriers(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::recherche_de_courriers)
{
    ui->setupUi(this);
}

recherche_de_courriers::~recherche_de_courriers()
{
    delete ui;
}

void recherche_de_courriers::on_bntanrech_clicked()
{
    this->close();
}

void recherche_de_courriers::on_bntouvrir_clicked()
{

}

void recherche_de_courriers::on_pushButton_2_clicked()
{
    if(ui->combotprcourrier->currentText()=="Courrier arrivée")
    {
        QSqlQuery reque;
        reque.exec("select * from table_courrier_arrive where  ref_cour_arrive='"+ui->lineEditrechcour->text()+"' || "
       " contenu_cour_arrive='"+ui->lineEditrechcour->text()+"' || date_enr_cour_arrive='"+ui->lineEditrechcour->text()+"' ||"
        " heure_enr_cour_arrive='"+ui->lineEditrechcour->text()+"'");
        QSqlQueryModel *modl = new QSqlQueryModel();
        modl->setQuery(reque);
        ui->treeViewrecherrchecourrier->setModel(modl);
        ui->lineEditrechcour->clear();
    }

    else if(ui->combotprcourrier->currentText()=="Courrier départ")
    {

    }

    else if(ui->combotprcourrier->currentText()=="Circulaire"  || ui->combotprcourrier->currentText()=="Note de service")
    {

    }

}
