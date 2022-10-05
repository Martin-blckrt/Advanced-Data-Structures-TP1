//
// Created by Clement on 05/10/2022.
//

#ifndef EXERCICE_4_NODE_H
#define EXERCICE_4_NODE_H

#include <string>
#include <utility>

struct member
{
    std::string type;
    std::string parent;
    std::string firstName;
    std::string lastName;
    std::string birthYear;
    std::string eyeColor;
};

class Node {
public:
    // Constructeur
    Node() {
        firstName = "";
        lastName = "";
        birthYear = "";
        eyeColor = "";
        firstChild = nullptr;
        spouse = nullptr;
        sibling = nullptr;
    };

    Node(std::string first, std::string last, std::string birth, std::string color):
            firstName(std::move(first)), lastName(std::move(last)), birthYear(std::move(birth)), eyeColor(std::move(color)),
            firstChild(nullptr), spouse(nullptr), sibling(nullptr){};

    // Destructeur
    ~Node() {
        firstChild = nullptr;
        spouse = nullptr;
        sibling = nullptr;
    };

    // Getters
    std::string getFirstName();
    std::string getLastName();
    std::string getBirthYear();
    std::string getEyeColor();
    Node* getFirstChild();
    Node* getSibling();
    Node* getSpouse();

    // Setters
    void setFirstName(std::string);
    void setLastName(std::string);
    void setBirthYear(std::string);
    void setEyeColor(std::string);
    void setFirstChild(Node*);
    void setSibling(Node*);
    void setSpouse(Node*);

private:
    std::string firstName;
    std::string lastName;
    std::string birthYear;
    std::string eyeColor;
    //list of children but what struct Node *left = nullptr;
    Node *firstChild, *sibling, *spouse = nullptr;
};


#endif //EXERCICE_4_NODE_H
