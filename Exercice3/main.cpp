#include <iostream>
#include <fstream>
#include "Arbre.h"
#include <string>

using namespace std;

void menu();
void mainMenu();
void optionsMenu();
void options(Arbre*);
void fillDico(Arbre*, const string&);
int choice1 = 0;
int choice2 = 5;

int main() {
    menu();
    return 0;
}

void menu() {
    do {
        choice2 = 0;
        mainMenu();
        Arbre a;
        Arbre* a_ptr = &a;

        switch (choice1) {
        case 0:
            break;
        case 1:
            fillDico(a_ptr, "alain");
            options(a_ptr);
            break;
        case 2:
            fillDico(a_ptr, "g");
            options(a_ptr);
            break;
        case 3:
            fillDico(a_ptr, "g1");
            options(a_ptr);
            break;
        case 4:
            fillDico(a_ptr, "guillaume");
            options(a_ptr);
            break;
        case 5:
            fillDico(a_ptr, "test");
            options(a_ptr);
            break;
        default:
            break;
        }
    } while (choice1 != 0);
}

void options(Arbre* a_ptr) {
    do {
        optionsMenu();
        switch (choice2) {
        case 0:
            exit(0);
        case 1:
            cout << *a_ptr << endl;
            break;
        case 2: {
            cout << "Type the word : ";
            string to_search;
            cin >> to_search;
            a_ptr->chercherMot(to_search) ? cout << to_search + " exists.\n" : cout << to_search + " does not exist.\n";
            break;
        }
        case 3: {
            cout << "Type the word : ";
            string to_add;
            cin >> to_add;
            cout << "Ajout en cours...\n";
            a_ptr->firstAjouterMot(to_add);
            break;
        }
        case 4: {
            cout << "Type the word : ";
            string to_delete;
            cin >> to_delete;
            a_ptr->enleverMot(to_delete);
            break;
        }
        case 5: {
            cout << "Number of words : " << a_ptr->getCompteur() << endl;
            break;
        }
        case 6: {
            break;
        }
        default:
            break;
        }
    } while (choice2 != 6);
}

void mainMenu() {
    cout << "Choose a dictionnary" << endl;
    cout << "1 - alain" << endl;
    cout << "2 - g" << endl;
    cout << "3 - g1" << endl;
    cout << "4 - guillaume" << endl;
    cout << "5 - test" << endl;
    cout << "0 - Exit" << endl;
    cout << "Please choose: ";
    cin >> choice1;
}

void optionsMenu() {
    cout << "Functions Menu" << endl;
    cout << "1 - Print tree" << endl;
    cout << "2 - Search a word (add a * to get all words with same root : arb*)" << endl;
    cout << "3 - Add a word" << endl;
    cout << "4 - Delete a word" << endl;
    cout << "5 - Get number of words" << endl;
    cout << "6 - Change dictionnary" << endl;
    cout << "0 - Exit" << endl;
    cout << "Please choose: ";
    cin >> choice2;
}

void fillDico(Arbre* a_ptr, const string& filename) {

    string path = "Test_files/";
    fstream inputFile(path + filename + ".dico");
    string word;

    while (getline(inputFile, word)) {
        a_ptr->firstAjouterMot(word);
    }
    inputFile.close();
}