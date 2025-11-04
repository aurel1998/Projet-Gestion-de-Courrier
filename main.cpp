#include "corex.h"
#include <QApplication>
#include "connexion_bdd.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*if(!etablir_connexion())
        return 1;*/
    Corex w;
    w.show();

    return a.exec();
}
