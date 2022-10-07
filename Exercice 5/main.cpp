#include <iostream>
#include <thread>
#include <vector>

#include "List.h"
#include "Node.h"

using namespace std;

int main () {

    // create and fill a list of nodes with id
    // send each node on a different thread
    // make the send method

    List<Node> list(10);

    for (int i = 0; i < 10; i++) {
        list.addNode();
    }
    while(true){
        list.tab->suivant->run_thread = true;
        list.tab->suivant->send(1);

        list.tab->suivant->run_thread = true;
        list.tab->suivant->send(1);
    }

    return 0;
}
