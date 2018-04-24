#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "model/model.h"
#include <QQmlApplicationEngine>
#include <QQmlContext>

class Controller : public QObject
{
    Q_OBJECT
public:
    Controller();
    void setModel(Model *model);
    void setView(QQmlApplicationEngine *view);

    Q_INVOKABLE int getModelData();
    Q_INVOKABLE void changeModelData();

    Q_INVOKABLE SqlQueryModel* getModelQuery();
    void rootModelQuery();
    void rootController();

    virtual void load() =0;

protected:
    Model* _model;
    QQmlApplicationEngine* _view;

    bool setRootModelQuery = false;

};

#endif // CONTROLLER_H
