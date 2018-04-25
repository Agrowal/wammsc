#include "model.h"

Model::Model()
{
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
