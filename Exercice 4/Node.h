//
// Created by marti on 03/10/2022.
//
#include <string>

#ifndef EXERCICE_2_NODE_H
#define EXERCICE_2_NODE_H


class Node {

    public:
        std::string getFirstName();
        std::string getName();
        std::string getBirthDate();
        std::string getEyeColor();
        Node* getParent1(Node*);
        Node* getParent2(Node*);

        void setFirstName(std::string);
        void setName(std::string);
        void setBirthDate(std::string);
        void setEyeColor(std::string);
        void setParent1(Node*, Node*);
        void setParent2(Node*, Node*);

    private:
        std::string name;
        std::string firstName;
        std::string birthDate;
        std::string eyeColor;
        //list of children but what struct Node *left = nullptr;
        Node *parent1, *parent2 = nullptr;
};


#endif //EXERCICE_2_NODE_H
