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
    string p1, p2, continueInput;
    bool continueGame = true;

    // Get player names
    cout << "Hello what is player 1 name : " << endl;
    cin >> p1;
    cout << "Hello what is player 2 name : " << endl;
    cin >> p2;

    // Ask user for deck size and fill deck
    deckSize = getDeckSize();
    Pile<Card> deckBataille = makeFillDeck(deckSize);

    // Initialize players
    Player player1(p1, deckSize/2), player2(p2, deckSize/2);

    // Create pointers on players and game deck
    Player *ptr_1 = &player1;
    Player *ptr_2 = &player2;
    Pile<Card> *p_deck = &deckBataille;

    // Distribute cards in players' decks
    distributeCards(p_deck, ptr_1, ptr_2, deckSize/2);

    // Play the game
    while (!player1.isDeckEmpty() && continueGame)
    {
        playTurn(ptr_1, ptr_2);

        if (player1.isDeckEmpty())
            continueGame = false;
        else {
            do {
                cout << "Do you wish to continue the game ? (Y/N)" << endl;
                cin >> continueInput;
                if (continueInput == "N")
                    continueGame = false;
            }
            while (continueInput != "Y" && continueInput != "N");
        }
    }

    // Compute the players' points
    player1.computePoints();
    player2.computePoints();

   if (player1 > player2)
       cout << player1.getName() << " wins !" << endl;
   else if (player1 == player2)
       cout << "It's a tie !" << endl;
   else
       cout << player2.getName() << " wins !" << endl;

    return 0;
}
