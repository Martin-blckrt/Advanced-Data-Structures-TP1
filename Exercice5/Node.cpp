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

Node::Node(const int& number, const int& data_item, Node* next_ptr, Node* pred_ptr) {
    id = number;
    value = data_item;
    cout << "Node " << id << " has value : " << data_item << endl;
    suivant = next_ptr;
    precedent = pred_ptr;
    run_thread = false;
}

void Node::send(int i) {
    if (run_thread) {
        run_thread = false;
        if (suivant != nullptr) {
            cout << "At node " << id << ", sum is : " << i + value << endl;
            suivant->run_thread = true;
            suivant->send(i + value);
        }
        else
            cout << "\nTotal sum is : " << i + value << endl;
    }
}