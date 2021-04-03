// Copyright 2021 Davydov Nikolay <davy.nikola@gmail.com>

#ifndef SEMESTER_DB_DRIVER_H
#define SEMESTER_DB_DRIVER_H

#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

namespace config {
    char separator = fs::path::preferred_separator;
    std::string path = fs::current_path();
    std::string directory = "myDB";
}

void menu() {
    setlocale(LC_ALL, "Russian");
    std::cout.fixed;
    std::cout << "----Создание БД - CREATE_DB <NAME DB>------------------------------------------------------" << "\n";
    std::cout << "----Вывод на экран существующих БД - PRINT DB>---------------------------------------------" << "\n";
    std::cout << "----Удаление БД - DELETE_DB <NAME DB>------------------------------------------------------" << "\n";
    std::cout << "----Переименование БД - RENAME <NAME> <NEW NAME>-------------------------------------------" << "\n";
    std::cout << "----Открытие БД - OPEN <NAME>--------------------------------------------------------------" << "\n";
    std::cout << "----Сохранение БД - SAVE <NAME>>-----------------------------------------------------------" << "\n";
    std::cout << "----Добавление записей в БД - ADD IN <NAME> <PARAM1>=VARIABLE1-----------------------------" << "\n";
    std::cout << "----Редактирование записей в БД - UPDATE <NAME> SET <PARAM>=VARIABLE WHERE <PARAM>=VARIABLE" << "\n";
    std::cout << "----Удаление записей в БД - DELETE <NAME> WHERE <PARAM>=VARIABLE---------------------------" << "\n";
    std::cout << "----Вывод на экран записей в БД - PRINT <NAME_DB>------------------------------------------" << "\n";
    std::cout << "----Выборка записей по по правилу - SELECT <NAME> WHERE <PARAM>=VARIABLE-------------------" << "\n";
    std::cout << "----Сохранение выборки как новый БД - SAVE <NAME> <NEW NAME> WHERE <PARAM>=VARIABLE--------" << "\n";
    std::cout << "----Сортировка записей БД - SORT <NAME> <PARAM>--------------------------------------------" << "\n";

}

void create_db(const std::string &name) {
    try {
        fs::create_directory(config::path + config::separator + config::directory + config::separator + name);
    }
    catch (fs::filesystem_error) {
        fs::create_directory(config::path + config::separator + config::directory);
        fs::create_directory(config::path + config::separator + config::directory + config::separator + name);
    }
}

void print_db() {
    for (auto &temp : fs::recursive_directory_iterator(config::path + config::separator + config::directory)) {
        std::cout << temp << "\n";
    }
    return;
}

void delete_db(const std::string &name) {
    fs::remove_all(config::path + config::separator + config::directory + config::separator + name);
}

void rename_db(const std::string &name, const std::string &new_name){
    const fs::path path = config::path+config::separator+config::directory;
    fs::rename(path/name, path/new_name);
}

void open_db(){

}

void save_db();

void update_record();

void delete_record();

void print_records();

void sort_records();

void select_record();

void save_new_db();

#endif //SEMESTER_DB_DRIVER_H
