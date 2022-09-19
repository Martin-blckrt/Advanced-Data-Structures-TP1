//
// Created by Clement on 18/09/2022.
//
#include <string>
#include "Machine.h"
using namespace std;

Machine :: Machine(int tpsExec, int type) {
    m_temps_exec = tpsExec;
    m_type = type;
    m_en_panne = false;
    m_occupee = false;
    m_file_test = new File<Piece>(100);

    if (type == 3) {
        axeU = new File<Piece>(100);
        jupeU = new File<Piece>(100);
        teteU = new File<Piece>(100);
    }
    else
        toManufacture = new File<Piece>(100);
}

bool Machine :: isBroken() const {
    return m_en_panne;
}

bool Machine :: isWorking() const {
    return m_occupee;
}

void Machine :: setState() {
    if (m_occupee)
        m_occupee = false;
    else
        m_occupee = true;
}

void Machine :: setBreak() {
    if (m_en_panne)
        m_en_panne = false;
    else
        m_en_panne = true;
}

void Machine :: testMethod(Piece p)
{
    string name("tete");
    m_file_test->enfiler(p);
}

void Machine :: addElemToQueue(int type) {
    if (type == 0)
    {
        //auto new_p = new Piece(type);
        toManufacture->enfiler(Piece(type));
    }
    else if (type == 1)
    {
        toManufacture->enfiler(Piece(type));

    }
    else if (type == 2)
    {
        toManufacture->enfiler(Piece(type));
    } else
    {
        cout << "autre ? piston ?" << endl;
    }

}

int Machine :: getQueueSize() {
    return toManufacture->taille();
}

int Machine :: work() {
    //
    if (m_type == 3) {
        if (!axeU->estVide() && !jupeU->estVide() && !teteU->estVide())
            return manufacture();
    } else
    {
        if (!toManufacture->estVide()) {
            if (!m_en_panne) {
                return manufacture();
            } else {
                m_en_panne = false;
                return (300 + (rand() % 300)); // repair time
            }
        } else {
            return 999999999;
        }
    }
    return 0;
}

int Machine :: manufacture() {
    if (m_type == 3) {
        axeU->defiler();
        jupeU->defiler();
        teteU->defiler();
    }
    if (((double)rand() / RAND_MAX) < 0.25)
        m_en_panne = true;
    return m_temps_exec;
}

Piece Machine :: removePiece() {
    return toManufacture->defiler();
}