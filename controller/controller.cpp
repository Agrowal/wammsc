#include "controller.h"

Controller::Controller(Model *model,QQmlApplicationEngine *view)
{
    this->setModel(model);
    this->setView(view);
    rootModelQuery();
}

void Controller::setModel(Model *model)
{
    _model = model;
}

void Controller::setView(QQmlApplicationEngine *view)
{
    _view = view;
}

int Controller::getModelData()
{
    return _model->getData();
}

void Controller::changeModelData()
{
    _model->changeData();
}

SqlQueryModel* Controller::getModelQuery()
{
    _model->getQuery();
}

void Controller::rootModelQuery()
{
    if(!setRootModelQuery){
        _view->rootContext()->setContextProperty("modelQuery",getModelQuery());
        setRootModelQuery = true;
    }
}

void Controller::load(QString url)
{
    _view->load(QUrl(url));
}
