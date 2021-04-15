// Copyright 2021 Davydov Nikolay <davy.nikola@gmail.com>


#ifndef HOMEWORK_1_DB_DRIVER_GIBRID_FACULTIES_H
#define HOMEWORK_1_DB_DRIVER_GIBRID_FACULTIES_H
#include <vector>
#include <string>
#include <iostream>

#include <db_driver.h>
#include "basic_faculties.h"
#include "branch_faculties.h"
#include "faculties.h"

class DB_gibrid_faculties: public DB_driver{
private:
    std::vector<Faculties *> vec_gibrid_faculties;
public:
    DB_gibrid_faculties();

    void open(const std::string &name_db);

    void close();

    void add_record(const Branch_faculties &record);

    void add_record(const Basic_faculties &record);

    void all_records(std::fstream &file);

    void print_reports();

    template<class Compare = std::less<>>
    void sort(Compare cmp = Compare{}) {
        std::fstream file(path_ + separator_ + name_open_db_ + separator_ + file_name1_,
                          std::ios::trunc | std::ios::out);

        std::vector<Branch_faculties> new_vec_branch_faculties(num_records);
        num_records = 0;
        file.write((char *) &num_records, sizeof(num_records));
        file.close();

        merge_sort(vec_branch_faculties.begin(), vec_branch_faculties.end(), new_vec_branch_faculties.begin(),
                   cmp);

        vec_branch_faculties.resize(0);
        for (auto branch_faculties : new_vec_branch_faculties) {
            add_record(branch_faculties);
        }
    }

    std::pair<Basic_faculties, Branch_faculties> select_by_NUK(const std::string &NUK);

    std::pair<Basic_faculties, Branch_faculties> select_by_num_teachers(const size_t num_teachers);

    void delete_record(const std::string &name);

    void edit_record(const std::string &name_old_record, const Branch_faculties &new_record);

    void edit_record(const std::string &name_old_record, const Basic_faculties &new_record);
};

#endif //HOMEWORK_1_DB_DRIVER_GIBRID_FACULTIES_H
