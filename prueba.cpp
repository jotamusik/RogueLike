#include <iostream>

#include "libreria_.hpp"

#include "tablero_t.hpp"

using namespace std;


void mod_mat(tablero_t& A) {

	pos_ b;

	b.x=2;
	b.y=3;

	A.set_char(b, 'O');

}

int main (void) {

	tablero_t tab(5,5);

	pos_ p;


	for (int i=1;i<=5;i++) {

		for (int j=1;j<=5;j++) {

			p.x=i;
			p.y=j;
			tab.set_char(p,'.');

		}

	}


	mod_mat(tab);

	tab.imprime_tablero();

}