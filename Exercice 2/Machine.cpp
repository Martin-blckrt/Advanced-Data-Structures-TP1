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

    if (type == PISTON) {
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

void Machine :: addElemToQueue(Piece p) {
    if (m_type == PISTON)
    {
        if (p.getType() == AXE)
            axeU->enfiler(p);
        if (p.getType() == JUPE)
            jupeU->enfiler(p);
        if (p.getType() == TETE)
            teteU->enfiler(p);
    }
    else if (m_type == 0 || m_type == 1 || m_type == 2)
        toManufacture->enfiler(p);
}

int Machine :: getQueueSize() {
    return toManufacture->taille();
}

double Machine :: work() {
    // If machine is MP, check if it has 3 pieces before trying to work
    if (m_type == PISTON) {
        if (!axeU->estVide() && !jupeU->estVide() && !teteU->estVide()) {
            // if machine isnt broken down, manufacture the piece
            if (!m_en_panne) {
                return manufacture();
            } else { // if machine is broken down, unbreak it and send back repair time
                m_en_panne = false;
                return (5 + (rand() % 5)); // repair time
            }
        }
    } else
    {
        if (!toManufacture->estVide()) {
            if (!m_en_panne) {
                return manufacture();
            } else {
                m_en_panne = false;
                return (5 + (rand() % 5)); // repair time
            }
        } else {
            return 999999999; // all pieces of this machine have been manufactured, dont need it anymore
        }
    }
    return 0;
}

double Machine :: manufacture() {
    if (m_type == PISTON) { // if machine is MP, get rid of the three pieces
        axeU->defiler();
        jupeU->defiler();
        teteU->defiler();
    }
    if (((double)rand() / RAND_MAX) < 0.25) // generate random chance on panne
        m_en_panne = true;
    return m_temps_exec;
}

Piece Machine :: removePiece() {
    return toManufacture->defiler();
}