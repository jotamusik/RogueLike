//#include "struct_pos.hpp"
#include "tablero.hpp"
#pragma once


class amuleto {

private:

	pos pos_amuleto;

public:

	amuleto();
	amuleto(pos pos_inicial);
	~amuleto();

	pos posicion();

	void mod_tab(matriz_char& tab);

	void coger_amuleto(matriz_char& tab);

};