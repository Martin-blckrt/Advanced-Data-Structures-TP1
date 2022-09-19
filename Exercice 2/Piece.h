//
// Created by Clement on 18/09/2022.
//

#ifndef EXERCICE_2_PIECE_H
#define EXERCICE_2_PIECE_H

#include <string>

class Piece {
public:
    //Constructeur
    explicit Piece(int);
    explicit Piece();

    //Getter
    int getType() const;

    //Setter
    //void setType(int&);

private:
    int m_type;
};


#endif //EXERCICE_2_PIECE_H
