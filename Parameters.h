#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <QDebug>
#include <QList>
#include <QString>

class Parameters
{
public:
  explicit Parameters(int argc, char *argv[]);

  QString getDbLocation() const;
  QList<QString> getMusicLibraryLocations() const;

private:
  QString m_dbLocation;
  QList<QString> m_musicLibraryLocations;
};

#endif // PARAMETERS_H
