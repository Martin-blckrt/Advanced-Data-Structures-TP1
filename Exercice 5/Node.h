//
// Created by marti on 03/10/2022.
//
#include <string>
#include <thread>

#ifndef EXERCICE_2_NODE_H
#define EXERCICE_2_NODE_H

class Node {

public:
    int id;
    Node* suivant; //Un pointeur vers le noeud suivant
    Node* precedent; //Un pointeur vers le noeud précédent
    Node () : id(0), suivant(nullptr), precedent(nullptr) {};
    Node (const int& data_item, Node * next_ptr = 0, Node * pred_ptr =0) :
            id(data_item), suivant(next_ptr), precedent(pred_ptr){
        std::thread node(whileTrue());
    }

    void whileTrue() {while(true){}};
    ~Node() {};
};

#endif //EXERCICE_2_NODE_H
