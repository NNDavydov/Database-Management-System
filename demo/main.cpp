// Copyright 2021 Davydov Nikolay <davy.nikola@gmail.com>

#include "db_driver.h"

int main() {
    setlocale(LC_ALL, "Russian");
    menu();
    create_db("DB1");
    create_db("DB2");
    create_db("DB3");
    create_db("DB4");
    print_db();
    delete_db("DB3");
    rename_db("DB4", "DB5");
};

