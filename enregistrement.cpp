#include "enregistrement.h"
#include "ui_enregistrement.h"


Enregistrement::Enregistrement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Enregistrement)
{
    ui->setupUi(this);
}

Enregistrement::~Enregistrement()
{
    delete ui;
}

void Enregistrement::on_bntannenreagent_clicked()
{
     this->close();
}
