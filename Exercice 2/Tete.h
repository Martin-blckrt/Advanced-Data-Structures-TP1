#ifndef EXERCICE_2_FILE_H
#define EXERCICE_2_FILE_H

#include "Morceau.h"
#include <iostream>

template<typename T>
class Tete : public Morceau
{
public:
	virtual void usiner();
}

#endif //EXERCICE_2_FILE_H