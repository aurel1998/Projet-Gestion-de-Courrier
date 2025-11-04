#ifndef DOCUMENTEZ_VOUS_H
#define DOCUMENTEZ_VOUS_H

#include <QWidget>

namespace Ui {
class documentez_vous;
}

class documentez_vous : public QWidget
{
    Q_OBJECT

public:
    explicit documentez_vous(QWidget *parent = 0);
    ~documentez_vous();

private slots:
    void on_bntquitdoc_clicked();

private:
    Ui::documentez_vous *ui;
};

#endif // DOCUMENTEZ_VOUS_H
