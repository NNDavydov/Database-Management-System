// Copyright 2021 Davydov Nikolay <davy.nikola@gmail.com>

#ifndef HOMEWORK_1_SORTING_H
#define HOMEWORK_1_SORTING_H

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

#endif //HOMEWORK_1_SORTING_H
