#pragma once

//
// Created by Clement on 05/10/2022.
//

#include <vector>
#include <string>
#include "Node.h"


class Arbre {
private:
    // Les membres données
    Node* root; // Racine de l'arbre
    int taille; // Taille de l'arbre

public:
    //..Les méthodes publiques (i.e. les opérateurs)
    //Constructeurs
    Arbre();
    //Destructeur
    ~Arbre();
    //Les fonctions membres
    bool estVide() const;
    int getTreeSize() const;
    Node* getRoot() const;
    void updateTaille();
    void firstNode(const member&);
    static void addNode(const member&, Node*);
    int getAvgAge(int) const;
    int getSumAge(int, Node*);
    void getSameEyedPeople(const std::string&, Node*);
    void getSameEyedAncestors(const std::string&, const std::string&, Node*);
    void getLineageOfPersonInOrder(const Node*, Node*);
    void getLineageOfPersonPreOrder(const Node*, Node*);
    void getLineageOfPersonPostOrder(const Node*, Node*);
    Node* getPersonNode(const std::string&, Node*);
};
