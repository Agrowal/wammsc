#include "model.h"

Model::Model()
{
    _data = 10;
}

int Model::getData()
{
    return _data;
}

void Model::changeData()
{
    _data += 5;
    if (this->event != nullptr){
        this->event(getData());
    }
}

void Model::RegisterDataChangeHandler(DataChangeHandler handler)
{
    this->event = handler;
}

SqlQueryModel* Model::getQuery()
{
    _query.setQuery(_queryString);
    return &_query;
}

void Model::setQueryString(const QString &value)
{
    _queryString = value;
}
