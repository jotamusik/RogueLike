#include "amuleto.hpp"

amuleto::amuleto(){

	pos_amuleto.x = 0;
	pos_amuleto.y = 0;
}


amuleto::amuleto(pos pos_inicial){

	pos_amuleto.x = pos_inicial.x;
	pos_amuleto.y = pos_inicial.y;
}

amuleto::~amuleto() {}


pos amuleto::posicion() {

	return pos_amuleto;

}

void amuleto::mod_tab(matriz_char& tablero) {

	tablero.set_char(pos_amuleto,'&');

}

void amuleto::coger_amuleto(matriz_char& tablero) {

	tablero.set_char(pos_amuleto, ' ');

}