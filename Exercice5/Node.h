#pragma once

#include <string>
#include <thread>
#include <vector>
#include <iostream>
#include <condition_variable>

class Node {

public:
    int id, value;
    bool run_thread;
    Node* suivant; //Un pointeur vers le noeud suivant
    Node* precedent; //Un pointeur vers le noeud pr�c�dent
    Node();
    explicit Node(const int&, const int&, Node*, Node*);
    ~Node() = default;
    void send(int);

};
