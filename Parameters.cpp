#include "Parameters.h"

Parameters::Parameters(QObject * parent):
  QObject(parent),
  m_dbLocation("./demo/bdd.db"),
  m_musicLibraryLocations()
{
  qDebug() << "Loading parameters";
  QStringList args = qApp->arguments();

  for(auto it = args.cbegin(); it != args.cend(); ++it)
  {
    qDebug() << *it;
  }
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
