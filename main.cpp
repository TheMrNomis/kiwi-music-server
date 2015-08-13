#include <QCoreApplication>
#include <QMediaPlayer>
#include <QDebug>
#include <taglib/tag.h>

#include "Parameters.h"
#include "BDD.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Parameters* param = new Parameters(argc, argv);
    BDD* bdd = new BDD(param->getDbLocation());

    delete bdd;
    delete param;

    return a.exec();
}
