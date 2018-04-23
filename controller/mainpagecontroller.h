#ifndef MAINPAGECONTROLLER_H
#define MAINPAGECONTROLLER_H
#include "controller.h"
#include "model/mainpagemodel.h"

class mainPageController : public Controller
{
public:
    mainPageController(Model *model,QQmlApplicationEngine *view);

    static Controller* _stdcall Create();

};

#endif // MAINPAGECONTROLLER_H
