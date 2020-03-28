//
// Created by Win10Pro on 28.03.2020.
//

#include "Diff_sorts.h"

int Diff_sorts::limit = 10;

int Diff_sorts::rule = 0;

std::vector <int> Diff_sorts::gaps = {};

int Diff_sorts::compare(Point a, Point b) {

    if(a.x_cor > b.x_cor)
        return 1;
    if(a.x_cor < b.x_cor)
        return -1;
    if(a.y_cor > b.y_cor)
        return 1;
    if(a.y_cor < b.y_cor)
        return -1;
    if(a.z_cor > b.z_cor)
        return 1;
    if(a.z_cor < b.z_cor)
        return -1;
    return 0;

}

void Diff_sorts::print_all_from_array(Point *array, int lo, int hi) {

    for(int i  = lo; i < hi + 1; i++){
        std::cout<<array[i].x_cor<<"\t"<<array[i].y_cor<<"\t"<<array[i].z_cor<<"\n";
    }

}

void Diff_sorts::insertion_sort(Point *array, int lo, int hi, bool printing) {

    for (int i = lo; i < hi + 1; i++) {
        Point temp = array[i];
        int j;
        for (j = i; j > lo && compare(array[j-1], temp) > 0;j--) {
            array[j] = array[j-1];
        }
        array[j] = temp;
        if(printing){
            std::cout<<"It`s our array on "<<i<<" step\n";
            print_all_from_array(array, lo, hi);
        }
    }

}

void Diff_sorts::shuffle(Point *array, int lo, int hi, bool printing) {

    for(int i = 0; i < hi - lo + 1; i++){
        std::swap(array[i], array[lo + rand() % i]);
    }

}

int Diff_sorts::partition(Point *array, int lo, int hi, bool printing) {

    int i = lo, j = hi;
    while (true){
        while(compare(array[lo], array[i]) > 0){
            i++;
        }
        if(i == hi)
            break;
        while (compare(array[j], array[lo]) > 0){
            j--;
        }
        if(j == lo)
            break;
        if(i >= j)
            break;
        std::swap(array[i], array[j]);
        i++;
        j--;
    }
    std::swap(array [lo], array[j]);
    if(printing){
        std::cout << "It`s our array after partition by element "<<array[j].x_cor<<"\n";
        print_all_from_array(array, lo, hi);
    }

    return j;

}

void Diff_sorts::sort(Point *array, int lo, int hi, bool printing) {

    if(hi <= lo )
        return;
    int j = partition(array, lo, hi, printing);
    sort(array, lo, j - 1, printing);
    if(printing){
        std::cout<<"Now the left part of our array (maybe on recursive step) is sorted\n";
        print_all_from_array(array, lo, hi);
    }
    sort(array, j + 1, hi, printing);
    if(printing){
        std::cout<<"Now the whole array (maybe on recursive step) is sorted\n";
        print_all_from_array(array, lo, hi);
    }

}

void Diff_sorts::quick_sort(Point *array, int lo, int hi, bool printing) {

    shuffle(array, lo, hi, printing);
    if(printing){
        std::cout<<"Now we shuffle our array and then sort it\n";
        print_all_from_array(array, lo, hi);
    }
    sort(array, lo, hi, printing);

}

void Diff_sorts::merge(Point *array, Point *for_merge, int lo, int mid, int hi, bool printing) {

    for(int i = lo; i < hi + 1; i++){
        for_merge[i] = array[i];
    }
    int i = lo, j = mid + 1;
    for(int k = lo; k < hi + 1; k++){
        if(i > mid){
            array[k] = for_merge[j];
            j++;
        } else if(j > hi){
            array[k] = for_merge[i];
            i++;
        } else if(compare(for_merge[i], for_merge[j]) > 0){
            array[k] = for_merge[j];
            j++;
        } else{
            array[k] = for_merge[i];
            i++;
        }

    }
    if(printing){
        std::cout<<"Now we will merge our array\n";
        print_all_from_array(array, lo, hi);
    }

}

void Diff_sorts::sort(Point *array, Point *for_merge, int lo, int hi, bool printing) {

    if(hi <= lo)
        return;
    int mid = lo + (hi - lo) / 2;
    sort(array, for_merge, lo, mid, printing);
    sort(array, for_merge, mid + 1, hi, printing);
    merge(array, for_merge, lo ,mid, hi, printing);


}

