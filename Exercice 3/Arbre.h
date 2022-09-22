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
        //int card;
        // int height;
        Node(const char &d): data(d) {};
        //Node( const char&d ): left(0),data(d),right(0),height(0) { }
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
    Arbre(const Arbre&) ;
    //Destructeur
    ~Arbre();
    //Les fonctions membres
    bool estVide() const;
    long taille() const;

    //const char& max() const;
    //const Node& _max(Node*)const;

    //const char& min() const ;
    //const Node& _min(Node*)const;

    //int nbNoeuds()const;
    //int _nbNoeuds(Node*) const;

    //int nbFeuilles()const;
    //int _nbFeuilles(Node*) const;

    //int hauteur() const;
    //int _hauteurParcours(Node*) const;

    //bool appartient(const E &) const;
    //Node* _auxAppartient(Node*, const E&) const;

    //const E& parent(const E&) const;
    //Node* _parent(Node*, Node*) const;

    //E successeur(const E& ) const;
    //E _successeur(Node*, const E&) const;
    void firstAjouterMot(std::string);
    void ajouterMot(std::string, Node*);
    void prepareBrutePlace(std::string, Node*, Node*);
    void brutePlaceWord(std::string, Node*);
    void enleveMot(std::string);
    void afficherDict();
    void afficherArbre(const std::string, Node*, bool);
    bool chercheMot(std::string);

};


#endif //EXERCICE_3_ARBRE_H
