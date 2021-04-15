// Copyright 2021 Davydov Nikolay <davy.nikola@gmail.com>

#ifndef SEMESTER_DB_DRIVER_H
#define SEMESTER_DB_DRIVER_H

#include <filesystem>
#include <iostream>
#include <string>
#include <fstream>

#include "faculties.h"
#include "basic_faculties.h"
#include "branch_faculties.h"
#include "sorting.h"

namespace fs = std::filesystem;

class DB_driver{
protected:
    const std::string directory_ = "";
    const char separator_ = fs::path::preferred_separator;
    const std::string path_ = std::string(fs::current_path()) + separator_ + directory_;
    const std::string file_name1_ = "file_with_reports.o";
    std::string name_open_db_ = "";
    size_t num_records = 0;
public:
    DB_driver(const std::string &directory);

    void create_db(const std::string &name_db);

    void print_db();

    void delete_db(const std::string &name_db);

    void rename_db(const std::string &name, const std::string &new_name);

    virtual void open(const std::string &name_db) = 0;

    virtual void close() = 0;
};

#endif //SEMESTER_DB_DRIVER_H