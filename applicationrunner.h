#ifndef APPLICATIONRUNNER_H
#define APPLICATIONRUNNER_H

#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "controller/controller.h"
#include "model/model.h"

#include "controller/mainpagecontroller.h"

#include "genericfactory.h"

class ApplicationRunner
{
public:    
    // Static access method
    static ApplicationRunner* getApplicationRunner();

    void load();

private:
    // Private constructor
    ApplicationRunner();
    // Instance stored
    static ApplicationRunner* instance;

    //Members
    QQmlApplicationEngine *m_viewEngine = new QQmlApplicationEngine;
    Controller *m_controller;
    Model *m_model;

    using ModelFactory = GenericFactory<Model, MainpageModel>;
    ModelFactory m_modelFactory;

    using ControllerFactory = GenericFactory<Controller, MainpageController>;
    ControllerFactory m_controllerFactory;


};

#endif // APPLICATIONRUNNER_H
