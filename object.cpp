#include "object.h"



Object::Object()
{
    count=1;
    weight=0;
    value=0;
}

Object::Object(int _weight, int _value)
{
  count=1;
  weight=_weight;
  value=_value;

}

int Object::get_weight(){
    return weight;
}

int Object::get_value(){
    return value;
}

istream & operator>>(istream & in,Object &e){
    in>>e.weight>>e.value;
    return in;
}

ostream & operator<<(ostream & out,Object &e){
    out<<e.weight<<"/"<<e.value;
    return out;
}
