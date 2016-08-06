#include "tablero.hpp"
#include <iostream>
using namespace std;


matriz_char::matriz_char():
	c_(NULL),
	m_(0),
	n_(0)
	{}

matriz_char::matriz_char(int m, int n):
c_(NULL),
m_(m),
n_(n)
{

	c_ = new char[m_*n_];
	if (c_ == NULL) cerr << endl << "Error creando tablero, no se pudo crear" << endl;

}

matriz_char::~matriz_char() {}

int matriz_char::posicion(int i, int j) {

	return (i-1)*n_+j-1;		

}

int matriz_char::get_m() {

	return m_;

}

int matriz_char::get_n() {

	return n_;

}

void matriz_char::set_m(int m){

	m_=m;
}

void matriz_char::set_n(int n){

	n_=n;
}

void matriz_char::set_char(pos posic, char c) {

	c_[posicion(posic.x,posic.y)] = c;

}

char matriz_char::get_char(pos posic) {

	return c_[posicion(posic.x,posic.y)];

}

void matriz_char::imprime_tablero() {

	for (int i=1;i<=get_m();i++) {

		for (int j=1;j<=get_n();j++) {

			cout << c_[posicion(i,j)];

		}

		cout << endl;

	}

}