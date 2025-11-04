#include "documentez_vous.h"
#include "ui_documentez_vous.h"
#include "accueil.h"

documentez_vous::documentez_vous(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::documentez_vous)
{
    ui->setupUi(this);
}

documentez_vous::~documentez_vous()
{
    delete ui;
}

void documentez_vous::on_bntquitdoc_clicked()
{
    this->close();
}
