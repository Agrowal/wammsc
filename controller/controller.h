#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "model/model.h"
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <memory>

class Controller : public QObject
{
    Q_OBJECT
public:
    Controller();
    void setModel(Model *model);
    void setView(QQmlApplicationEngine *view);

//    Q_INVOKABLE int getModelData();
//    Q_INVOKABLE void changeModelData();

    void rootModelQuery();

    virtual void load() =0;
    virtual void rootController() =0;

protected:
    Model* _model;
    QQmlApplicationEngine* _view;

    bool setRootModelQuery = false;
    const QString qmlControllerName = "PageController";
};

#endif // CONTROLLER_H
