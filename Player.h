//
// Created by Clement on 13/09/2022.
//

#ifndef BATAILLE_PLAYER_H
#define BATAILLE_PLAYER_H

#include <iostream>
#include <string>
#include "Pile.h"
#include "Card.h"

class Player {
public:
    // Constructeur
    explicit Player(std::string name);

    // Accesseur
    std::string getName() const;

    // Affichage
    void display() const;

private:
    std::string m_name;
    Pile<Card> m_deck, m_gain;
};


#endif //BATAILLE_PLAYER_H
