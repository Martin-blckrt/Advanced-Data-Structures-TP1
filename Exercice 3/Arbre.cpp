//
// Created by Clement on 19/09/2022.
//

#include "Arbre.h"
#include <iostream>

template<typename E>
const E& Arbre<E>::max()const throw (std::logic_error)
{
    if (cpt==0)
        throw std::logic_error("max: l'arbre est vide!\n");
    if (racine->droite == 0)
    {
        return racine->data;
    }
    Noeud * temp = racine->droite;
    while (temp->droite!=0)
        temp = temp->droite;
    return temp->data;
}

template<typename E>
int Arbre<E>:: nbNoeuds() const
{
    return _nbNoeuds(racine);
}
template<typename E>
int Arbre<E>:: _nbNoeuds(Noeud* arb) const
{
    if (arb==0)
        return 0;
    return _nbNoeuds(arb->gauche) + _nbNoeuds(arb->droite) + 1;
}

template<typename E>
int Arbre<E>::nbFeuilles() const
{
    return _nbFeuilles(racine);
}
template<typename E>
int Arbre<E>::_nbFeuilles(Noeud*arb) const
{
    int nbG (0), nbD(0);
    if (arb != 0)
    {
        if (arb->gauche == 0 && arb->droite == 0)
            return 1;
        else
        {
            if (arb->gauche != 0)
                nbG = _nbFeuilles(arb->gauche);
            if (arb->droite != 0)
                nbD = _nbFeuilles(arb->droite);
        }
    }
    return nbG + nbD;
}

template<typename E>
int Arbre<E>::hauteur() const throw (std::logic_error)
{
    if (cpt==0)
        throw std::logic_error("hauteur: l'arbre est vide!\n");
    return _hauteurParcours(racine);
}
template<typename E>
int Arbre<E>::_hauteurParcours(Noeud * arb) const
{
    if (arb==0)
        return -1;
    return 1 + _maximum(_hauteur(arb->gauche), _hauteur(arb->droite));
}

template<typename E>
bool Arbre<E>:: appartient(const E &data) const
{
    return _auxAppartient(racine, data)!=0;
}
template<typename E>
typename Arbre<E>:: Noeud* Arbre<E>:: _auxAppartient(Noeud*
arbre, const E &data) const
{
    if (arbre == 0)
        return 0;
    if ( arbre->data == data )
        return arbre;
    if ( arbre->data > data )
        return _auxAppartient(arbre->gauche, data);
    else
        return _auxAppartient(arbre->droite, data);
}

template <typename E>
const E& Arbre<E>:: parent(const E& el) const throw(std::logic_error)
{
    Noeud* noeudDeEl = _auxAppartient(racine, el);
    Noeud* parentDeEl = _parent(racine, noeudDeEl);
    return parentDeEl->data;
}

template <typename E>
typename Arbre<E>:: Noeud* Arbre<E>:: _parent(Noeud* arb, Noeud* sArb) const
throw(std::logic_error)
{
    if (arb == 0)
        throw std::logic_error("parent: l'arbre est vide!\n");
    if (sArb == 0)
        throw std::logic_error("parent: l'element n'existe pas!\n");
    if (sArb == arb)
        throw std::logic_error("parent: Le parent de la racine d'existe pas!\n");
    if ( sArb->data < arb-> data )
    {
        if (arb->gauche == sArb) return arb;
        else return _parent(arb->gauche, sArb);
    }
    else
    {
        if (arb->droite == sArb) return arb;
        else return _parent(arb->droite, sArb);
    }
}

template <typename E>
E Arbre<E>:: successeur(const E& info) const throw(std::logic_error)
{
    return _successeur(racine, info);
}
template <typename E>
E Arbre<E>:: _successeur(Noeud* arb, const E& info) throw (std::logic_error)
{
    if (cpt == 0)
        throw std::logic_error("successeur: l'arbre est vide!\n");
    Noeud* sArb = _auxAppartient(racine, info);
    if (sArb == 0)
        throw std::logic_error("successeur: l'element n'existe pas!\n");
    if ( info == _max(arb))
        throw std::logic_error("successeur: l'element est le max dans l'arbre!\n");
    if (sArb->droite != 0)
        return _min(sArb->droite);
    else
    {
        Noeud * pere = _parent(arb, sArb);
        while (pere->data < sArb->data ) pere = _parent(arb,pere);
        return pere->data;
    }
}
