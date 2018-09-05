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

//int Controller::getModelData()
//{
//    return 0;
//}

//void Controller::changeModelData()
//{
//}


