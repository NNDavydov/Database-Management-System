#include "db_driver_gibrid_faculties.h"

DB_gibrid_faculties::DB_gibrid_faculties(): DB_driver("Gibrid Faculties"){}


void DB_gibrid_faculties::open(const std::string &name_db) {
    if (fs::is_directory(path_ + separator_ + name_db)) {
        name_open_db_ = name_db;
        std::fstream file(path_ + separator_ + name_open_db_ + separator_ + file_name1_,
                          std::ios::binary | std::ios::in);
        file.read((char *) &num_records, sizeof(num_records));
        vec_gibrid_faculties.resize(num_records);
        all_records(file);
        file.close();
    }
}


void DB_gibrid_faculties::close(){
    name_open_db_ = "";
    num_records = 0;
    for(size_t i = 0; i < num_records; ++i){
        delete[] vec_gibrid_faculties[i];
    }
    vec_gibrid_faculties.resize(0);
    vec_gibrid_faculties.shrink_to_fit();
}


//void DB_gibrid_faculties::add_record(const Branch_faculties &record);


//void DB_gibrid_faculties::add_record(const Basic_faculties &record);


void DB_gibrid_faculties::all_records(std::fstream &file){
    for(auto &faculties: vec_gibrid_faculties){
        std::string type_faculties;
        std::getline(file, type_faculties, '\0');
        if(type_faculties == "basic_faculties")
    }
}


//void DB_gibrid_faculties::print_reports();


//std::pair<Basic_faculties, Branch_faculties> DB_gibrid_faculties::select_by_NUK(const std::string &NUK);


//std::pair<Basic_faculties, Branch_faculties> DB_gibrid_faculties::select_by_num_teachers(const size_t num_teachers);


//void DB_gibrid_faculties::delete_record(const std::string &name);


//void DB_gibrid_faculties::edit_record(const std::string &name_old_record, const Branch_faculties &new_record);


//void DB_gibrid_faculties::edit_record(const std::string &name_old_record, const Basic_faculties &new_record);

