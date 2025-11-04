#ifndef AJOUTER_UN_AGENT_H
#define AJOUTER_UN_AGENT_H

#include <QWidget>

namespace Ui {
class ajouter_un_agent;
}

class ajouter_un_agent : public QWidget
{
    Q_OBJECT

public:
    explicit ajouter_un_agent(QWidget *parent = 0);
    ~ajouter_un_agent();
public slots:
    void adduser();

private slots:
     void on_bntannuler_clicked();

     void on_bntsaauveenreagent_clicked();

private:
    Ui::ajouter_un_agent *ui;
};

#endif // AJOUTER_UN_AGENT_H
