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
	string x, y, z;
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
			if(!file.eof())
			{
				pos = line.find(";");
				number = line.substr(0, pos);
				nro = atoi(number.c_str());
				line.erase(0, pos+1);
				pos = line.find(";");
				name = line.substr(0, pos);
			
				line.erase(0, pos+1);
				pos = line.find(",");
				latitude = line.substr(0, pos);
				y = latitude;
				y = y + '.';
				line.erase(0, pos+1);
				pos = line.find(";");
				latitude =  line.substr(0, 6);
				y = y + latitude;
				lat = atof(y.c_str());
				cout << lat << endl;
			
				line.erase(0, pos+1);
				pos = line.find(",");
				longitude = line.substr(0, pos);
				z = longitude;
				z = z + '.';
				line.erase(0, pos+1);
				pos = line.find(";");
				longitude = line.substr(0, 6);
				z = z + longitude;
				lon = atof(z.c_str());
				cout << lon << endl;
			
				if(locais == NULL)
				{
					locais = new EstacaoDeBike();
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
					no = new EstacaoDeBike();				
					no = locais;
					while (no->get_prox() != NULL)
					{
						no = no->get_prox();
					}
					no->set_prox(new EstacaoDeBike());
					no->set_prox(aux);
				}
			}	
		}
	}
	//aux = NULL; 
	//no = NULL;
	//delete(aux);
	//delete(no);
	file.close();
}

void listaDeEstacoesDeBike::ListaParadasProximasDaEstacao(string estacao, listaDeParadas lst)
{
	EstacaoDeBike *aux;
	Parada *prim, *no, *closest;
	aux = locais;
	double late, longe, latp, longp, menor = 10000.0, laterad, longerad, latprad, longprad, deltlat, deltlong, a, c, d;
	while(aux->get_nome() != estacao)
	{
		aux = aux->get_prox();
	}
	late = aux->get_latitude();
	longe = aux->get_longitude();
	laterad = late*(PI/180.0);
	longerad = longe*(PI/180.0);
	prim = lst.get_locais();
	no = prim;
	while (no != NULL)
	{
		latp = no->get_latitude();
		longp = no->get_longitude();
		latprad = latp*(PI/180.0);
		longprad = longp*(PI/180.0);
		deltlat = laterad - latprad;
		deltlong = longerad - longprad;
		
		a = ((powf((sin(deltlat/2.0)), 2.0) + cos(laterad)) * cos(latprad) * powf((sin(deltlong/2.0)), 2.0));
		c = 2.0 * (1.0/tan((sqrt(a))/sqrt(1.0-a)));
		d = 6731.0 * c;

		if (d < menor)
		{
			menor = d;
			closest = no;
		}
		no = no->get_prox();
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
