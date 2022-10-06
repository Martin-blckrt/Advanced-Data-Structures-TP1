#include <string>
#include "Arbre.h"
#include "Node.h"
#include <vector>
#include "utils.h"
#include <iostream>

using namespace std;

int main() {
    string path = "../data/later.txt";
    Arbre a;

    vector<member> members = getMembersFromFile(path);

    for (const auto& m: members) {
        m.type == "first" ? a.firstNode(m) : Arbre::addNode(m, a.getRoot());
        a.updateTaille();
    }

    cout << "Age moyen dans l'arbre : " << a.getAvgAge(a.getSumAge(2022, a.getRoot())) << endl;
    cout << "Personnes ayant des yeux gris :" << endl;
    a.getSameEyedPeople("grey", a.getRoot());

    cout << "Ancetres d'Ava Louri ayant les memes yeux qu'elle :" << endl;
    a.getSameEyedAncestors("brown", "avalouri", a.getRoot());

    return 0;
}
