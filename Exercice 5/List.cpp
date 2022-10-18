#include "List.h"
#include <thread>
using namespace std;

template <>
List<Node*> :: List () {
    tete = 0;
    queue = 0;
    cpt = 0;
    tailleMax = 0;
    tab = nullptr;
}

template <>
List<Node> :: List (int max) {
    tab = new Node [max];
    tete = 0;
    queue = 1;
    cpt = 1;
    tailleMax = max;
}

template <>
List<Node> :: ~List () {
    delete[] tab;
}

template <>
void List<Node> :: addNode() {
    if (cpt < tailleMax) {
        Node* prev = &tab[0];
        while (prev->suivant != nullptr)
            prev = prev->suivant;
        Node *newNode = new Node(rand() % 10 + 1, nullptr , prev);
        prev->suivant = newNode;

        thread thr(&Node::send, newNode, cpt);
        thr.detach();
        queue ++;
        cpt ++;
    }
}
