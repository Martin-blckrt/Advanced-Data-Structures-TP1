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
    ind_taille = 0;
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
    if (!estVide()) return tab[ind_sommet--];
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

//resize
template <typename T>
void Pile<T>::resize(const Pile<T>& p) noexcept(false)
{
    int nouvelleTaille = ind_sommet++ * 2;
    tab = new T [nouvelleTaille ];
    for (int i=0; i< ind_sommet;i++)
        tab[i] = p.tab[i];
    tailleMax=nouvelleTaille;
}

//surcharge =
template <typename T>
const Pile<T>& Pile<T>::operator =(const Pile<T>& p) noexcept(false)
{
    if (tab!=0) delete [ ] tab; //on nettoie l’objet qu’on veux écraser
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
    return tailleMax;
}

template<typename T>
void Pile<T>::fillDeck() {
    for (int i = 0; i < tailleMax; i++)
    {
        Card card;
        empiler(card);
    }
}

template class Pile<Card>;

/*
template <typename U>
ostream& operator<<(ostream& flux, Pile<U> const& p)
{
    p.display(flux);
    return flux;
}

template<> void Pile<int>::display(ostream &flux) const
{
    flux << "oh " << tailleMax << " cartes" << endl;
}
*/