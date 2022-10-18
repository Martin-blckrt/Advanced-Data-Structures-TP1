#include "Node.h"
#include <thread>
#include <iostream>


using namespace std;

Node::Node() {
    id = 0;
    suivant = nullptr;
    precedent = nullptr;
    run_thread = false;
}

Node::Node(const int &data_item, Node *next_ptr, Node *pred_ptr) {
    id = data_item;
    cout << "Node id : " << data_item << endl;
    suivant = next_ptr;
    precedent = pred_ptr;
    run_thread = false;
}

void Node::send(int i) {
    if (run_thread) {
        run_thread = false;
        if (suivant != nullptr) {
            cout << "At node " << id << ", sum is : " << i + id << endl;
            suivant->run_thread = true;
            suivant->send(i + id);
        } else
            cout << "\nTotal sum is : " << i + id << endl;
    }
}
