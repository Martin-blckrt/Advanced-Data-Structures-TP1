#ifndef EXERCICE_2_FILE_H
#define EXERCICE_2_FILE_H

#include <iostream>
#include "Morceau.h"

template<typename T>
class Axe : public Morceau
{
public:
	virtual void usiner();
}

#endif //EXERCICE_2_FILE_H