#ifndef MAINPAGECONTROLLER_H
#define MAINPAGECONTROLLER_H
#include "controller.h"
#include "fileImporter/fileimporter.h"
#include "treemodel/treemodel.h"

class MainpageController : public Controller
{
    Q_OBJECT
public:
    MainpageController();

    static auto className() { return "Mainpage"; }
    void load() override;
    void rootController() override;

    Q_INVOKABLE QString getUserName();
    Q_INVOKABLE SqlQueryModel *getSqlQuery();

    Q_INVOKABLE TreeModel *getTreeModel();

    Q_INVOKABLE QStringList columnList();

    Q_INVOKABLE int readFile(QString path);

private:
    QString m_url = "qrc:/qml/main.qml";


};

#endif // MAINPAGECONTROLLER_H
