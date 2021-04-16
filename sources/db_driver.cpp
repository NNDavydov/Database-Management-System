#include "db_driver.h"

DB_driver::DB_driver(const std::string &directory) : directory_(directory) {
    fs::create_directory(path_);
}


DB_driver::DB_driver(const std::string &directory, const std::string &path) : directory_
(path + fs::path::preferred_separator + directory) {
    fs::create_directory(path);
    fs::create_directory(path_);
}


void DB_driver::create_db(const std::string &name_db, const std::string &type_db) {
    if (fs::is_directory(path_ + separator_ + name_db)) {
        return;
    }

    fs::create_directory(path_ + separator_ + name_db);
    std::ofstream file;

    if (type_db == "basic") {
        file.open(path_ + separator_ + name_db + separator_ + file_name1_, std::ios::binary);
    } else if (type_db == "branch") {
        file.open(path_ + separator_ + name_db + separator_ + file_name2_, std::ios::binary);
    }

    file.write((char *) &num_records, sizeof(num_records));
    file.close();
}


void DB_driver::print_db() {
    for (auto &temp : fs::recursive_directory_iterator(path_)) {
        if (temp.is_directory()) {
            std::cout << temp << "\n";
        }
    }
    return;
}


void DB_driver::delete_db(const std::string &name_db) {
    if (name_open_db_ == name_db) {
        close();
    }
    fs::remove_all(path_ + separator_ + name_db);
}


void DB_driver::rename_db(const std::string &name, const std::string &new_name) {
    const fs::path path = path_;
    try {
        fs::rename(path / name, path / new_name);
    }
    catch (fs::filesystem_error &error) {
        std::cout << "Базы данных не существует\n";
    }
}



