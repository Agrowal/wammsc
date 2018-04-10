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
    return &_db;
}


Connection::Connection()
{
    _db = QSqlDatabase::addDatabase("QMYSQL");
    _db.setHostName("www.wammsc.pl");
    _db.setDatabaseName("wammsc_test");
    _db.setUserName("wammsc_micek");
    _db.setPassword("test");
    _db.setPort(3306);
    qDebug() << _db.open();
}
