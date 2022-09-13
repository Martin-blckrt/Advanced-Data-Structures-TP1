#include "Pile.h"
#include "Card.h"

using namespace std;

int main() {
    Pile<Card> bataille (40);
    bataille.fillDeck();
    cout << bataille.taille() << endl;
    //cout << bataille.sommet() << endl;
    for (int i = 0; i < bataille.taille(); i++)
    {
        Card a = bataille.depiler();
        cout << a << endl;
    }
    cout << bataille.taille() << endl;
    //cout << bataille.sommet() << endl;
    return 0;
}
