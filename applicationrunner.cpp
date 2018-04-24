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

void ApplicationRunner::load(QString newPageName)
{
    m_model = ModelFactory::CreateA(newPageName);
    m_controller = ControllerFactory::CreateA(newPageName);

    m_controller->setModel(m_model);
    m_controller->setView(m_viewEngine);
    m_controller->rootModelQuery();
    m_controller->rootController();
    m_controller->load();

}

ApplicationRunner::ApplicationRunner()
{
    m_viewEngine->rootContext()->setContextProperty("ApplicationControl",QVariant::fromValue(this));
}
