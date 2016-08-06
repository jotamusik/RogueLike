//#include "struct_pos.hpp"
#include "tablero.hpp"
#include "mazmorra.hpp"
#include "amuleto.hpp"
#include "protagonista.hpp"
#include <cstdlib>
#include <iostream>
#pragma once


class monstruo {

private:

	pos pos_actual_monstruo;

public:

	monstruo();
	monstruo(pos pos_inicial);
	~monstruo();

	void modificar_tablero(matriz_char& tablero);

	void mover_monstruo(mazmorra& M, matriz_char& tablero, amuleto& amu, pos pto_acceso, protagonista& prota);

	void ubicar_mons(mazmorra& M, matriz_char& tablero, amuleto& amu, pos pto_acceso, protagonista& prota);

};