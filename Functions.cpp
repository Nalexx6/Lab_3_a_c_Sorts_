//
// Created by Win10Pro on 28.03.2020.
//

#include "Functions.h"

double Functions::generate_rand_double(double min, double max) {

    double d = (double)rand() / RAND_MAX;
    return min + d * (max - min);

}

Point* Functions::create_N_rand(int& N) {

    Point* array = new Point[N];
    for(int i = 0; i < N; i++){
        array[i].x_cor = generate_rand_double(-N, N);
        array[i].y_cor = generate_rand_double(-N, N);
        array[i].z_cor = generate_rand_double(-N, N);
    }
    return array;
//    Diff_sorts::print_all_from_array(array, 0 , N - 1);
//    Diff_sorts::quick_sort(array, 0, N - 1, true);

}

Point* Functions::create_almost_sorted(int &N) {
    Point* array = new Point[N];
    for(int i = 0; i < N; i++){
        array[i].x_cor = i;
        array[i].y_cor = i;
        array[i].z_cor = i;
    }
    Diff_sorts::shuffle(array, 0, 20, false);
//    clock_t start = clock();
//    Diff_sorts::insertion_sort(array, 0 , N - 1, false);
//    clock_t end = clock();
//    std::cout<<end - start<<" ms\n";
    return array;
}

Point* Functions::create_almost_unsorted(int &N) {
    Point* array = new Point[N];
    for(int i = 0; i < N; i++){
        array[i].x_cor = N - i;
        array[i].y_cor = N - i;
        array[i].z_cor = N - i;
    }
    Diff_sorts::shuffle(array, 0, 20, false);
//    clock_t start = clock();
//    Diff_sorts::insertion_sort(array, 0 , N - 1, false);
//    clock_t end = clock();
//    std::cout<<end - start<<" ms\n";
    return array;
}

void Functions::multiple_sort_demo(void (*sort_ptr[])(Point*, int, int, bool), int key) {

    /*
     *
     */
    int N = 30;
    Point* array = create_N_rand(N);
    if(key == 3){
        Diff_sorts::set_limit(N / 4 + 1);
    }
    if(key == 4){
        Diff_sorts::set_rule(2);
    }
    (*sort_ptr[key])(array, 0, N - 1, true);
    std::cout<<"As we can see our array is sorted\n";
    delete[] array;
}

