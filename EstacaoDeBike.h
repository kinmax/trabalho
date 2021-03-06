#ifndef _estacao_de_bike_h_
#define _estacao_de_bike_h_
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class EstacaoDeBike
{
	private:
		int numero;
		string nome;
		float latitude;
		float longitude;
		EstacaoDeBike* prox; // Este atributo deve ser usado somente se for implementada uma lista ENCADEADA de estações
	public:
		EstacaoDeBike();
		int get_numero();
		string get_nome();
		float get_latitude();
		float get_longitude();
		EstacaoDeBike* get_prox();
		void set_numero(int _numero);
		void set_nome(string _nome);
		void set_latitude(float _latitude);
		void set_longitude(float _longitude);
		void set_prox(EstacaoDeBike* e);
};
#endif
