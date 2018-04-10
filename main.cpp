#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "controller/controller.h"
#include "model/model.h"

#include "domain/connection.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);


    Model *model = new Model;
    QQmlApplicationEngine *view = new QQmlApplicationEngine;
    Controller* controller = new Controller(model, view);

    view->rootContext()->setContextProperty("controller",controller);

    controller->load("qrc:/qml/main.qml");

    Connection* con = Connection::getConnection();

    if (view->rootObjects().isEmpty())
        return -1;

    return app.exec();
}
