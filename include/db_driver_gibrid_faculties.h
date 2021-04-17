// Copyright 2021 Davydov Nikolay <davy.nikola@gmail.com>


#ifndef HOMEWORK_1_DB_DRIVER_GIBRID_FACULTIES_H
#define HOMEWORK_1_DB_DRIVER_GIBRID_FACULTIES_H

#include <vector>
#include <string>
#include <iostream>

#include "db_driver_basic_faculties.h"
#include "db_driver_branch_faculties.h"

class DB_gibrid_faculties : public DB_branch_faculties, public DB_basic_faculties {
public:
    DB_gibrid_faculties();

    void create_db(const std::string &name_db, const std::string &type);

    void print_db();

    void delete_db(const std::string &name_db);

    void rename_db(const std::string &name, const std::string &new_name);

    void open(const std::string &name_db);

    void close();

    void add_record(const Basic_faculties &record);

    void add_record(const Branch_faculties &record);

    void print_reports();

    template<class Compare = std::less<>>
    void sort_Basic_faculties(Compare cmp = Compare{}) {
        DB_basic_faculties::sort(cmp);
    }

    template<class Compare = std::less<>>
    void sort_Branch_faculties(Compare cmp = Compare{}) {
        DB_branch_faculties::sort(cmp);
    }

    std::pair<std::vector<Basic_faculties>, std::vector<Branch_faculties>> select_by_NUK(const std::string &NUK);

    std::pair<std::vector<Basic_faculties>, std::vector<Branch_faculties>>
    select_by_num_teachers(const size_t num_teachers);

    void delete_record(const std::string &name);

    void edit_record(const std::string &name_old_record, const Basic_faculties &new_record);

    void edit_record(const std::string &name_old_record, const Branch_faculties &new_record);
};

#endif //HOMEWORK_1_DB_DRIVER_GIBRID_FACULTIES_H
