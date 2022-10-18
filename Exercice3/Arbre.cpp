//
// Created by Clement on 19/09/2022.
//

#include "Arbre.h"
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

// Constructeur
Arbre::Arbre() {
    root = new Node('-');
    cpt = 0;
}

// Destructeur
Arbre :: ~Arbre() = default;

int Arbre::getCompteur() const {
    return cpt;
}

// Exercice
void Arbre::enleverMot(const string& s) {
    if (chercherMot(s)) {
        if (cpt > 1) {
            _enleverMot(root->right, s);
        }
        else {
            Node* currNode = root->right;
            Node* tempNode;

            while (currNode->left != nullptr) {
                tempNode = currNode->left;
                currNode->left = nullptr;
                currNode = tempNode;
            }
            root->right = nullptr;
        }

        cout << s << " a ete supprime du dictionnaire." << endl;
        cpt -= 1;
    }
    else
        cout << "Ce mot n'existe pas" << endl;
}

void Arbre::_enleverMot(Node* start, string s) {

    Node* currentNode = start;
    Node* previousNode = nullptr;
    Node* nextNode = nullptr;

    int indLastRightChild = -1; // Indice dans le parcours de l'abrbre indiquant le dernier noeud avec un right child
    int indLastEndOfWord = -1;  // Indice dans le parcours de l'abrbre indiquant le dernier noeud indiquant la fin d'un mot
    int compteur = 0;

    // Premier parcours pour r�cup�rer le dernier noeud non supprimable
    for (int i = 0; i < s.size(); i++) {

        while (currentNode->data != s[i]) {
            currentNode = currentNode->right;
            compteur += 1;
        }

        if (currentNode->isEndOfWord) {
            if (i != s.size() - 1) {
                indLastEndOfWord = compteur;
            }
            else {
                if (currentNode->left)
                    indLastEndOfWord = compteur;
            }
        }

        if (currentNode->right)
            indLastRightChild = compteur;

        compteur += 1;
        currentNode = currentNode->left;

        if (currentNode) {
            if (currentNode->right)
                indLastRightChild = compteur;
        }

    }

    if (indLastRightChild == -1 && indLastEndOfWord == -1)
        indLastRightChild = 0;

    currentNode = start;
    // On r�cup�re l'indice du dernier noeud non supprimable
    int stop = max(indLastRightChild, indLastEndOfWord);
    compteur = 0;

    for (char i : s) {
        while (currentNode->data != i) {
            if (compteur != stop) {
                previousNode = currentNode;
                currentNode = currentNode->right;
                compteur += 1;
            }
            else {
                break;
            }
        }

        if (compteur == stop) {

            if (stop == indLastRightChild) {
                if (currentNode->right->data != i) {
                    if (compteur == 0) {
                        root->right = currentNode->right;
                    }
                    else {
                        if (previousNode->left == currentNode) {
                            previousNode->left = currentNode->right;
                        }
                        else {
                            previousNode->right = currentNode->right;
                        }
                    }

                }
                else {
                    previousNode = currentNode;
                    currentNode = currentNode->right;
                    previousNode->right = nullptr;
                }
            }
            else {
                if (i == s.back()) {
                    currentNode->isEndOfWord = false;
                    break;
                }
            }


            while (currentNode->left != nullptr) {
                nextNode = currentNode->left;
                currentNode->left = nullptr;
                currentNode = nextNode;
            }
            break;
        }
        previousNode = currentNode;
        currentNode = currentNode->left;
        compteur += 1;
    }
}

void Arbre::firstAjouterMot(string s)
{
    ajouterMot(std::move(s), root, nullptr);

}

void Arbre::ajouterMot(string s, Node* cur, Node* prev)
{
    if (!chercherMot(s)) {
        Node* previous = prev;
        Node* current = cur;

        if (s == "de")
            cout << "here";

        char letter = s.at(0);

        // on se d�place vers la droite jusqu'�
        // soit arriver le plus � droite de l'arbre � cet �tage
        // soit arriver juste � droite de la lettre avant notre lettre
        while (current != nullptr && current->data < letter) {
            previous = current;
            current = current->right;
        }

        // si on est situ� sur la lettre en question
        if (current != nullptr && current->data == letter) {
            // si la taille du mot vaut 1 et qu'on est sur la bonne lettre, alors on a fini le mot
            if (s.size() == 1) {
                current->isEndOfWord = true;
                cpt += 1;
            }
            // si le mot continue apr�s, on "descend" d'un �tage pour poursuivre l'ajout � l'�tage d'en dessous sans la premi�re lettre
            else {
                // avant de "descendre", on update le parent
                previous = current;
                current = current->left;
                ajouterMot(s.erase(0, 1), current, previous);
            }
        }
        // si on n'est pas sur la lettre en question alors on peut juste placer notre mot "tout droit"
        else
            prepareBrutePlace(s, current, previous);
    }
    else
        cout << "Le mot " << s << " est deja dans le dictionnaire !" << endl;
}

