#include <string>
#include <thread>
#include <vector>
#include <iostream>
#include <condition_variable>

#ifndef EXERCICE5_NODE_H
#define EXERCICE5_NODE_H


class Node {

public:
    int id;
    bool run_thread;
    Node* suivant; //Un pointeur vers le noeud suivant
    Node* precedent; //Un pointeur vers le noeud précédent
    Node ();
    explicit Node (const int&, Node *, Node *);
    ~Node() = default;
    void send(int);

};
#endif //EXERCICE5_NODE_H
