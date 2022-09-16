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
    explicit Player(std::string name, int);

    // Constructeur de copie
    Player(std::string name, int);

    // Accesseur
    std::string getName() const;

    // Affichage
    void display() const;

    // Remplisseur de deck
    void addCardToDeck(Card const&);

    // Ajout de cartes gagnées
    void addWonCard (Card const&);

    // Jouer une carte
    Card playCard();

    // Compter les points
    double computePoints();

    // Le deck est vide
    bool isDeckEmpty();

    // Reset le joueur
    Player* resetPlayer();

    // opérateurs surchargés
    bool operator==(Player const&);
    bool operator>(Player const&);

private:
    std::string m_name;
    double totalPoints;
    Pile<Card> m_deck, m_gain;
};


#endif //BATAILLE_PLAYER_H
