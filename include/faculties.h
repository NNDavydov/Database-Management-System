// Copyright 2021 Davydov Nikolay <davy.nikola@gmail.com>

#ifndef SEMESTER2_HOMEWORK_1_FACULTIES_H
#define SEMESTER2_HOMEWORK_1_FACULTIES_H

#include <iostream>
#include <string>
#include <map>

namespace Cathedra {
    struct Cathedra{
        std::string name_;
        std::map<std::string, size_t> disciplines_;
    };
}

class Faculties {
public:
    virtual size_t count_teachers() = 0;

    virtual ~Faculties() {}
};

#endif //SEMESTER2_HOMEWORK_1_FACULTIES_H
