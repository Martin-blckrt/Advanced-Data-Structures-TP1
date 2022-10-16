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
    char userInput = 'y';
    List<Node> list(10);

    for (int i = 0; i < 10; i++) {
        list.addNode();
    }

    do {
        list.tab->suivant->run_thread = true;
        list.tab->suivant->send(0);
        cout << "Launch another sequence ? (y/n)" << endl;
        cin >> userInput;
    } while(userInput == 'y');

    return 0;
}
