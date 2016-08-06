//#include "struct_pos.hpp"
#include "tablero.hpp"
#include <iostream>
using namespace std;
#pragma once

class mazmorra {

private:

	pos pos_inicial_mazmorra;
	pos size_mazmorra;
	pos puerta_1;
	pos puerta_2;
	pos punto_acceso;

public:

	mazmorra();
	mazmorra(pos pos_inicial, pos size, pos pto_acceso, pos puerta1, pos puerta2);
	~mazmorra();

	pos pos_puerta1();
	pos pos_puerta2();
	pos size();
	pos pos_inicial();

	void set_pos_inicial(pos pos_inicial);
	void set_size(pos size);
	void set_puerta1(pos pta);
	void set_puerta2(pos pta);
	void set_pto_acceso(pos pto_acceso);


	pos get_punto_acceso();


	void imprimir_paredes(matriz_char& tablero);

	void imprimir_puertas(matriz_char& tablero);

	void imprimir_punto_acceso(matriz_char& tablero);

	void imprimir_mazmorra(matriz_char& tablero);


};