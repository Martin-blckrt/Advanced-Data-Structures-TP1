//
// Created by Clement on 13/09/2022.
//

#pragma once

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
    double getValue() const;

    // Affichage
    void display(std::ostream&) const;
    friend std::ostream& operator<<(std::ostream&, Card const&);

    bool operator==(Card const&);
    bool operator>(Card const&);

private:
    int m_number;
    bool m_color;
    int m_bonus;
};
