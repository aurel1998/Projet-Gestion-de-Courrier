#include "archives.h"
#include "ui_archives.h"

Archives::Archives(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Archives)
{
    ui->setupUi(this);
    connect(ui->btnrecharchive,SIGNAL(clicked(bool)),this,SLOT(rechercher_element_archiver()));
}

Archives::~Archives()
{
    delete ui;
}

void Archives::on_bntanfermer_clicked()
{
    this->close();
}

void Archives::rechercher_element_archiver()
{

    mod = new QSqlQueryModel();
    if(ui->combotyprcourrier->currentText()=="Courrier arrivée")
    {
        requ.exec("select * from table_courrier_arrive where  ref_cour_arrive='"+ui->champrecherche->text()+"' || "
       " contenu_cour_arrive='"+ui->champrecherche->text()+"' || date_enr_cour_arrive='"+ui->champrecherche->text()+"' ||"
        " heure_enr_cour_arrive='"+ui->champrecherche->text()+"'");

        mod->setQuery(requ);
        ui->treeViewarchives->setModel(mod);
        ui->champrecherche->clear();
    }

    else if(ui->combotyprcourrier->currentText()=="Courrier départ")
    {
        requ.exec("select * from table_courrier_emis where  ref_cour_em='"+ui->champrecherche->text()+"' || "
       " contenu_cour_em='"+ui->champrecherche->text()+"' || date_enr_cour_em='"+ui->champrecherche->text()+"' ||"
        " heure_enr_cour_em='"+ui->champrecherche->text()+"'");

        mod->setQuery(requ);
        ui->treeViewarchives->setModel(mod);
        ui->champrecherche->clear();
    }

    else if(ui->combotyprcourrier->currentText()=="Circulaire"  || ui->combotyprcourrier->currentText()=="Note de service")
    {
        requ.exec("select * from table_autre_courrier where  ref_autre_courrier='"+ui->champrecherche->text()+"' || "
       " contenu_autre_courrier='"+ui->champrecherche->text()+"' || date_enr_autre_courrier='"+ui->champrecherche->text()+"' ||"
        " heure_enr_autre_courrier='"+ui->champrecherche->text()+"'");

        mod->setQuery(requ);
        ui->treeViewarchives->setModel(mod);
        ui->champrecherche->clear();
    }
    else if(ui->combotyprcourrier->currentText()=="Réponse Courrier Arrivé" )
    {
        requ.exec("select * from table_rep_cour_em where  ref_rep_em='"+ui->champrecherche->text()+"' || "
       " contenu_rep_em='"+ui->champrecherche->text()+"' || date_rep_em='"+ui->champrecherche->text()+"' ||"
        " heure_rep_em='"+ui->champrecherche->text()+"'");

        mod->setQuery(requ);
        ui->treeViewarchives->setModel(mod);
        ui->champrecherche->clear();
    }
    else if(ui->combotyprcourrier->currentText()=="Réponse Courrier Départ" )
    {
        requ.exec("select * from table_rep_cour_arrive where  ref_rep_arrive='"+ui->champrecherche->text()+"' || "
       " contenu_rep_arrive='"+ui->champrecherche->text()+"' || date_rep_arrive='"+ui->champrecherche->text()+"' ||"
        " heure_enr_autre_courrier='"+ui->champrecherche->text()+"'");

        mod->setQuery(requ);
        ui->treeViewarchives->setModel(mod);
        ui->champrecherche->clear();
    }
    else if(ui->combotyprcourrier->currentText()=="Code Objet")
    {
        requ.exec("select * from table_courrier_emis where  cod_obj='"+ui->champrecherche->text()+"'"
                         "AND"
        "select * from table_autre_courrier where  cod_obj='"+ui->champrecherche->text()+"'"
                         "AND"
        "select * from table_autre_courrier where  cod='"+ui->champrecherche->text()+"' ");

        mod->setQuery(requ);
        ui->treeViewarchives->setModel(mod);
        ui->champrecherche->clear();
    }else
    {
        QMessageBox::information(this, tr("Opération de recherche"), tr("Aucun élement trouvé ne correspond à votre recherche"));
        ui->champrecherche->clear();
    }

}
