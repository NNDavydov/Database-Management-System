#include "interface.h"

void menu() {
    setlocale(LC_ALL, "Russian");
    std::cout << "-------------------------------------------------------------------------------------------" << "\n";
    std::cout << "----Открытие всех БД однонго типа - OPEN_TYPE_DB <TYPE>------------------------------------" << "\n";
    std::cout << "----Закрытие всех БД однонго типа - CLOSE_TYPE_DB------------------------------------------" << "\n";
    std::cout << "----Создание БД - CREATE_DB <NAME DB>------------------------------------------------------" << "\n";
    std::cout << "----Вывод на экран существующих БД - PRINT_DB----------------------------------------------" << "\n";
    std::cout << "----Удаление БД - DELETE_DB <NAME DB>------------------------------------------------------" << "\n";
    std::cout << "----Переименование БД - RENAME <NAME> <NEW NAME>-------------------------------------------" << "\n";
    std::cout << "----Открытие БД - OPEN_DB <NAME>-----------------------------------------------------------" << "\n";
    std::cout << "----Закрытие БД - CLOSE_DB ----------------------------------------------------------------" << "\n";
    std::cout << "----Добавление записей в БД - ADD REPORT IN DB---------------------------------------------" << "\n";
    std::cout << "----Редактирование записей в БД - UPDATE WHERE NAME= VARIABLE------------------------------" << "\n";
    std::cout << "----Удаление записей в БД - DELETE WHERE NAME= VARIABLE------------------------------------" << "\n";
    std::cout << "----Вывод на экран записей в БД - PRINT_RECORDS--------------------------------------------" << "\n";
    std::cout << "----Выборка записей по по правилу - SELECT WHERE <PARAM>=VARIABLE--------------------------" << "\n";
    std::cout << "----Сохранение выборки как новый БД - SELECT_AND_SAVE <NEW NAME> WHERE <PARAM>= VARIABLE---" << "\n";
    std::cout << "----Сортировка записей БД - SORT <PARAM>---------------------------------------------------" << "\n";
    std::cout << "----Завершение работы - QUIT---------------------------------------------------------------" << "\n";
    std::cout << "-------------------------------------------------------------------------------------------" << "\n";
}

void insert_report_Basic_faculties(Basic_faculties &faculty) {
    std::string name;
    std::string NYK;
    size_t num_departament;
    std::cin.ignore();
    std::cout << "Введите название факультета: ";
    std::getline(std::cin, name);
    std::cout << "Введите НУК факультета: ";
    std::getline(std::cin, NYK);
    std::cout << "Введите количество кафедр факультета: ";
    std::cin >> num_departament;

    faculty.set_name(name);
    faculty.set_NUK(NYK);
    faculty.set_num_departament(num_departament);

    std::vector<Cathedra::Cathedra> list_cathedra(num_departament);
    for (auto &cathedra : list_cathedra) {
        std::string name_cathedra;
        size_t num_disciplines;
        std::map<std::string, size_t> map_disciplines;

        std::cin.ignore();
        std::cout << "Введите название кафедры: ";
        std::getline(std::cin, name_cathedra);
        std::cout << "Введите количество дисциплин: ";
        std::cin >> num_disciplines;

        for (size_t i = 0; i < num_disciplines; ++i) {
            std::string name_discipline;
            size_t num_teachers;

            std::cin.ignore();
            std::cout << "Введите название дисциплины и количество предподавателей: ";
            std::getline(std::cin, name_discipline);
            std::cin >> num_teachers;

            map_disciplines.insert({name_discipline, num_teachers});
        }

        cathedra.name_ = name_cathedra;
        cathedra.disciplines_ = map_disciplines;
        std::cin.ignore();
    }

    faculty.set_list_cathedra(list_cathedra);
}

