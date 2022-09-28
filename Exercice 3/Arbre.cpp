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
    if (!chercherMot(s)) {
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
    else
        cout << "Le mot " << s << " est deja dans le dictionnaire !" << endl;
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
    else if (s.find('*') != string::npos)
        return chercherMots(root, s);
    else
        return _chercherMot(root, s);
}

bool Arbre::_chercherMot(Node* n, string s) {

    if (n == nullptr) // Fin de l'arbre
        return false;
    // Si mot vide, on a tout parcouru
    if (n->data == s[0] && s.size() == 1)
        return n->isEndOfWord;

    if (n->data == s[0]) // Si data = premier caractère, on part à gauche
        return _chercherMot(n->left, s.erase(0,1));

    else // Sinon on cherche une alternative à droite
        return _chercherMot(n->right, s);

}

bool Arbre::chercherMots(Node* n, string s) {

    vector<Node*> path;
    vector<Node*> visited;

    // si le mot est etoile, retourner tous les mots du dico
    if (s.at(0) == '*') {
        path.push_back(n);
        findAfterStar(n, path, visited);

    // sinon recuperer ce qu'il y a avant l'etoile
    // puis retourner tous les mots possibles apres l'etoile
    } else {
        if (findUntilStar(n, s, path)) {
            findAfterStar(path.back()->left, path, visited);
        } else
            cout << "This word isn't in our dictionary !" << endl;
    }
    return true;
}

bool Arbre::findUntilStar(Node* n, string s, vector<Node*> &path) {

    // tant qu'on est pas à l'étoile on remplit le path avec le mot
    while (s.at(0) != '*') {
        if (n == nullptr) // Fin de l'arbre
            return false;
        // Si mot vide, on a tout parcouru
        if (n->data == s[0] && s.size() == 1)
            return n->isEndOfWord;

        // Si data = premier caractère, on part à gauche
        if (n->data == s[0]) {
            path.push_back(n);
            return findUntilStar(n->left, s.erase(0,1), path);
        }

        else // Sinon on cherche une alternative à droite
            return findUntilStar(n->right, s, path);
    }
    return true;
}

void Arbre::findAfterStar(Node* n, vector<Node*> &path, vector<Node*> &visited) {

    // tant qu'on n'a pas exploré toutes les possibilités
    if (!path.empty()) {

        // si on est à la fin d'un mot qu'on n'a pas affiche, on l'affiche
        if (n->isEndOfWord && isNodeUnvisited(n, visited)) {
            path.push_back(n);
            printWord(path);
            path.pop_back();
        }

        // si c'est la premiere fois qu'on passe par ici, on le marque
        if (isNodeUnvisited(n, visited))
            visited.push_back(n);

        // si on ne peut plus aller à gauche, alors on passe à la droite
        if (n->left != nullptr && isNodeUnvisited(n->left, visited)) {
            path.push_back(n);
            n = n->left;
            findAfterStar(n, path, visited);

        // si on ne peut plus aller a droite, alors on rebrousse chemin
        } else if (n->right != nullptr && isNodeUnvisited(n->right, visited)) {
            n = n->right;
            findAfterStar(n,  path, visited);
        } else {
            n = path.back();
            path.pop_back();
            findAfterStar(n,  path, visited);
        }
    }
}

bool Arbre::isNodeUnvisited(Node* node, vector<Node*> &visited) {

    //renvoie faux si node est dans le vector visited
    for (auto elem: visited)
        if (elem == node)
            return false;

    return true;
}

void Arbre::printWord(vector<Node*> path) {
    string word;
    for (auto node : path) {
        word.push_back(node->data);
    }

    // dans le cas ou le mot etait etoile, il faut enlever la racine de l'arbre
    if (word.at(0) == '-')
        word.erase(0,1);
    cout << word << endl;
}
