#include <QCoreApplication>
#include <QMediaPlayer>
#include <QDebug>
#include <taglib/tag.h>

#include "Parameters.h"
#include "BDD.h"
#include "Commander.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Parameters* param = new Parameters(&a);
    BDD* bdd = new BDD(param->getDbLocation(),&a);
    Commander* commander = new Commander(bdd, param,&a);

    return a.exec();
}
