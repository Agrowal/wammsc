#ifndef MVCFACTORY_H
#define MVCFACTORY_H

#include "factory.h"

template <class Interface, class ...Types>
class GenericFactory : public Factory<Interface> {
public:
  GenericFactory() {
    this->template Register<Types...>();
  }
};

#endif // MVCFACTORY_H
