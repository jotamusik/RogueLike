#include "monstruo.hpp"

monstruo::monstruo(){

	pos_actual_monstruo.x = 0;
	pos_actual_monstruo.y = 0;

}


monstruo::monstruo(pos pos_inicial){

	pos_actual_monstruo.x = pos_inicial.x;
	pos_actual_monstruo.y = pos_inicial.y;

}


monstruo::~monstruo() {}

void monstruo::modificar_tablero(matriz_char& tablero) {

	tablero.set_char(pos_actual_monstruo, 'O');

}

void monstruo::mover_monstruo(mazmorra& M, matriz_char& tablero, amuleto& amu, pos pto_acceso, protagonista& prota) {    // Comprobar que no se sale de las mazmorras

	pos p_inicial, size, aux, amuleto, prota_;

	p_inicial = M.pos_inicial();
	size = M.size();
	amuleto = amu.posicion();
	prota_ = prota.posicion_actual();

	//Posicion anterior restaurada ' '

	tablero.set_char(pos_actual_monstruo, ' ');

	int x=1;

	while(x==1){

		aux.x = rand() % (size.x-3) + (p_inicial.x+2);
		aux.y = rand() % (size.y-3) + (p_inicial.y+2);

		if(((aux.x == amuleto.x)&&(aux.y == amuleto.y))||((aux.x == pto_acceso.x)&&(aux.y == pto_acceso.y))||((aux.x == prota_.x)&&(aux.y == prota_.y))) x=1;

		else{

			pos_actual_monstruo = aux;
			x=0;
		}

	}

	modificar_tablero(tablero);

}

void monstruo::ubicar_mons(mazmorra& M, matriz_char& tablero, amuleto& amu, pos pto_acceso, protagonista& prota) {

	pos p_inicial, size, aux, amuleto, prota_;

	p_inicial = M.pos_inicial();
	size = M.size();
	amuleto = amu.posicion();
	prota_ = prota.posicion_actual();

	int x=1;

	while(x==1){

		aux.x = rand() % (size.x-3) + (p_inicial.x+2);
		aux.y = rand() % (size.y-3) + (p_inicial.y+2);

		if(((aux.x == amuleto.x)&&(aux.y == amuleto.y))||(tablero.get_char(aux)=='O')||((aux.x == pto_acceso.x)&&(aux.y == pto_acceso.y))||((aux.x == prota_.x)&&(aux.y == prota_.y))) x=1;

		else{

			cout << "Monstruo ubicado correctamente" << endl;
			cout << aux.x << " " << aux.y << endl;
			pos_actual_monstruo = aux;
			x=0;
		}

	}

	modificar_tablero(tablero);

}