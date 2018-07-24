#include "fileimporter.h"

FileImporter::FileImporter()
{

}

bool FileImporter::checkWarehouse(QString magazyn)
{
    return true;
}

bool FileImporter::checkIndex(QString kod_towaru)
{
    QSqlQuery query;
    query.prepare("select t.ID from firmatowary t where t.Kod = :KOD_TOWARU");
    query.bindValue(0,kod_towaru);
    query.exec();
    while(query.next()){
        return true;
    }
    return false;
}

bool FileImporter::checkAmount(QString ilosc)
{
    bool isNumeric;
    ilosc.toDouble(&isNumeric);
    return isNumeric;
}

bool FileImporter::checkIfAlreadyExists(QString kod_towaru)
{
    QSqlQuery query;
    query.prepare("select tech.* from firmaewid tech where tech.IDzzs = (select t.ID from firmatowary t where t.Kod = :KOD_TOWARU)");
    query.bindValue(0,kod_towaru);
    query.exec();
    while(query.next()){
        return false;
    }
    return true;
}

bool FileImporter::importRow(QString KOD_TOWARU, QString KOD_TOWARU_SKLADOWEGO, QString ILOSC, QString MAGAZYN)
{
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
    if(checkIndex(KOD_TOWARU) && checkIndex(KOD_TOWARU_SKLADOWEGO) && checkIfAlreadyExists(KOD_TOWARU) && checkAmount(ILOSC)){
        QSqlQuery insertRowQuery;
        insertRowQuery.prepare(sqlQueryString);
        insertRowQuery.bindValue(0,KOD_TOWARU_SKLADOWEGO);
        insertRowQuery.bindValue(1,KOD_TOWARU);
        insertRowQuery.bindValue(2,KOD_TOWARU_SKLADOWEGO);
        insertRowQuery.bindValue(3,ILOSC);
        insertRowQuery.bindValue(4,KOD_TOWARU_SKLADOWEGO);
        insertRowQuery.bindValue(5,MAGAZYN);
        return insertRowQuery.exec();
    }
    return false;
}
