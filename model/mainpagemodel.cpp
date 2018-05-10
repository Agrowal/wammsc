#include "mainpagemodel.h"

MainpageModel::MainpageModel()
{
    const char * sqlString = R"SQL(
                             SELECT
                             t.ID
                             ,t.KOD
                             ,t.Nazw Nazwa
                             ,t.Kat Nr_Katalog
                             ,t.Gr Grupa
                             ,t.MAG Magazyn
                             ,' '
                             ,a.KOD KOD_skladowy
                             ,a.Nazw Nazwa_skladowy
                             ,a.Kat Nr_Katalog_skladowy
                             ,a.Gr Grupa_skladowy
                             ,w.ce Ilosc_skladowy
                             ,w.str1 Magazyn_skladowy
                             FROM
                             firmatowary t
                             JOIN firmaewid w ON (t.ID=w.IDzzs)
                             JOIN firmatowary a ON (a.Kod=w.IDp AND a.MAG = w.str1)
                             )SQL";

    setQueryString(sqlString);
    //setQueryString("SELECT * FROM wammsc_test.firmatowary");
}

