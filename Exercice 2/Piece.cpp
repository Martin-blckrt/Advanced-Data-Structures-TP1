//
// Created by Clement on 18/09/2022.
//

#include "Piece.h"

using namespace std;

Piece :: Piece (int type) {
    m_type = type;
}


Piece :: Piece() = default;

int Piece :: getType() const {
    return m_type;
}

/*
void Piece :: setType(int &i) {
    m_type = i;
}*/