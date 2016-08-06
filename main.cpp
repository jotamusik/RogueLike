

#include <fstream>
#include <stdlib.h> 
#include <iostream>

#include "tablero.hpp"
#include "mazmorra.hpp"
#include "protagonista.hpp"
#include "monstruo.hpp"
#include "amuleto.hpp"

// Probando integracion continua con un push


//#include "struct_pos.hpp"

using namespace std;

void clear() {
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    cout << "\x1B[2J\x1B[H";
}




void generar_pasillos(mazmorra& M1, mazmorra& M2, mazmorra& M3, matriz_char& tablero) {

	pos puerta1, puerta2, puerta3, puerta4, puerta5, puerta6, aux;

	puerta1 = M1.pos_puerta1();

	puerta2 = M1.pos_puerta2();
	
	puerta3 = M2.pos_puerta1();

	puerta4 = M2.pos_puerta2();
	
	puerta5 = M3.pos_puerta1();
	
	puerta6 = M3.pos_puerta2();

	for (int i=puerta1.y+1;i<puerta3.y;i++) {

		aux.x=puerta1.x;
		aux.y=i;

		tablero.set_char(aux, '#');

	}

	for (int i=puerta2.x+1;i<puerta5.x;i++) {

		aux.x=i;
		aux.y=puerta2.y;

		tablero.set_char(aux, '#');

	}

	for (int i=puerta4.x+1;i<puerta6.x;i++) {

		aux.x=i;
		aux.y=puerta4.y;

		tablero.set_char(aux, '#');

	}

}



