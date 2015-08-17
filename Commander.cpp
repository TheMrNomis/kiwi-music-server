#include "Commander.h"

Commander::Commander(BDD *const bdd, Parameters *const params, QObject *parent) :
  QObject(parent),
  m_tcpServer(new QTcpServer(this)),
  m_bdd(bdd),
  m_params(params)
{
  if(!QCA::isSupported("pkey") || !QCA::PKey::supportedIOTypes().contains(QCA::PKey::RSA))
  {
    qCritical() << "RSA not supported.";
    exit(0);
  }
  QFile RSAKeyFile(m_params->getRSAKeyLocation());
  if(!RSAKeyFile.exists())
  {
    qDebug() << "No RSA Key file found. Creating a new RSA keypair.";
    _createRSAKey();
  }
  else
  {
    QCA::ConvertResult convertResult;
    m_privateKey = QCA::PrivateKey::fromPEMFile(m_params->getRSAKeyLocation(),m_params->getRSAPassphrase(),&convertResult);

    if(!convertResult == QCA::ConvertGood || m_privateKey.isNull())
    {
      qCritical() << "Error while reading the key from the disk";
      exit(0);
    }
  }
  m_publicKey = m_privateKey.toPublicKey();

  qDebug() << "KeyPair sucessfully retrieved";
}

void Commander::start()
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

void Commander::_createRSAKey()
{
  m_privateKey = QCA::KeyGenerator().createRSA(1024);
  if(m_privateKey.isNull())
  {
    qCritical() << "Impossible to create a private key. Aborting";
    exit(0);
  }
  else
  {
    if(!m_privateKey.toPEMFile(m_params->getRSAKeyLocation(), m_params->getRSAPassphrase()))
      qWarning() << "Error while writing the key to the disk.";
  }
}
