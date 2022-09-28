//
// Created by Clement on 19/09/2022.
//

#include "Arbre.h"
#include <iostream>

using namespace std;

// Constructeur
Arbre :: Arbre() {
    root = new Node('-');
    cpt = 0;
}

// Constructeur de copie
Arbre :: Arbre(const Arbre& source) {

}

// Destructeur
Arbre :: ~Arbre() {

}

bool Arbre::estVide() const {
    return root == 0;
}

// Exercice
void Arbre::firstAjouterMot(string s)
{
    ajouterMot(s, root, nullptr);
}

void Arbre::enleverMot(string s) {
    if (chercherMot(s)) {  // On vérifie que le mot existe bien dans l'arbre

    } else {
        cout << "Ce mot n'existe pas" << endl;
    }
}

void Arbre::ajouterMot(string s, Node* cur, Node* prev)
{
    //if (!chercherMot(s)) {
    if (true) {
        Node* previous = prev;
        Node* current = cur;

        char letter = s.at(0);

        // on se déplace vers la droite jusqu'à
        // soit arriver le plus à droite de l'arbre à cet étage
        // soit arriver juste à droite de la lettre avant notre lettre
        while (current != nullptr && current->data < letter) {
            previous = current;
            current = current->right;
        }

        // si on est arrivé tout à droite de l'arbre (current == nullptr)
        // ou si on est juste à droite de la lettre précédente
        // alors on n'a pas à réutiliser une structure existante et on peut juste placer notre mot "tout droit"
        if (current == nullptr || current->data > letter) {
            prepareBrutePlace(s, current, previous);

            // si on est situé sur la lettre en question
        } else if (current->data == letter) {

            // si la taille du mot vaut 1 et qu'on est sur la bonne lettre, alors on a fini le mot
            if (s.size() == 1)
                current->isEndOfWord = true;

                // si le mot continue après, on "descend" d'un étage pour poursuivre l'ajout à l'étage d'en dessous sans la première lettre
            else {

                // si on se situe actuellement sur la fin d'un mot, alors précédent prend la valeur de cette lettre avant de "descendre"
                if (current->isEndOfWord)
                    previous = current;
                current = current->left;
                ajouterMot(s.erase(0,1), current, previous);
            }
        }
    }
}

void Arbre::prepareBrutePlace(string s, Node* cur, Node* prev) {
    Node* newNode = new Node(s.at(0));

    // si on n'est pas sur un pointeur nul, alors il faut assurer la continuité du noeud avant de s'insérer
    if (cur != nullptr) {
        newNode->right = prev->right;
    }

    // si on est sur un pointeur nul et que l'on est juste "en dessous" de précédent, alors on est en train d'ajouter une fin à un mot existant (sauf si prev est la racine)
    if (cur == nullptr && prev->left == cur && prev != root)
        prev->left = newNode;

        // sinon on est en train d'ajouter une "alternative" à la lettre précédente
    else
        prev->right = newNode;

    // si il ne reste plus qu'une lettre dans le mot, alors le nouveau noeud est le dernier et le mot est fini
    if (s.size() == 1)
        newNode->isEndOfWord = true;

        // sinon, on n'a plus qu'à placer le mot "tout droit"
    else
        brutePlaceWord(s.erase(0,1), newNode);
}

void Arbre :: brutePlaceWord(string s, Node* cur) {

    // on place toutes les lettres les unes à la suite des autres
    for (char letter : s) {
        Node* newNode = new Node(letter);
        cur->left = newNode;
        cur = newNode;
    }
    cur->isEndOfWord = true;
}

void Arbre::afficherArbre(const string prefix, Node* n, bool isLeftNode) const{
    //https://stackoverflow.com/questions/36802354/print-binary-tree-in-a-pretty-way-using-c
    if (n != nullptr) {

        cout << prefix;
        cout << (isLeftNode ? "|--" : "L--"); // if left node : |--, L-- otherwise
        cout << n->data << endl;

        afficherArbre( prefix + (isLeftNode ? "|   " : "    "), n->left, true);
        afficherArbre( prefix + (isLeftNode ? "|   " : "    "), n->right, false);
    }
}

ostream &operator<<(ostream & output, const Arbre& a) {
    a.afficherArbre("", a.root, false);
    return output;

}


bool Arbre::chercherMot(const string s) {
    if (s.size() == 0)
        return false;
    else
        return _chercherMot(root, s);
}

bool Arbre::_chercherMot(Node* n, string s) {

    // Si mot vide, on a tout parcouru
    if (n->data == s[0] && s.size() == 1)
        return n->isEndOfWord;

    if (n == nullptr) // Fin de l'arbre et le mot n'a pas été trouvé
        return false;

    if (n->data == s[0]) // Si data = premier caractère, on part à gauche
        return _chercherMot(n->left, s.erase(0,1));

    else // Sinon on cherche une alternative à droite
        return _chercherMot(n->right, s);

}


/*
template <typename E>
void Arbre<E>::enleverMot(string s);


template <typename E>
bool Arbre<E>::chercherMot(string s);*/

// -------------------- NODE -----------------------

/*
const char& Arbre<E>::max()const
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
const E& Arbre<E>::_max(Node* arb)const {
    if (cpt == 0)
        throw std::logic_error("max: l'arbre est vide!\n");
    if (arb->right == 0) {
        return arb->data;
    }
    Node *temp = arb->right;
    while (temp->right != 0)
        temp = temp->right;
}

template<typename E>
const E& Arbre<E>::min()const
{
    if (cpt==0)
        throw std::logic_error("max: l'arbre est vide!\n");
    if (root->left == 0)
    {
        return root->data;
    }
    Node * temp = root->left;
    while (temp->left!=0)
        temp = temp->left;
    return temp->data;
}

template<typename E>
const E& Arbre<E>::_min(Node* arb)const {
    if (cpt == 0)
        throw std::logic_error("max: l'arbre est vide!\n");
    if (arb->left == 0) {
        return arb->data;
    }
    Node *temp = arb->left;
    while (temp->left != 0)
        temp = temp->left;
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
    return 1 + _maximum(_hauteurParcours(arb->left), _hauteurParcours(arb->right));
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
E Arbre<E>:: _successeur(Node* arb, const E& info) const
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
*/
//Getter