//
// Created by Clement on 19/09/2022.
//

#include "Arbre.h"
#include <iostream>

using namespace std;

// Constructeur
Arbre :: Arbre() {
    root = new Node();
    gen = 0;
}

// Destructeur
Arbre :: ~Arbre() {

}

bool Arbre::estVide() const {
    return root == 0;
}

int Arbre::getTreeSize() const {
    //return treeSize;
}

void Arbre::listDescendance(string name, string firstName) {
    // get Node of mister name Firstname
    // itere in tree doing parcours in/pre/post order
}

void Arbre::addFamilyMember(string name, string firstName, string bDate, string eye, string parentName, string parentFirstName) {
    // build newNode
}

void Arbre::listSameEyedPeople(string iColor) {
    // parcours tree return eye == this color
}

void Arbre::listSameEyedAncestors(string iColor) {
    // same mais parcours inversé
}

int Arbre::getAvgAge() {
    // parcours whole arbre log people ages
}

Node* Arbre::getNode(string name, string firstName) {
    // parcours arbre until name = name
}