void Diff_sorts::merge_sort(Point *array, int lo, int hi, bool printing) {

    Point* for_merge = new Point[hi - lo + 1];
    if(printing){
        std::cout<<"This merge sort use top-down algorithm\n";
        print_all_from_array(array, lo ,hi);

    }
    sort(array, for_merge, lo, hi, printing);
    delete[] for_merge;
}

void Diff_sorts::set_limit(int a) {

    limit = a;

}

void Diff_sorts::smart_sort(Point *array, Point *for_merge, int lo, int hi, bool printing) {

    if(hi <= lo + limit - 1){
        if(printing)
            std::cout<<"Now we will use insertion sort\n";
        insertion_sort(array, lo, hi, printing);
        return;
    }
    int mid = lo + (hi - lo) / 2;
    smart_sort(array, for_merge, lo, mid, printing);
    smart_sort(array, for_merge, mid + 1, hi, printing);
    merge(array, for_merge, lo, mid, hi, printing);


}

void Diff_sorts::smart_merge_sort(Point *array, int lo, int hi, bool printing) {

    Point* for_merge = new Point[hi - lo + 1];
    if(printing) {
        std::cout << "In smart merge sort we also use top_down algorithm,\n but for arrays which size is no more than "
                  << limit << " we use insertion sort\n";
        print_all_from_array(array, lo, hi);
    }
    smart_sort(array, for_merge, lo, hi, printing);
    delete[] for_merge;

}

void Diff_sorts::std_quick_sort(Point *array) {

    int (*comp)(Point, Point) = compare;
    std::qsort(array, sizeof(array), sizeof(array[0]), reinterpret_cast<int (*)(const void *, const void *)>(comp));

}

bool Diff_sorts::check_for_sorted(Point *array, int lo, int hi) {

    if(hi <= lo)
        return true;
    for(int i = lo + 1; i < hi + 1; i++){
        if(compare(array[i], array[i - 1]) < 0){
            return false;
        }
    }
    return true;
}

void Diff_sorts::set_rule(int a) {

    rule = a;

}

int Diff_sorts::my_pow(int base, int power) {

    int res = 1;
    for(int i = 0; i < power; i++){
        res *= base;
    }
    return res;

}

void Diff_sorts::set_gaps() {

    int i = 1;
    gaps.clear();
    if(rule == 0){

        while(i <= 10000000 / 3){
            gaps.emplace(gaps.begin(), i);
            i = 3 * i + 1;
        }
        return;

    }
    int k = 1;
    if(rule == 1){

        while(i <= 10000000){
            gaps.emplace(gaps.begin(), i);
            i = my_pow(4, k) + 3 * my_pow(2, k - 1)  + 1;
            k++;
        }
        return;

    }
    if(rule == 2){

        while(i <= 10000000){
            gaps.emplace(gaps.begin(), i);
            if(k % 2){
                i = 8 * my_pow(2, k) - 6 * my_pow(2, (k + 1) / 2) + 1;
            } else{
                i = 9 * (my_pow(2, k) - my_pow(2, k /2)) + 1;
            }
            k++;
        }

    }


}

void Diff_sorts::shell_sort(Point *array, int lo, int hi, bool printing) {

    set_gaps();
    for(auto gap: gaps) {
        if(gap < hi - lo + 1) {
            Point temp;
            for (int i = lo + gap; i < hi + 1; i++) {
                temp = array[i];
                std::size_t j;
                for (j = i; j >= gap && compare(array[j - gap], temp) > 0; j -= gap) {
                    array[j] = array[j - gap];
                }
                array[j] = temp;
            }
            if (printing) {
                std::cout << "It`s our array after sorting our array by gap = " << gap << "\n";
                print_all_from_array(array, lo, hi);
            }
        }
    }

}

void Diff_sorts::bt_sort(Point *array, int lo, int hi, bool printing) {

    Bin_search_tree* tree = new Bin_search_tree();
    if(printing){
        std::cout<<"Firstly we will build our tree\n";
    }
    for(int i = lo; i < hi + 1; i++){
        tree->insert(array[i]);
    }
    if(printing){
        std::cout<<"Now our tree is builded, so we will go-round it, and rewrite our array\n";
    }
    int index = lo;
    tree->go_round(array, index, tree->root, printing);
    tree->destroy(tree->root);
    delete tree;


}
