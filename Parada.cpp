#include "Parada.h"
#include "Veiculo.h"
#include <iostream>
#include <string>
using namespace std;

Parada::Parada()
{
	int i;
	nv = 0;
	ID = 0;
	latitude = 0;
	longitude = 0;
	for (i = 0; i < 100; i++)
	{
		listaVeiculosQuePassamPorAqui[i] = NULL;
	}
	prox = NULL;
}

int Parada::get_ID()
{
	return ID;
}

int Parada::get_codigo()
{
	return codigo;
}

int Parada::get_nv()
{
	return nv;
}

float Parada::get_latitude()
{
	return latitude;
}

float Parada::get_longitude()
{
	return longitude;
}

char Parada::get_terminal()
{
	return terminal;
}

Parada* Parada::get_prox()
{
	return prox;
}

void Parada::exibir_listaVeiculosQuePassamPorAqui()
{
	int i = 0;
	while (listaVeiculosQuePassamPorAqui[i] != NULL)
	{
		cout << "Linha: " << listaVeiculosQuePassamPorAqui[i]->get_linha() << endl;
		cout << "Nome: " << listaVeiculosQuePassamPorAqui[i]->get_nome() << endl;
		cout << endl;
		i++;
	}
}

void Parada::set_ID(int _ID)
{
	ID = _ID;
}

void Parada::set_codigo(int _codigo)
{
	codigo = _codigo;
}

void Parada::set_nv(int _nv)
{
	nv = _nv;
}

void Parada::set_latitude(float _latitude)
{
	latitude = _latitude;
}

void Parada::set_longitude(float _longitude)
{
	longitude = _longitude;
}

void Parada::set_terminal(char _terminal)
{
	terminal = _terminal;
}

void Parada::set_prox(Parada* p)
{
	prox = p;
}

void Parada::RegistraVeiculoNaParada(Veiculo *v)
{
	int i = 0;
	while (listaVeiculosQuePassamPorAqui[i] != NULL && i < 99)
	{
		i++;
	}
	if(i < 100)
	{
		listaVeiculosQuePassamPorAqui[i] = v;
		nv++;
	}
}
