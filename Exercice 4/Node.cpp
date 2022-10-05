//
// Created by Clement on 05/10/2022.
//

#include "Node.h"
#include <string>

using namespace std;

string Node::getFirstName() {
    return firstName;
}

string Node::getName() {
    return name;
}

string Node::getBirthDate() {
    return birthDate;
}

string Node::getEyeColor() {
    return eyeColor;
}

Node* Node::getParent1(Node* node) {
    return node->parent1;
}

Node* Node::getParent2(Node* node) {
    return node->parent2;
}

void Node::setFirstName(string _fname) {
    firstName = _fname;
}

void Node::setName(string _name) {
    name = _name;
}

void Node::setBirthDate(string _bdate) {
    birthDate = _bdate;
}

void Node::setEyeColor(string _iColor) {
    eyeColor = _iColor;
}

void Node::setParent1(Node * childNode, Node * parentNode) {
    childNode->parent1 = parentNode;
}

void Node::setParent2(Node * childNode, Node * parentNode) {
    childNode->parent2 = parentNode;
}