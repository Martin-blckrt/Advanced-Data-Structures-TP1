#pragma once

//
// Created by Clement on 18/09/2022.
//

#define AXE 0
#define JUPE 1
#define TETE 2
#define PISTON 3

#include "File.h"
#include "Piece.h"
#include <string>

class Machine {
public:
    //Constructeur
    Machine(double, int);

    void addElemToQueue(Piece);
    double work();
    double manufacture();
    Piece removePiece();

private:
    double m_temps_exec;
    int m_type;
    bool m_en_panne;
    //bool m_occupee;
    File<Piece>* toManufacture;
    File<Piece>* axeU;
    File<Piece>* jupeU;
    File<Piece>* teteU;
};