void insert_report_Branch_faculties(Branch_faculties &faculty) {
    std::string name;
    std::string NYK;
    size_t num_departament;

    std::cin.ignore();
    std::cout << "Введите название факультета: ";
    std::getline(std::cin, name);
    std::cout << "Введите НУК факультета: ";
    std::getline(std::cin, NYK);
    std::cout << "Введите количество кафедр факультета: ";
    std::cin >> num_departament;

    faculty.set_name(name);
    faculty.set_NUK(NYK);
    faculty.set_num_departament(num_departament);

    std::vector<Cathedra::Cathedra> list_cathedra(num_departament);
    for (auto &cathedra : list_cathedra) {
        std::string name_cathedra;
        size_t num_disciplines;
        std::map<std::string, size_t> map_disciplines;

        std::cin.ignore();
        std::cout << "Введите название кафедры: ";
        std::getline(std::cin, name_cathedra);
        std::cout << "Введите количество дисциплин: ";
        std::cin >> num_disciplines;

        for (size_t i = 0; i < num_disciplines; ++i) {
            std::string name_discipline;
            size_t num_teachers;

            std::cin.ignore();
            std::cout << "Введите название дисциплины и количество предподавателей: ";
            std::getline(std::cin, name_discipline);
            std::cin >> num_teachers;

            map_disciplines.insert({name_discipline, num_teachers});
        }

        std::cin.ignore();
        cathedra.name_ = name_cathedra;
        cathedra.disciplines_ = map_disciplines;
    }

    faculty.set_list_cathedra(list_cathedra);

    size_t num_organization;
    std::cout << "Введите количество базовых организаций: ";
    std::cin >> num_organization;
    faculty.set_num_organization(num_organization);

    std::vector<Cathedra::Cathedra> list_organization(num_organization);
    for (auto &organization : list_organization) {
        std::string name_cathedra;
        size_t num_disciplines;
        std::map<std::string, size_t> map_disciplines;

        std::cin.ignore();
        std::cout << "Введите название организации: ";
        std::getline(std::cin, name_cathedra);
        std::cout << "Введите количество дисциплин: ";
        std::cin >> num_disciplines;

        for (size_t i = 0; i < num_disciplines; ++i) {
            std::string name_discipline;
            size_t num_teachers;

            std::cin.ignore();
            std::cout << "Введите название дисциплины и количество предподавателей: ";
            std::getline(std::cin, name_discipline);
            std::cin >> num_teachers;

            map_disciplines.insert({name_discipline, num_teachers});
        }

        std::cin.ignore();
        organization.name_ = name_cathedra;
        organization.disciplines_ = map_disciplines;
    }

    faculty.set_list_organization(list_organization);
}

void words_command(std::vector<std::string> &words, std::string &command) {
    words.resize(0);
    std::string word;
    std::istringstream iss(command, std::istringstream::in);
    while (iss >> word) {
        words.push_back(word);
    }
}

