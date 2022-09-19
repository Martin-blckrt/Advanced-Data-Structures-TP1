//
// Created by Clement on 15/09/2022.
//

#ifndef EXERCICE_2_FILE_H
#define EXERCICE_2_FILE_H

#include <iostream>

template<typename T>
class File {

public:
    // constructeurs et destructeurs:
    File(int) noexcept(false); //constructeur
    //File(const File &); //constructeur copie
    ~File(); //destructeur

    // Modificateurs
    T enfiler(const T&) noexcept(false);
    T defiler() noexcept(false);

    // Sélecteurs
    //int taille() const;
    bool estVide() const;
    //bool estPleine() const;
    //const T& premier() const; // tête de la file
    //const T& dernier() const; // queue de la file

    // Surcharges d'opérateurs
    const File<T>& operator = (const File<T>&) noexcept(false);
private: // Modèle d'implantation

    T* tab;
    int tete;
    int queue;
    int tailleMax;
    int cpt;
};


#endif //EXERCICE_2_FILE_H
