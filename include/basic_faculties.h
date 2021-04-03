// Copyright 2021 Davydov Nikolay <davy.nikola@gmail.com>

#ifndef SEMESTER_BASIC_FACULTIES_H
#define SEMESTER_BASIC_FACULTIES_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "faculties.h"

class BasicFaculties : public Faculties {
private:
    std::string name_ = "";
    std::string NYK_ = "";
    size_t num_department_ = 0;
    std::multimap <std::string, std::vector> list_disciplines_;
    std::multimap <std::string, size_t> list_num_teachers_;
public:
    BasicFaculties(std::string &name, std::string NYK, size_t num_department,
                   std::multimap <std::string, std::vector> &list_disciplines,
                   std::multimap <std::string, size_t> &list_num_teachers);

    void set_name(std::string &name);

    void set_NUK(std::string &NYK);

    void set_num_departament(size_t num_departament);

    void set_list_disciplines(std::multimap <std::string, std::vector> list_disciplines);

    void set_list_num_teachers(std::multimap <std::string, size_t> list_num_teachers);

    std::string &set_name();

    std::string &set_NUK();

    size_t set_num_departament();

    std::multimap <std::string, std::vector> set_list_disciplines();

    std::multimap <std::string, size_t> set_list_num_teachers();

    size_t count_teachers();

    Faculties *search(std::string &name);

    ~BasicFaculties() = default;
};

#endif //SEMESTER_BASIC_FACULTIES_H
