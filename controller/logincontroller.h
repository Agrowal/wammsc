#ifndef LOGINCONTROLLER_H
#define LOGINCONTROLLER_H
#include "controller.h"

class LoginController : public Controller
{
    Q_OBJECT
public:
    LoginController();

    static auto className() { return "Login"; }
    void load() override;
    void rootController() override;

    Q_INVOKABLE bool login(QString userName, QString password, QString dbName);

private:
    QString m_url = "qrc:/qml/LoginDialog.qml";
};

#endif // LOGINCONTROLLER_H
