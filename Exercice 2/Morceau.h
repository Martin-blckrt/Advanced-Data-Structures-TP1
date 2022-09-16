#ifndef EXERCICE_2_FILE_H
#define EXERCICE_2_FILE_H

#include <iostream>

template<typename T>
class Morceau
{
public:
	virtual void usiner() = 0; // méthode virtuelle pure, Morceau devient une classe abstraite dont on ne peut pas créer d'instance
}

#endif //EXERCICE_2_FILE_H