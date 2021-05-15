//
// Created by Jerry on 2021/5/15.
//
#include "IndexOutOfBoundException.h"
#include <cstring>

const char *IndexOutOfBoundException::DEFAULT_NAME = "Index out of bound!";

IndexOutOfBoundException::IndexOutOfBoundException(const string& name) {
    char* origin = const_cast<char*>(name.data());
    this->name = static_cast<char *>(malloc(sizeof(char *)));
    strcpy(this->name, origin);
}


const char *IndexOutOfBoundException::what() const noexcept {
    return name;
}

IndexOutOfBoundException::IndexOutOfBoundException():name(const_cast<char *>(DEFAULT_NAME)) {
}

char* IndexOutOfBoundException::getMsg() const {
    return name;
}

IndexOutOfBoundException::~IndexOutOfBoundException() {
    if (name) {
        free(name);
        name = nullptr;
    }
}
