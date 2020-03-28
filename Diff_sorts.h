//
// Created by Win10Pro on 28.03.2020.
//

#ifndef LAB_3_A_C_SORTS__DIFF_SORTS_H
#define LAB_3_A_C_SORTS__DIFF_SORTS_H

#include "Bin_search_tree.h"


#include <iostream>
#include <vector>
#include <cstdlib>

class Diff_sorts {

private:

    //Auxiliary

    static int compare(Point a, Point b);
    static void print_all_from_array(Point* array, int lo, int hi);

    //Quick sort

    static int partition(Point* array, int lo, int hi, bool printing);
    static void sort(Point* array, int lo, int hi, bool printing);


    //Merge sort

    static void merge(Point* array, Point* for_merge, int lo, int mid, int hi, bool printing);
    static void sort(Point* array, Point* for_merge, int lo, int hi, bool printing);

    //Smart merge sort

    static int limit;
    static void smart_sort(Point* array, Point* for_merge, int lo, int hi, bool printing);

    //Shell sort

    static int rule;
    static std::vector <int> gaps;
    static void set_gaps();
    static int my_pow(int base, int power);

public:
    //Auxiliary

    static void shuffle(Point* array, int lo, int hi, bool printing);
    static bool check_for_sorted(Point* array, int lo, int hi);

    //Insertion sort

    static void insertion_sort(Point* array, int lo, int hi, bool printing);

    //Quick sort

    static void quick_sort(Point* array, int lo, int hi, bool printing);

    //Merge sort

    static void merge_sort(Point* array, int lo, int hi, bool printing);

    //Smart merge sort

    static void set_limit(int a);
    static void smart_merge_sort(Point* array, int lo, int hi, bool printing);

    //Std:: quick sort

    static void std_quick_sort(Point* array, int lo, int hi);

    //Shell sort

    static void set_rule(int a);
    static void shell_sort(Point* array, int lo, int hi, bool printing);

    //Binary tree sort

    static void bt_sort(Point* array, int lo, int hi, bool printing);



};


#endif //LAB_3_A_C_SORTS__DIFF_SORTS_H
