//
// Created by Jerry on 2021/5/14.
//

#ifndef DATASTRUCTURE_STRUTILS_H
#define DATASTRUCTURE_STRUTILS_H

#include <sstream>

using namespace std;

class StrUtils {
public:
    template<typename T>
    static string toString(const T &);
};

template<typename T>
string StrUtils::toString(const T &data) {
    ostringstream stream;
    stream << data;
    return stream.str();
}


#endif //DATASTRUCTURE_STRUTILS_H
