// Copyright 2021 Davydov Nikolay <davy.nikola@gmail.com>

#ifndef SEMESTER2_HOMEWORK_1_BRANCH_FACULTIES_H
#define SEMESTER2_HOMEWORK_1_BRANCH_FACULTIES_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "faculties.h"


class Branch_faculties : public Faculties {
private:
    std::string name_ = "";
    std::string NYK_ = "";
    size_t num_department_ = 0;
    std::vector<Cathedra::Cathedra> list_cathedra_;
    size_t num_organization_ = 0;
    std::vector<Cathedra::Cathedra> list_organization_;
public:
    Branch_faculties();

    Branch_faculties(const std::string &name, const std::string &NYK,
                     const size_t num_department, const std::vector<Cathedra::Cathedra> &list_cathedra,
                     const size_t num_organization, const std::vector<Cathedra::Cathedra> &list_organization);

    void set_name(const std::string &name);

    void set_NUK(const std::string &NYK);

    void set_num_departament(const size_t num_departament);

    void set_list_cathedra(const std::vector<Cathedra::Cathedra> &list_cathedra);

    void set_num_organization(const size_t num_organization);

    void set_list_organization(const std::vector<Cathedra::Cathedra> &list_organization);

    std::string get_name() const;

    std::string get_NUK() const;

    size_t get_num_departament() const;

    std::vector<Cathedra::Cathedra> get_list_cathedra() const;

    size_t get_num_organization() const;

    std::vector<Cathedra::Cathedra> get_list_organization() const;

    size_t count_teachers();

    ~Branch_faculties();
};

#endif //SEMESTER2_HOMEWORK_1_BRANCH_FACULTIES_H
