class Parada; //Definição prévia para que o compilador possa identificar Parada como um tipo
#ifndef _veiculo_h_
#define _veiculo_h_
#include <iostream>
#include <string>
#include "Parada.h"
using namespace std;

class Veiculo
{
	private:
		int ID; //Ex.: 128104
		string linha; //Ex.: T1-1
		string nome; //Ex.: TRANSVERSAL 1
		char tipo; //L = Lotação	O = Ônibus
		Parada* listaParadasPorOndePassa[100]; //Lista de paradas por onde a linha passa, na ordem em que a linha passa
		//Veiculo* prox; // Este atributo deve ser usado somente se for implementada uma lista ENCADEADA de veículos
		//Parada *listaParadas; // Este atributo deve ser usado somente se for implementada uma lista ENCADEADA de Paradas
	public:
		Veiculo();
		int get_ID();
		string get_linha();
		string get_nome();
		char get_tipo();
		void set_ID(int _ID);
		void set_linha(string _linha);
		void set_nome(string _nome);
		void set_tipo(char _tipo);
		void exibir_listaParadasPorOndePassa();
		void RegistraParadaNoVeiculo(Parada *p);
};
#endif
