#ifndef BDD_H
#define BDD_H

#include <QDebug>
#include <QObject>
#include <QtSql>
#include <QList>

class BDD : public QObject
{
  Q_OBJECT
public:
  explicit BDD(QString const& bddLocation, QObject *parent = 0);

  QList<QString> listAllArtists();
  QList<QString> listAllAlbums();
  QList<QString> listAllSongs();

signals:

public slots:

private:
  QSqlDatabase m_bdd;
};

#endif // BDD_H
