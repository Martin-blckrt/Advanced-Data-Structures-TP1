#include "Pile.h"
#include "Card.h"
#include "Player.h"
#include <string>

using namespace std;

int main() {
    cout << "Hello how many cards you want" << endl;
    cin >> DECK_SIZE;

    string p1, p2;
    Card a, b;
    cout << "Hello what is player 1 name" << endl;
    cin >> p1;
    cout << "Hello what is player 2 name" << endl;
    cin >> p2;

    Player player1(p1), player2(p2);

    Pile<Card> deckBataille(DECK_SIZE);
    deckBataille.fillDeck();
    for (int i = 0; i < deckBataille.taille(); i++)
    {
        for (int i = 0; i < 2; i++)
        {
            Card a = deckBataille.depiler();
        }
        if (!i)
            player1.addCardToDeck(a);
        else
            player2.addCardToDeck(a);
    }

    while (!deckBataille.estVide())
    {
        a = player1.playCard();
        b = player2.playCard();

        if (a > b) {
            player1.addWonCard(a);
            player1.addWonCard(b);
        } else if (a < b) {
            player2.addWonCard(a);
            player2.addWonCard(b);
        } else {
            cout << "Egalite on fait comment" << endl;
        }
    }

    int p1_points = player1.computePoints();
    int p2_points = player2.computePoints();

    if (p1_points > p2_points) {
        cout << player1 << " gagne !" << endl;
    } else if (p1_points < p2_points) {
        cout << player2 << " gagne !" << endl;
    } else {
        cout << "c'est une égalité !" << endl;
    }


    return 0;
}