void Functions::comparison_benchmark(Point* array, int al_sorted, std::ofstream& f) {
    //std::cout<<"Running benchmark for random array....\n";
    //std::ofstream f ("../Files/Benchmark data(3a).txt", std::ios::app);
    clock_t start, end;
    int values[13][6] = {0};
    int i = 0;
    for(int N = 100; N <= 10000000; N *= 10){
        std::cout<<"Proccesing all sorts for array size "<<N<<"...."<<std::endl;
//        Point* array = create_N_rand(N);
        Point* copy = new Point[N];
        std::cout<<"Processing insertion sort...\n";
        if(N <= 100000 || al_sorted == 1) {
            for (int j = 0; j < N; j++) {
                copy[j] = array[j];
            }
            start = clock();
            Diff_sorts::insertion_sort(copy, 0, N - 1, false);
            end = clock();
            if (!Diff_sorts::check_for_sorted(copy, 0, N - 1))
                std::cout << "Array isn`t sorted insertion\n";
            values[0][i] = end - start;
        }

        for(int j = 0; j < N; j++) {
            copy[j] = array[j];
        }
        std::cout<<"Processing quick sort...\n";
        start = clock();
        Diff_sorts::quick_sort(copy, 0, N - 1, false);
        end = clock();
        if(! Diff_sorts::check_for_sorted(copy, 0, N - 1))
            std::cout<<"Array isn`t sorted quick\n";
        values[1][i] = end - start;

        for(int j = 0; j < N; j++) {
            copy[j] = array[j];
        }
        std::cout<<"Processing merge sort...\n";
        start = clock();
        Diff_sorts::merge_sort(copy, 0, N - 1, false);
        end = clock();
        if(! Diff_sorts::check_for_sorted(copy, 0, N - 1))
            std::cout<<"Array isn`t sorted \n";
        values[2][i] = end - start;


        for(int j = 0; j < N; j++) {
            copy[j] = array[j];
        }
        std::cout<<"Processing std quick sort...\n";
        start = clock();
        Diff_sorts::std_quick_sort(copy, 0, N - 1);
        end = clock();
        if(! Diff_sorts::check_for_sorted(copy, 0, N - 1))
//            std::cout<<"Array isn`t sorted std\n";
        values[3][i] = end - start;
        int k = 4;
        for(int l = 5; l <= 80; l *= 2) {
            Diff_sorts::set_limit(l);
            for(int j = 0; j < N; j++) {
                copy[j] = array[j];
            }
            std::cout<<"Processing smart merge sort for limit "<<l<<"\n";
            start = clock();
            Diff_sorts::smart_merge_sort(copy, 0, N - 1, false);
            end = clock();
            if(! Diff_sorts::check_for_sorted(copy, 0, N - 1))
                std::cout<<"Array isn`t sorted\n";
            values[k][i] = end - start;
            k++;
            //std::cout<<"fdsff\n";
        }
        for(int rule = 0; rule <= 2; rule++) {
            Diff_sorts::set_rule(rule);
            for(int j = 0; j < N; j++) {
                copy[j] = array[j];
            }
            std::cout<<"Processing shell sort for rule "<<rule<<"\n";
            start = clock();
            Diff_sorts::shell_sort(copy, 0, N - 1, false);
            end = clock();
            if(! Diff_sorts::check_for_sorted(copy, 0, N - 1))
                std::cout<<"Array isn`t sorted\n";
            values[k][i] = end - start;
            k++;
            //std::cout<<"fdsff\n";
        }
        if(N <= 1000000) {
            if( N != 1000000 || al_sorted == 0) {
                for (int j = 0; j < N; j++) {
                    copy[j] = array[j];
                }
                std::cout<<"Processing binary tree sort...\n";
                start = clock();
                Diff_sorts::bt_sort(copy, 0, N - 1, false);
                end = clock();
                if (!Diff_sorts::check_for_sorted(copy, 0, N - 1))
                    std::cout << "Array isn`t sorted\n";
                values[12][i] = end - start;
            }
        }

        i++;
        delete[] copy;
    }
    f << "Number of elements\t\t\t\t10^2\t10^3\t10^4\t10^5\t10^6\t10^7"
         "\nInsertion sort\t\t\t";

    for(int i = 0; i < 4; i++) {
        f << "\t\t" << values[0][i];
    }
    if(al_sorted)
        f<<"\t\t"<<values[0][4]<<"\t\t"<<values[0][5];
    else
        f <<"\t> 3 hours\t> 5 days";

    f << "\nQuick sort\t\t\t\t";
    for(int i = 0; i < 6; i++){
        f <<"\t\t"<< values[1][i];
    }

    f << "\nMerge sort\t\t\t\t";
    for(int i = 0; i < 6; i++){
        f <<"\t\t"<< values[2][i];
    }

    f << "\nStd::quick sort\t\t\t";
    for(int i = 0; i < 6; i++){
        f <<"\t\t"<< values[3][i];
    }

    int k = 4;
    for(int l = 5; l <= 80; l *= 2){
        f << "\nSmart merge sort(limit "<<l<<")";

        for(int i = 0; i < 6; i++){
            f <<"\t\t"<< values[k][i];
        }
        k++;
    }
    for(int rule = 0; rule < 3; rule++){
        f << "\nShell sort(rule "<<rule<<")\t\t";

        for(int i = 0; i < 6; i++){
            f <<"\t\t"<< values[k][i];
        }
        k++;
    }
    f << "\nBinary tree sort\t\t";
    for(int i = 0; i < 5; i++){
        f <<"\t\t"<< values[12][i];
    }
    if(al_sorted == 0)
        f <<"\t> 5 minutes";
    else
        f <<"\t~ 1 minute\t> 3 hours";



}