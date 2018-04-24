#ifndef MAINPAGECONTROLLER_H
#define MAINPAGECONTROLLER_H
#include "controller.h"
#include "model/mainpagemodel.h"

class MainpageController : public Controller
{
public:
    MainpageController();

    static auto className() { return "Mainpage"; }
    virtual void load() override;

private:
    QString m_url = "qrc:/qml/main.qml";

};

#endif // MAINPAGECONTROLLER_H
