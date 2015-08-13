#include "Parameters.h"

Parameters::Parameters(int argc, char *argv[]):
  m_dbLocation("./demo/bdd.db"),
  m_musicLibraryLocations()
{
  Q_UNUSED(argc)
  Q_UNUSED(argv)

  qDebug() << "Loading parameters";
}

QString Parameters::getDbLocation() const
{
  if(m_dbLocation == QString())
    return QString(); //TODO : default location
  else
    return m_dbLocation;
}

QList<QString> Parameters::getMusicLibraryLocations() const
{
  if(m_musicLibraryLocations.size() == 0)
    return QList<QString>(); //TODO
  else
    return m_musicLibraryLocations;
}
