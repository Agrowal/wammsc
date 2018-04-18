#ifndef MVCFACTORY_H
#define MVCFACTORY_H

#include "mvcabstractfactory.h"

#include "model/mainpagemodel.h"

class MvcFactory : public MvcAbstractFactory
{
public:
    // Static access method
    static MvcFactory *getMvcFactory();
    Model *createModel(const QString &modelName);
    Controller *createController(const QString &controllerName);

    void registerModel(const QString &modelName,CreateModelFn pfnCreate);
    void registerController(const QString &modelController,CreateControllerFn pfnCreate);

private:
    // Private constructor
    MvcFactory();
    // Instance stored
    static MvcFactory *instance;

    typedef QMap<QString,CreateModelFn> FactoryModelMap;
    typedef QMap<QString,CreateControllerFn> FactoryControllerMap;
    FactoryModelMap _factoryModelMap;
    FactoryControllerMap _factoryControllerMap;

};

#endif // MVCFACTORY_H
