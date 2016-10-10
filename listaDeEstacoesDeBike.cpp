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
				//cout << lat << endl;
			
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
				//cout << lon << endl;
			
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
	aux = NULL; 
	no = NULL;
	//delete(aux);
	//delete(no);
	file.close();
}

void listaDeEstacoesDeBike::ListaParadasProximasDaEstacao(string estacao, listaDeParadas lst)
{
	EstacaoDeBike *aux;
	Parada *prim, *no, *closest;
	ofstream outfile("parada_proxima.txt");
	aux = locais;
	int i = 0, n = 0;
	double late, longe, latp, longp, menor = 1000000000000.0, laterad, longerad, latprad, longprad, deltlat, deltlong, a, c, d;
	while(aux->get_nome() != estacao)
	{
		aux = aux->get_prox();
	}
	
	//cout << aux->get_latitude() << endl;
	//cout << aux->get_longitude() << endl;

	late = aux->get_latitude();
	longe = aux->get_longitude();
	laterad = late*(0.01745);
	longerad = longe*(0.01745);
	prim = lst.get_locais();
	no = prim;
	
	//cout << no->get_latitude() << endl;
	//cout << no->get_longitude() << endl;
	while (no != NULL)
	{
		latp = no->get_latitude();
		longp = no->get_longitude();
		//cout << longp << endl;
		latprad = latp*(0.01745);
		longprad = longp*(0.01745);
		//cout << longprad << endl;
		//cout << latprad << endl;
		//cout << laterad << endl;
		//cout << longerad << endl;
		deltlat = laterad - latprad;
		deltlong = longerad - longprad;
		deltlat = abs(deltlat);
		deltlong = abs(deltlong);
		//cout << deltlat << endl;
		//cout << deltlong << endl;
		cout << fixed;
		cout << setprecision(9) << showpoint;
		//cout << sin(deltlat/2)*sin(deltlat/2) << endl;
		
		a = (pow((sin(deltlat/2.0)), 2.0) + cos(laterad)) * cos(latprad) * pow((sin(deltlong/2.0)), 2.0);
		c = 2.0 * (1.0/tan((sqrt(a))/sqrt(1.0-a)));
		d = 6731.0 * c;
		//cout << d << endl;

		if (d < menor)
		{
			menor = d;
			closest = no;
		}
		no = no->get_prox();
		//cout << no->get_latitude() << endl;
		//cout << no->get_longitude() << endl;
	}
	//cout << no->get_latitude() << endl;
	//cout << no->get_longitude() << endl;
	outfile << "Parada Mais Próxima" << endl;
	outfile << "ID da Parada: " << closest->get_ID() << endl;
	outfile << "Código da Parada: " << closest->get_codigo() << endl;
	outfile << "Latitude da Parada: " << closest->get_latitude() << endl;
	outfile << "Longitude da Parada: " << closest->get_longitude() << endl;
	
	outfile << endl << endl;
	outfile << "Linhas que passam por esta parada: " << endl;
	for (i = 0; i < 100; i++)
	{
		if (closest->listaVeiculosQuePassamPorAqui[i] != NULL)
		{
			n++;
		}
	}
	for(i = 0; i < n; i++)
	{
		outfile << "ID da Linha: " << closest->listaVeiculosQuePassamPorAqui[i]->get_ID() << endl;
		outfile << "Código da Linha: " << closest->listaVeiculosQuePassamPorAqui[i]->get_linha() << endl;
		outfile << "Nome da Linha: " << closest->listaVeiculosQuePassamPorAqui[i]->get_nome() << endl;
		outfile << "Tipo de Veículo: " << closest->listaVeiculosQuePassamPorAqui[i]->get_tipo() << endl;
		outfile << "===========================================================================" << endl;
	}
	
	closest = NULL; 
	aux = NULL;
	no = NULL;
	prim = NULL;
	outfile.close();
	//delete(closest);
	//delete(aux);
	//delete(no);
	//delete(prim);	
}

void listaDeEstacoesDeBike::ListaEstacoesDeBike()
{
	EstacaoDeBike *aux;
	aux = locais;
	ofstream outfile("lista_estacoes_de_bike.txt");
	while(aux != NULL)
	{
		outfile << "Número da Estação: " << aux->get_numero() << endl;
		outfile << "Nome da Estação: " << aux->get_nome() << endl;
		outfile << "Latitude da Estação: " << aux->get_latitude() << endl;
		outfile << "Longitude da Estação: " << aux->get_longitude() << endl;
		outfile << "=========================================================" << endl;
		aux = aux->get_prox();
	}
	outfile.close();
	aux = NULL;
	//delete(aux);
}
