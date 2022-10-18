//
// Created by Clement on 14/09/2022.
//

#pragma once

#include "Pile.h"
#include "Card.h"
#include "Player.h"

int getDeckSize();
Pile<Card> makeFillDeck(int);
void distributeCards(Pile<Card>*, Player*, Player*, int);
void playTurn(Player*, Player*);
void playGame(Player*, Player*);
