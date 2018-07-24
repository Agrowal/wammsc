#ifndef FILEIMPORTER_H
#define FILEIMPORTER_H
#include <QtCore>
#include <QSqlQuery>

class FileImporter
{
public:
    FileImporter();
    bool warehouseOk(QString magazyn);
    bool indexOk(QString kod_towaru);
    bool amountOk(QString ilosc);
    bool techAlreadExists(QString kod_towaru);

    bool importRow(QString KOD_TOWARU,QString KOD_TOWARU_SKLADOWEGO, QString ILOSC, QString MAGAZYN);

    int getErrorCode() const;

private:
    int _errorCode;
    QString _indexAlreadyChecked = "";
};

#endif // FILEIMPORTER_H
