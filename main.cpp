#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "controller/controller.h"
#include "model/model.h"

#include "applicationrunner.h"


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    ApplicationRunner *appRunner = ApplicationRunner::getApplicationRunner();
    appRunner->load();

//    if (view->rootObjects().isEmpty())
//        return -1;

    return app.exec();
}
