//
// Created by Clement on 05/10/2022.
//

#ifndef EXERCICE_4_ARBRE_H
#define EXERCICE_4_ARBRE_H

#include <vector>
#include <string>
#include "Node.h"



class Arbre {
private:
// Les membres données
    Node* root; // Racine de l'arbre
    int taille; // Taille de l'arbre
// Les membres méthodes privés
//...

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
    void getPeopleWithEyeColor(std::string, Node*);


        //void listDescendance(std::string, std::string); // in order, pre-order, post-order
    //void listSameEyedPeople(std::string);
    //void listSameEyedAncestors(std::string);

    //Node* getNode(std::string, std::string);

    //friend std::ostream& operator<<(std::ostream&, const Arbre&);
};


#endif //EXERCICE_4_ARBRE_H
