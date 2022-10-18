//
// Created by Clement on 05/10/2022.
//

#include "Node.h"
#include <string>
#include <utility>

using namespace std;

string Node::getFirstName() {
    return firstName;
}

string Node::getLastName() {
    return lastName;
}

string Node::getBirthYear() {
    return birthYear;
}

string Node::getEyeColor() {
    return eyeColor;
}

Node* Node::getFirstChild() {
    return firstChild;
}

Node* Node::getSibling() {
    return sibling;
}

Node* Node::getSpouse() {
    return spouse;
}

void Node::setFirstName(string _fname) {
    firstName = std::move(_fname);
}

void Node::setLastName(string _name) {
    lastName = std::move(_name);
}

void Node::setBirthYear(string _byear) {
    birthYear = std::move(_byear);
}

void Node::setEyeColor(string _iColor) {
    eyeColor = std::move(_iColor);
}

void Node::setFirstChild(Node* node) {
    firstChild = node;
}
void Node::setSibling(Node* node) {
    sibling = node;
}
void Node::setSpouse(Node* node) {
    spouse = node;
}