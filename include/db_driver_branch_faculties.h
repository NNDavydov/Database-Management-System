// Copyright 2021 Davydov Nikolay <davy.nikola@gmail.com>

#ifndef HOMEWORK_1_DB_DRIVER_BRANCH_FACULTIES_H
#define HOMEWORK_1_DB_DRIVER_BRANCH_FACULTIES_H

#include <filesystem>
#include <iostream>
#include <string>
#include <fstream>

#include "branch_faculties.h"
#include "db_driver.h"

class DB_branch_faculties {
private:
    char separator_ = fs::path::preferred_separator;
    std::string path_ = std::string(fs::current_path()) + separator_ + "Branch Faculties";
    std::string file_name1_ = "branch_faculties.o";
    std::string name_open_db_ = "";
    size_t num_records = 0;
    std::vector<Branch_faculties> vec_branch_faculties;
public:
    DB_branch_faculties();

    void create_db(const std::string &name_db);

    void print_db();

    void delete_db(const std::string &name_db);

    void rename_db(const std::string &name, const std::string &new_name);

    void open(const std::string &name_db);

    void close();

    void add_record(const Branch_faculties &record);

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

    std::vector<Branch_faculties> select_by_NUK(const std::string &NUK);

    std::vector<Branch_faculties> select_by_num_teachers(const size_t num_teachers);

    void delete_record(const std::string &name);

    void edit_record(const std::string &name_old_record, const Branch_faculties &new_record);
};


#endif //HOMEWORK_1_DB_DRIVER_BRANCH_FACULTIES_H
