#include "listaDeParadas.h"
#include "Parada.h"
#include "Veiculo.h"
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
	float latitude, longitude;
	char terminal;
	stringstream x, y, z, w;
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
			pos = line.find(";");
			ident = line.substr(0, pos);
			x << ident;
			x >> ID;
			line.erase(0, pos+1);
			pos = line.find(";");
			code = line.substr(0, pos);
			w << code;
			w >> codego;	
			line.erase(0, pos+1);
			pos = line.find(",");
			y << line.substr(0, pos);
			y << ".";
			line.erase(0, pos+1);
			pos = line.find(";");
			y << line.substr(0, 8);
			y >> longitude;
			line.erase(0, pos+1);
			pos = line.find(",");
			z << line.substr(0, pos);
			z << ".";
			line.erase(0, pos+1);
			pos = line.find(";");
			z << line.substr(0, 8);
			z >> latitude;
			line.erase(0, pos+1);
			pos = line.find("\n");
			term = line.substr(0, pos);
			w << term;
			w >> terminal;
			line.erase(0, pos+1);		

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

void listaDeParadas::vinculaVeiculos(const char *_fileName, listaDeVeiculos lst)
{
	ifstream file;
	file.open(_fileName, ios::in);
	string idlinha, idparada, line;
	stringstream x, y;
	int idl, idp, pos;
	Veiculo *aux;
	Parada *no;
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
			pos = line.find(";");
			idlinha = line.substr(0, pos);
			line.erase(0, pos+1);
			pos = line.find("\n");
			idparada = line.substr(0, pos);
			line.erase(0, pos+1);
			x << idlinha;
			x >> idl;
			y << idparada;
			y >> idp;

			
			aux = lst.get_transporte();
			no = locais;				
			while(aux->get_ID() != idl)
			{
				aux = aux->get_prox();
			}
			while (no->get_ID() != idp)
			{
				no = no->get_prox();
			}
			aux->RegistraParadaNoVeiculo(no);
			no->RegistraVeiculoNaParada(aux);
			
		}
	}
}

void listaDeParadas::imprimeUsoDasParadas()
{
	Parada *pvet[5675], *aux;	
	aux = locais;
	int i = 0, j;
	while(aux != NULL)
	{
		pvet[i] = aux;
		i++;
	}
	for(i = 0; i < 5675; i++)
	{
		for(j = i+1; j < 5675; j++)
		{
			if(pvet[i]->get_nv() > pvet[j]->get_nv())
			{
				aux = pvet[i];
				pvet[i] = pvet[j];
				pvet[j] = aux;
			}
		}
		
	}
	for (i = 0; i < 5675; i++)
	{
		cout << "ID da Parada: " << pvet[i]->get_ID() << endl;
		cout << "Código da Parada: " << pvet[i]->get_codigo() << endl;
		cout << "Longitude da Parada: " << pvet[i]->get_longitude() << endl;
		cout << "Latitude da Parada: " << pvet[i]->get_latitude() << endl;
		cout << "Terminal: " << pvet[i]->get_terminal() << endl;
		cout << "==================================================================" << endl;
	}
}
