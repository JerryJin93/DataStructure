//
// Created by Jerry on 2021/5/14.
//

#include "DS.h"

string DS::toString() const {
    string str = "This is the base DataStructure class";
    return str;
}

ostream &operator<<(ostream &os, const DS &ds) {
    os << "This is the base Data Structure class operator" << endl;
    return os;
}
