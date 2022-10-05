#include <string>
#include "Arbre.h"
#include "Node.h"
#include <vector>
#include "utils.h"

using namespace std;

int main() {
    string path = "../data/later.txt";
    Arbre a;

    vector<member> members = getMembersFromFile(path);

    for (const auto& m: members) {
        m.type == "first" ? a.firstNode(m) : Arbre::addNode(m, a.getRoot());
        a.updateTaille();
    }

    return 0;
}
