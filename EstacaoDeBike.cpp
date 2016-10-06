#include "EstacaoDeBike.h"

EstacaoDeBike::EstacaoDeBike()
{
	ID = 0;
	nome = "NULL";
	latitude = 0;
	longitude = 0;
}

int EstacaoDeBike::get_ID()
{
	return ID;
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

void EstacaoDeBike::set_ID(int _ID)
{
	ID = _ID;
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
