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

bool MainpageController::readFile(QString path)
{
    QUrl filePath = QUrl(path);
    QXlsx::Document doc(filePath.path());
    QXlsx::CellRange a = doc.dimension();

    const char * sqlQueryString = R"SQL(
                             insert into firmaewid (IDe,IDzzs,IDp,Ro,ce,Okaz,str1,Akt,Anul) values
                             (
                                 concat('WG.',:KOD_TOWARU_SKLADOWEGO,(select UNIX_TIMESTAMP(sysdate())))
                                 ,(select t.ID from firmatowary t where t.Kod = :KOD_TOWARU)
                                 ,:KOD_TOWARU_SKLADOWEGO
                                 ,'sklad'
                                 ,:ILOSC
                                 ,(select a.Nazw from firmatowary a where a.Kod = :KOD_TOWARU_SKLADOWEGO)
                                 ,:MAGAZYN
                                 ,'T'
                                 ,'N'
                             )
                             )SQL";


    QString KOD_TOWARU;
    QString KOD_TOWARU_SKLADOWEGO;
    QString ILOSC;
    QString MAGAZYN;

    FileImporter import;
    bool parametersSet;


    qDebug() << a.rowCount();
    for(int r = 2; r<=a.rowCount(); r++){
        for(int c = 1; c<= a.columnCount(); c++){
            //QXlsx::Cell cell = QXlsx::CellReference(r,c);
            QXlsx::Cell* cell = doc.cellAt(r, c);

            //qDebug()<<cell->value().toString();
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

        if(import.checkIndex(KOD_TOWARU) && import.checkIndex(KOD_TOWARU_SKLADOWEGO)){
               parametersSet = true;
        }
        else{
            parametersSet = false;
        }

        qDebug()<<KOD_TOWARU<<" "<<KOD_TOWARU_SKLADOWEGO<<" "<<ILOSC<<" "<<MAGAZYN;
        if(parametersSet){
            QSqlQuery insertRowQuery;
            insertRowQuery.prepare(sqlQueryString);
            insertRowQuery.bindValue(0,KOD_TOWARU_SKLADOWEGO);
            insertRowQuery.bindValue(1,KOD_TOWARU);
            insertRowQuery.bindValue(2,KOD_TOWARU_SKLADOWEGO);
            insertRowQuery.bindValue(3,ILOSC);
            insertRowQuery.bindValue(4,KOD_TOWARU_SKLADOWEGO);
            insertRowQuery.bindValue(5,MAGAZYN);
            if(!insertRowQuery.exec()){return false;}
        }
    }
    return true;
}
