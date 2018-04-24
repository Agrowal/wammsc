#include "logincontroller.h"

LoginController::LoginController()
{

}

void LoginController::load()
{
    _view->load(QUrl(m_url));
}
