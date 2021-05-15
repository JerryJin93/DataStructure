//
// Created by Jerry on 2021/5/12.
//

#ifndef DATASTRUCTURE_COMPARABLE_H
#define DATASTRUCTURE_COMPARABLE_H

class Comparable {
public:
    virtual bool operator>(const Comparable &another) = 0;

    virtual bool operator>=(const Comparable &another) = 0;

    virtual bool operator<(const Comparable &another) = 0;

    virtual bool operator<=(const Comparable &another) = 0;

    virtual bool operator==(const Comparable &another) = 0;
};

#endif //DATASTRUCTURE_COMPARABLE_H
