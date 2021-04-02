// Copyright 2021 Davydov Nikolay <davy.nikola@gmail.com>

#ifndef SEMESTER2_HOMEWORK_1_FACULTIES_H
#define SEMESTER2_HOMEWORK_1_FACULTIES_H

#include <iostream>
#include <string>

class Faculties {
public:
    virtual size_t count_teachers() =0;

    virtual Faculties *search(std::string &name)= 0;

    ~Faculties();
};

#endif //SEMESTER2_HOMEWORK_1_FACULTIES_H
