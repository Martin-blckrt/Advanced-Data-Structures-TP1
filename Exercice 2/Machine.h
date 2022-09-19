//
// Created by Clement on 18/09/2022.
//

#ifndef EXERCICE_2_MACHINE_H
#define EXERCICE_2_MACHINE_H

#include "File.h"
#include "Piece.h"
#include <string>

class Machine {
public:
    //Constructeur
    Machine (int, int);

    //Getter
    bool isWorking() const;
    bool isBroken() const;
    int getQueueSize();

    //Setter
    void setState();
    void setBreak();

    void addElemToQueue(int);
    int work();
    int manufacture();
    Piece removePiece();
    void testMethod(Piece);

private:
    int m_temps_exec;
    int m_type;
    bool m_en_panne;
    bool m_occupee;
    File<Piece> *toManufacture;
    File<Piece> *axeU;
    File<Piece> *jupeU;
    File<Piece> *teteU;
    File<Piece> *m_file_test;
};


#endif //EXERCICE_2_MACHINE_H
