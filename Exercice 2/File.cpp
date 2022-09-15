//
// Created by marti on 15/09/2022.
//

#include "File.h"
using namespace std;

// Constructeur
template <typename T>
File<T> :: File (int max) throw (bad_alloc)
{
    tab = new T [max];
    tete = 0;
    queue = 0;
    cpt = 0;
    tailleMax = max;
}

// Destructeur
template <typename T>
File<T>::~File ()
{
    delete[] tab;
}

// Défiler
template <typename T>
T File<T> :: defiler() throw (logic_error)
{
    if (cpt!=0)
    {
        T elementaDefiler = tab[tete];
        tete = (tete+1)% tailleMax; //permet de « boucler » si on dépasse
        cpt--;
        return elementaDefiler;
    }
    else
        throw logic_error("Defiler: la file est vide!");
}

// Enfiler
template <typename T>
T File<T> :: enfiler(const T& e) throw (length_error)
{
    if(cpt<tailleMax)
    {
        tab[queue]= e;
        queue = (queue+1)%tailleMax;
        cpt++;
    }
    else
        throw length_error("Enfiler: la file est pleine!");
}

// estVide
template <typename T>
bool File<T> :: estVide () const {
    return (tete == 0); // BOF
}

// estPleine
template <typename T>
bool File<T> :: estPleine () const {
    return (queue == tailleMax); // BOF
}

// taille
template<typename T>
int File<T>::taille() const {
    return queue; // BOF
}

//surcharge =
template <typename T>
const File<T>& File<T>::operator =(const File<T>& p) throw (bad_alloc)
{
    if (tab!=nullptr) delete [ ] tab; //on nettoie l’objet qu’on veu écraser
    tab=new T [p. tailleMax];
    tailleMax =p.tailleMax;
    for (int i=0; i< tailleMax;i+=1)
        tab[i]=p.tab[i];
    //ind_sommet = p.ind_sommet;
    return (*this);
//retourner : une référence sur l ’objet courant
}
