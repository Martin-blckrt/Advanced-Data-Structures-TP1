//
// Created by Clement on 13/09/2022.
//

#pragma once

#include <iostream>
#include <string>
#include "Pile.h"
#include "Card.h"

class Player {
public:
    // Constructeur
    explicit Player(std::string name, int);

    // Accesseur
    std::string getName() const;

    // Affichage
    void display() const;

    // Remplisseur de deck
    void addCardToDeck(Card const&);

    // Ajout de cartes gagn?es
    void addWonCard(Card const&);

    // Jouer une carte
    Card playCard();

    // Compter les points
    double computePoints();

    // Le deck est vide
    bool isDeckEmpty();

    // op?rateurs surcharg?s
    bool operator==(Player const&) const;
    bool operator>(Player const&) const;

private:
    std::string m_name;
    double totalPoints;
    Pile<Card> m_deck, m_gain;
};
