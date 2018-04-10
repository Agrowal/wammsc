#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "model/model.h"
#include <QQmlApplicationEngine>

class Controller : public QObject
{
    Q_OBJECT
public:
    Controller(Model *model,QQmlApplicationEngine *view);
    void setModel(Model *model);
    void setView(QQmlApplicationEngine *view);

    Q_INVOKABLE int getModelData();
    Q_INVOKABLE void changeModelData();


    void load(QString url);

private:
    Model* _model;
    QQmlApplicationEngine* _view;

};

#endif // CONTROLLER_H
