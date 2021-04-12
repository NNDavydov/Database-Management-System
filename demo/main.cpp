// Copyright 2021 Davydov Nikolay <davy.nikola@gmail.com>

#include <sstream>

#include "faculties.h"
#include "branch_faculties.h"
#include "basic_faculties.h"
#include "db_driver.h"

int main() {
    Basic_faculties IU("IU", "NOZ", 2,
                       {{"IU8", {{"MOI",         4}, {"TIMP",   2}}},
                        {"IU7", {{"Programming", 5}, {"Python", 3}}}});

    Basic_faculties FN("FN", "NYK", 3,
                       {{"FN2",  {{"Linal",  6}, {"Angem",     6}}},
                        {"FN1",  {{"Matan",  5}, {"Integrals", 7}}},
                        {"FN10", {{"Fizika", 3}}}});

    Basic_faculties RK("RK", "NYK", 1,
                       {{"RK11",  {{"IngGraf",  6}}}});
    /*
    std::string command;
    std::getline(std::cin, command);
    std::string word;

    std::istringstream iss(command, std::istringstream::in);
    std::vector<std::string> wordsVector;
    while (iss >> word)
    {
        wordsVector.push_back(word);
        std::cout << word << "\n";
    }
     */

    DB_basic_faculties db;
    db.create_db("Db1");
    db.open("Db1");
    db.add_report(IU);
    db.add_report(FN);
    db.add_report(RK);
    db.print_reports();

    db.sort([](Basic_faculties lhs, Basic_faculties rhs){
        return lhs.get_name() < rhs.get_name();
    });
    db.print_reports();

    db.sort([](Basic_faculties lhs, Basic_faculties rhs){
        return lhs.get_num_departament() < rhs.get_num_departament();
    });
    db.print_reports();

    std::vector<Basic_faculties> vec_basic_faculties = db.select_by_num_teachers(10);
    for(size_t i =0; i<vec_basic_faculties.size(); ++i){
        std::cout<<vec_basic_faculties[i].get_name()<<"\n";
    }


};

