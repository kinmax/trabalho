#include "listaDeParadas.h"
#include "Parada.h"
#include "Veiculo.h"
#include <stdlib.h>
#include <cstdlib>
using namespace std;
listaDeParadas::listaDeParadas()
{
	locais = NULL;
}


void listaDeParadas::carregaParadas(const char *_fileName)
{
	ifstream paradafile;
	paradafile.open(_fileName, ios::in);
	Parada *aux, *no;
	string line;
	string ident, code, lat, lon, term;
	int pos, ID, codego;
	double latitudei, longitudei, latituded, longituded, latitude, longitude;
	char terminal;
	string x, y, z; 
	stringstream w;
	if (!paradafile.is_open())
	{
		cout << "O arquivo paradas.csv não pôde ser aberto" << endl;
	}
	else
	{
		getline(paradafile, line); //Pular a primeira linha (cabeçalho)
		while(!paradafile.eof())
		{
			/*leitura do arquivo paradas.csv e atribuição das variáveis*/			
			getline(paradafile, line);
			if(!paradafile.eof())
			{	
							
				pos = line.find(";");
				ident = line.substr(0, pos);
				ID = atoi(ident.c_str());
				line.erase(0, pos+2);
				pos = line.find(";");
				code = line.substr(0, pos-1);
				codego = atoi(code.c_str());
	
				line.erase(0, pos+1);
				pos = line.find(",");
				lon = line.substr(0, pos);
				y = lon;
				y = y + '.';
				line.erase(0, pos+1);
				pos = line.find(";");
				lon = line.substr(0, 8);				
				y = y + lon;
				longitude = atof(y.c_str());
				//cout << longitude << endl;

				line.erase(0, pos+1);
				pos = line.find(",");
				lat = line.substr(0, pos);
				z = lat;				
				z = z + '.';
				line.erase(0, pos+1);
				pos = line.find(";");
				lat = line.substr(0, 8);
				z = z + lat;
				latitude = atof(z.c_str());
				//cout << latitude << endl;
				
				line.erase(0, pos+1);
				pos = line.find("\n");
				term = line.substr(1, 1);
				w << term;
				w >> terminal;
				line.erase(0, pos+1);

				//cout << z << endl;		

				/*Criação da parada, definição dos atributos e inserção na lista*/
				if (locais == NULL)
				{
					locais = new Parada();
					locais->set_ID(ID);
					locais->set_codigo(codego);
					locais->set_longitude(longitude);
					locais->set_latitude(latitude);
					locais->set_terminal(terminal);
				}
				else
				{
					no = new Parada();					
					no = locais;
					aux = new Parada();
					aux->set_ID(ID);
					aux->set_codigo(codego);
					aux->set_longitude(longitude);
					aux->set_latitude(latitude);
					aux->set_terminal(terminal);
					while(no->get_prox() != NULL)
					{
						no = no->get_prox();
					}
					no->set_prox(aux);
				}
			}
		}
	}	
	paradafile.close();
	aux = NULL; 
	no = NULL;
	//delete(aux);
	//delete(no);
}

void listaDeParadas::vinculaVeiculos(const char *_fileName, listaDeVeiculos lst)
{
	ifstream file;
	file.open(_fileName, ios::in);
	string idlinha, idparada, line;
	stringstream x, y;
	int idl, idp, pos;
	Veiculo *aux;
	Parada *no;
	//aux = new Veiculo();
	//no = new Parada();
	aux = lst.get_transporte();
	no = locais;
	if (!file.is_open())
	{
		cout << "O arquivo paradalinha.csv não pôde ser aberto" << endl;
	}
	else
	{
		getline(file, line); //Pular a primeira linha (cabeçalho)
		while(!file.eof())
		{
			/*Leitura do arquivo paradalinha.csv e atribuição das variáveis*/
			getline(file, line);
			if(!file.eof())
			{	
				pos = line.find(";");
				idlinha = line.substr(0, pos);
				line.erase(0, pos+1);
				pos = line.find("\n");
				idparada = line.substr(0, pos);
				line.erase(0, pos+1);
				idl = atoi(idlinha.c_str());
				idp = atoi(idparada.c_str());

				//cout << idl << endl;
				//cout << idp << endl;

			
				aux = lst.get_transporte();
				no = locais;				
				while(aux->get_ID() != idl && aux->get_prox() != NULL)
				{
					//cout << idl << endl;
					aux = aux->get_prox();
					
				}
				while (no->get_ID() != idp && no->get_prox() != NULL)
				{
					//cout << idl << endl;					
					no = no->get_prox();
				}
				//cout << idl << endl;
				aux->RegistraParadaNoVeiculo(no);
				no->RegistraVeiculoNaParada(aux);
			}
		}
		//cout << idl << endl;
	}
	no = NULL;
	aux = NULL;
	//delete(aux);
	//delete(no);
	file.close();
}

void listaDeParadas::imprimeUsoDasParadas()
{
	Parada *pvet[5675], *aux, *no;
	aux = new Parada();
	no = new Parada();
	ofstream outfile("uso_paradas.txt");
	int i = 0, j;
	for (i = 0; i < 5675; i++)
	{
		pvet[i] = new Parada();
	}	
	aux = locais;
	i = 0;
	while(aux != NULL && i < 5675)
	{
		pvet[i] = aux;
		i++;
		aux = aux->get_prox();
	}
	for(i = 0; i < 5675; i++)
	{
		for(j = i+1; j < 5675; j++)
		{
			if(pvet[i]->get_nv() < pvet[j]->get_nv())
			{
				no = pvet[i];
				pvet[i] = pvet[j];
				pvet[j] = no;
			}
		}
		
	}
	for (i = 0; i < 5675; i++)
	{
		outfile << "ID da Parada: " << pvet[i]->get_ID() << endl;
		outfile << "Código da Parada: " << pvet[i]->get_codigo() << endl;
		outfile << "Longitude da Parada: " << pvet[i]->get_longitude() << endl;
		outfile << "Latitude da Parada: " << pvet[i]->get_latitude() << endl;
		outfile << "Terminal: " << pvet[i]->get_terminal() << endl;
		outfile << "==================================================================" << endl;
	}
	for(i = 0; i < 5675; i++)
	{
		pvet[i] = NULL;
		//delete(pvet[i]);
	}
	aux = no = NULL;
	outfile.close();
	//delete(aux);
	//delete(no);
}

Parada* listaDeParadas::get_locais()
{
	return locais;
}
