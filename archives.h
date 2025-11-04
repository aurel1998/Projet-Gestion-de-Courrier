#ifndef ARCHIVES_H
#define ARCHIVES_H

#include <QWidget>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>

namespace Ui {
class Archives;
}

class Archives : public QWidget
{
    Q_OBJECT

public:
    explicit Archives(QWidget *parent = 0);
    ~Archives();

private slots:
    void on_bntanfermer_clicked();
    void rechercher_element_archiver();

private:
    Ui::Archives *ui;
    QSqlQuery requ;
    QSqlQueryModel *mod;
};

#endif // ARCHIVES_H
