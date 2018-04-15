#ifndef MAINPAGECONTROLLER_H
#define MAINPAGECONTROLLER_H
#include "controller.h"
#include "model/mainpagemodel.h"

class mainPageController : public Controller
{
public:
    mainPageController(QQmlApplicationEngine *view);
    mainPageController();
};

#endif // MAINPAGECONTROLLER_H
