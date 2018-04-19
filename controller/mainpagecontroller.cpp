#include "mainpagecontroller.h"

mainPageController::mainPageController(Model *model,QQmlApplicationEngine *view) : Controller(model,view)
{
    load("qrc:/qml/main.qml");
}

Controller* mainPageController::Create()
{
    return new mainPageController(new Model, new QQmlApplicationEngine);
}
