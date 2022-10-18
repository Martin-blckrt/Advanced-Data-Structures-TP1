#include <iostream>
#include <thread>
#include <vector>

#include "List.h"
#include "Node.h"

using namespace std;

void menu();
void mainMenu();
int choice = 0;

int main() {
    srand(time(nullptr));
    menu();
    return 0;
}

void menu() {
    auto* list = new List<Node>(20);
    do {
        mainMenu();

        switch(choice) {
            case 0:
                break;
            case 1:
                for (int i = 0; i < 10; i++)
                    list->addNode();
                break;
            case 2:
                list->addNode();
                break;
            case 3:
                if (list->tab->suivant != nullptr) {
                    list->tab->suivant->run_thread = true;
                    list->tab->suivant->send(0);
                }
                else
                    cout << "\nList only has element 0, fill it !" << endl;
                break;
            case 4:
                list = new List<Node>(20);
                break;
            default:
                break;
        }
    } while(choice != 0);
}

void mainMenu() {
    cout << "\nSelect an action" << endl;
    cout << "1 - Add 10 nodes to the list" << endl;
    cout << "2 - Add a node to the list" << endl;
    cout << "3 - Compute sum" << endl;
    cout << "4 - Clear list" << endl;
    cout << "0 - Exit" << endl;
    cout << "Please choose: ";
    cin >> choice;
}
