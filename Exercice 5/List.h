#include "Node.h"
#include <vector>
#include <pthread.h>

#ifndef EXERCICE5_LIST_H
#define EXERCICE5_LIST_H

template <typename Node>
class List {
public:

    List();
    explicit List(int);
    ~List();

    void addNode();

    Node* tab;
private:
    int tete;
    int queue;
    int tailleMax;
    int cpt;
};


#endif //EXERCICE5_LIST_H
