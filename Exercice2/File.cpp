//
// Created by marti on 15/09/2022.
//

#include "File.h"
#include "Piece.h"

using namespace std;

// Constructeur
template <typename T>
File<T> ::File(int max) noexcept(false)
{
    tab = new T[max];
    tete = 0;
    queue = 0;
    cpt = 0;
    tailleMax = max;
}

// Destructeur
template <typename T>
File<T>::~File()
{
    delete[] tab;
}

// D�filer
template <typename T>
T File<T> ::defiler() noexcept(false)
{
    if (cpt != 0)
    {
        T elementaDefiler = tab[tete];
        tete = (tete + 1) % tailleMax; //permet de � boucler � si on d�passe
        cpt--;
        return elementaDefiler;
    }
    else
        throw logic_error("Defiler: la file est vide!");
}

// Enfiler
template <typename T>
T File<T> ::enfiler(const T& e) noexcept(false)
{
    if (cpt < tailleMax)
    {
        tab[queue] = e;
        queue = (queue + 1) % tailleMax;
        cpt++;
    }
    else
        throw length_error("Enfiler: la file est pleine!");
}

// estVide
template <typename T>
bool File<T> ::estVide() const {
    return (cpt == 0); // BOF
}

//surcharge =
template <typename T>
const File<T>& File<T>::operator =(const File<T>& f) noexcept(false)
{
    if (tab != nullptr) delete[] tab; //on nettoie l�objet qu�on veu �craser
    tab = new T[f.tailleMax];
    tailleMax = f.tailleMax;
    for (int i = 0; i < tailleMax; i += 1)
        tab[i] = f.tab[i];

    return (*this);
    //retourner : une r�f�rence sur l �objet courant
}

template class File<Piece>;