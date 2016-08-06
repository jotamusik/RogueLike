#include "protagonista.hpp"
#include <iostream>


using namespace std;


protagonista::protagonista(): 

vidas(5),
amuleto(false) 

{

pos_actual_protagonista.x = 0;
pos_actual_protagonista.y = 0;

}

protagonista::protagonista(pos pos_inicial)
	/*
vidas(5),
amuleto(false)*/

{

	pos_actual_protagonista.x = pos_inicial.x;
	pos_actual_protagonista.y = pos_inicial.y;
	vidas = 5;
	amuleto = false;

}


protagonista::~protagonista() {}

	
pos protagonista::posicion_actual() {

	return pos_actual_protagonista;

}

bool protagonista::tiene_amuleto() {

	return amuleto;

}

void protagonista::set_amuleto(bool amul) {

	amuleto = amul;

}

int& protagonista::vidas_disponibles() {

	return vidas;

}

void protagonista::modificar_tablero(matriz_char& tablero) {

	tablero.set_char(pos_actual_protagonista, '@');

}

void protagonista::mover_protagonista(char c, char& elto_anterior, matriz_char& tablero) {

	//tablero.set_char(pos_actual_protagonista, elto_anterior);

	pos aux;
	aux.x = pos_actual_protagonista.x;
	aux.y = pos_actual_protagonista.y;

	switch (c) {

		case 'i': 	aux.x--;
					break;

		case 'k':	aux.x++;
					break;

		case 'j':	aux.y--;
					break;

		case 'l':	aux.y++;
					break;

	}
	// OJO con los puntitos. Si queremos que sean espacios, hay que modificar el tablero.get_char(aux) != ' ' por un '.'

	if(((tablero.get_char(aux) != '*')/*&&(tablero.get_char(aux) != ' ')*/&&(tablero.get_char(aux) != 'O'))||((tablero.get_char(aux) == '#')&&(tablero.get_char(aux) == '+'))){

		if ( elto_anterior == '#' ) {

			if ( (tablero.get_char(aux) == '+')||(tablero.get_char(aux) == '#')  ) {

				tablero.set_char(pos_actual_protagonista, elto_anterior);	// Modificar tablero (restablecer caracter anterior)
				pos_actual_protagonista = aux;	// ????	SI FUNCIONA !!!					
				elto_anterior = tablero.get_char(pos_actual_protagonista);	// Nuevo elemento anterior
				modificar_tablero(tablero);

			}

		}

		else {

			tablero.set_char(pos_actual_protagonista, elto_anterior);	// Modificar tablero (restablecer caracter anterior)
			pos_actual_protagonista = aux;	// ????	SI FUNCIONA !!!					
			elto_anterior = tablero.get_char(pos_actual_protagonista);	// Nuevo elemento anterior
			modificar_tablero(tablero);

		}

	}



}

void protagonista::comprobar_vidas(matriz_char& tablero) {

	pos aux = posicion_actual();
	pos aux1 = posicion_actual();

	aux.x = aux1.x + 1;
	aux.y = aux1.y;

	if (tablero.get_char(aux) == 'O') vidas--;

	aux.x = aux1.x - 1;
	aux.y = aux1.y;

	if (tablero.get_char(aux) == 'O') vidas--;

	aux.x = aux1.x;
	aux.y = aux1.y + 1;

	if (tablero.get_char(aux) == 'O') vidas--;

	aux.x = aux1.x;
	aux.y = aux1.y - 1;

	if (tablero.get_char(aux) == 'O') vidas--;

}