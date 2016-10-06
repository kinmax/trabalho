#ifndef _lista_de_veiculos_h_
#define _lista_de_veiculos_h_
#include <iostream>
#include <string>
#include "Veiculo.h"
using namespace std;

class listaDeVeiculos
{
	private:	
		Veiculo* transporte[1008];
	public:
		listaDeVeiculos(); //Construtor		
		void carregaVeiculos(const char *_fileName); //Usa o arquivo para armazenar os veículos em um vetor
		void ListaLinhasDeOnibus(); //Exibe o vetor de veículos
		void ListaParadasDaLinha(string _linha); //Exibe as paradas de uma linha específica, na ordem em que o veículo passa por elas
};
#endif
