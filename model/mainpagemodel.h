#ifndef MAINPAGEMODEL_H
#define MAINPAGEMODEL_H

#include "model.h"

class MainpageModel : public Model
{
public:
    MainpageModel();

    static auto className() { return "Mainpage"; }
};

#endif // MAINPAGEMODEL_H
