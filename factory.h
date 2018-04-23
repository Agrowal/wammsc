#ifndef MVCABSTRACTFACTORY_H
#define MVCABSTRACTFACTORY_H

#include <type_traits>
#include <typeindex>
#include <map>
#include <QtCore>

template <class Interface> class Factory {
  template <class C, class T = void> struct enable_if_I :
    std::enable_if<std::is_base_of<Interface, C>::value, T> {};
  using create_fn = Interface* (*)();

  std::map<QByteArray, create_fn, std::less<>> m_creators;
  std::map<std::type_index, QByteArray> m_names;

  static Factory *&instance_ref() { // assume no inline static yet
    static Factory *m_instance;
    return m_instance;
  }
  Factory(const Factory &) = delete;
  Factory &operator=(const Factory &) = delete;

public:
  Factory() {
    Q_ASSERT(!instance());
    instance_ref() = this;
  }
  virtual ~Factory() { instance_ref() = {}; }

  template <class T> typename enable_if_I<T>::type Register(const QByteArray &name) {
    m_creators[name] = +[]()->Interface* { return new T(); };
    m_names[{typeid(T)}] = name;
  }

  template <class T1> typename enable_if_I<T1>::type Register() {
    this->Register<T1>(T1::className());
  }
  template <class T1, class T2, class...T> typename enable_if_I<T1>::type Register() {
    this->Register<T1>(T1::className());
    this->Register<T2, T...>();
  }

  template <typename T> static Interface *CreateA(T &&t) {
        return instance() ? instance()->Create(std::forward<T>(t)) : nullptr;
    }
    Interface *Create(QLatin1String name) const { return Create(name.data()); }
    template <typename T> Interface *Create(T &&name) const;
    static const QByteArray &NameOfA(const Interface * obj);
    const QByteArray &NameOf(const Interface *) const;
    static Factory *instance() { return instance_ref(); }
  };

  template <class Interface>
  template <typename T> Interface *Factory<Interface>::Create(T &&name) const {
    auto it = m_creators.find(name);
    return (it != m_creators.end()) ? it->second() : nullptr;
  }

  namespace detail {
  static const QByteArray & null() { static const QByteArray n; return n; }
  }
  template <class Interface>
  const QByteArray &Factory<Interface>::NameOfA(const Interface *obj) {
    return instance() ? instance()->NameOf(obj) : detail::null();
  }
  template <class Interface>
  const QByteArray &Factory<Interface>::NameOf(const Interface *obj) const {
    auto it = m_names.find(typeid(*obj));
    return (it != m_names.end()) ? it->second : detail::null();
  }

#endif // MVCABSTRACTFACTORY_H
