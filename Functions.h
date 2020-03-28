//
// Created by Win10Pro on 28.03.2020.
//

#ifndef LAB_3_A_C_SORTS__FUNCTIONS_H
#define LAB_3_A_C_SORTS__FUNCTIONS_H


#include "Diff_sorts.h"

#include <ctime>
#include <fstream>

class Functions {

public:

    //Auxiliary functions

    static double generate_rand_double(double min, double max);
    static Point* create_N_rand(int& N);
    static Point* create_almost_sorted(int& N);
    static Point* create_almost_unsorted(int& N);

    //Functions

    static void multiple_sort_demo(void (*sort_ptr[])(Point*, int, int, bool), int key);
    static void comparison_benchmark(Point* array, int al_sorted, std::ofstream& f);

};


#endif //LAB_3_A_C_SORTS__FUNCTIONS_H
