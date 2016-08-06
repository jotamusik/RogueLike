#include "mazmorra.hpp"

mazmorra::mazmorra(){

	pos_inicial_mazmorra.x = 0;
	pos_inicial_mazmorra.y = 0;
	size_mazmorra.x = 0;
	size_mazmorra.y = 0;
	puerta_1.x = 0;
	puerta_1.y = 0;
	puerta_2.x = 0;
	puerta_2.y = 0;
	punto_acceso.x = 0;
	punto_acceso.y = 0; 

}




mazmorra::mazmorra(pos pos_inicial, pos size, pos pto_acceso, pos puerta1, pos puerta2){


	pos_inicial_mazmorra.x = pos_inicial.x;
	pos_inicial_mazmorra.y = pos_inicial.y;
	size_mazmorra.x = size.x;
	size_mazmorra.y = size.y;
	puerta_1.x = puerta1.x;
	puerta_1.y = puerta1.y;
	puerta_2.x = puerta2.x;
	puerta_2.y = puerta2.y;
	punto_acceso.x = pto_acceso.x;
	punto_acceso.y = pto_acceso.y;

}


mazmorra::~mazmorra() {}

pos mazmorra::pos_puerta1() {

	return puerta_1;

}
pos mazmorra::pos_puerta2() {

	return puerta_2;

}
pos mazmorra::size() {

	return size_mazmorra;

}
pos mazmorra::pos_inicial() {

	return pos_inicial_mazmorra;

}

//void mazmorra::mazmorra_aleatoria() {    //*************   Usar RAND() **********



//}

void mazmorra::imprimir_paredes(matriz_char& tablero) {

	pos aux;

	for (int i=pos_inicial_mazmorra.x;i<=size_mazmorra.x+pos_inicial_mazmorra.x;i++) {

		for (int j=pos_inicial_mazmorra.y;j<=size_mazmorra.y+pos_inicial_mazmorra.y;j++) {

			aux.x=i;
			aux.y=j;

			tablero.set_char(aux,' ');

		}

	}


	for (int i=pos_inicial_mazmorra.x;i<=size_mazmorra.x+pos_inicial_mazmorra.x;i++) {

		for (int j=pos_inicial_mazmorra.y;j<=size_mazmorra.y+pos_inicial_mazmorra.y;j++) {

			aux.x=i;
			aux.y=j;

			if ( (i==pos_inicial_mazmorra.x) || (i==pos_inicial_mazmorra.x+1) ) 


				tablero.set_char(aux, '*'); 


			if ( (j==pos_inicial_mazmorra.y) || (j==pos_inicial_mazmorra.y+1) ) 

				tablero.set_char(aux, '*');


			if ( (i==(size_mazmorra.x+pos_inicial_mazmorra.x-1)) || (i==(size_mazmorra.x+pos_inicial_mazmorra.x)) ) 

				tablero.set_char(aux, '*');


			if ( (j==(size_mazmorra.y+pos_inicial_mazmorra.y-1)) || (j==(size_mazmorra.y+pos_inicial_mazmorra.y)) ) 

				tablero.set_char(aux, '*');

		}

	}

}

void mazmorra::set_pos_inicial(pos pos_inicial){

	pos_inicial_mazmorra.x = pos_inicial.x;
	pos_inicial_mazmorra.y = pos_inicial.y;
}

void mazmorra::set_size(pos size){

	size_mazmorra.x = size.x;
	size_mazmorra.y = size.y;

}

void mazmorra::set_puerta1(pos pta){

	puerta_1.x = pta.x;
	puerta_1.y = pta.y;
}

void mazmorra::set_puerta2(pos pta){

	puerta_2.x = pta.x;
	puerta_2.y = pta.y;
}

void mazmorra::set_pto_acceso(pos pto_acceso){

	punto_acceso.x = pto_acceso.x;
	punto_acceso.y = pto_acceso.y;
}



void mazmorra::imprimir_puertas(matriz_char& tablero) {

	tablero.set_char(puerta_1, '+');
	tablero.set_char(puerta_2, '+');

}

void mazmorra::imprimir_punto_acceso(matriz_char& tablero) {

	tablero.set_char(punto_acceso, 'x');
	
}

void mazmorra::imprimir_mazmorra(matriz_char& tablero) {

	imprimir_paredes(tablero);
	imprimir_puertas(tablero);
	imprimir_punto_acceso(tablero);

}

pos mazmorra::get_punto_acceso(){

	return punto_acceso;
}