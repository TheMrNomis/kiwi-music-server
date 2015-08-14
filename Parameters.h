#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <QDebug>

#include <QCoreApplication>
#include <QObject>
#include <iostream>

#include <QList>
#include <QString>

class Parameters : public QObject
{
  Q_OBJECT
public:
  explicit Parameters(QObject *parent = 0);

  bool runApplication() const;

  QString getDbLocation() const;
  QList<QString> getMusicLibraryLocations() const;

private:
  bool m_runApplication;

  QString m_dbLocation;
  QList<QString> m_musicLibraryLocations;
};

#endif // PARAMETERS_H
