#include "Veiculo.h"
#include "Parada.h"
#include <iostream>
#include <string>
using namespace std;

Veiculo::Veiculo()
{
	int i;	
	ID = 0;
	linha = "NULL";
	nome = "NULL";
	tipo = 'N';
	for(i = 0; i < 100; i++)
	{
		listaParadasPorOndePassa[i] = NULL;
	}
}

int Veiculo::get_ID()
{
	return ID;
}

string Veiculo::get_linha()
{
	return linha;
}

string Veiculo::get_nome()
{
	return nome;
}

char Veiculo::get_tipo()
{
	return tipo;
}

void Veiculo::set_ID(int _ID)
{
	ID = _ID;
}

void Veiculo::set_linha(string _linha)
{
	linha = _linha;
}

void Veiculo::set_nome(string _nome)
{
	nome = _nome;
}

void Veiculo::set_tipo(char _tipo)
{
	tipo = _tipo;
}

void Veiculo::exibir_listaParadasPorOndePassa()
{
	int i = 0;
	while (listaParadasPorOndePassa[i] != NULL)
	{
		cout << listaParadasPorOndePassa[i]->get_ID() << endl;
	}	
}

void Veiculo::RegistraParadaNoVeiculo(Parada *p)
{
	int i = 0;
	while(listaParadasPorOndePassa[i] != NULL)
	{
		i++;
	}
	listaParadasPorOndePassa[i] = p;
}
