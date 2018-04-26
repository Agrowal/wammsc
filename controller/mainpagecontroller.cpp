#include "mainpagecontroller.h"

MainpageController::MainpageController()
{
}

void MainpageController::load()
{
    _view->load(QUrl(m_url));
}

void MainpageController::rootController()
{
    _view->rootContext()->setContextProperty(qmlControllerName,QVariant::fromValue(this));
}

QString MainpageController::getUserName()
{
    return Connection::getConnection()->getDb()->userName();
}

SqlQueryModel *MainpageController::getSqlQuery()
{
    return _model->getQuery();
}

QStringList MainpageController::columnList()
{
    QStringList acceptedColumns;
    acceptedColumns << "Nazw" << "MAG" << "NVat" << "JM";

    QStringList availableColumns = _model->getQuery()->userRoleNames();


//    QMap<int, QString> res;
//    QHashIterator<int, QByteArray> i(_model->getQuery()->roleNames());
//    while (i.hasNext()) {
//        i.next();
//        if((i.key() > Qt::UserRole)&&(acceptedColumns.indexOf(i.value())))
//            res[i.key()] = i.value();
//    }
//    return res.values();

    return acceptedColumns;
}
