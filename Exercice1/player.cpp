//
// Created by Clement on 13/09/2022.
//

#include "Player.h"
#include <iostream>
#include <string>
#include <utility>
#include "Pile.h"

using namespace std;

Player::Player(string name, int playerDeckSize)
{
    m_name = std::move(name);
    m_gain = Pile<Card>();
    m_deck = Pile<Card>(playerDeckSize);
    totalPoints = 0;
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

double Player::computePoints() {
    while (!m_gain.estVide())
    {
        Card a = m_gain.depiler();
        totalPoints += a.getValue();
    }
    cout << m_name << " has " << totalPoints << " points." << endl;
    return totalPoints;
}

void Player::display() const
{
    cout << "Hi ! My name is what, my name is who, my name is : " << m_name << endl;
}

bool Player::isDeckEmpty()
{
    return m_deck.estVide();
}

bool Player::operator>(Player const& p2) const
{
    return totalPoints > p2.totalPoints;
}

bool Player::operator==(Player const& p2) const
{
    return totalPoints == p2.totalPoints;
}