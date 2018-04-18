#ifndef MVCABSTRACTFACTORY_H
#define MVCABSTRACTFACTORY_H

#include "controller/controller.h"
#include "model/model.h"

class MvcAbstractFactory
{
public:
    MvcAbstractFactory();
    virtual Model *createModel(const QString &modelName)=0;
    virtual Controller *createController(const QString &controllerName)=0;
};

#endif // MVCABSTRACTFACTORY_H
