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
    File(int) throw (std::bad_alloc); //constructeur
    File(const File &); //constructeur copie
    ~File(); //destructeur

    // Modificateurs
    T enfiler(const T&) throw (std::length_error);
    T defiler() throw (std::logic_error);

    // Sélecteurs
    int taille() const;
    bool estVide() const;
    bool estPleine() const;
    const T& premier() const; // tête de la file
    const T& dernier() const; // queue de la file

    // Surcharges d'opérateurs
    const File<T>& operator = (const File<T>&) throw (std::bad_alloc);
    template <typename U>
    friend std::ostream& operator <<(std::ostream& f, const File<U>& q);
private: // Modèle d'implantation

    // Martin trying stuff
    void trierCarton();

    T* tab;
    int tete;
    int queue;
    int tailleMax;
    int cpt;
};


#endif //EXERCICE_2_FILE_H
