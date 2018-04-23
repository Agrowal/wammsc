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
    _model = ModelFactory::CreateA("Mainpage");
    _controller = new mainPageController(_model,_viewEngine);
    _viewEngine->rootContext()->setContextProperty("controller",_controller);
}

ApplicationRunner::ApplicationRunner()
{

}
