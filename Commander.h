#ifndef COMMANDER_H
#define COMMANDER_H

#include <QDebug>
#include <QObject>

#include "BDD.h"
#include "Parameters.h"

class Commander : public QObject
{
  Q_OBJECT
public:
  explicit Commander(BDD *const bdd, Parameters *const params, QObject * parent = 0);

signals:
  void play();
  void pause();
  void stop();
  void next();
  void previous();

public slots:

private:
  void localScan();

  BDD *const m_bdd;
  Parameters *const m_params;
};

#endif // COMMANDER_H
