//
// Created by Clement on 13/09/2022.
//

#ifndef BATAILLE_PILE_H
#define BATAILLE_PILE_H

#include <iostream>

template <typename T>
class Pile
{
public:
    // constructeurs et destructeurs
    explicit Pile(int max = MAX_PILE)  noexcept(false); //constructeur
    Pile(const Pile&); //constructeur copie
    ~Pile(); //destructeur
    // Modificateurs
    void empiler(const T&) noexcept(false);
    T depiler() noexcept(false);
    //Sélecteurs
    bool estVide() const;
    int taille() const;
    //const T& sommet() const; // consulte l’élément au sommet
    //surcharge d'opérateurs
    Pile<T>& operator = (const Pile<T>& p) noexcept(false);

private: //Modèle d’implantation
    T* tab;
    int ind_sommet; // indice de l’élément au sommet
    int tailleMax;
    static const int MAX_PILE = 100;
};


#endif //BATAILLE_PILE_H
