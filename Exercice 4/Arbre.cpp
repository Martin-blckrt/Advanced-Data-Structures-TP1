//
// Created by Clement on 05/10/2022.
//
#include "Arbre.h"
#include <iostream>

using namespace std;

// Constructeur
Arbre :: Arbre() {
    root = new Node();
    taille = 0;
}

// Destructeur
Arbre :: ~Arbre() = default;

bool Arbre::estVide() const {
    return root == nullptr;
}

int Arbre::getTreeSize() const {
    return taille;
}

Node* Arbre::getRoot() const {
    return root;
}

void Arbre::updateTaille() {
    taille += 1;
}

void Arbre::firstNode(const member& m) {
    root->setFirstName(m.firstName);
    root->setLastName(m.lastName);
    root->setBirthYear(m.birthYear);
    root->setEyeColor(m.eyeColor);
}

void Arbre::addNode(const member& m, Node* curr_node) {
    if (curr_node) { // On evite les segmentation fault

        if (curr_node->getFirstName() + curr_node->getLastName() == m.parent) { // Si on est au bon parent
            Node* new_node = new Node(m.firstName, m.lastName, m.birthYear, m.eyeColor);

            if (m.type == "spouse")
                curr_node->setSpouse(new_node);
            if (m.type == "sibling")
                curr_node->setSibling(new_node);
            if (m.type == "firstchild")
                curr_node->setFirstChild(new_node);
        }
        else { // appels récursifs sur les enfants
            addNode(m, curr_node->getSpouse());
            addNode(m, curr_node->getSibling());
            addNode(m, curr_node->getFirstChild());
        }
    }
}

int Arbre::getAvgAge(int somme) const {
    return somme / taille;
}

int Arbre::getSumAge(int currentYear, Node* curr_node) {
    if (curr_node == nullptr)
        return 0;
    return (currentYear - stoi(curr_node->getBirthYear()) + getSumAge(currentYear, curr_node->getFirstChild()) +
            getSumAge(currentYear, curr_node->getSibling()) + getSumAge(currentYear, curr_node->getSpouse()));
}

void Arbre::getSameEyedPeople(const string& eyeColor, Node* curr_node) {
    if (curr_node->getEyeColor() == eyeColor)
        cout << curr_node->getFirstName() << " " << curr_node->getLastName() << endl;
    if (curr_node->getSpouse() != nullptr)
        getSameEyedPeople(eyeColor, curr_node->getSpouse());
    if (curr_node->getSibling() != nullptr)
        getSameEyedPeople(eyeColor, curr_node->getSibling());
    if (curr_node->getFirstChild() != nullptr)
        getSameEyedPeople(eyeColor, curr_node->getFirstChild());
}

void Arbre::getSameEyedAncestors(const string& eyeColor, const string& username, Node* curr_node) {
    if (curr_node->getEyeColor() == eyeColor)
        cout << curr_node->getFirstName() << " " << curr_node->getLastName() << endl;
    if (curr_node->getFirstName() + curr_node->getLastName() == username)
        return;
    if (curr_node->getSpouse() != nullptr)
        getSameEyedPeople(eyeColor, curr_node->getSpouse());
    if (curr_node->getSibling() != nullptr)
        getSameEyedPeople(eyeColor, curr_node->getSibling());
    if (curr_node->getFirstChild() != nullptr)
        getSameEyedPeople(eyeColor, curr_node->getFirstChild());
}

Node* Arbre::getPersonNode(const string& username, Node* curr_node) {
    if (curr_node->getFirstName() + curr_node->getLastName() == username)
        return curr_node;
    if (curr_node->getSpouse() != nullptr)
        getPersonNode(username, curr_node->getSpouse());
    if (curr_node->getSibling() != nullptr)
        getPersonNode(username, curr_node->getSibling());
    if (curr_node->getFirstChild() != nullptr)
        getPersonNode(username, curr_node->getFirstChild());
    return nullptr;
}

void Arbre::getLineageOfPersonPreOrder(const Node* person_node, Node* curr_node) {
    // Prefixe : racine, puis gauche, puis droite AKA person -> spouse -> first child -> siblings)
    cout << curr_node->getFirstName() + " " + curr_node->getLastName() << endl;

    if (curr_node->getSpouse() != nullptr)
        getLineageOfPersonPreOrder(person_node, curr_node->getSpouse());
    if (curr_node->getFirstChild() != nullptr)
        getLineageOfPersonPreOrder(person_node, curr_node->getFirstChild());
    if (curr_node->getSibling() != nullptr)
        getLineageOfPersonPreOrder(person_node, curr_node->getSibling());
}

void Arbre::getLineageOfPersonInOrder(const Node* person_node, Node* curr_node) {
    // son sous-arbre gauche, puis sa racine, puis son sous-arbre droit

    if (curr_node->getSpouse() != nullptr)
        getLineageOfPersonInOrder(person_node, curr_node->getSpouse());

    cout << curr_node->getFirstName() + " " + curr_node->getLastName() << endl;

    if (curr_node->getSibling() != nullptr)
        getLineageOfPersonInOrder(person_node, curr_node->getSibling());
    if (curr_node->getFirstChild() != nullptr)
        getLineageOfPersonInOrder(person_node, curr_node->getFirstChild());
}

void Arbre::getLineageOfPersonPostOrder(const Node* person_node, Node* curr_node) {
    // son sous-arbre gauche, puis son sous-arbre droit, puis sa racine.

    if (curr_node->getSpouse() != nullptr)
        getLineageOfPersonPostOrder(person_node, curr_node->getSpouse());
    if (curr_node->getSibling() != nullptr)
        getLineageOfPersonPostOrder(person_node, curr_node->getSibling());
    if (curr_node->getFirstChild() != nullptr)
        getLineageOfPersonPostOrder(person_node, curr_node->getFirstChild());

    cout << curr_node->getFirstName() + " " + curr_node->getLastName() << endl;
}

