#include "mainpagemodel.h"

MainpageModel::MainpageModel()
{
    const char * sqlString = R"SQL(
                             SELECT
                             z.*
                             from
                             (SELECT distinct
                             '' ID_PARENT
                             ,t.KOD
                             ,t.Nazw Nazwa
                             ,t.Kat Nr_Katalog
                             ,t.Gr Grupa
                             ,'' Ilosc
                             ,t.MAG Magazyn
                             FROM
                             firmaewid w
                             JOIN firmatowary t ON (t.ID=w.IDzzs)
                             ) z
                             UNION
                             SELECT
                             (select t.kod from firmatowary t where t.ID=w.IDzzs) ID_PARENT
                             ,a.KOD KOD
                             ,a.Nazw Nazwa
                             ,a.Kat Nr_Katalog
                             ,a.Gr Grupa
                             ,w.ce Ilosc
                             ,w.str1 Magazyn
                             FROM
                             firmaewid w
                             JOIN firmatowary a ON (a.Kod=w.IDp AND a.MAG = w.str1)
                             )SQL";

    setQueryString(sqlString);
    //setQueryString("SELECT * FROM wammsc_test.firmatowary");
}

