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

namespace fs = std::filesystem;

namespace sorting {
    template<class It, class Out, class Compare = std::less<>>
    Out merge(It first1, It last1, It first2, It last2, Out out, Compare cmp = Compare{}) {
        while (first1 != last1) {
            if (cmp(*first1, *first2)) {
                *out = *first1;
                ++first1;
            } else {
                *out = *first2;
                ++first2;
            }
            ++out;
            if (first2 == last2) {
                std::copy(first1, last1, out);
                return out;
            }
        }
        std::copy(first2, last2, out);
        return out;
    }


    template<class It, class Out, class Compare = std::less<>>
    Out merge_sort(It first, It last, Out out, Compare cmp = Compare{}) {
        if (last - first == 2) {
            return merge(first, first + 1, first + 1, last, out, cmp);
        } else if (last - first < 2) {
            *out = *first;
            return out;
        }
        size_t half_size = (last - first) / 2;
        It middle = first + half_size;
        std::vector<typename std::iterator_traits<Out>::value_type> vec1(half_size);
        if ((last - first) % 2 != 0) {
            ++half_size;
        }
        std::vector<typename std::iterator_traits<Out>::value_type> vec2(half_size);
        merge_sort(first, middle, vec1.begin(), cmp);
        merge_sort(middle, last, vec2.begin(), cmp);
        return merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), out, cmp);
    }
}


class DB_basic_faculties {
private:
    char separator_ = fs::path::preferred_separator;
    std::string path_ = std::string(fs::current_path()) + separator_ + "Basic Faculties";
    std::string file_name1_ = "basic_faculties.o";
    std::string name_open_db_ = "";
    size_t num_records = 0;
public:
    DB_basic_faculties();

    void create_db(const std::string &name_db);

    void print_db();

    void delete_db(const std::string &name_db);

    void rename_db(const std::string &name, const std::string &new_name);

    void open(const std::string &name_db);

    void close();

    void add_record(const Basic_faculties &record);

    void all_records(std::vector<Basic_faculties> &vec_basic_faculties, std::fstream &file);

    void print_reports();

    template<class Compare = std::less<>>
    void sort(Compare cmp = Compare{}) {
        std::fstream file(path_ + separator_ + name_open_db_ + separator_ + file_name1_,
                          std::ios::binary | std::ios::in);

        std::vector<Basic_faculties> vec_basic_faculties(num_records);

        file.read((char *) &num_records, sizeof(num_records));
        all_records(vec_basic_faculties, file);

        std::vector<Basic_faculties> new_vec_basic_faculties(num_records);

        file.close();
        file.open(path_ + separator_ + name_open_db_ + separator_ + file_name1_,
                  std::ios::trunc | std::ios::out);
        num_records = 0;
        file.write((char *) &num_records, sizeof(num_records));
        file.close();

        sorting::merge_sort(vec_basic_faculties.begin(), vec_basic_faculties.end(), new_vec_basic_faculties.begin(),
                            cmp);

        for (auto basic_faculties : new_vec_basic_faculties) {
            add_record(basic_faculties);
        }
    }

    std::vector<Basic_faculties> select_by_NUK(const std::string &NUK);

    std::vector<Basic_faculties> select_by_num_teachers(const size_t num_teachers);

    void delete_record(const std::string &name);
};

#endif //SEMESTER_DB_DRIVER_H