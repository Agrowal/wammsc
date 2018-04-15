#ifndef APPLICATIONRUNNER_H
#define APPLICATIONRUNNER_H

#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "controller/controller.h"
#include "model/model.h"

#include "controller/mainpagecontroller.h"

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
    QQmlApplicationEngine *_viewEngine = new QQmlApplicationEngine;
    mainPageController *_controller;

};

#endif // APPLICATIONRUNNER_H
