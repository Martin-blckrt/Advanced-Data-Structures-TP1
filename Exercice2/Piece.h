#pragma once

//
// Created by Clement on 18/09/2022.
//

#include <string>

class Piece {
public:
    //Constructeur
    explicit Piece(int);
    explicit Piece();

    //Getter
    int getType() const;

private:
    int m_type;
};

