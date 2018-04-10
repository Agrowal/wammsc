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
    query.setQuery("SELECT * FROM wammsc_test.firmatowary");
    return &query;
}
