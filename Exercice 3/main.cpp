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
    a.enleverMot("abas");
    a.enleverMot("las");
    a.enleverMot("lasse");
    a.enleverMot("bas");
    a.enleverMot("arbre");
    a.enleverMot("arbuste");
    cout << a.getCompteur() << endl;
    a.enleverMot("lit");
    cout << a << endl;
    cout << a.getCompteur() << endl;
    a.firstAjouterMot("lit");
    cout << a.getCompteur() << endl;
    cout << a << endl;
}
