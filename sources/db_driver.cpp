#include "db_driver.h"


DB_basic_faculties::DB_basic_faculties() {
    fs::create_directory(path_);
}

void DB_basic_faculties::create_db(const std::string &name_db) {
    if (fs::is_directory(path_ + separator_ + name_db)) {
        return;
    }

    fs::create_directory(path_ + separator_ + name_db);

    std::ofstream file(path_ + separator_ + name_db + separator_ + file_name1_, std::ios::binary);
    file.write((char *) &num_reports, sizeof(num_reports));
    file.close();
}

void DB_basic_faculties::print_db() {
    for (auto &temp : fs::recursive_directory_iterator(path_)) {
        if (temp.is_directory()) {
            std::cout << temp << "\n";
        }
    }
    return;
}

void DB_basic_faculties::delete_db(const std::string &name_db) {
    fs::remove_all(path_ + separator_ + name_db);
}

void DB_basic_faculties::rename_db(const std::string &name, const std::string &new_name) {
    const fs::path path = path_;
    try {
        fs::rename(path / name, path / new_name);
    }
    catch (fs::filesystem_error &error) {
        std::cout << "Базы данных не существует\n";
    }
}

void DB_basic_faculties::open(const std::string &name_db) {
    if (fs::is_directory(path_ + separator_ + name_db)) {
        name_open_db_ = name_db;
        std::ifstream file(path_ + separator_ + name_db + separator_ + file_name1_, std::ios::binary);
        file.read((char *) &num_reports, sizeof(num_reports));
        file.close();
    }
}

void DB_basic_faculties::close() {
    name_open_db_ = "";
    num_reports = 0;
}

void DB_basic_faculties::add_report(const Basic_faculties &report) {
    std::fstream file(path_ + separator_ + name_open_db_ + separator_ + file_name1_,
                      std::ios::binary | std::ios::in | std::ios::out);

    ++num_reports;
    file.seekp(0);
    file.write((char *) &num_reports, sizeof(size_t));
    file.close();


    file.open(path_ + separator_ + name_open_db_ + separator_ + file_name1_, std::ios::binary | std::ios::app);

    size_t num_departament = report.get_num_departament();
    size_t num_discipline;

    file << report.get_name() << std::ends;
    file << report.get_NUK() << std::ends;
    file.write((char *) &num_departament, sizeof(num_departament));


    for (auto &cathedra: report.get_list_cathedra()) {
        file << cathedra.name_ << std::ends;
        num_discipline = cathedra.disciplines_.size();
        file.write((char *) &num_discipline, sizeof(num_discipline));
        for (auto disciplines: cathedra.disciplines_) {
            file << disciplines.first << std::ends;
            file.write((char *) &disciplines.second, sizeof(disciplines.second));
        }
    }

    file.close();
}

void DB_basic_faculties::all_reports(std::vector<Basic_faculties> &vec_basic_faculties, std::fstream &file) {
    for (auto &basic_faculties : vec_basic_faculties) {
        std::string name;
        std::string NUK;
        size_t num_departament;

        std::getline(file, name, '\0');
        std::getline(file, NUK, '\0');
        file.read((char *) &num_departament, sizeof(num_departament));

        basic_faculties.set_name(name);
        basic_faculties.set_NUK(NUK);
        basic_faculties.set_num_departament(num_departament);

        std::vector<Cathedra::Cathedra> list_cathedra(num_departament);

        for (auto &cathedra: list_cathedra) {
            std::getline(file, cathedra.name_, '\0');

            std::map<std::string, size_t> map_disciplines;
            size_t num_discipline;
            file.read((char *) &num_discipline, sizeof(num_discipline));

            for (size_t i = 0; i < num_discipline; ++i) {
                std::string discipline;
                size_t num_teachers;

                std::getline(file, discipline, '\0');
                file.read((char *) &num_teachers, sizeof(num_teachers));

                map_disciplines.insert({discipline, num_teachers});
            }
            cathedra.disciplines_ = map_disciplines;

        }
        basic_faculties.set_list_cathedra(list_cathedra);
    }
}

void DB_basic_faculties::print_reports() {
    std::fstream file(path_ + separator_ + name_open_db_ + separator_ + file_name1_,
                      std::ios::binary | std::ios::in);

    std::vector<Basic_faculties> vec_basic_faculties(num_reports);
    file.read((char *) &num_reports, sizeof(num_reports));

    all_reports(vec_basic_faculties, file);

    size_t number = 1;
    for (auto &basic_faculties : vec_basic_faculties) {
        std::cout << "Запись №" << number << "\n";
        std::cout << "Факультет: " << basic_faculties.get_name() << "\n";
        std::cout << "НУК: " << basic_faculties.get_NUK() << "\n";
        std::cout << "Количество кафедр: " << basic_faculties.get_num_departament() << "\n";
        for (auto &cathedra: basic_faculties.get_list_cathedra()) {
            std::cout << "Кафедра: " << cathedra.name_ << "\n";
            std::cout << "Дисциплины и количество предподавателей: " << "\n";
            for (auto discipline : cathedra.disciplines_) {
                std::cout << discipline.first << ": " << discipline.second << "\t";
            }
            std::cout << "\n";
        }
        std::cout << "\n\n";
        ++number;
    }

    file.close();
}

std::vector<Basic_faculties> DB_basic_faculties::select_by_NUK(std::string NUK) {
    std::fstream file(path_ + separator_ + name_open_db_ + separator_ + file_name1_,
                      std::ios::binary | std::ios::in);

    std::vector<Basic_faculties> vec_basic_faculties(num_reports);

    file.read((char *) &num_reports, sizeof(num_reports));
    all_reports(vec_basic_faculties, file);

    std::vector<Basic_faculties> new_vec_basic_faculties;

    for (size_t i = 0; i < num_reports; ++i) {
        if (vec_basic_faculties[i].get_NUK() == NUK) {
            new_vec_basic_faculties.push_back(vec_basic_faculties[i]);
        }
    }

    return new_vec_basic_faculties;
}

std::vector<Basic_faculties> DB_basic_faculties::select_by_num_teachers(size_t num_teachers) {
    std::fstream file(path_ + separator_ + name_open_db_ + separator_ + file_name1_,
                      std::ios::binary | std::ios::in);

    std::vector<Basic_faculties> vec_basic_faculties(num_reports);

    file.read((char *) &num_reports, sizeof(num_reports));
    all_reports(vec_basic_faculties, file);

    std::vector<Basic_faculties> new_vec_basic_faculties;

    for (size_t i = 0; i < num_reports; ++i) {
        if (vec_basic_faculties[i].count_teachers() <= num_teachers) {
            new_vec_basic_faculties.push_back(vec_basic_faculties[i]);
        }
    }

    return new_vec_basic_faculties;
}

