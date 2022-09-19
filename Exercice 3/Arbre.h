//
// Created by Clement on 19/09/2022.
//

#ifndef EXERCICE_3_ARBRE_H
#define EXERCICE_3_ARBRE_H

#include <vector>

template <typename E>
class Arbre
{
public:
    //..Les méthodes publiques (i.e. les opérateurs)
    //Constructeurs
    Arbre();
    Arbre(const Arbre& source) ;
    //Destructeur
    ~Arbre();
    //Les fonctions membres
    bool estVide() const;
    long taille() const;
    const E & max() const;
    const E & min() const ;
    int nbNoeuds()const;
    int nbFeuilles()const;
    int hauteur() const;
    bool appartient(const E &) const;
    const E& parent(const E&) const;
    E successeur(const E& ) const;
    void lister(std::vector<E>&) const;
private:
// classe Noeud
    class Noeud
    { public:
        E data;
        Noeud *gauche;
        Noeud *droite;
        int card;
        int hauteur;
        Noeud( const E&d ): gauche(0),data( d ),droite(0),hauteur(0) { }
    };
// Les membres données
    Noeud * racine; //racine de l'arbre
    int cpt; // Nombre de noeuds dans l'arbre
// Les membres méthodes privés
//...
};


#endif //EXERCICE_3_ARBRE_H
