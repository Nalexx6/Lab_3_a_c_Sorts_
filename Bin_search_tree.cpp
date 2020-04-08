//
// Created by Win10Pro on 29.03.2020.
//

#include "Bin_search_tree.h"

Bin_search_tree::Bin_search_tree() {

    this->root = nullptr;

}

int Bin_search_tree::compare(Point a, Point b) {

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

void Bin_search_tree::insert(Point value) {

    root = insert(root, value);

}

Bin_search_tree::Node *Bin_search_tree::insert(Bin_search_tree::Node *node, Point value) {

    if(node == nullptr)
        return new Node(value);
    if(compare(value, node->value) < 0){
        node->left = insert(node->left, value);
    }
    if(compare(value, node->value) > 0){
        node->right = insert(node->right, value);
    }
    if(compare(value, node->value) == 0){
        node->count++;
    }
    return node;

}

void Bin_search_tree::go_round(Point *array, int& index, Bin_search_tree::Node *node, bool printing) {

    if(node == nullptr)
        return;
    if(printing)
        std::cout<<"Now we will go left from element: "<<node->value.x_cor<<"\n";
    go_round(array, index,  node->left, printing);
    if(printing)
        std::cout<<"Now we will write element: "<<node->value.x_cor<<" to our array\n";
    for(int i = 0; i < node->count; i++) {
        array[index] = node->value;
        index++;
    }
    if(printing)
        std::cout<<"Now we will go right from element: "<<node->value.x_cor<<"\n";
    go_round(array, index, node->right, printing);

}

void Bin_search_tree::destroy(Node* node) {

    if(node == nullptr){
        return;
    }
    destroy(node->left);
    destroy(node->right);
    delete node;

}