void Arbre::prepareBrutePlace(string s, Node* cur, Node* prev) {
    Node* newNode = new Node(s.at(0));

    if (prev == root) {
        newNode->right = prev->right;
        prev->right = newNode;
    }
    else {
        // je viens de "descendre" (mon prev est au dessus de moi)
        if (prev->right != cur) {
            prev->left = newNode;
            // si je ne suis pas nouveau et que j'avais une autre branche
            if (cur != nullptr)
                newNode->right = cur;
        }
        else {
            prev->right = newNode;
            newNode->right = cur;
        }
    }

    // si il ne reste plus qu'une lettre dans le mot, alors le nouveau noeud est le dernier et le mot est fini
    if (s.size() == 1) {
        newNode->isEndOfWord = true;
        cpt += 1;
    }
    // sinon, on n'a plus qu'� placer le mot "tout droit"
    else
        brutePlaceWord(s.erase(0, 1), newNode);
}

void Arbre::brutePlaceWord(const string& s, Node* cur) {

    // on place toutes les lettres les unes � la suite des autres
    for (char letter : s) {
        Node* newNode = new Node(letter);
        cur->left = newNode;
        cur = newNode;
    }
    cur->isEndOfWord = true;
    cpt += 1;
}

void Arbre::afficherArbre(const string& prefix, Node* n, bool isLeftNode) const {
    //https://stackoverflow.com/questions/36802354/print-binary-tree-in-a-pretty-way-using-c
    if (n != nullptr) {

        cout << prefix;
        cout << (isLeftNode ? "|--" : "L--"); // if left node : |--, L-- otherwise
        cout << n->data << endl;

        afficherArbre(prefix + (isLeftNode ? "|   " : "    "), n->left, true);
        afficherArbre(prefix + (isLeftNode ? "|   " : "    "), n->right, false);
    }
}

ostream& operator<<(ostream& output, const Arbre& a) {
    a.afficherArbre("", a.root, false);
    return output;

}


bool Arbre::chercherMot(const string& s) {
    if (s.empty())
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

    if (n->data == s[0]) // Si data = premier caract�re, on part � gauche
        return _chercherMot(n->left, s.erase(0, 1));

    else // Sinon on cherche une alternative � droite
        return _chercherMot(n->right, s);

}

bool Arbre::chercherMots(Node* n, string s) {

    vector<Node*> path;
    vector<Node*> visited;

    // si le mot est etoile, retourner tous les mots du dico
    if (s.at(0) == '*') {
        path.push_back(n);
        findAfterStar(n, path, visited, path.size());

        // sinon recuperer ce qu'il y a avant l'etoile
        // puis retourner tous les mots possibles apres l'etoile
    }
    else {
        if (findUntilStar(n, s, path)) {
            findAfterStar(path.back()->left, path, visited, path.size());
        }
        else
            cout << "This word isn't in our dictionary !" << endl;
    }
    return true;
}

bool Arbre::findUntilStar(Node* n, string s, vector<Node*>& path) {

    // tant qu'on est pas � l'�toile on remplit le path avec le mot
    while (s.at(0) != '*') {
        if (n == nullptr) // Fin de l'arbre
            return false;
        // Si mot vide, on a tout parcouru
        if (n->data == s[0] && s.size() == 1)
            return n->isEndOfWord;

        // Si data = premier caract�re, on part � gauche
        if (n->data == s[0]) {
            path.push_back(n);
            return findUntilStar(n->left, s.erase(0, 1), path);
        }

        else // Sinon on cherche une alternative � droite
            return findUntilStar(n->right, s, path);
    }
    return true;
}

void Arbre::findAfterStar(Node* n, vector<Node*>& path, vector<Node*>& visited, int size) {

    // tant qu'on n'a pas explor� toutes les possibilit�s
    if (!path.empty()) {

        // si on est � la fin d'un mot qu'on n'a pas affiche, on l'affiche
        if (n->isEndOfWord && isNodeUnvisited(n, visited)) {
            path.push_back(n);
            printWord(path);
            path.pop_back();
        }

        // si c'est la premiere fois qu'on passe par ici, on le marque
        if (isNodeUnvisited(n, visited))
            visited.push_back(n);

        // si on peut descendre, on descend
        if (n->left != nullptr && isNodeUnvisited(n->left, visited)) {
            path.push_back(n);
            n = n->left;
            findAfterStar(n, path, visited, size);
            // si on ne peut plus aller � gauche, alors on passe � la droite
        }
        else if (n->right != nullptr && isNodeUnvisited(n->right, visited)) {
            n = n->right;
            findAfterStar(n, path, visited, size);
            // si on ne peut plus aller a droite, alors on rebrousse chemin
        }
        else if (path.size() > size) {
            n = path.back();
            path.pop_back();
            findAfterStar(n, path, visited, size);
        }
    }
}

bool Arbre::isNodeUnvisited(Node* node, vector<Node*>& visited) {

    //renvoie faux si node est dans le vector visited
    for (auto elem : visited)
        if (elem == node)
            return false;

    return true;
}

void Arbre::printWord(const vector<Node*>& path) {
    string word;
    for (auto node : path) {
        word.push_back(node->data);
    }

    // dans le cas ou le mot etait etoile, il faut enlever la racine de l'arbre
    if (word.at(0) == '-')
        word.erase(0, 1);
    cout << word << endl;
}
