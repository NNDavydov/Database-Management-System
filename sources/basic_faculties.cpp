// Copyright 2021 Davydov Nikolay <davy.nikola@gmail.com>
#include "basic_faculties.h"

BasicFaculties::BasicFaculties() = default;


BasicFaculties::BasicFaculties(const std::string &name, const std::string NYK, const size_t num_department,
                               const std::map<std::string, std::vector<std::string>> &list_disciplines,
                               const std::map<std::string, size_t> &list_num_teachers) : name_(name), NYK_(NYK),
                                                                                         num_department_(
                                                                                                 num_department),
                                                                                         list_disciplines_(
                                                                                                 list_disciplines),
                                                                                         list_num_teachers_(
                                                                                                 list_num_teachers) {}


void BasicFaculties::set_name(const std::string &name) {
    name_ = name;
}


void BasicFaculties::set_NUK(const std::string &NYK) {
    NYK_ = NYK;
}


void BasicFaculties::set_num_departament(const size_t num_departament) {
    num_department_ = num_departament;
}


void BasicFaculties::set_list_disciplines(const std::map<std::string, std::vector<std::string>> list_disciplines) {
    list_disciplines_ = list_disciplines;
}


void BasicFaculties::set_list_num_teachers(const std::map<std::string, size_t> list_num_teachers) {
    list_num_teachers_ = list_num_teachers;
}


const std::string &BasicFaculties::get_name() {
    return name_;
}


const std::string &BasicFaculties::get_NUK() {
    return NYK_;
}


const size_t BasicFaculties::get_num_departament() {
    return num_department_;
}


const std::map<std::string, std::vector<std::string>> &BasicFaculties::get_list_disciplines() {
    return list_disciplines_;
}


const std::map<std::string, size_t> &BasicFaculties::get_list_num_teachers() {
    return list_num_teachers_;
}


size_t BasicFaculties::count_teachers() {
    size_t num_teachers = 0;
    for(auto temp: list_num_teachers_){
        num_teachers += temp.second;
    }

    return num_teachers;
}


BasicFaculties::~BasicFaculties() = default;
