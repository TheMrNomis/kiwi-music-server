#include "Commander.h"

Commander::Commander(BDD *const bdd, Parameters *const params, QObject *parent) :
  QObject(parent),
  m_tcpServer(new QTcpServer(this)),
  m_bdd(bdd),
  m_params(params)
{
  if(!m_tcpServer->listen(QHostAddress::Any, 6600))
  {
    qCritical() << "The server cannot be started : " << m_tcpServer->errorString();
    exit(0);
  }
  else
  {
    qDebug() << "Server started on port " << m_tcpServer->serverPort();
    QObject::connect(m_tcpServer, SIGNAL(newConnection()), this, SLOT(_connectClients()));
  }
}

void Commander::_connectClients()
{
  while(m_tcpServer->hasPendingConnections())
  {
    QTcpSocket * client = m_tcpServer->nextPendingConnection();

    qDebug() << "new connexion from " << client->peerAddress().toString();

    m_clients.push_back(client);
  }
}

void Commander::_localScan()
{

}
