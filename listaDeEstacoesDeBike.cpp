#include "listaDeEstacoesDeBike.h"

listaDeEstacoesDeBike::listaDeEstacoesDeBike()
{
	locais = NULL;
}

void listaDeEstacoesDeBike::carregaEstacoes(const char *_fileName)
{
	ifstream file;
	file.open(_fileName, ios::in);
	string line, number, name, latitude, longitude;
	int nro, pos;
	float lat, lon;
	stringstream x, y, z;
	EstacaoDeBike *aux, *no;
	if (!file.is_open())
	{
		cout << "O arquivo estacoes-bikepoa.csv não pôde ser aberto" << endl;
	}
	else
	{
		getline(file, line); //Pula a primeira linha (cabeçalho)
		while(!file.eof())
		{
			getline(file, line);
			pos = line.find(";");
			number = line.substr(0, pos);
			x << number;
			x >> nro;
			line.erase(0, pos+1);
			pos = line.find(";");
			name = line.substr(0, pos);
			line.erase(0, pos+1);
			pos = line.find(",");
			latitude = line.substr(0, pos);
			y << latitude;
			y << ".";
			pos = line.find(";");
			latitude = line.substr(0, 6);
			y << latitude;
			y >> lat;
			line.erase(0, pos+1);
			pos = line.find(",");
			longitude = line.substr(0, pos);
			z << longitude;
			z << ".";
			pos = line.find("\n");
			longitude = line.substr(0, 6);
			z << longitude;
			z >> lon;
			
			if(locais == NULL)
			{
				locais->set_numero(nro);
				locais->set_nome(name);
				locais->set_latitude(lat);
				locais->set_longitude(lon);
			}
			else
			{
				aux = new EstacaoDeBike();
				aux->set_numero(nro);
				aux->set_nome(name);
				aux->set_latitude(lat);
				aux->set_longitude(lon);
				no = locais;
				while (no->get_prox() != NULL)
				{
					no = no->get_prox();
				}
				no->set_prox(aux);
			}	
		}
	}
	aux = NULL; 
	no = NULL;
	delete(aux);
	delete(no);
}

void listaDeEstacoesDeBike::ListaParadasProximasDaEstacao(string estacao, listaDeParadas lst)
{
	EstacaoDeBike *aux;
	Parada *prim, *no, *closest;
	aux = locais;
	float late, longe, latp, longp, menor = 10000.0f, laterad, longerad, latprad, longprad, deltlat, deltlong, a, c, d;
	while(aux->get_nome() != estacao)
	{
		aux = aux->get_prox();
	}
	late = aux->get_latitude();
	longe = aux->get_longitude();
	laterad = late*(PI/180.0f);
	longerad = longe*(PI/180.0f);
	prim = lst.get_locais();
	no = prim;
	while (no != NULL)
	{
		latp = no->get_latitude();
		longp = no->get_longitude();
		latprad = latp*(PI/180.0f);
		longprad = longp*(PI/180.0f);
		deltlat = laterad - latprad;
		deltlong = longerad - longprad;
		
		a = ((powf((sin(deltlat/2)), 2) + cos(laterad)) * cos(latprad) * powf((sin(deltlong/2)), 2));
		c = 2 * (1/tan((sqrt(a))/sqrt(1-a)));
		d = 6731.0f * c;

		if (d < menor)
		{
			menor = d;
			closest = no;
		}
	}
	cout << "Parada Mais Próxima" << endl;
	cout << "ID da Parada: " << closest->get_ID() << endl;
	cout << "Código da Parada: " << closest->get_codigo() << endl;
	cout << "Latitude da Parada: " << closest->get_latitude() << endl;
	cout << "Longitude da Parada: " << closest->get_longitude() << endl;
	
	closest = NULL; 
	aux = NULL;
	no = NULL;
	prim = NULL;
	delete(closest);
	delete(aux);
	delete(no);
	delete(prim);	
}

void listaDeEstacoesDeBike::ListaEstacoesDeBike()
{
	EstacaoDeBike *aux;
	aux = locais;
	while(aux != NULL)
	{
		cout << "Número da Estação: " << aux->get_numero() << endl;
		cout << "Nome da Estação: " << aux->get_nome() << endl;
		cout << "Latitude da Estação: " << aux->get_latitude() << endl;
		cout << "Longitude da Estação: " << aux->get_longitude() << endl;
		cout << "=========================================================" << endl;
		aux = aux->get_prox();
	}
	aux = NULL;
	delete(aux);
}
