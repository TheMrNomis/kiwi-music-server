#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <QDebug>

#include <QObject>
#include <QCoreApplication>

#include <QList>
#include <QString>

class Parameters : public QObject
{
  Q_OBJECT
public:
  explicit Parameters(QObject *parent = 0);

  QString getDbLocation() const;
  QList<QString> getMusicLibraryLocations() const;

private:
  QString m_dbLocation;
  QList<QString> m_musicLibraryLocations;
};

#endif // PARAMETERS_H
