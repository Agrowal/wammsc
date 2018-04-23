#ifndef MAINPAGEMODEL_H
#define MAINPAGEMODEL_H

#include "model.h"

class mainpageModel : public Model
{
public:
    mainpageModel();

    static auto className() { return "Mainpage"; }
};

#endif // MAINPAGEMODEL_H
