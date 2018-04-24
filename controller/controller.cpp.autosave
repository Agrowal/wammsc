#include "controller.h"

Controller::Controller()
{
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
    return 0;
}

void Controller::changeModelData()
{
}

SqlQueryModel* Controller::getModelQuery()
{
    _model->getQuery();
}

// tego trzeba sie pozbyc - rejestracja typu w qml i przekazywanie wyniku getModelQuery bezposrednio do widoku
void Controller::rootModelQuery()
{
    if(!setRootModelQuery){
        _view->rootContext()->setContextProperty("modelQuery",getModelQuery());
        setRootModelQuery = true;
    }
}

void Controller::rootController()
{
    _view->rootContext()->setContextProperty("controller",this);
}


