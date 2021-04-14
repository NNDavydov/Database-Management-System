// Copyright 2021 Davydov Nikolay <davy.nikola@gmail.com>
#include "branch_faculties.h"

Branch_faculties::Branch_faculties() = default;


Branch_faculties::Branch_faculties(const std::string &name, const std::string &NYK,
                                   const size_t num_department, const std::vector<Cathedra::Cathedra> &list_cathedra,
                                   size_t num_organization, const std::vector<Cathedra::Cathedra> &list_organization) :
                                   name_(name), NYK_(NYK), num_department_(num_department), list_cathedra_(list_cathedra),
                                   num_organization_(num_organization), list_organization_(list_organization) {}


void Branch_faculties::set_name(const std::string &name) {
    name_ = name;
}


void Branch_faculties::set_NUK(const std::string &NYK) {
    NYK_ = NYK;
}


void Branch_faculties::set_num_departament(const size_t num_departament) {
    num_department_ = num_departament;
}


void Branch_faculties::set_list_cathedra(const std::vector<Cathedra::Cathedra> &list_cathedra) {
    list_cathedra_ = list_cathedra;
}


void Branch_faculties::set_num_organization(const size_t num_organization) {
    num_organization_=num_organization;
}


void Branch_faculties::set_list_organization(const std::vector<Cathedra::Cathedra> &list_organization) {
    list_organization_=list_organization;
}


std::string Branch_faculties::get_name() const {
    return name_;
}


std::string Branch_faculties::get_NUK() const {
    return NYK_;
}


size_t Branch_faculties::get_num_departament() const {
    return num_department_;
}


std::vector<Cathedra::Cathedra> Branch_faculties::get_list_cathedra() const {
    return list_cathedra_;
}


size_t Branch_faculties::get_num_organization() const {
    return num_organization_;
}


std::vector<Cathedra::Cathedra> Branch_faculties::get_list_organization() const {
    return list_organization_;
}


size_t Branch_faculties::count_teachers() {
    size_t num_teachers = 0;

    for (auto cathedra: list_cathedra_) {
        for (auto disciplines : cathedra.disciplines_) {
            num_teachers += disciplines.second;
        }
    }

    return num_teachers;
}


Branch_faculties::~Branch_faculties() = default;
