#include "mainpagecontroller.h"

#include "xlsxdocument.h"

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

int MainpageController::readFile(QString path)
{
    QUrl filePath = QUrl(path);
    QXlsx::Document doc(filePath.path());
    QXlsx::CellRange a = doc.dimension();

    QString KOD_TOWARU;
    QString KOD_TOWARU_SKLADOWEGO;
    QString ILOSC;
    QString MAGAZYN;

    FileImporter import;

    for(int r = 2; r<=a.rowCount(); r++){
        for(int c = 1; c<= a.columnCount(); c++){
            //QXlsx::Cell cell = QXlsx::CellReference(r,c);
            QXlsx::Cell* cell = doc.cellAt(r, c);

            switch(c){
            case 1:
                KOD_TOWARU = cell->value().toString();
                break;
            case 2:
                KOD_TOWARU_SKLADOWEGO = cell->value().toString();
                break;
            case 3:
                ILOSC = cell->value().toString();
                break;
            case 4:
                MAGAZYN = cell->value().toString();
                break;
            }
        }

        qDebug()<<KOD_TOWARU<<" "<<KOD_TOWARU_SKLADOWEGO<<" "<<ILOSC<<" "<<MAGAZYN;

        Connection::getConnection()->getDb()->transaction();
        if(!import.importRow(KOD_TOWARU,KOD_TOWARU_SKLADOWEGO,ILOSC,MAGAZYN)){
            //rollback
            Connection::getConnection()->getDb()->rollback();
            qDebug()<<import.getErrorCode();
            return import.getErrorCode();
        }
    }
    //commit
    Connection::getConnection()->getDb()->commit();
    return 0;
}
