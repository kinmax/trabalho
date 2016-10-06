#ifndef _lista_de_paradas_h_
#define _lista_de_paradas_h_
#include <iostream>
#include <string>
#include "Parada.h"
using namespace std;

class listaDeParadas
{
	private:	
		Parada* locais[5765];
	public:
		listaDeParadas(); //Construtor
		void exibe_locais(); //Exibe a lista de paradas		
		void carregaParadas(const char *_fileName); //Usa o arquivo para armazenar as paradas em um vetor
		void vinculaVeiculos(const char *_fileName); //Usa o arquivo para vincular os veículos às paradas
		void imprimeUsoDasParadas(); //Exibe paradas ordenadas de acordo com a quantidade de veículos que passam por elas
};
#endif
