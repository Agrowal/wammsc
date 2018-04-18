#include "mainpagemodel.h"

mainpageModel::mainpageModel()
{
    setQueryString("SELECT * FROM wammsc_test.firmatowary");
}

Model *mainpageModel::Create()
{
    return new mainpageModel();
}
