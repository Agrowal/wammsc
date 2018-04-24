#ifndef LOGINCONTROLLER_H
#define LOGINCONTROLLER_H
#include "controller.h"

class LoginController : public Controller
{
public:
    LoginController();

    static auto className() { return "Login"; }
    virtual void load() override;

private:
    QString m_url = "qrc:/qml/LoginDialog.qml";
};

#endif // LOGINCONTROLLER_H