void interface() {
    menu();
    std::string command;
    std::vector<std::string> words;

    DB_branch_faculties db_branch_faculties;
    DB_basic_faculties db_basic_faculties;
    DB_gibrid_faculties db_gibrid_faculties;

    std::getline(std::cin, command);
    words_command(words, command);

    while (words.at(0) != "QUIT") {
        try {
            if (words.at(0) == "OPEN_TYPE_DB") {
                if (words.at(1) == "Basic") {
                    std::cout << "Открыт тип БД - Basic Faculties" << "\n";
                    std::getline(std::cin, command);
                    words_command(words, command);

                    while (words.at(0) != "CLOSE_TYPE_DB") {
                        if (words.at(0) == "CREATE_DB") {
                            db_basic_faculties.create_db(words.at(1), "basic");
                            std::cout << "БД создана" << "\n";
                        } else if (words.at(0) == "PRINT_DB") {
                            db_basic_faculties.print_db();
                        } else if (words.at(0) == "DELETE_DB") {
                            db_basic_faculties.delete_db(words.at(1));
                            std::cout << "БД удалена" << "\n";
                        } else if (words.at(0) == "RENAME") {
                            db_basic_faculties.rename_db(words.at(1), words.at(2));
                            std::cout << "БД переименована" << "\n";
                        } else if (words.at(0) == "OPEN_DB") {
                            db_basic_faculties.open(words.at(1));
                            std::cout << "БД открыта" << "\n";
                        } else if (words.at(0) == "CLOSE_DB") {
                            db_basic_faculties.close();
                            std::cout << "БД закрыта" << "\n";
                        } else if (words.at(0) == "DELETE") {
                            db_basic_faculties.delete_record(words.at(1));
                            std::cout << "Запись удалена" << "\n";
                        } else if (words.at(0) == "PRINT_RECORDS") {
                            db_basic_faculties.print_reports();
                        } else if (words.at(0) == "SELECT_AND_SAVE") {
                            if (words.at(3) == "NUM_TEACHERS=") {
                                std::istringstream iss(words.at(4), std::istringstream::in);
                                size_t num_teachers;
                                iss >> num_teachers;

                                auto vec_records = db_basic_faculties.select_by_num_teachers(num_teachers);
                                db_basic_faculties.close();
                                db_basic_faculties.create_db(words.at(1), "basic");
                                db_basic_faculties.open(words.at(1));
                                for (auto record: vec_records) {
                                    db_basic_faculties.add_record(record);
                                }
                                std::cout << "\n";
                                std::cout << "Выборка по количеству предподавателей сохранена" << "\n";
                            } else if (words.at(3) == "NYK=") {
                                auto vec_records = db_basic_faculties.select_by_NUK(words.at(4));
                                db_basic_faculties.close();
                                db_basic_faculties.create_db(words.at(1), "basic");
                                db_basic_faculties.open(words.at(1));
                                for (auto record: vec_records) {
                                    db_basic_faculties.add_record(record);
                                }
                                std::cout << "Выборка по НУК сохранена" << "\n";
                            }
                        } else if (words.at(0) == "SORT") {
                            if (words.at(1) == "name") {
                                db_basic_faculties.sort([](Basic_faculties lhs, Basic_faculties rhs) {
                                    return lhs.get_name() < rhs.get_name();
                                });
                            } else if (words.at(1) == "num_departments") {
                                db_basic_faculties.sort([](Basic_faculties lhs, Basic_faculties rhs) {
                                    return lhs.get_num_departament() < rhs.get_num_departament();
                                });
                            }
                            std::cout << "Сортировка выполнена" << "\n";
                        } else if (words.at(0) == "UPDATE") {
                            Basic_faculties faculty;
                            insert_report_Basic_faculties(faculty);
                            db_basic_faculties.edit_record(words.at(3), faculty);
                            std::cout << "Запись отредактирована" << "\n";
                        } else if (words.at(0) == "ADD") {
                            Basic_faculties faculty;
                            insert_report_Basic_faculties(faculty);
                            db_basic_faculties.add_record(faculty);
                            std::cout << "Запись добавлена" << "\n";
                        } else {
                            std::cout << "Неверная команда!" << "\n";
                        }

                        std::getline(std::cin, command);
                        words_command(words, command);
                    }
                } else if (words.at(1) == "Branch") {
                    std::cout << "Открыт тип БД - Branch Faculties" << "\n";
                    std::getline(std::cin, command);
                    words_command(words, command);

                    while (words.at(0) != "CLOSE_TYPE_DB") {
                        if (words.at(0) == "CREATE_DB") {
                            db_branch_faculties.create_db(words.at(1), "branch");
                            std::cout << "БД создана" << "\n";
                        } else if (words.at(0) == "PRINT_DB") {
                            db_branch_faculties.print_db();
                        } else if (words.at(0) == "DELETE_DB") {
                            db_branch_faculties.delete_db(words.at(1));
                            std::cout << "БД удалена" << "\n";
                        } else if (words.at(0) == "RENAME") {
                            db_branch_faculties.rename_db(words.at(1), words.at(2));
                            std::cout << "БД переименована" << "\n";
                        } else if (words.at(0) == "OPEN_DB") {
                            db_branch_faculties.open(words.at(1));
                            std::cout << "БД открыта" << "\n";
                        } else if (words.at(0) == "CLOSE_DB") {
                            db_branch_faculties.close();
                            std::cout << "БД закрыта" << "\n";
                        } else if (words.at(0) == "DELETE") {
                            db_branch_faculties.delete_record(words.at(1));
                            std::cout << "Запись удалена" << "\n";
                        } else if (words.at(0) == "PRINT_RECORDS") {
                            db_branch_faculties.print_reports();
                        } else if (words.at(0) == "SELECT_AND_SAVE") {
                            if (words.at(3) == "NUM_TEACHERS=") {
                                std::istringstream iss(words.at(4), std::istringstream::in);
                                size_t num_teachers;
                                iss >> num_teachers;

                                auto vec_records = db_branch_faculties.select_by_num_teachers(num_teachers);
                                db_branch_faculties.close();
                                db_branch_faculties.create_db(words.at(1), "branch");
                                db_branch_faculties.open(words.at(1));
                                for (auto record: vec_records) {
                                    db_branch_faculties.add_record(record);
                                }
                                std::cout << "\n";
                                std::cout << "Выборка по количеству предподавателей сохранена" << "\n";
                            } else if (words.at(3) == "NYK=") {
                                auto vec_records = db_branch_faculties.select_by_NUK(words.at(4));
                                db_branch_faculties.close();
                                db_branch_faculties.create_db(words.at(1), "branch");
                                db_branch_faculties.open(words.at(1));
                                for (auto record: vec_records) {
                                    db_branch_faculties.add_record(record);
                                }
                                std::cout << "Выборка по НУК сохранена" << "\n";
                            }
                        } else if (words.at(0) == "SORT") {
                            if (words.at(1) == "name") {
                                db_branch_faculties.sort([](Branch_faculties lhs, Branch_faculties rhs) {
                                    return lhs.get_name() < rhs.get_name();
                                });
                            } else if (words.at(1) == "num_departments") {
                                db_branch_faculties.sort([](Branch_faculties lhs, Branch_faculties rhs) {
                                    return lhs.get_num_departament() < rhs.get_num_departament();
                                });
                            }
                            std::cout << "Сортировка выполнена" << "\n";
                        } else if (words.at(0) == "UPDATE") {
                            Branch_faculties faculty;
                            insert_report_Branch_faculties(faculty);
                            db_branch_faculties.edit_record(words.at(3), faculty);
                            std::cout << "Запись отредактирована" << "\n";
                        } else if (words.at(0) == "ADD") {
                            Branch_faculties faculty;
                            insert_report_Branch_faculties(faculty);
                            db_branch_faculties.add_record(faculty);
                            std::cout << "Запись добавлена" << "\n";
                        } else {
                            std::cout << "Неверная команда!" << "\n";
                        }

                        std::getline(std::cin, command);
                        words_command(words, command);
                    }
                } else if (words.at(1) == "Gibrid") {
                    std::cout << "Открыт тип БД - Gibrid Faculties" << "\n";
                    std::getline(std::cin, command);
                    words_command(words, command);

                    while (words.at(0) != "CLOSE_TYPE_DB") {
                        if (words.at(0) == "CREATE_DB") {
                            db_gibrid_faculties.create_db(words.at(1), "gibrid");
                            std::cout << "БД создана" << "\n";
                        } else if (words.at(0) == "PRINT_DB") {
                            db_gibrid_faculties.print_db();
                        } else if (words.at(0) == "DELETE_DB") {
                            db_gibrid_faculties.delete_db(words.at(1));
                            std::cout << "БД удалена" << "\n";
                        } else if (words.at(0) == "RENAME") {
                            db_gibrid_faculties.rename_db(words.at(1), words.at(2));
                            std::cout << "БД переименована" << "\n";
                        } else if (words.at(0) == "OPEN_DB") {
                            db_gibrid_faculties.open(words.at(1));
                            std::cout << "БД открыта" << "\n";
                        } else if (words.at(0) == "CLOSE_DB") {
                            db_gibrid_faculties.close();
                            std::cout << "БД закрыта" << "\n";
                        } else if (words.at(0) == "DELETE") {
                            db_gibrid_faculties.delete_record(words.at(1));
                            std::cout << "Запись удалена" << "\n";
                        } else if (words.at(0) == "PRINT_RECORDS") {
                            db_gibrid_faculties.print_reports();
                        } else if (words.at(0) == "SELECT_AND_SAVE") {
                            if (words.at(3) == "NUM_TEACHERS=") {
                                std::istringstream iss(words.at(4), std::istringstream::in);
                                size_t num_teachers;
                                iss >> num_teachers;

                                auto vec_records = db_gibrid_faculties.select_by_num_teachers(num_teachers);
                                db_gibrid_faculties.close();
                                db_gibrid_faculties.create_db(words.at(1), "gibrid");
                                db_gibrid_faculties.open(words.at(1));
                                for (auto record: vec_records.first) {
                                    db_gibrid_faculties.add_record(record);
                                }
                                for (auto record: vec_records.second) {
                                    db_gibrid_faculties.add_record(record);
                                }
                                std::cout << "\n";
                                std::cout << "Выборка по количеству предподавателей сохранена" << "\n";
                            } else if (words.at(3) == "NYK=") {
                                auto vec_records = db_gibrid_faculties.select_by_NUK(words.at(4));
                                db_gibrid_faculties.close();
                                db_gibrid_faculties.create_db(words.at(1), "gibrid");
                                db_gibrid_faculties.open(words.at(1));
                                for (auto record: vec_records.first) {
                                    db_gibrid_faculties.add_record(record);
                                }
                                for (auto record: vec_records.second) {
                                    db_gibrid_faculties.add_record(record);
                                }
                                std::cout << "Выборка по НУК сохранена" << "\n";
                            }
                        } else if (words.at(0) == "SORT") {
                            if (words.at(1) == "name") {
                                db_gibrid_faculties.sort_Basic_faculties([](Basic_faculties lhs, Basic_faculties rhs) {
                                    return lhs.get_name() < rhs.get_name();
                                });
                                db_gibrid_faculties.sort_Branch_faculties(
                                        [](Branch_faculties lhs, Branch_faculties rhs) {
                                            return lhs.get_name() < rhs.get_name();
                                        });
                            } else if (words.at(1) == "num_departments") {
                                db_gibrid_faculties.sort_Basic_faculties([](Basic_faculties lhs, Basic_faculties rhs) {
                                    return lhs.get_num_departament() < rhs.get_num_departament();
                                });
                                db_gibrid_faculties.sort_Branch_faculties(
                                        [](Branch_faculties lhs, Branch_faculties rhs) {
                                            return lhs.get_num_departament() < rhs.get_num_departament();
                                        });
                            }
                            std::cout << "Сортировка выполнена" << "\n";
                        } else if (words.at(0) == "UPDATE") {
                            std::cout << "Введите тип факультета: ";
                            std::string type;
                            std::cin >> type;
                            if (type == "Basic") {
                                Basic_faculties faculty;
                                insert_report_Basic_faculties(faculty);
                                db_gibrid_faculties.edit_record(words.at(3), faculty);
                                std::cout << "Запись отредактирована" << "\n";
                            } else if (type == "Branch") {
                                Branch_faculties faculty;
                                insert_report_Branch_faculties(faculty);
                                db_gibrid_faculties.edit_record(words.at(3), faculty);
                                std::cout << "Запись отредактирована" << "\n";
                            }
                        } else if (words.at(0) == "ADD") {
                            std::cout << "Введите тип факультета: ";
                            std::string type;
                            std::cin >> type;

                            if (type == "Basic") {
                                Basic_faculties faculty;
                                insert_report_Basic_faculties(faculty);
                                db_gibrid_faculties.add_record(faculty);
                                std::cout << "Запись добавлена" << "\n";
                            } else if (type == "Branch") {
                                Branch_faculties faculty;
                                insert_report_Branch_faculties(faculty);
                                db_gibrid_faculties.add_record(faculty);
                                std::cout << "Запись добавлена" << "\n";
                            }
                        } else {
                            std::cout << "Неверная команда!" << "\n";
                        }

                        std::getline(std::cin, command);
                        words_command(words, command);
                    }
                } else {
                    std::cout << "Неверный тип БД" << "\n";
                }
            } else {
                std::cout << "Неверная команда! Чтобы начать работать с БД укажите тип БД." << "\n";
            }
        }
        catch (std::range_error &e) {
            std::cout << e.what() << "\n";
        }

        std::getline(std::cin, command);
        words_command(words, command);
    }
}

