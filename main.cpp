#include "Pile.h"
#include "Card.h"
#include "Player.h"
#include <string>
#include "tools.h"

using namespace std;

int main() {
    srand(time(nullptr));

    // Initialize variables
    int deckSize;
    string p1, p2;

    // Get player names
    cout << "Hello what is player 1 name : " << endl;
    cin >> p1;
    cout << "Hello what is player 2 name : " << endl;
    cin >> p2;

    // Initialize players
    Player player1(p1), player2(p2);
    cout << player1.getName() << endl;
    cout << player2.getName() << endl;

    // Ask user for deck size and fill deck
    deckSize = getDeckSize();
    Pile<Card> deckBataille = makeFillDeck(deckSize);

    // Create pointers on players and game deck
    Player *ptr_1 = &player1;
    Player *ptr_2 = &player2;
    Pile<Card> *p_deck = &deckBataille;

    // Distribute cards in players' decks
    distributeCards(p_deck, ptr_1, ptr_2, deckSize/2);

    // Check for updated size of deck
    cout << deckBataille.taille() << endl;


   /*

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
    }*/


    return 0;
}
