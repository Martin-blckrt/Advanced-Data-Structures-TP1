//
// Created by marti on 02/10/2022.
//

#include "Node.h"

#ifndef EXERCICE_2_LIST_H
#define EXERCICE_2_LIST_H

template <typename Node>
class List {
public:

    List();
    List(int);
    ~List();

    void addNode();

private:
    Node* tab;
    int tete;
    int queue;
    int tailleMax;
    int cpt;
};


#endif //EXERCICE_2_LIST_H
