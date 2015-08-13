#include "BDD.h"

BDD::BDD(QString const& bddLocation, QObject *parent) :
  QObject(parent),
  m_bdd(QSqlDatabase::addDatabase("QSQLITE"))
{
  qDebug() << "Loading database" << bddLocation;

  m_bdd.setHostName("localhost");
  m_bdd.setDatabaseName(bddLocation);

  if (!m_bdd.open())
  {
    qDebug() << "Error opening the database";
    //TODO
  }
}

QList<QString> BDD::listAllArtists()
{
  QList<QString> artists;

  QSqlQuery query = QSqlQuery("SELECT artist_name FROM artist", m_bdd);
  while(query.next())
    artists.append(query.value(0).toString());

  return artists;
}

QList<QString> BDD::listAllAlbums()
{
  QList<QString> albums;

  QSqlQuery query = QSqlQuery("SELECT album_name FROM album", m_bdd);
  while (query.next())
    albums.append(query.value(0).toString());

  return albums;
}

QList<QString> BDD::listAllSongs()
{
  QList<QString> songs;

  QSqlQuery query = QSqlQuery("SELECT song_name FROM song", m_bdd);
  while (query.next())
    songs.append(query.value(0).toString());

  return songs;
}
