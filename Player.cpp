//
// Created by Clement on 13/09/2022.
//

#include "Player.h"
#include <iostream>
#include <string>

using namespace std;

Player::Player(string name) : m_name(name)
{

}

string Player::getName() const
{
    return m_name;
}

void Player::display() const
{
    cout << "Hi ! My name is what, my name is who, my name is : " << m_name << endl;
}