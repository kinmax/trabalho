#include "EstacaoDeBike.h"

EstacaoDeBike::EstacaoDeBike()
{
	numero = 0;
	nome = "NULL";
	latitude = 0;
	longitude = 0;
	prox = NULL;
}

int EstacaoDeBike::get_numero()
{
	return numero;
}

string EstacaoDeBike::get_nome()
{
	return nome;
}

float EstacaoDeBike::get_latitude()
{
	return latitude;
}

float EstacaoDeBike::get_longitude()
{
	return longitude;
}

EstacaoDeBike* EstacaoDeBike::get_prox()
{
	return prox;
}

void EstacaoDeBike::set_numero(int _numero)
{
	numero = _numero;
}

void EstacaoDeBike::set_nome(string _nome)
{
	nome = _nome;
}

void EstacaoDeBike::set_latitude(float _latitude)
{
	latitude = _latitude;
}

void EstacaoDeBike::set_longitude(float _longitude)
{
	longitude = _longitude;
}

void EstacaoDeBike::set_prox(EstacaoDeBike* e)
{
	prox = e;
}
