#ifndef FORMULAIRE_TYPE_H
#define FORMULAIRE_TYPE_H

#include <QWidget>

namespace Ui {
class formulaire_type;
}

class formulaire_type : public QWidget
{
    Q_OBJECT

public:
    explicit formulaire_type(QWidget *parent = 0);
    ~formulaire_type();

public slots:
    void enregistrement();
private slots:
    void on_bntannuler_clicked();
    void on_btncontenu_clicked();

private:
    Ui::formulaire_type *ui;
    QString fichier;
};

#endif // FORMULAIRE_TYPE_H
