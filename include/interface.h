// Copyright 2021 Davydov Nikolay <davy.nikola@gmail.com>

#ifndef HOMEWORK_1_INTERFACE_H
#define HOMEWORK_1_INTERFACE_H

#include <iostream>
#include <string>

#include "db_driver_gibrid_faculties.h"
#include "db_driver_branch_faculties.h"
#include "db_driver_basic_faculties.h"

void menu();

void words_command(std::vector<std::string> &wordsVector, std::string &command);

void insert_report_Basic_faculties(Basic_faculties &faculty);

void insert_report_Branch_faculties(Branch_faculties &faculty);

void interface();

#endif //HOMEWORK_1_INTERFACE_H
