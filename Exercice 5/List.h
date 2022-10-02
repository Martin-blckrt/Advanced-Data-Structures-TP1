//
// Created by marti on 02/10/2022.
//

#ifndef EXERCICE_2_LIST_H
#define EXERCICE_2_LIST_H

template <typename T>
class List {
    public:
//..
    private:
        class Node;
        typedef Node* elem;
        class Node { //Un noeud typique de la liste
        public:
            T el; //L'élément de base de la liste
            Node* suivant; //Un pointeur vers le noeud suivant
            Node* precedent; //Un pointeur vers le noeud précédent
            Node (const T& data_item, Node * next_ptr = 0, Node * pred_ptr =0) :
                    el(data_item), suivant(next_ptr), precedent(pred_ptr){}
        };
        elem sommetG; //Pointeur vers le sommet à gauche
        elem sommetD; //...vers le sommet droit
        int cpt; //cardinalité de la liste
    } ;
};


#endif //EXERCICE_2_LIST_H
