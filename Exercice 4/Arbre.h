//
// Created by Clement on 19/09/2022.
//

#ifndef EXERCICE_3_ARBRE_H
#define EXERCICE_3_ARBRE_H

#include <vector>
#include <string>
#include "Node.h"

class Arbre
{
private:
// Les membres données
    Node* root; //racine de l'arbre
    int gen; // numero de la generation (= taille arbre)
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
    void listDescendance(std::string, std::string); // in order, pre-order, post-order
    void addFamilyMember(std::string, std::string, std::string, std::string, std::string, std::string);
    void listSameEyedPeople(std::string);
    void listSameEyedAncestors(std::string);
    int getAvgAge();
    Node* getNode(std::string, std::string);

    friend std::ostream& operator<<(std::ostream&, const Arbre&);
};


#endif //EXERCICE_3_ARBRE_H
