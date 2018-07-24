#ifndef FILEIMPORTER_H
#define FILEIMPORTER_H
#include <QtCore>
#include <QSqlQuery>

class FileImporter
{
public:
    FileImporter();
    bool checkWarehouse(QString magazyn);
    bool checkIndex(QString kod_towaru);
    bool checkAmount(QString ilosc);
    bool checkIfAlreadyExists(QString kod_towaru);

    bool importRow(QString KOD_TOWARU,QString KOD_TOWARU_SKLADOWEGO, QString ILOSC, QString MAGAZYN);
};

#endif // FILEIMPORTER_H
