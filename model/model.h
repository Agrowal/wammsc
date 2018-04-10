#ifndef MODEL_H
#define MODEL_H

typedef void (*DataChangeHandler)(int newData);

class Model
{
public:
    Model();
    int getData();
    void changeData();

    void RegisterDataChangeHandler(DataChangeHandler handler);

private:
    int _data;
    DataChangeHandler event = nullptr;
};

#endif // MODEL_H
