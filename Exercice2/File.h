#pragma once

//
// Created by Clement on 15/09/2022.
//

#include <iostream>

template<typename T>
class File {

public:
    // constructeurs et destructeurs:
    File(int) noexcept(false); //constructeur
    ~File(); //destructeur

    // Modificateurs
    T enfiler(const T&) noexcept(false);
    T defiler() noexcept(false);

    // Sélecteurs
    bool estVide() const;

    // Surcharges d'opérateurs
    const File<T>& operator = (const File<T>&) noexcept(false);
private: // Modèle d'implantation

    T* tab;
    int tete;
    int queue;
    int tailleMax;
    int cpt;
};
