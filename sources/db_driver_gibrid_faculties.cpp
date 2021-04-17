#include "db_driver_gibrid_faculties.h"

DB_gibrid_faculties::DB_gibrid_faculties() :
        DB_basic_faculties("Gibrid Faculties"), DB_branch_faculties("Gibrid Faculties") {}


void DB_gibrid_faculties::create_db(const std::string &name_db, const std::string &type) {
    DB_basic_faculties::create_db(name_db, "basic");
    DB_branch_faculties::create_db(name_db, "branch");
}


void DB_gibrid_faculties::print_db() {
    DB_basic_faculties::print_db();
}


void DB_gibrid_faculties::delete_db(const std::string &name_db) {
    DB_basic_faculties::delete_db(name_db);
    DB_branch_faculties::delete_db(name_db);
}


void DB_gibrid_faculties::rename_db(const std::string &name, const std::string &new_name) {
    DB_basic_faculties::rename_db(name, new_name);
    DB_branch_faculties::rename_db(name, new_name);
}


void DB_gibrid_faculties::open(const std::string &name_db) {
    DB_basic_faculties::open(name_db);
    DB_branch_faculties::open(name_db);
}


void DB_gibrid_faculties::close() {
    DB_basic_faculties::close();
    DB_branch_faculties::close();
}


void DB_gibrid_faculties::add_record(const Basic_faculties &record) {
    DB_basic_faculties::add_record(record);
}


void DB_gibrid_faculties::add_record(const Branch_faculties &record) {
    DB_branch_faculties::add_record(record);
}


void DB_gibrid_faculties::print_reports() {
    DB_basic_faculties::print_reports();
    DB_branch_faculties::print_reports();
}


std::pair<std::vector<Basic_faculties>, std::vector<Branch_faculties>>
DB_gibrid_faculties::select_by_NUK(const std::string &NUK) {
    std::pair<std::vector<Basic_faculties>, std::vector<Branch_faculties>> select_vectors;
    select_vectors.first = DB_basic_faculties::select_by_NUK(NUK);
    select_vectors.second = DB_branch_faculties::select_by_NUK(NUK);
    return select_vectors;
}


std::pair<std::vector<Basic_faculties>, std::vector<Branch_faculties>>
DB_gibrid_faculties::select_by_num_teachers(const size_t num_teachers) {
    std::pair<std::vector<Basic_faculties>, std::vector<Branch_faculties>> select_vectors;
    select_vectors.first = DB_basic_faculties::select_by_num_teachers(num_teachers);
    select_vectors.second = DB_branch_faculties::select_by_num_teachers(num_teachers);
    return select_vectors;
}


void DB_gibrid_faculties::delete_record(const std::string &name) {
    DB_basic_faculties::delete_record(name);
    DB_branch_faculties::delete_record(name);
}


void DB_gibrid_faculties::edit_record(const std::string &name_old_record, const Basic_faculties &new_record) {
    DB_basic_faculties::edit_record(name_old_record, new_record);
}


void DB_gibrid_faculties::edit_record(const std::string &name_old_record, const Branch_faculties &new_record) {
    DB_branch_faculties::edit_record(name_old_record, new_record);
}
