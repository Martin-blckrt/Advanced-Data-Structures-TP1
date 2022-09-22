//
// Created by Clement on 19/09/2022.
//

#ifndef EXERCICE_3_ARBRE_H
#define EXERCICE_3_ARBRE_H

#include <vector>

template <typename E>
class Arbre
{
private:
// classe Node
    class Node
    {
    public:
        E data;
        Node *left;
        Node *right;
        int card;
        int height;
        Node( const E&d ): left(0),data( d ),right(0),height(0) { }
    };
// Les membres données
    Node * root; //racine de l'arbre
    int cpt; // Nombre de noeuds dans l'arbre
// Les membres méthodes privés
//...

public:
    //..Les méthodes publiques (i.e. les opérateurs)
    //Constructeurs
    Arbre();
    Arbre(const Arbre&) ;
    //Destructeur
    ~Arbre();
    //Les fonctions membres
    bool estVide() const;
    long taille() const;

    const E& max() const;
    const E& min() const ;

    int nbNoeuds()const;
    int _nbNoeuds(Node*) const;

    int nbFeuilles()const;
    int _nbFeuilles(Node*) const;

    int hauteur() const;
    int _hauteurParcours(Node*) const;

    bool appartient(const E &) const;
    Node* _auxAppartient(Node*, const E&) const;

    const E& parent(const E&) const;
    Node* _parent(Node*, Node*) const;

    E successeur(const E& ) const;
    E _successeur(Node*, const E&);

};


#endif //EXERCICE_3_ARBRE_H
