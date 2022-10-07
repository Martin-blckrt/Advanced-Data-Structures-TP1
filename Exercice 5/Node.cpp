#include "Node.h"
#include <thread>
#include <iostream>


using namespace std;

Node :: Node () {
    id = 0;
    suivant = nullptr;
    precedent = nullptr;
    run_thread = false;
}

Node :: Node (const int& data_item, Node * next_ptr, Node * pred_ptr) {
    id = data_item;
    suivant = next_ptr;
    precedent = pred_ptr;
    run_thread = false;
}

void Node::send(int i) {
    cout << "sum is : " << i << endl;
    //while(true) {
        if (run_thread) {
            run_thread = false;
            if (suivant != nullptr) {
                suivant->run_thread = true;
                suivant->send(i + id);
            } //else
                //break;
        }
   // }

}
