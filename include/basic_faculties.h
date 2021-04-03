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
    std::map<std::string, std::vector<std::string>> list_disciplines_;
    std::map<std::string, size_t> list_num_teachers_;
public:
    BasicFaculties();

    BasicFaculties(const std::string &name, const std::string NYK, const size_t num_department,
                   const std::map<std::string, std::vector<std::string>> &list_disciplines,
                   const std::map<std::string, size_t> &list_num_teachers);

    void set_name(const std::string &name);

    void set_NUK(const std::string &NYK);

    void set_num_departament(const size_t num_departament);

    void set_list_disciplines(const std::map<std::string, std::vector<std::string>> list_disciplines);

    void set_list_num_teachers(const std::map<std::string, size_t> list_num_teachers);

    const std::string &get_name();

    const std::string &get_NUK();

    const size_t get_num_departament();

    const std::map<std::string, std::vector<std::string>> &get_list_disciplines();

    const std::map<std::string, size_t> &get_list_num_teachers();

    size_t count_teachers();

    ~BasicFaculties();
};

#endif //SEMESTER_BASIC_FACULTIES_H
