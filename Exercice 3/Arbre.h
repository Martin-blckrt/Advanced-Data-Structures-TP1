//
// Created by Clement on 19/09/2022.
//

#ifndef EXERCICE_3_ARBRE_H
#define EXERCICE_3_ARBRE_H

#include <vector>
#include <string>

class Arbre
{
private:
// classe Node
    class Node
    {
    public:
        char data;
        Node *left = nullptr;
        Node *right = nullptr;
        bool isEndOfWord = false;

        explicit Node(const char &d): data(d) {};
        ~Node() {
            delete left;
            delete right;
        };
    };
// Les membres données
    Node* root; //racine de l'arbre
    int cpt; // Nombre de noeuds dans l'arbre
// Les membres méthodes privés
//...

public:
    //..Les méthodes publiques (i.e. les opérateurs)
    //Constructeurs
    Arbre();
    //Destructeur
    ~Arbre();
    // Getter
    int getCompteur() const;

    void firstAjouterMot(std::string);
    void ajouterMot(std::string, Node*, Node*);
    void prepareBrutePlace(std::string, Node*, Node*);
    void brutePlaceWord(const std::string&, Node*);
    void enleverMot(const std::string&);
    void _enleverMot(Node*, std::string);
    void afficherArbre(const std::string&, Node*, bool) const;
    bool chercherMot(const std::string&);
    bool _chercherMot(Node* , std::string);
    bool chercherMots(Node* , std::string);
    bool findUntilStar(Node* , std::string, std::vector<Node*>&);
    void findAfterStar(Node*, std::vector<Node*>&, std::vector<Node*>&, int);
    static bool isNodeUnvisited(Node*, std::vector<Node*>&);
    static void printWord(const std::vector<Node*>&);

    friend std::ostream& operator<<(std::ostream&, const Arbre&);
};


#endif //EXERCICE_3_ARBRE_H
