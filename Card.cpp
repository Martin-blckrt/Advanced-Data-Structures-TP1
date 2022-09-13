//
// Created by Clement on 13/09/2022.
//

#include "Card.h"
#include <iostream>
#include <string>

using namespace std;

Card::Card()
{
    m_number = rand() % 10 + 1; // NOLINT(cert-msc30-c, cert-msc50-cpp)
    m_color = rand() % 2; // NOLINT(cert-msc30-c, cert-msc50-cpp)
    m_bonus = rand() % 4 + 1; // NOLINT(cert-msc30-c, cert-msc50-cpp)
}

bool Card::isEqual(Card const& b) const
{
    return (m_number == b.m_number && m_color == b.m_color);
}

double Card::getValue() const
{
    if (m_color)
    {
        return m_number * 1.5 * m_bonus;
    }
    else
    {
        return m_number * 1 * m_bonus;

    }
}
bool operator==(Card const& a, Card const& b)
{
    return a.isEqual(b);
}

int Card::getNumber() const
{
    return m_number;
}

bool Card::getColor() const
{
    return m_color;
}

int Card::getBonus() const
{
    return m_bonus;
}

ostream& operator<<(ostream& flux, Card const& c)
{
    c.display(flux);
    return flux;
}

void Card::display(ostream &flux) const
{
    cout << "Number : " << m_number << endl;
    if (m_color)
        cout << "Color : Red" << endl;
    else
        cout << "Color : Black" << endl;
    cout << "Bonus : " << m_bonus << endl;
    cout << "________________________________________________" << endl;
}

bool operator>(Card const &a, Card const& b)
{
    // Compare numbers first
    if (a.getNumber() > b.getNumber())
    {
        return true;
    }
    if (a.getNumber() < b.getNumber())
    {
        return false;
    }
    // If equal numbers compare color
    else
    {
        // Rouge = 1 | Noir = 0
        return (a.getColor() > b.getColor());
    }
}