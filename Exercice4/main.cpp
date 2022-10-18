#include <string>
#include "Arbre.h"
#include "Node.h"
#include <vector>
#include "utils.h"
#include <iostream>

using namespace std;

int main() {
    string path = "data/later.txt";
    Arbre a;

    vector<member> members = getMembersFromFile(path);

    for (const auto& m : members) {
        m.type == "first" ? a.firstNode(m) : Arbre::addNode(m, a.getRoot());
        a.updateTaille();
    }

    cout << "Arbre vide ? : ";
    a.estVide() ? cout << "Oui\n" : cout << "Non\n";

    cout << "Taille de l'arbre " << a.getTreeSize() << endl;

    cout << "Age moyen dans l'arbre : " << a.getAvgAge(a.getSumAge(2022, a.getRoot())) << "\n \n" << endl;

    cout << "Personnes ayant des yeux gris :" << endl;
    a.getSameEyedPeople("grey", a.getRoot());

    cout << "\n\nAncetres d'Ava Louri ayant les memes yeux qu'elle :" << endl;
    a.getSameEyedAncestors("brown", "avalouri", a.getRoot());

    cout << "\n\nDescendance de Lucas Delteil Prefixe: " << endl;
    a.getLineageOfPersonPreOrder(a.getPersonNode("lucasdelteil", a.getRoot()), a.getRoot());

    cout << "\n\nDescendance de Lucas Delteil Infixe: " << endl;
    a.getLineageOfPersonInOrder(a.getPersonNode("lucasdelteil", a.getRoot()), a.getRoot());

    cout << "\n\nDescendance de Lucas Delteil Postfixe: " << endl;
    a.getLineageOfPersonPostOrder(a.getPersonNode("lucasdelteil", a.getRoot()), a.getRoot());

    return 0;
}
