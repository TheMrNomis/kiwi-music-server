#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <QDebug>

#include <QCoreApplication>
#include <iostream>
#include <QtCrypto>

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

  QString getDbLocation() const{return m_dbLocation;}
  QList<QString> getMusicLibraryLocations() const{return m_musicLibraryLocations;}

  QString getRSAKeyLocation() const{return m_RSAKeyLocation;}
  QCA::SecureArray getRSAPassphrase() const{return m_RSAPassphrase;}

private:
  void _parseConfigFile();

  void _singleDashArgument(QString const& argument);
  void _doubleDashArgument(QString const& argument);

  void _printVersionAndQuit() const;

  QFile m_configFile;

  QString m_dbLocation;
  QList<QString> m_musicLibraryLocations;

  QString m_RSAKeyLocation;
  QCA::SecureArray m_RSAPassphrase;
};

#endif // PARAMETERS_H
