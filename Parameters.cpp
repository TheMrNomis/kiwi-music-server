#include "Parameters.h"

Parameters::Parameters(QObject * parent):
  QObject(parent),
  m_configFileLocation(this),
  m_dbLocation("./demo/bdd.db"),
  m_musicLibraryLocations()
{
  QStringList args = qApp->arguments();

  for(auto it = args.cbegin(); it != args.cend(); ++it)
  {
    if(it->startsWith("--"))
      _doubleDashArgument(it->mid(2));
    else if(it->startsWith("-"))
      _singleDashArgument(it->mid(1));
  }

  if(m_configFileLocation.exists())
  {
    //setting paths relative to the config file
    QDir::setCurrent(m_configFileLocation.fileName().left(m_configFileLocation.fileName().lastIndexOf('/')));
    qDebug() << "working directory : " << QDir::currentPath();
    _parseConfigFile();
  }
  else
  {
    qDebug() << "no config file given (or file doesn't exist). Aborting";
    exit(0);
  }
}

QString Parameters::getDbLocation() const
{
  if(m_dbLocation == QString())
    return QString(); //TODO : default location
  else
    return m_dbLocation;
}

QList<QString> Parameters::getMusicLibraryLocations() const
{
  if(m_musicLibraryLocations.size() == 0)
    return QList<QString>(); //TODO
  else
    return m_musicLibraryLocations;
}

void Parameters::_parseConfigFile()
{
  if(m_configFileLocation.open(QIODevice::ReadOnly))
  {
    QTextStream configFile(&m_configFileLocation);
    QString line;
    while(configFile.readLineInto(&line))
    {
      //TODO: parsing all the parameters
      if(!line.startsWith('#'))//comments
      {
        if(line.startsWith("db="))
          m_dbLocation = line.mid(3);
      }
    }
  }
}

void Parameters::_singleDashArgument(QString const& argument)
{
  for(auto it = argument.cbegin(); it != argument.cend(); ++it)
  {
    const char c(it->toLower().unicode());
    switch(c)
    {
      case 'v':
        _printVersionAndQuit();
        break;
    }
  }
}

void Parameters::_doubleDashArgument(QString const& argument)
{
  QString var;
  QString val;

  int equalPos = argument.indexOf('=');

  if(equalPos < 0)
  {
    var = argument;
  }
  else
  {
    var = argument.mid(0,equalPos);
    val = argument.mid(equalPos+1);
  }
  var = var.toLower();

  if(var == "version")
  {
    _printVersionAndQuit();
  }
  else if(var == "config")
  {
    m_configFileLocation.setFileName(val); //TODO
    qDebug() << "config file : " << m_configFileLocation.fileName();
  }
}

void Parameters::_printVersionAndQuit() const
{
  std::cout << "Kiwi-Music-server " << GIT_BUILDVERSION << " (build on " << __DATE__ << ", " << __TIME__ << ")" << std::endl;
  std::cout << "Copyright (C) 2015 - Amaury Louarn" << std::endl;
  std::cout << std::endl;
  std::cout << "This program is free software: you can redistribute it and/or modify" << std::endl;
  std::cout << "it under the terms of the GNU General Public License as published by" << std::endl;
  std::cout << "the Free Software Foundation, either version 3 of the License, or" << std::endl;
  std::cout << "(at your option) any later version." << std::endl;
  std::cout << std::endl;
  std::cout << "This program is distributed in the hope that it will be useful," << std::endl;
  std::cout << "but WITHOUT ANY WARRANTY; without even the implied warranty of" << std::endl;
  std::cout << "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the" << std::endl;
  std::cout << "GNU General Public License for more details." << std::endl;
  std::cout << std::endl;
  std::cout << "You should have received a copy of the GNU General Public License" << std::endl;
  std::cout << "along with this program.  If not, see <http://www.gnu.org/licenses/>." << std::endl;
  exit(0);
}
