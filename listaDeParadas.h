#ifndef _lista_de_paradas_h_
#define _lista_de_paradas_h_
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Parada.h"
#include "listaDeVeiculos.h"
#include "Veiculo.h"
#include <cstdlib>
class Parada;
class Veiculo;
using namespace std;

class listaDeParadas
{
	private:	
		Parada* locais;
	public:
		listaDeParadas(); //Construtor	
		void carregaParadas(const char *_fileName); //Usa o arquivo para armazenar as paradas em um vetor
		void vinculaVeiculos(const char *_fileName, listaDeVeiculos lst); //Usa o arquivo para vincular os veículos às paradas
		void imprimeUsoDasParadas(); //Exibe paradas ordenadas de acordo com a quantidade de veículos que passam por elas
};
#endif
