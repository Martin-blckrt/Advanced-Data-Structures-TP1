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
    Pile(int max = MAX_PILE)  noexcept(false); //constructeur
    Pile(const Pile&); //constructeur copie
    ~Pile(); //destructeur
// Modificateurs
    void empiler(const T&) noexcept(false);
    T depiler() noexcept(false);
    void resize(const Pile<T>& p) noexcept(false);
//Sélecteurs
    bool estVide() const;
    int taille() const;
    const T& sommet() const; // consulte l’élément au sommet
//surcharge d'opérateurs
    const Pile<T>& operator = (const Pile<T>& p) noexcept(false);
/*
    friend std::ostream& operator<<(std::ostream&, Pile const&);


    void display(std::ostream &flux) const;
*/
    void fillDeck(Pile<T>& p);

    void fillDeck();

private: //Modèle d’implantation
    T* tab;
    int ind_sommet; // indice de l’élément au sommet
    int ind_taille;
    int tailleMax;
    static const int MAX_PILE = 100;
};


#endif //BATAILLE_PILE_H