int main (){

	char c='o';

	do{

	cout << "i.Introducir archivo" << endl;
	cout << "g.Generar aleatoriamente" << endl;

	cin >> c;

	}while((c != 'i') && (c != 'g'));

	int m,n;

	pos punto_acceso;

	pos amul;

	pos m_inicial;	//punto inicial para las mazmorras
	pos m_tam;		//tamaños para las mazmorras
	pos m_p1;		//ubicacion de las puertas
	pos m_p2;

	//DECLARAR MAZMORRAS

	pos aux;
	aux.x = 0;
	aux.y = 0;

	/*mazmorra mazmorra1();
	mazmorra mazmorra2();
	mazmorra mazmorra3();*/

	// Constructor no funciona

	mazmorra mazmorra1(aux, aux, aux, aux, aux);
	mazmorra mazmorra2(aux, aux, aux, aux, aux);
	mazmorra mazmorra3(aux, aux, aux, aux, aux);


	if(c == 'i'){

		char file[50];

		cout << "Introduzca el nombre del archivo: " << endl;
		cin >> file;

		ifstream fe(file);

		//int m,n;

		fe >> m;
		fe >> n;

		//char* tablero;
		//tablero = new char [n][m];


		//pos punto_acceso;
		int x,y;

		fe >> x;
		fe >> y;
		//leer punto de acceso
		punto_acceso.x = x;
		punto_acceso.y = y;



		for(int i=0;i<3;i++){

			fe>>m_inicial.x;
			fe>>m_inicial.y;
			fe>>m_tam.x;
			fe>>m_tam.y;
			fe>>m_p1.x;
			fe>>m_p1.y;
			fe>>m_p2.x;
			fe>>m_p2.y;

			if((m_tam.x >= 8) && (m_tam.y >= 8)){

				cout << i << endl;

				if(i==0){


					mazmorra1.set_pos_inicial(m_inicial);
					mazmorra1.set_size(m_tam);
					mazmorra1.set_puerta1(m_p1);
					mazmorra1.set_puerta2(m_p2);
					mazmorra1.set_pto_acceso(punto_acceso);


				}

				else if(i==1){


					mazmorra2.set_pos_inicial(m_inicial);
					mazmorra2.set_size(m_tam);
					mazmorra2.set_puerta1(m_p1);
					mazmorra2.set_puerta2(m_p2);
					mazmorra2.set_pto_acceso(punto_acceso);


				}

				else{


					mazmorra3.set_pos_inicial(m_inicial);
					mazmorra3.set_size(m_tam);
					mazmorra3.set_puerta1(m_p1);
					mazmorra3.set_puerta2(m_p2);
					mazmorra3.set_pto_acceso(punto_acceso);

				}

			}

			else{

				cout << "El tamaño de la mazmorra " << i+1 << " no es lo suficientemente grande" << endl;
				exit(0);

			}

		}


	//protagonista prota(punto_acceso);

	//pos amul;  Declarado antes del if

	fe>>amul.x;
	fe>>amul.y;


	//Comprobar que se encuentra dentro de la mazmorra 3

	//amuleto amuleto_m3(amul);
	
	fe.close();

	}

	else {

		pos p1,p2;
	//aleatorio

		cout << "Introduzca las dimensiones del tablero" << endl;
		cout << "Filas [25,40]: " ;
		cin >> m;

		while((m > 40) || (m < 25)){

			cout << "El numero de filas no cumple el rango. Introduzca otro valor: " ;
			cin >> m;
		}

		cout << "Columnas [30,185]: " ;
		cin >> n;

		while((n > 185) || (n < 30)){

			cout << "El numero de columnas no cumple el rango. Introduzca otro valor: " ;
			cin >> n;
		}

		int col_p2;
		int col_p4;

		for(int i=0;i<3;i++){

			if(i==0){	// MAZMORRA 1

				m_inicial.x = rand() % (m/2 - 9) + 1;
				m_inicial.y = rand() % (n/2 - 9) + 1;

				mazmorra1.set_pos_inicial(m_inicial);

				m_tam.x = rand() % (m/2 - m_inicial.x - 8) + 8;
				m_tam.y = rand() % (n/2 - m_inicial.y - 8) + 8;

				cout << m_tam.x << " " << m_tam.y << endl;

				mazmorra1.set_size(m_tam);

				//m_p1.x = (m_inicial.x + m_tam.x) / 2;
				p1.y = m_inicial.y + m_tam.y - 1;

				//mazmorra1.set_puerta1(m_p1);

				m_p2.x = m_inicial.x + m_tam.x - 1;
				m_p2.y = m_inicial.y + m_tam.y - 2;
				
				mazmorra1.set_puerta2(m_p2);

				col_p2 = m_p2.y;

				punto_acceso.x = m_inicial.x + 2;
				punto_acceso.y = m_inicial.y + 2;

				mazmorra1.set_pto_acceso(punto_acceso);

			}

			if(i==1){

				m_inicial.x = rand() % (m/2 - 9) + 1;
				m_inicial.y = rand() % (n - 9 - n/2) + (n/2 + 1);

				mazmorra2.set_pos_inicial(m_inicial);

				m_tam.x = rand() % (m/2 - m_inicial.x - 8) + 8;
				m_tam.y = rand() % (n/2 - m_inicial.y - 8) + 8;

				while((m_tam.y + m_inicial.y) > n){

					//m_tam.y = rand() % (n/2 - m_inicial.y - 8) + 8;
					m_tam.y--;
				}

				cout << m_tam.x << " " << m_tam.y << endl;

				mazmorra2.set_size(m_tam);

				//m_p1.x no se modifica, se corresponde con la puerta 1 (en la mazmorra 1)
				p2.y = m_inicial.y + 1;

				//mazmorra2.set_puerta1(m_p1);

				m_p2.x = m_inicial.x + m_tam.x - 1;
				m_p2.y = m_inicial.y + 2;
				
				mazmorra2.set_puerta2(m_p2);

				col_p4 = m_p2.y;

				mazmorra2.set_pto_acceso(punto_acceso);

			}

			if(i==2){

				pos aux4;

				aux4 = mazmorra1.pos_inicial();
				aux = mazmorra1.size();

				m_inicial.x = rand() % (m - 9 - m/2) + (m/2 + 1);
				m_inicial.y = rand() % (aux4.y + aux.y - 5) + 1;

				mazmorra3.set_pos_inicial(m_inicial);

				aux = mazmorra2.pos_inicial();

				m_tam.x = rand() % (m/2 - m_inicial.x - 8) + 8; 
				m_tam.y = rand() % (n - aux.y - -6) + (aux.y + 5 - m_inicial.y);

				while((m_inicial.x + m_tam.x) > m){

					m_tam.x--;
				}

				while((m_inicial.y + m_tam.y) > n){

					m_tam.y--;
				}

				cout << m_tam.x << " " << m_tam.y << endl;

				mazmorra3.set_size(m_tam);

				m_p1.x = m_inicial.x + 1;
				m_p2.x = m_inicial.x + 1;

				m_p1.y = col_p2;
				m_p2.y = col_p4;

				mazmorra3.set_puerta1(m_p1);
				mazmorra3.set_puerta2(m_p2);

				mazmorra3.set_pto_acceso(punto_acceso);



				amul.x = rand() % (m_tam.x-3) + (m_inicial.x+2);
				amul.y = rand() % (m_tam.y-3) + (m_inicial.y+2);


			}
		}

		pos puerta1, puerta3;

		puerta1 = mazmorra1.pos_inicial();
		puerta3 = mazmorra2.pos_inicial();

		if(puerta1.x < puerta3.x){

			p1.x = puerta3.x + 2;
			p2.x = puerta3.x + 2;

			mazmorra1.set_puerta1(p1);
			mazmorra2.set_puerta1(p2);



		}

		else{

			p1.x = puerta1.x + 2;
			p2.x = puerta1.x + 2;

			mazmorra1.set_puerta1(p1);
			mazmorra2.set_puerta1(p2);

		}
	}


	//------------------------------------------------------------------------------------------------

	//leer de fichero o aleatorio n filas y m columnas. Comprobar que el pto de acceso esta dentro de los limites de la mazmorra 1


	matriz_char tablero(m,n);

	pos auxii;
	auxii.x=8;
	auxii.y=8;

	/*    IMPORTANTE 

		No se puede usar el constructor por defecto (ni mazmorras ni monstruos), da problemas.
		Motivo : Desconocido

	*/

	/*mazmorra mazmorra1(auxii,auxii,auxii,auxii,auxii);
	mazmorra mazmorra2(auxii,auxii,auxii,auxii,auxii);
	mazmorra mazmorra3(auxii,auxii,auxii,auxii,auxii);*/

	monstruo mons1(auxii);
	monstruo mons2(auxii);
	monstruo mons3(auxii);
	monstruo mons4(auxii);
	monstruo mons5(auxii);
	monstruo mons6(auxii);
	monstruo mons7(auxii);
	monstruo mons8(auxii);
	monstruo mons9(auxii);


	// Los puntitos o espacios de la matriz

	for (int i=1;i<=tablero.get_m();i++) {

		for (int j=1;j<=tablero.get_n();j++) {

			pos p;
			p.x=i;
			p.y=j;
			tablero.set_char(p,' ');

		}

	}

	mazmorra1.imprimir_mazmorra(tablero);
	mazmorra2.imprimir_mazmorra(tablero);
	mazmorra3.imprimir_mazmorra(tablero);

	generar_pasillos(mazmorra1, mazmorra2, mazmorra3, tablero);

	amuleto amuleto_m3(amul);

	protagonista prota(punto_acceso);

	mons1.ubicar_mons(mazmorra1/*para evitar que se salga de las dimensiones de la mazmorra*/, tablero/*escribir en la matriz*/, amuleto_m3, punto_acceso, prota/*los 3 ultimos parametros son para evitar que se posicione el monstruo sobre alguna de tales posiciones*/);
	mons2.ubicar_mons(mazmorra1, tablero, amuleto_m3, punto_acceso, prota);
	mons3.ubicar_mons(mazmorra1, tablero, amuleto_m3, punto_acceso, prota);
	mons4.ubicar_mons(mazmorra2, tablero, amuleto_m3, punto_acceso, prota);
	mons5.ubicar_mons(mazmorra2, tablero, amuleto_m3, punto_acceso, prota);
	mons6.ubicar_mons(mazmorra2, tablero, amuleto_m3, punto_acceso, prota);
	mons7.ubicar_mons(mazmorra3, tablero, amuleto_m3, punto_acceso, prota);
	mons8.ubicar_mons(mazmorra3, tablero, amuleto_m3, punto_acceso, prota);
	mons9.ubicar_mons(mazmorra3, tablero, amuleto_m3, punto_acceso, prota);

	amuleto_m3.mod_tab(tablero);

	//pos punto_acceso;

	prota.modificar_tablero(tablero);

	
	
	pos aux2, aux3, m1;

	m1 = mazmorra1.get_punto_acceso();

	aux2 = prota.posicion_actual();

	aux3 = amuleto_m3.posicion();
	
	char op;
	char elemento_anterior='x';

	clear();

	do{

		tablero.imprime_tablero();
		cout << "Vidas Disponibles: " << prota.vidas_disponibles() << endl;
		//contiguo a un monstruo??? vidas--

		cin >> op;


		prota.mover_protagonista(op, elemento_anterior, tablero);

		prota.comprobar_vidas(tablero);

		aux2 = prota.posicion_actual();

		/* En aux3 esta la posicion del amuleto y la comparamos con la siguiente posicion que tendra el
		protagonista para que si coincide:

		1- Modificamos el bool amuleto de prota a true
		2- Eliminamos del tablero y del elemento anterior el caracter del amuleto '&'
		3- Y ponemos en su lugar en la matriz al protagonista y en el elemento anterior un espacio
		*/

		if ( (aux2.x == aux3.x) && (aux2.y == aux3.y) ) {

			prota.set_amuleto(true);
			amuleto_m3.coger_amuleto(tablero);
			elemento_anterior = ' ';
			prota.modificar_tablero(tablero);

		}		

		clear();

		mons1.mover_monstruo(mazmorra1, tablero, amuleto_m3, punto_acceso, prota);
		mons2.mover_monstruo(mazmorra1, tablero, amuleto_m3, punto_acceso, prota);
		mons3.mover_monstruo(mazmorra1, tablero, amuleto_m3, punto_acceso, prota);
		mons4.mover_monstruo(mazmorra2, tablero, amuleto_m3, punto_acceso, prota);
		mons5.mover_monstruo(mazmorra2, tablero, amuleto_m3, punto_acceso, prota);
		mons6.mover_monstruo(mazmorra2, tablero, amuleto_m3, punto_acceso, prota);
		mons7.mover_monstruo(mazmorra3, tablero, amuleto_m3, punto_acceso, prota);
		mons8.mover_monstruo(mazmorra3, tablero, amuleto_m3, punto_acceso, prota);
		mons9.mover_monstruo(mazmorra3, tablero, amuleto_m3, punto_acceso, prota);

		prota.comprobar_vidas(tablero);


		if((aux2.x == m1.x)&&(aux2.y == m1.y)&&(prota.tiene_amuleto() == true)){
			cout << "Has ganado" << endl;
			break;
		}


	}while((prota.vidas_disponibles() != 0)/*&&((tablero.get_char(aux2) != 'x')||(prota.tiene_amuleto() != true))*/);

		
	//}while((prota.vidas_disponibles() != 0)&&(aux2.x != punto_acceso.x)&&(aux2.y != punto_acceso.y)&&(prota.tiene_amuleto() != true));


}