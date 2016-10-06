class Veiculo; //Definição prévia para que o compilador possa identificar Veiculo como um tipo
#ifndef _parada_h_
#define _parada_h_
#include <iostream>
#include <string>
#include "Veiculo.h"
using namespace std;

class Parada
{
	private:
		int ID;
		float latitude;
		float longitude;
		Veiculo* listaVeiculosQuePassamPorAqui[100];
		//Parada* prox;  // Este atributo deve ser usado somente se for implementada uma lista ENCADEADA de paradas
	public:
		Parada();		
		int get_ID();
		float get_latitude();
		float get_longitude();
		void exibir_listaVeiculosQuePassamPorAqui();
		void set_ID(int _ID);
		void set_latitude(float _latitude);
		void set_longitude(float _longitude);
		void RegistraVeiculoNaParada(Veiculo *v);
};
#endif
