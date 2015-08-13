#include "Commander.h"

Commander::Commander(BDD *const bdd, Parameters *const params, QObject *parent) :
  QObject(parent),
  m_bdd(bdd),
  m_params(params)
{

}

void Commander::localScan()
{

}
