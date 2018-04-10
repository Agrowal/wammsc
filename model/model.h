#ifndef MODEL_H
#define MODEL_H

#include "domain/sqlquerymodel.h"

typedef void (*DataChangeHandler)(int newData);

class Model
{
public:
    Model();
    int getData();
    void changeData();

    void RegisterDataChangeHandler(DataChangeHandler handler);

    SqlQueryModel* getQuery();

private:
    int _data;
    DataChangeHandler event = nullptr;
    SqlQueryModel query;

};

#endif // MODEL_H
