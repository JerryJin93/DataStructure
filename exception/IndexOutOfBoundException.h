//
// Created by Jerry on 2021/5/14.
//
#ifndef DATASTRUCTURE_INDEXOUTOFBOUNDEXCEPTION_H
#define DATASTRUCTURE_INDEXOUTOFBOUNDEXCEPTION_H

#include <iostream>

using namespace std;

class IndexOutOfBoundException : public exception {
private:
    char *name;
    static const char *DEFAULT_NAME;
public:
    IndexOutOfBoundException();

    explicit IndexOutOfBoundException(const string &);

    const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT override;

    char* getMsg() const;

    ~IndexOutOfBoundException();
};

#endif