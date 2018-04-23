#ifndef MODEL_H
#define MODEL_H

#include "domain/sqlquerymodel.h"

typedef void (*DataChangeHandler)(int newData);

class Model
{
public:
    Model();

    void RegisterDataChangeHandler(DataChangeHandler handler);

    SqlQueryModel* getQuery();
    void setQueryString(const QString &value);

private:
    int _data;
    DataChangeHandler event = nullptr;

    QString _queryString;
    SqlQueryModel _query;

};


#endif // MODEL_H
