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
    qmlRegisterType<SqlQueryModel>("io.qt.queryModel", 1, 0, "QueryModel");

    ApplicationRunner *appRunner = ApplicationRunner::getApplicationRunner();
    appRunner->load("Login");

//    if (view->rootObjects().isEmpty())
//        return -1;

    return app.exec();
}
