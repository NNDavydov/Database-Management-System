// Copyright 2021 Davydov Nikolay <davy.nikola@gmail.com>

#ifndef SEMESTER_BASIC_FACULTIES_H
#define SEMESTER_BASIC_FACULTIES_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "faculties.h"

class Basic_faculties : public Faculties {
private:
    std::string name_ = "";
    std::string NYK_ = "";
    size_t num_department_ = 0;
    std::vector<Cathedra::Cathedra> list_cathedra_;
public:
    Basic_faculties();

    Basic_faculties(const std::string &name, const std::string &NYK, const size_t num_department,
                    const std::vector<Cathedra::Cathedra> &list_cathedra);

    void set_name(const std::string &name);

    void set_NUK(const std::string &NYK);

    void set_num_departament(const size_t num_departament);

    void set_list_cathedra(const std::vector<Cathedra::Cathedra> &list_cathedra);

    std::string get_name() const;

    std::string get_NUK() const;

    size_t get_num_departament() const;

    std::vector<Cathedra::Cathedra> get_list_cathedra() const;

    size_t count_teachers();

    ~Basic_faculties();
};

#endif //SEMESTER_BASIC_FACULTIES_H
