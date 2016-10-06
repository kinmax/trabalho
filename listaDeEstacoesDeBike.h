#ifndef _lista_de_estacoes_de_bike_h_
#define _lista_de_estacoes_de_bike_h_
#include <iostream>
#include <string>
#include "EstacaoDeBike.h"
using namespace std;

class listaDeEstacoesDeBike
{
	private:	
		EstacaoDeBike* locais[37];
	public:
		listaDeEstacoesDeBike(); //Construtor		
		void InsereEstacao(EstacaoDeBike V); //Adiciona uma estação de bicicleta do BikePOA ao vetor de estações
		void carregaEstacoes(const char *nomeArquivo); //Usa o arquivo para armazenar todas as estações de bicicleta do BikePOA em um vetor de estações
		void ListaParadasProximasDaEstacao(string estacao); //Mostra a parada mais próxima de uma determinada estação de bicicleta do BikePOA
		void ListaEstacoesDeBike(); //Lista todas as estações de bicicleta do BikePOA
};
#endif
