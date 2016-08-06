//#include "struct_pos.hpp"
#include "tablero.hpp"
#pragma once


class protagonista {

private:

	pos pos_actual_protagonista;
	int vidas;
	bool amuleto;

public:
	protagonista();
	protagonista(pos pos_inicial);
	~protagonista();
	
	pos posicion_actual();
	bool tiene_amuleto();

	void set_amuleto(bool amul);

	int& vidas_disponibles();

	void modificar_tablero(matriz_char& tablero);

	void mover_protagonista(char c, char& elto_anterior, matriz_char& tablero);

	void comprobar_vidas(matriz_char& tablero);

};