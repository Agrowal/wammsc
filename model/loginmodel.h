#ifndef LOGINMODEL_H
#define LOGINMODEL_H

#include "model.h"

class LoginModel : public Model
{
public:
    LoginModel();

    static auto className() { return "Login"; }
};

#endif // LOGINMODEL_H
