//
// Created by Clement on 05/10/2022.
//

#ifndef EXERCICE_4_NODE_H
#define EXERCICE_4_NODE_H

#include <string>


class Node {
public:
    std::string getFirstName();
    std::string getName();
    std::string getBirthDate();
    std::string getEyeColor();
    static Node* getFirstChild(Node*);
    static Node* getSibling(Node*);
    static Node* getSpouse(Node*);

    void setFirstName(std::string);
    void setName(std::string);
    void setBirthDate(std::string);
    void setEyeColor(std::string);
    static void setFirstChild(Node*, Node*);
    static void setSibling(Node*, Node*);
    static void setSpouse(Node*, Node*);

private:
    std::string name;
    std::string firstName;
    std::string birthDate;
    std::string eyeColor;
    //list of children but what struct Node *left = nullptr;
    Node *firstChild, *sibling, *spouse = nullptr;
};


#endif //EXERCICE_4_NODE_H
