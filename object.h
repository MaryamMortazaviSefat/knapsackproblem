#ifndef OBJECT_H
#define OBJECT_H
#include <iostream>

using namespace std;

class Object
{
    friend istream & operator>>(istream & in,Object &e);
    friend ostream & operator<<(ostream & out,Object &e);

public:
    Object();
    Object(int _weight,int _value);
    int get_weight();
    int get_value();
private:
    int count;
    int weight;
    int value;
};

#endif // OBJECT_H
