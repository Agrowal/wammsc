#include "mvcfactory.h"

/* Null, because instance will be initialized on demand. */
MvcFactory* MvcFactory::instance = 0;

MvcFactory *MvcFactory::getMvcFactory()
{
    if (instance == 0)
    {
        instance = new MvcFactory();
    }

    return instance;
}

Model *MvcFactory::createModel(const QString &modelName)
{
    FactoryModelMap::iterator it = _factoryModelMap.find(modelName);
    if( it !=_factoryModelMap.end()){
        return it.value();
    }
    return NULL;
}

Controller *MvcFactory::createController(const QString &controllerName)
{

}

void MvcFactory::registerModel(const QString &modelName, CreateModelFn pfnCreate)
{
    _factoryModelMap[modelName] = pfnCreate;
}

MvcFactory::MvcFactory()
{
    registerModel("Mainpage", &mainpageModel::Create);
}
