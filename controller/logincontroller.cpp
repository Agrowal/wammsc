#include "logincontroller.h"

LoginController::LoginController()
{

}

void LoginController::load()
{
    _view->load(QUrl(m_url));
}

void LoginController::rootController()
{
    _view->rootContext()->setContextProperty(qmlControllerName,QVariant::fromValue(this));
}

bool LoginController::login(QString userName, QString password, QString dbName)
{
    return Connection::getConnection()->login(userName, password, dbName);
}
