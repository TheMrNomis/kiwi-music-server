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

    Parameters* param = new Parameters();
    if(!param->runApplication())
      return 0;

    BDD* bdd = new BDD(param->getDbLocation());
    Commander* commander = new Commander(bdd, param);

    delete commander;
    delete bdd;
    delete param;

    return a.exec();
}
