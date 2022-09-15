//
// Created by Clement on 14/09/2022.
//

#include "tools.h"
#include "Pile.h"
#include "Card.h"
#include "Player.h"

using namespace std;

int getDeckSize() //Get even number between
{
    int size = 0;
    do {
        cout << "Please enter an even number between 2 and 100 (included) : ";
        cin >> size;
    }
    while (size < 2 || size > 100 || (size % 2 != 0));

    return size;
}

Pile<Card> makeFillDeck(int size)
{
    Pile<Card> deckBataille(size);

    for (int i = 0; i < size; i++)
    {
        deckBataille.empiler(Card());
    }
    return deckBataille;
}

void distributeCards(Pile<Card> *deck ,Player *p1, Player *p2, int num_cards)
{
    for (int i = 0; i<num_cards; i++)
    {
        p1->addCardToDeck(deck->depiler());
        p2->addCardToDeck(deck->depiler());
    }
}

void playGame(Player *p1, Player *p2)
{
    while (!p1->isDeckEmpty())
    {
        Card a = p1->playCard();
        Card b = p2->playCard();

        if (a > b) {
            p1->addWonCard(a);
            p1->addWonCard(b);
        } else if (a == b) {
            cout << "Egalite on fait comment" << endl;
        } else {
            p2->addWonCard(a);
            p2->addWonCard(b);
        }
    }
}