#ifndef _lista_de_estacoes_de_bike_h_
#define _lista_de_estacoes_de_bike_h_
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include "EstacaoDeBike.h"
#include "listaDeParadas.h"
#include <iomanip>
using namespace std;

class listaDeEstacoesDeBike
{
	private:	
		EstacaoDeBike* locais;
	public:
		const double PI = 3.141592;
		listaDeEstacoesDeBike(); //Construtor		
		void carregaEstacoes(const char *_fileName); //Usa o arquivo para armazenar todas as estações de bicicleta do BikePOA em um vetor de estações
		void ListaParadasProximasDaEstacao(string estacao, listaDeParadas lst); //Mostra a parada mais próxima de uma determinada estação de bicicleta do BikePOA
		void ListaEstacoesDeBike(); //Lista todas as estações de bicicleta do BikePOA
};
#endif
