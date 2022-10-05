#include <iostream>
#include <fstream>
#include "Arbre.h"
#include <string>

using namespace std;

int main() {

    string path = "../Test_files/test.dico";
    Arbre a;

    fstream inputFile(path);
    string word;

    while (getline(inputFile, word)) {
        cout << word << endl;
        a.firstAjouterMot(word);
    }
    inputFile.close();

    cout << a.getCompteur() << endl;

    cout << a << endl;
    //cout << a.chercherMot("abas") << endl;
    //cout << a.chercherMot("martin") << endl;
    a.enleverMot("abs");
    a.enleverMot("las");
    cout << a << endl;
    a.enleverMot("lasse");
    cout << a << endl;
    a.enleverMot("bas");
    cout << a << endl;
    a.enleverMot("arbre");
    cout << a << endl;
    a.enleverMot("arbuste");
    cout << a << endl;
    a.enleverMot("lit");
    cout << a << endl;
    a.enleverMot("abas");
    cout << a << endl;

}
