#ifndef CONNECTION_H
#define CONNECTION_H


#include <QtSql>
//#include "user.h"


class Connection
{
public:
    // Static access method
    static Connection* getConnection();

    //User getUser() const;
    //User* getUser();
    //void setUser(const User &user);
    //void setUser(const QString &userName, const QString &userPass);

    QSqlDatabase* getDb();

    void openDB();
    bool login(QString userName, QString password);
    bool login(QString userName, QString password, QString dbName);

private:
    // Private constructor
    Connection();
    // Instance stored
    static Connection* instance;

    QSqlDatabase m_db;
    //User m_user;
};
#endif // CONNECTION_H
