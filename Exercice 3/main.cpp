#include <iostream>
#include <fstream>
#include "Arbre.h"
#include <string>

using namespace std;

int main() {

    string path = "../Test_files/alain.dico";
    Arbre a;

    fstream inputFile(path);
    string word;

    while (getline(inputFile, word) && word != "de") {
        cout << word << endl;
        a.firstAjouterMot(word);
    }
    inputFile.close();

    cout << a << endl;
}
