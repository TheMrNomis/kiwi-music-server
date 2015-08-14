#include "Commander.h"

Commander::Commander(BDD *const bdd, Parameters *const params, QObject *parent) :
  QObject(parent),
  m_tcpServer(this),
  m_bdd(bdd),
  m_params(params)
{
  int port = 66600;
  if(!m_tcpServer.listen(QHostAddress::Any, port))
  {
    qCritical() << "The server cannot be started : " << m_tcpServer.errorString();
  }
  else
  {
    qDebug() << "Server started on port " << port;
    QObject::connect(&m_tcpServer, SIGNAL(newConnection()), this, SLOT(_connectClients()));
  }
}

void Commander::_connectClients()
{
  while(m_tcpServer.hasPendingConnections())
  {
    QTcpSocket * client = m_tcpServer.nextPendingConnection();

    std::cout << "new connexion from " << client->peerAddress().toString().toStdString();

    m_clients.push_back(client);
  }
}

void Commander::_localScan()
{

}
