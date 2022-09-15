//
// Created by Clement on 14/09/2022.
//

#ifndef BATAILLE_TOOLS_H
#define BATAILLE_TOOLS_H

#include "Pile.h"
#include "Card.h"
#include "Player.h"

int getDeckSize();
Pile<Card> makeFillDeck(int);
void distributeCards(Pile<Card>*, Player*, Player*, int);
void playTurn(Player*, Player*);

#endif //BATAILLE_TOOLS_H
