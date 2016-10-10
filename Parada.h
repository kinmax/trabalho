class Veiculo; //Definição prévia para que o compilador possa identificar Veiculo como um tipo
#ifndef _parada_h_
#define _parada_h_
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Veiculo.h"
using namespace std;

class Parada
{
	private:
		int ID, codigo, nv; //nv = número de veículos que passam pela parada
		double latitude;
		double longitude;
		char terminal;
		Parada* prox;  // Este atributo deve ser usado somente se for implementada uma lista ENCADEADA de paradas
	public:
		Parada();
		Veiculo* listaVeiculosQuePassamPorAqui[100];		
		int get_ID();
		int get_codigo();
		int get_nv();
		double get_latitude();
		double get_longitude();
		char get_terminal();
		Parada* get_prox();
		void exibir_listaVeiculosQuePassamPorAqui();
		void set_ID(int _ID);
		void set_codigo(int _codigo);
		void set_nv(int _nv);
		void set_latitude(double _latitude);
		void set_longitude(double _longitude);
		void set_terminal(char _terminal);
		void set_prox(Parada *p);
		void RegistraVeiculoNaParada(Veiculo *v);
};
#endif
