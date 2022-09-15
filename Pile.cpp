//
// Created by Clement on 13/09/2022.
//

#include "Pile.h"
#include "Card.h"
#include <iostream>

using namespace std;

//constructeur
template <typename T>
Pile<T> :: Pile(int max) noexcept(false)
{
    tab = new T[max];
    ind_sommet = -1; //valeur dummy pour indiquer que la pile est vide.
    tailleMax = max;
}

//constructeur copie
template <typename T>
Pile<T> :: Pile (const Pile<T>& p)
{
    tab = new T [p. tailleMax];
    tailleMax = p. tailleMax;
    for (int i=0; i< tailleMax;i+=1)
        tab[i]=p.tab[i];
    ind_sommet = p.ind_sommet;
}

//destructeur
template <typename T>
Pile<T>::~Pile ()
{
    delete[] tab;
}

//depiler
template <typename T>
T Pile<T> :: depiler() noexcept(false)
{
    if (!estVide())
    {
        T elem = tab[ind_sommet];
        ind_sommet--;
        return elem;
    }
    else
        throw logic_error("Depiler: la pile est vide!");
}

//estVide
template <typename T>
bool Pile<T> :: estVide () const {
    return (ind_sommet == -1);
}

//empiler
template <typename T>
void Pile<T> :: empiler(const T& e) noexcept(false)
{
    if (ind_sommet+1 < tailleMax)
    {
        ind_sommet += 1; // a += b  a = a+ b
        tab[ind_sommet] = e;
    }
    else
        throw length_error("Empiler:la pile est pleine\n");
}

//surcharge =
template <typename T>
Pile<T>& Pile<T>::operator =(const Pile<T>& p) noexcept(false)
{
    if (tab!=nullptr) delete [ ] tab; //on nettoie l’objet qu’on veu écraser
    tab=new T [p. tailleMax];
    tailleMax =p.tailleMax;
    for (int i=0; i< tailleMax;i+=1)
        tab[i]=p.tab[i];
    ind_sommet = p.ind_sommet;
    return (*this);
//retourner : une référence sur l ’objet courant
}

template<typename T>
int Pile<T>::taille() const {
    return ind_sommet + 1;
}

template class Pile<Card>;