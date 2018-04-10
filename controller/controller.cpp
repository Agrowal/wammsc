#include "controller.h"

Controller::Controller(Model *model,QQmlApplicationEngine *view)
{
    this->setModel(model);
    this->setView(view);
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

void Controller::load(QString url)
{
    _view->load(QUrl(url));
}
