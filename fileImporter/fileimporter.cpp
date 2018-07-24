#include "fileimporter.h"

FileImporter::FileImporter()
{

}

bool FileImporter::warehouseOk(QString magazyn)
{
    return true;
}

bool FileImporter::indexOk(QString kod_towaru)
{
    QSqlQuery query;
    query.prepare("select t.ID from firmatowary t where t.Kod = :KOD_TOWARU");
    query.bindValue(0,kod_towaru);
    query.exec();
    while(query.next()){
        return true;
    }
    _errorCode=1;
    return false;
}

bool FileImporter::techAlreadExists(QString kod_towaru)
{
    QSqlQuery query;
    query.prepare("select tech.* from firmaewid tech where tech.IDzzs = (select t.ID from firmatowary t where t.Kod = :KOD_TOWARU) and tech.Anul = 'N'");
    query.bindValue(0,kod_towaru);
    query.exec();
    while(query.next()){
        return true;
    }
    _errorCode=2;
    return false;
}

bool FileImporter::amountOk(QString ilosc)
{
    bool isNumeric;
    ilosc.toDouble(&isNumeric);
    if(!isNumeric){_errorCode=3;}
    return isNumeric;
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

    if(!indexOk(KOD_TOWARU)){return false;}
    if(!indexOk(KOD_TOWARU_SKLADOWEGO)){return false;}
    if(!(_indexAlreadyChecked==KOD_TOWARU)){
        _indexAlreadyChecked=KOD_TOWARU;
        if(techAlreadExists(KOD_TOWARU)){return false;}
    }
    if(!amountOk(ILOSC)){return false;}

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

int FileImporter::getErrorCode() const
{
    return _errorCode;
}
