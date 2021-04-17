#include "db_driver_branch_faculties.h"


DB_branch_faculties::DB_branch_faculties() : DB_driver("Branch Faculties") {}


DB_branch_faculties::DB_branch_faculties(const std::string &path) : DB_driver("Branch Faculties", path) {}


void DB_branch_faculties::open(const std::string &name_db) {
    if (fs::is_directory(path_ + separator_ + name_db)) {
        name_open_db_ = name_db;
        std::fstream file(path_ + separator_ + name_open_db_ + separator_ + file_name2_,
                          std::ios::binary | std::ios::in);
        file.read((char *) &num_records, sizeof(num_records));
        vec_branch_faculties.resize(num_records);
        all_records(file);
        file.close();
    }
}


void DB_branch_faculties::close() {
    name_open_db_ = "";
    num_records = 0;
    vec_branch_faculties.resize(0);
    vec_branch_faculties.shrink_to_fit();
}


void DB_branch_faculties::add_record(const Branch_faculties &record) {
    for (size_t i = 0; i < num_records; ++i) {
        if (vec_branch_faculties[i].get_name() == record.get_name()) {
            return;
        }
    }

    std::fstream file(path_ + separator_ + name_open_db_ + separator_ + file_name2_,
                      std::ios::binary | std::ios::in | std::ios::out);

    ++num_records;
    file.seekp(0);
    file.write((char *) &num_records, sizeof(size_t));
    file.close();


    file.open(path_ + separator_ + name_open_db_ + separator_ + file_name2_, std::ios::binary | std::ios::app);

    size_t num_departament = record.get_num_departament();
    size_t num_organization = record.get_num_organization();
    size_t num_discipline;

    file << record.get_name() << std::ends;
    file << record.get_NUK() << std::ends;
    file.write((char *) &num_departament, sizeof(num_departament));
    file.write((char *) &num_organization, sizeof(num_organization));


    for (auto &cathedra: record.get_list_cathedra()) {
        file << cathedra.name_ << std::ends;
        num_discipline = cathedra.disciplines_.size();
        file.write((char *) &num_discipline, sizeof(num_discipline));
        for (auto disciplines: cathedra.disciplines_) {
            file << disciplines.first << std::ends;
            file.write((char *) &disciplines.second, sizeof(disciplines.second));
        }
    }

    for (auto &organization: record.get_list_organization()) {
        file << organization.name_ << std::ends;
        num_discipline = organization.disciplines_.size();
        file.write((char *) &num_discipline, sizeof(num_discipline));
        for (auto disciplines: organization.disciplines_) {
            file << disciplines.first << std::ends;
            file.write((char *) &disciplines.second, sizeof(disciplines.second));
        }
    }

    vec_branch_faculties.push_back(record);
    file.close();
}


void DB_branch_faculties::all_records(std::fstream &file) {
    for (auto &branch_faculties : vec_branch_faculties) {
        std::string name;
        std::string NUK;
        size_t num_departament;
        size_t num_organizations;

        std::getline(file, name, '\0');
        std::getline(file, NUK, '\0');
        file.read((char *) &num_departament, sizeof(num_departament));
        file.read((char *) &num_organizations, sizeof(num_organizations));

        branch_faculties.set_name(name);
        branch_faculties.set_NUK(NUK);
        branch_faculties.set_num_departament(num_departament);
        branch_faculties.set_num_organization(num_organizations);

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

        std::vector<Cathedra::Cathedra> list_organization(num_organizations);

        for (auto &organization: list_organization) {
            std::getline(file, organization.name_, '\0');

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
            organization.disciplines_ = map_disciplines;
        }

        branch_faculties.set_list_cathedra(list_cathedra);
        branch_faculties.set_list_organization(list_organization);
    }
}


void DB_branch_faculties::print_reports() {
    size_t number = 1;
    for (auto &basic_faculties : vec_branch_faculties) {
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

        for (auto &organization: basic_faculties.get_list_organization()) {
            std::cout << "Базовая организация: " << organization.name_ << "\n";
            std::cout << "Дисциплины и количество предподавателей: " << "\n";
            for (auto discipline : organization.disciplines_) {
                std::cout << discipline.first << ": " << discipline.second << "\t";
            }
            std::cout << "\n";
        }

        std::cout << "\n\n";
        ++number;
    }
}


std::vector<Branch_faculties> DB_branch_faculties::select_by_NUK(const std::string &NUK) {
    std::vector<Branch_faculties> new_vec_branch_faculties;

    for (size_t i = 0; i < num_records; ++i) {
        if (vec_branch_faculties[i].get_NUK() == NUK) {
            new_vec_branch_faculties.push_back(vec_branch_faculties[i]);
        }
    }

    return new_vec_branch_faculties;
}


std::vector<Branch_faculties> DB_branch_faculties::select_by_num_teachers(size_t num_teachers) {
    std::vector<Branch_faculties> new_vec_branch_faculties;

    for (size_t i = 0; i < num_records; ++i) {
        if (vec_branch_faculties[i].count_teachers() <= num_teachers) {
            new_vec_branch_faculties.push_back(vec_branch_faculties[i]);
        }
    }

    return new_vec_branch_faculties;
}


void DB_branch_faculties::delete_record(const std::string &name) {
    std::vector<Branch_faculties> new_vec_branch_faculties = vec_branch_faculties;
    vec_branch_faculties.resize(0);
    num_records = 0;

    std::fstream file(path_ + separator_ + name_open_db_ + separator_ + file_name2_,
                      std::ios::binary | std::ios::trunc | std::ios::out);
    file.write((char *) &num_records, sizeof(num_records));
    file.close();

    for (size_t i = 0; i < new_vec_branch_faculties.size(); ++i) {
        if (new_vec_branch_faculties[i].get_name() == name) {
            continue;
        }
        add_record(new_vec_branch_faculties[i]);
    }
}


void DB_branch_faculties::edit_record(const std::string &name_old_record, const Branch_faculties &new_record) {
    for (size_t i = 0; i < num_records; ++i) {
        if (vec_branch_faculties[i].get_name() == name_old_record) {
            vec_branch_faculties[i] = new_record;
        }
    }

    std::vector<Branch_faculties> new_vec_branch_faculties = vec_branch_faculties;
    vec_branch_faculties.resize(0);
    num_records = 0;

    std::fstream file(path_ + separator_ + name_open_db_ + separator_ + file_name2_,
                      std::ios::binary | std::ios::trunc | std::ios::out);
    file.write((char *) &num_records, sizeof(num_records));
    file.close();

    for (size_t i = 0; i < new_vec_branch_faculties.size(); ++i) {
        add_record(new_vec_branch_faculties[i]);
    }
}
