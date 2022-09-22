//
// Created by Clement on 19/09/2022.
//

#include "Arbre.h"
#include <iostream>

// Constructeur
template<typename E>
Arbre<E> :: Arbre() {

}

// Constructeur de copie
template<typename E>
Arbre<E> :: Arbre(const Arbre& source) {

}

// Destructeur
template<typename E>
Arbre<E> :: ~Arbre() {

}

template<typename E>
bool Arbre<E>::estVide() const {
    return root == 0;
}

template<typename E>
const E& Arbre<E>::max()const
{
    if (cpt==0)
        throw std::logic_error("max: l'arbre est vide!\n");
    if (root->right == 0)
    {
        return root->data;
    }
    Node * temp = root->right;
    while (temp->right!=0)
        temp = temp->right;
    return temp->data;
}

template<typename E>
const E& Arbre<E>::min()const
{

}

template<typename E>
int Arbre<E>:: nbNoeuds() const
{
    return _nbNoeuds(root);
}
template<typename E>
int Arbre<E>:: _nbNoeuds(Node* arb) const
{
    if (arb==0)
        return 0;
    return _nbNoeuds(arb->left) + _nbNoeuds(arb->right) + 1;
}

template<typename E>
int Arbre<E>::nbFeuilles() const
{
    return _nbFeuilles(root);
}
template<typename E>
int Arbre<E>::_nbFeuilles(Node*arb) const
{
    int nbG (0), nbD(0);
    if (arb != 0)
    {
        if (arb->left == 0 && arb->right == 0)
            return 1;
        else
        {
            if (arb->left != 0)
                nbG = _nbFeuilles(arb->left);
            if (arb->right != 0)
                nbD = _nbFeuilles(arb->right);
        }
    }
    return nbG + nbD;
}

template<typename E>
int Arbre<E>::hauteur() const
{
    if (cpt==0)
        throw std::logic_error("hauteur: l'arbre est vide!\n");
    return _hauteurParcours(root);
}
template<typename E>
int Arbre<E>::_hauteurParcours(Node * arb) const
{
    if (arb==0)
        return -1;
    return 1 + _maximum(_hauteur(arb->left), _hauteur(arb->right));
}

template<typename E>
bool Arbre<E>:: appartient(const E &data) const
{
    return _auxAppartient(root, data)!=0;
}
template<typename E>
typename Arbre<E>:: Node* Arbre<E>:: _auxAppartient(Node*
arbre, const E &data) const
{
    if (arbre == 0)
        return 0;
    if ( arbre->data == data )
        return arbre;
    if ( arbre->data > data )
        return _auxAppartient(arbre->left, data);
    else
        return _auxAppartient(arbre->right, data);
}

template <typename E>
const E& Arbre<E>:: parent(const E& el) const
{
    Node* noeudDeEl = _auxAppartient(root, el);
    Node* parentDeEl = _parent(root, noeudDeEl);
    return parentDeEl->data;
}

template <typename E>
typename Arbre<E>:: Node* Arbre<E>:: _parent(Node* arb, Node* sArb) const
{
    if (arb == 0)
        throw std::logic_error("parent: l'arbre est vide!\n");
    if (sArb == 0)
        throw std::logic_error("parent: l'element n'existe pas!\n");
    if (sArb == arb)
        throw std::logic_error("parent: Le parent de la racine d'existe pas!\n");
    if ( sArb->data < arb-> data )
    {
        if (arb->left == sArb) return arb;
        else return _parent(arb->left, sArb);
    }
    else
    {
        if (arb->right == sArb) return arb;
        else return _parent(arb->right, sArb);
    }
}

template <typename E>
E Arbre<E>:: successeur(const E& info) const
{
    return _successeur(root, info);
}
template <typename E>
E Arbre<E>:: _successeur(Node* arb, const E& info)
{
    if (cpt == 0)
        throw std::logic_error("successeur: l'arbre est vide!\n");
    Node* sArb = _auxAppartient(root, info);
    if (sArb == 0)
        throw std::logic_error("successeur: l'element n'existe pas!\n");
    if ( info == _max(arb))
        throw std::logic_error("successeur: l'element est le max dans l'arbre!\n");
    if (sArb->right != 0)
        return _min(sArb->right);
    else
    {
        Node * pere = _parent(arb, sArb);
        while (pere->data < sArb->data ) pere = _parent(arb,pere);
        return pere->data;
    }
}


// -------------------- NODE -----------------------

