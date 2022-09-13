//
// Created by Clement on 13/09/2022.
//

#ifndef BATAILLE_CARD_H
#define BATAILLE_CARD_H

#include <iostream>
#include <string>

class Card {
public:
    // Constructeur
    Card();

    // Accesseur
    int getNumber() const;
    bool getColor() const;
    int getBonus() const;

    // Affichage
    void display(std::ostream&) const;
    friend std::ostream& operator<<(std::ostream&, Card const&);

private:
    int m_number;
    bool m_color;
    int m_bonus;
};


#endif //BATAILLE_CARD_H
