#ifndef REGLAGES_COURRIERS_H
#define REGLAGES_COURRIERS_H

#include <QWidget>

namespace Ui {
class reglages_courriers;
}

class reglages_courriers : public QWidget
{
    Q_OBJECT

public:
    explicit reglages_courriers(QWidget *parent = 0);
    ~reglages_courriers();

private slots:
    void on_bntannrecour_clicked();

    void on_bntenregreglagecour_clicked();

private:
    Ui::reglages_courriers *ui;
};

#endif // REGLAGES_COURRIERS_H
