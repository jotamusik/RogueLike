//#include "struct_pos.hpp"
#pragma once

struct pos{

	int x;
	int y;
};

class matriz_char {

private:

	char* c_;
	int m_;
	int n_;


public:

	matriz_char();
	matriz_char(int m, int n);
	~matriz_char();

	int posicion(int i, int j);

	int get_m();
	int get_n();

	void set_m(int m);
	void set_n(int n);

	void set_char(pos posicion, char c);
	char get_char(pos posicion);

	void imprime_tablero();


};