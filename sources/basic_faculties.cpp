// Copyright 2021 Davydov Nikolay <davy.nikola@gmail.com>
#include "basic_faculties.h"

Basic_faculties::Basic_faculties() = default;


Basic_faculties::Basic_faculties(const std::string &name, const std::string &NYK, const size_t num_department,
                                 const std::vector<Cathedra::Cathedra> &list_cathedra) : name_(name), NYK_(NYK),
                                 num_department_(num_department), list_cathedra_(list_cathedra) {}


void Basic_faculties::set_name(const std::string &name) {
    name_ = name;
}


void Basic_faculties::set_NUK(const std::string &NYK) {
    NYK_ = NYK;
}


void Basic_faculties::set_num_departament(const size_t num_departament) {
    num_department_ = num_departament;
}


void Basic_faculties::set_list_cathedra(const std::vector<Cathedra::Cathedra> &list_cathedra) {
    list_cathedra_ = list_cathedra;
}


std::string Basic_faculties::get_name() const {
    return name_;
}


std::string Basic_faculties::get_NUK() const {
    return NYK_;
}


size_t Basic_faculties::get_num_departament() const {
    return num_department_;
}


std::vector<Cathedra::Cathedra> Basic_faculties::get_list_cathedra() const {
    return list_cathedra_;
}


size_t Basic_faculties::count_teachers() {
    size_t num_teachers = 0;
    for (auto cathedra: list_cathedra_) {
        for (auto disciplines : cathedra.disciplines_) {
            num_teachers += disciplines.second;
        }
    }

    return num_teachers;
}


Basic_faculties::~Basic_faculties() = default;
