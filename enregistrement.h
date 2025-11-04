#ifndef ENREGISTREMENT_H
#define ENREGISTREMENT_H

#include <QWidget>


namespace Ui {
class Enregistrement;
}

class Enregistrement : public QWidget
{
    Q_OBJECT

public:
    explicit Enregistrement(QWidget *parent = 0);
    ~Enregistrement();

private slots:
    void on_bntannenreagent_clicked();

private:
    Ui::Enregistrement *ui;
};

#endif // ENREGISTREMENT_H
