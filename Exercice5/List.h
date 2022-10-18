#pragma once

#include "Node.h"
#include <vector>

template <typename Node>
class List {
public:

    List();
    explicit List(int);
    ~List();

    void addNode();
    int getLength();

    Node* tab{};
private:
    int tete;
    int queue;
    int tailleMax;
    int cpt;
};