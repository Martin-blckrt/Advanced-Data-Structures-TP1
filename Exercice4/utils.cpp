//
// Created by Clement on 05/10/2022.
//
#include "utils.h"
#include <fstream>
#include <sstream>
#include <iterator>

using namespace std;

vector<member> getMembersFromFile(const string& path) {
    vector<member> membersList;
    fstream inputFile(path);
    string outputLine, temp;

    while (getline(inputFile, outputLine)) {
        stringstream X(outputLine);
        member m;
        int cpt = 0;

        while (getline(X, temp, ';')) {
            switch (cpt) {
            case 0:
                m.type = temp;
                cpt += 1;
                break;
            case 1:
                m.parent = temp;
                cpt += 1;
                break;
            case 2:
                m.firstName = temp;
                cpt += 1;
                break;
            case 3:
                m.lastName = temp;
                cpt += 1;
                break;
            case 4:
                m.birthYear = temp;
                cpt += 1;
                break;
            case 5:
                m.eyeColor = temp;
                cpt += 1;
                break;
            default:
                break;
            }
        }
        membersList.push_back(m);
    }
    inputFile.close();
    return membersList;
}
