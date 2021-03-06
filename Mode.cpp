//
// Created by Win10Pro on 28.03.2020.
//

#include "Mode.h"

void Mode::demo() {

    char response = 'y';
    while(response == 'y') {

        std::cout<<"Hello, please choose the sort for which you want to execute demo\n"
                   "0 - Insertion sort\n"
                   "1 - Quick sort\n"
                   "2 - Merge sort\n"
                   "3 - Smart merge sort\n"
                   "4 - Shell sort\n"
                   "5 - Binary tree search\n";
        int key;
        std::cin>>key;
        void (*sort_ptr[])(Point*, int, int, bool) = {Diff_sorts::insertion_sort, Diff_sorts::quick_sort, Diff_sorts::merge_sort,
                            Diff_sorts::smart_merge_sort, Diff_sorts::shell_sort, Diff_sorts::bt_sort};
        Functions::multiple_sort_demo(sort_ptr, key);
        std::cout<<"If you want to execute demo another sort press 'y', press 'n', if you don`t\n";
        std::cin>>response;

    }

}

void Mode::benchmark() {

    int N = 10000000;
    std::string breakpoint;
    std::ofstream f_c("../Files/Benchmark data(3a_c).txt", std::ios::trunc);
    f_c.close();

    std::ofstream f("../Files/Benchmark data(3a_c).txt", std::ios::trunc);
    std::cout<<"There will be 3 different benchmarks for all sorts\n"
               "1 - randomly sorted array\n"
               "2 - almost sorted array\n"
               "3 - almost sorted array, but in reverse order\n";
    std::cout<<"Firstly we will execute benchmark for randomly sorted array,\n"
               "cin anything to continue\n";
    std::cin>>breakpoint;
    Point* array = Functions::create_N_rand(N);
    f << "Data for random sorted array\n";
    Functions::comparison_benchmark(array, 0, f);

    std::cout<<"Now we will execute benchmark for almost sorted array,\n"
               "cin anything to continue\n";
    std::cin>>breakpoint;
    array = Functions::create_almost_sorted(N);
    f << "\n\nData for almost sorted array\n";
    Functions::comparison_benchmark(array, 1, f);

    std::cout<<"Firstly we will execute benchmark for almost sorted array, but in reverse order,\n"
               "cin anything to continue\n";
    std::cin>>breakpoint;
    array = Functions::create_almost_unsorted(N);
    f << "\n\nData for almost sorted array, but in reverse order\n";

    Functions::comparison_benchmark(array, 2, f);
    std::cout<<"Results of benchmark are accessible in file: Benchmark data(3a_c).txt\n";
    f.close();



}
