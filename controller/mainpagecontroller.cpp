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

TreeModel *MainpageController::getTreeModel()
{
    TreeModel *model = new TreeModel(*_model->getQuery());
    //usunac
    //qDebug()<<model->rowCount();
    qDebug()<<model->index(1,6).data().toString();
    return model;
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

    QString endOfFileMark = doc.cellAt(1,1)->value().toString();
    bool endOfFileFlag = false;
    QString currentCellValue;

    FileImporter import;

    int row = 3;
    while(true){

        for(int col = 1; col<= a.columnCount(); col++){
            //QXlsx::Cell cell = QXlsx::CellReference(r,c);
            //QXlsx::Cell* cell = doc.cellAt(row, col);

            currentCellValue = doc.read(row,col).toString();
            if(currentCellValue==endOfFileMark){
                endOfFileFlag = true;
            }

            switch(col){
            case 1:
                KOD_TOWARU = currentCellValue;
                break;
            case 2:
                KOD_TOWARU_SKLADOWEGO = currentCellValue;
                break;
            case 3:
                ILOSC = currentCellValue;
                break;
            case 4:
                MAGAZYN = currentCellValue;
                break;
            }
        }

        Connection::getConnection()->getDb()->transaction();

        if(endOfFileFlag){
            //commit
            Connection::getConnection()->getDb()->commit();
            return 0;
        }

        if(!import.importRow(KOD_TOWARU,KOD_TOWARU_SKLADOWEGO,ILOSC,MAGAZYN)){
            //rollback
            Connection::getConnection()->getDb()->rollback();
            return import.getErrorCode();
        }
        row+= 1;
    }
}
