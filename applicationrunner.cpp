#include "applicationrunner.h"

/* Null, because instance will be initialized on demand. */
ApplicationRunner* ApplicationRunner::instance = 0;

ApplicationRunner *ApplicationRunner::getApplicationRunner()
{
    if (instance == 0)
    {
        instance = new ApplicationRunner();
    }

    return instance;
}

void ApplicationRunner::load()
{
    m_model = ModelFactory::CreateA("Mainpage");
    m_controller = ControllerFactory::CreateA("Mainpage");

    m_controller->setModel(m_model);
    m_controller->setView(m_viewEngine);
    m_controller->rootModelQuery();
    m_controller->rootController();
    m_controller->load();

}

ApplicationRunner::ApplicationRunner()
{

}
