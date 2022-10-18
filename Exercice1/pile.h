//
// Created by Clement on 13/09/2022.
//

#pragma once

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
    //S�lecteurs
    bool estVide() const;
    int taille() const;
    //surcharge d'op�rateurs
    Pile<T>& operator = (const Pile<T>& p) noexcept(false);

private: //Mod�le d�implantation
    T* tab;
    int ind_sommet; // indice de l��l�ment au sommet
    int tailleMax;
    static const int MAX_PILE = 100;
};
