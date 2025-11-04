#include "infogeneralutilisateurs.h"
#include "ui_infogeneralutilisateurs.h"
#include "parametre.h"

infogeneralutilisateurs::infogeneralutilisateurs(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::infogeneralutilisateurs)
{
    ui->setupUi(this);

    req.exec("SELECT * FROM  `table_agent`");
    modele= new QSqlQueryModel;
    modele->setQuery(req);
    ui->treeView->setModel(modele);

}

infogeneralutilisateurs::~infogeneralutilisateurs()
{
    delete ui;
}

void infogeneralutilisateurs::on_bntanrech_clicked()
{
    this->close();
}
