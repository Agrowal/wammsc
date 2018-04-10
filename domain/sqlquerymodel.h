#ifndef SQLQUERYMODEL_H
#define SQLQUERYMODEL_H


#include <QSqlQueryModel>
#include "connection.h"

class SqlQueryModel : public QSqlQueryModel
{
    Q_OBJECT
    Q_PROPERTY(QStringList userRoleNames READ userRoleNames CONSTANT)
public:
    explicit SqlQueryModel(QObject *parent = 0);

    void setQuery(const QString &query, const QSqlDatabase *db = Connection::getConnection()->getDb());
    void setQuery(const QSqlQuery &query);
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const {	return m_roleNames;	}

    QStringList userRoleNames();

private:
    void generateRoleNames();
    QHash<int, QByteArray> m_roleNames;
};


#endif // SQLQUERYMODEL_H
