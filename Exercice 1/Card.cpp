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

bool Card::operator>(Card const& a)
{
    if (m_number != a.getNumber()) // Compare numbers first
        return (m_number > a.getNumber());
    else
        return (m_color > a.getColor()); // Rouge = 1 | Noir = 0
}

bool Card::operator==(Card const& a)
{
    return (m_number == a.m_number && m_color == a.m_color);
}