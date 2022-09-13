//
// Created by Clement on 13/09/2022.
//

#include "Player.h"
#include <iostream>
#include <string>

using namespace std;

Player::Player(string name) : m_name(name)
{
    m_deck(DECK_SIZE/2);
}

string Player::getName() const
{
    return m_name;
}

void Player::addCardToDeck(Card const& card) {
    m_deck.empiler(card);
}

void Player::addWonCard(Card const& card) {
    m_gain.empiler(card);
}

Card Player::playCard() {
    Card c = m_deck.depiler();
    return c;
}

int Player::computePoints() {
    while (!m_gain.estVide())
    {
        Card a = m_gain.depiler();
        totalPoints += a.compute();
    }
    return totalPoints;
}

void Player::display() const
{
    cout << "Hi ! My name is what, my name is who, my name is : " << m_name << endl;
}