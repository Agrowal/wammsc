#ifndef MAINPAGEMODEL_H
#define MAINPAGEMODEL_H

#include "model.h"

class mainpageModel : public Model
{
public:
    mainpageModel();

    static Model* _stdcall Create();
};

#endif // MAINPAGEMODEL_H
