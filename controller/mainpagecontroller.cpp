#include "mainpagecontroller.h"

mainPageController::mainPageController(Model *model,QQmlApplicationEngine *view) : Controller(model,view)
{
    load("qrc:/qml/main.qml");
}
