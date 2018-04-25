#include "connection.h"

/* Null, because instance will be initialized on demand. */
Connection* Connection::instance = 0;

Connection* Connection::getConnection()
{
    if (instance == 0)
    {
        instance = new Connection();
    }

    return instance;
}

QSqlDatabase *Connection::getDb()
{
    return &m_db;
}

bool Connection::login(QString userName, QString password)
{
    m_db.setUserName(userName);
    m_db.setPassword(password);
    return m_db.open();
}


Connection::Connection()
{
    m_db = QSqlDatabase::addDatabase("QMYSQL");
    m_db.setHostName("www.wammsc.pl");
    m_db.setDatabaseName("wammsc_test");
    m_db.setPort(3306);
}
