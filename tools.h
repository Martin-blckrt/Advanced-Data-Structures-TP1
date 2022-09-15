//
// Created by Clement on 14/09/2022.
//

#ifndef BATAILLE_TOOLS_H
#define BATAILLE_TOOLS_H

#include "Pile.h"
#include "Card.h"
#include "Player.h"

int getDeckSize();
Pile<Card> makeFillDeck(int size);
void distributeCards(Pile<Card> *p, Player *p1, Player *p2, int num_cards);
void playGame(Player*, Player*);

#endif //BATAILLE_TOOLS_H
