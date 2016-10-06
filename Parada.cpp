#include "Parada.h"
#include "Veiculo.h"
#include <iostream>
#include <string>
using namespace std;

Parada::Parada()
{
	int i;
	ID = 0;
	latitude = 0;
	longitude = 0;
	for (i = 0; i < 100; i++)
	{
		listaVeiculosQuePassamPorAqui[i] = NULL;
	}
}

int Parada::get_ID()
{
	return ID;
}

float Parada::get_latitude()
{
	return latitude;
}

float Parada::get_longitude()
{
	return longitude;
}

void Parada::exibir_listaVeiculosQuePassamPorAqui()
{
	int i = 0;
	while (listaVeiculosQuePassamPorAqui[i] != NULL)
	{
		cout << "Linha: " << listaVeiculosQuePassamPorAqui[i]->get_linha() << endl;
		cout << "Nome: " << listaVeiculosQuePassamPorAqui[i]->get_nome() << endl;
		cout << " " << endl;
		i++;
	}
}

void Parada::set_ID(int _ID)
{
	ID = _ID;
}

void Parada::set_latitude(float _latitude)
{
	latitude = _latitude;
}

void Parada::set_longitude(float _longitude)
{
	longitude = _longitude;
}

void Parada::RegistraVeiculoNaParada(Veiculo *v)
{
	int i;
	while (listaVeiculosQuePassamPorAqui[i] != NULL)
	{
		i++;
	}
	listaVeiculosQuePassamPorAqui[i] = v;
}
