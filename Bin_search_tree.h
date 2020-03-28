//
// Created by Win10Pro on 29.03.2020.
//

#ifndef LAB_3_A_C_SORTS__BIN_SEARCH_TREE_H
#define LAB_3_A_C_SORTS__BIN_SEARCH_TREE_H

#include "Point.h"

#include <iostream>

class Bin_search_tree {

private:

    class Node{

    public:
        Point value;
        Node* left;
        Node* right;
        int count;

        Node(Point value){
            this->value = value;
            this->right = nullptr;
            this->left = nullptr;
            count = 1;
        }
    };

    int compare(Point a, Point b);
public:
    Bin_search_tree();
    void insert(Point value);
    Node* insert(Node* node, Point value);
    void go_round(Point* array, int& index, Node* node, bool printing);
    void destroy(Node* node);


    Node* root;
};


#endif //LAB_3_A_C_SORTS__BIN_SEARCH_TREE_H
