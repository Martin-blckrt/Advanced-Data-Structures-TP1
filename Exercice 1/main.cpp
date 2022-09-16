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

    // Play the game
    while (continueGame)
    {
        Pile<Card> deckBataille = makeFillDeck(deckSize);

        // Initialize players
        Player player1(p1, deckSize / 2), player2(p2, deckSize / 2);

        // Create pointers on players and game deck
        Player* ptr_1 = &player1;
        Player* ptr_2 = &player2;
        Pile<Card>* p_deck = &deckBataille;

        // Distribute cards in players' decks
        distributeCards(p_deck, ptr_1, ptr_2, deckSize / 2);

        playGame(ptr_1, ptr_2);
        do {
            cout << "Do you wish to replay the game ? (Y/N)" << endl;
            cin >> continueInput;
            if (continueInput == "N")
                continueGame = false;
        } while (continueInput != "Y" && continueInput != "N");

        ~deckBataille~; // Delete the deck
        ptr_1 = ptr_1->resetPlayer(); // Reset the players
        ptr_2 = ptr_2->resetPlayer();
    }

    return 0;
}
