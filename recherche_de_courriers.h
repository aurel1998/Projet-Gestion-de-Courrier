#ifndef RECHERCHE_DE_COURRIERS_H
#define RECHERCHE_DE_COURRIERS_H

#include <QWidget>

namespace Ui {
class recherche_de_courriers;
}

class recherche_de_courriers : public QWidget
{
    Q_OBJECT

public:
    explicit recherche_de_courriers(QWidget *parent = 0);
    ~recherche_de_courriers();

private slots:
    void on_bntanrech_clicked();

    void on_bntouvrir_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::recherche_de_courriers *ui;
};

#endif // RECHERCHE_DE_COURRIERS_H
