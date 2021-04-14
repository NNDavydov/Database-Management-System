// Copyright 2021 Davydov Nikolay <davy.nikola@gmail.com>

#include <sstream>

#include "faculties.h"
#include "branch_faculties.h"
#include "basic_faculties.h"
#include "db_driver_basic_faculties.h"
#include "db_driver_branch_faculties.h"

int main() {
    Branch_faculties IU("IU", "NOZ", 2,
                        {{"IU8", {{"MOI",         4}, {"TIMP",   2}}},
                         {"IU7", {{"Programming", 5}, {"Python", 3}}}},
                        3, {{"FBI",        {{"MOI",         4}}},
                            {"Yandex",     {{"Programming", 5}, {"Python", 3}}},
                            {"Casperskiy", {{"TIMP",        2}}}});


    Branch_faculties PC("PC", "NYK", 1,
                        {{"PC4", {{"Priborostrenie", 3}}}}, 1,
                        {{"PC4", {{{"AlmazAntaiy", 3}}}}});


    Branch_faculties RK("RK", "NYK", 1,
                       {{"RK11", {{"IngGraf", 6}}}}, 1,
                       {{"AD", {{"Cherchenie", 5}}}});

    Branch_faculties RK2("RK", "NUK", 1,
                        {{"RK11", {{"IngGraf", 6}}}}, 1,
                        {{"AD", {{"Cherchenie", 5}}}});

    DB_branch_faculties db;
    db.create_db("DB1");
    db.open("DB1");
    db.add_record(RK);
    db.add_record(PC);
    db.add_record(IU);
    db.print_reports();
    db.close();
    db.open("DB1");
    db.print_reports();
    db.sort([](Branch_faculties lhs, Branch_faculties rhs){
        return lhs.get_name() < rhs.get_name();
    });

    db.print_reports();
    std::vector<Branch_faculties> vec = db.select_by_NUK("NYK");
    for(auto faculties: vec){
        std::cout<<faculties.get_name()<<"\t";
    }
    std::cout<<"\n\n\n\n";

    std::vector<Branch_faculties> vec2 = db.select_by_num_teachers(5);
    for(auto faculties: vec2){
        std::cout<<faculties.get_name()<<"\t";
    }
    std::cout<<"\n\n\n\n";

    db.delete_record("IU");
    db.print_reports();
    db.edit_record("RK", RK2);
    db.print_reports();
};

