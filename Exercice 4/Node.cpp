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

string Node::getName() {
    return name;
}

string Node::getBirthDate() {
    return birthDate;
}

string Node::getEyeColor() {
    return eyeColor;
}

Node* Node::getFirstChild(Node * node) {
    return node->firstChild;
}

Node* Node::getSibling(Node * node) {
    return node->sibling;
}

Node* Node::getSpouse(Node * node) {
    return node->spouse;
}

void Node::setFirstName(string _fname) {
    firstName = std::move(_fname);
}

void Node::setName(string _name) {
    name = std::move(_name);
}

void Node::setBirthDate(string _bdate) {
    birthDate = std::move(_bdate);
}

void Node::setEyeColor(string _iColor) {
    eyeColor = std::move(_iColor);
}

void Node::setFirstChild(Node* curr, Node* child) {
    curr->firstChild = child;
}
void Node::setSibling(Node* curr, Node* sib) {
    curr->sibling = sib;
}
void Node::setSpouse(Node* curr, Node* spou) {
    curr->spouse = spou;
}