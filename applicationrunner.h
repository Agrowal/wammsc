#ifndef APPLICATIONRUNNER_H
#define APPLICATIONRUNNER_H

#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "controller/controller.h"
#include "controller/mainpagecontroller.h"
#include "controller/logincontroller.h"

#include "model/model.h"
#include "model/mainpagemodel.h"
#include "model/loginmodel.h"

#include "genericfactory.h"

class ApplicationRunner : public QObject
{
    Q_OBJECT
public:    
    // Static access method
    static ApplicationRunner* getApplicationRunner();

    Q_INVOKABLE void load(QString newPageName);

private:
    // Private constructor
    ApplicationRunner();
    // Instance stored
    static ApplicationRunner* instance;

    //Members
    QQmlApplicationEngine *m_viewEngine = new QQmlApplicationEngine;
    Controller *m_controller;
    Model *m_model;

    using ModelFactory = GenericFactory<Model, MainpageModel, LoginModel>;
    ModelFactory m_modelFactory;

    using ControllerFactory = GenericFactory<Controller, MainpageController, LoginController>;
    ControllerFactory m_controllerFactory;


};

#endif // APPLICATIONRUNNER_H
