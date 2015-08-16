#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <QDebug>

#include <QCoreApplication>
#include <iostream>

#include <QObject>
#include <QFile>
#include <QDir>

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
  void _parseConfigFile();

  void _singleDashArgument(QString const& argument);
  void _doubleDashArgument(QString const& argument);

  void _printVersionAndQuit() const;

  QFile m_configFileLocation;
  QString m_dbLocation;
  QList<QString> m_musicLibraryLocations;
};

#endif // PARAMETERS_H
