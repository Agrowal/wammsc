#include "mainpagecontroller.h"

mainPageController::mainPageController(QQmlApplicationEngine *view) : Controller(new mainpageModel,view)
{
    load("qrc:/qml/main.qml");
}
