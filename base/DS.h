//
// Created by Jerry on 2021/5/14.
//

#ifndef DATASTRUCTURE_DS_H
#define DATASTRUCTURE_DS_H

#include <iostream>

using namespace std;

class DS {
public:
    virtual string toString() const;

    friend ostream &operator<<(ostream &, const DS &);
};


#endif //DATASTRUCTURE_DS_H
