#include "listaDeVeiculos.h"
using namespace std;

listaDeVeiculos::listaDeVeiculos()
{
	transporte = NULL;
	ult = NULL;
}

void listaDeVeiculos::carregaVeiculos(const char *_fileName)
{
	Veiculo *aux, *no;	
	ifstream linhafile;
	linhafile.open(_fileName, ios::in);
	string line, ident, linha, nome, type, idlinha, idparada;
	stringstream x, y, z, w;
	char tipo;
	int id, pos, idl, idp;
	if (!linhafile.is_open())
	{
		cout << "O arquivo linhas.csv não pôde ser aberto" << endl;
	}
	else
	{
		getline(linhafile, line); //Pular a primeira linha (cabeçalho)
		while(!linhafile.eof())
		{	
			getline(linhafile, line);		
			if(!linhafile.eof())
			{					
				
				pos = line.find(";");
				ident = line.substr(0, pos);
				id = stoi(ident);
	
				line.erase(0, pos+1);
				pos = line.find(";");
				nome = line.substr(0, pos);
				
				line.erase(0, pos+1);
				pos = line.find(";");
				linha = line.substr(0, pos);
				
				line.erase(0, pos+1);
				type = line.substr(1, 1);
				y << type;
				y >> tipo;
			
				//cout << id << endl;
				//cout << nome << endl;
				//cout << linha << endl;
				//cout << tipo << endl;
				//cout << endl << endl;

				/*Criação do veículo, definição dos atributos e inserção na lista*/			
				if (transporte == NULL)
				{
					transporte = new Veiculo();
					transporte->set_ID(id);
					transporte->set_nome(nome);
					transporte->set_linha(linha);
					transporte->set_tipo(tipo);
				}
				else
				{
					aux = new Veiculo();
					aux->set_ID(id);
					aux->set_nome(nome);
					aux->set_linha(linha);
					aux->set_tipo(tipo);
					no = new Veiculo();
					no = transporte;
					while(no->get_prox() != NULL)
					{
						no = no->get_prox();
					}
					no->set_prox(new Veiculo());
					no->set_prox(aux);
				}
			}
			
		}
	}
	ult = new Veiculo();
	ult->set_ID(aux->get_ID());
	ult->set_nome(aux->get_nome());
	ult->set_linha(aux->get_linha());
	ult->set_tipo(aux->get_tipo());
	no->set_prox(ult);
	//cout << aux->get_ID() << endl;	
	//cout << aux->get_linha() << endl;
	//cout << aux->get_nome() << endl;
	//cout << aux->get_tipo() << endl;
	linhafile.close();
	aux = no = NULL;
	//delete(aux);
	//delete(no);
		
}

void listaDeVeiculos::ListaLinhasDeOnibus()
{
	Veiculo *aux;
	aux = transporte;
	ofstream outfile("lista_linhas_de_onibus.txt");
	while(aux->get_prox() != NULL)
	{
		outfile << "ID da Linha: " << aux->get_ID() << endl;
		outfile << "Código da Linha: " << aux->get_linha() << endl;
		outfile << "Nome da Linha: " << aux->get_nome() << endl;
		if(aux->get_tipo() == 'O')
		{
			outfile << "Tipo de Veículo: Ônibus" << endl;
		}
		else
		{
			outfile << "Tipo de Veículo: Lotação" << endl;
		}
		outfile << "========================================================" << endl;
		aux = aux->get_prox();
	}
	outfile << "ID da Linha: " << ult->get_ID() << endl;
	outfile << "Código da Linha: " << ult->get_linha() << endl;
	outfile << "Nome da Linha: " << ult->get_nome() << endl;
	if(ult->get_tipo() == 'O')
	{
		outfile << "Tipo de Veículo: Ônibus" << endl;
	}
	else
	{
		outfile << "Tipo de Veículo: Lotação" << endl;
	}
	aux = NULL;
	outfile.close();
	//delete(aux);
	
}

void listaDeVeiculos::ListaParadasDaLinha(string _linha)
{
	int i, n = 0;
	Veiculo *aux;
	ofstream outfile("lista_paradas_da_linha.txt");
	aux = transporte;
	while(aux->get_linha() != _linha && aux->get_prox() != NULL)
	{
		aux = aux->get_prox();
	}
	for(i = 0; i < 100; i++)
	{
		if (aux->listaParadasPorOndePassa[i] != NULL)
		{
			n++;
		}
	}
	for(i = 0; i < n; i++)
	{
		//cout << "ID da Parada: " << aux->listaParadasPorOndePassa[i]->get_ID() << endl;
		//cout << "Código da Parada: " << aux->listaParadasPorOndePassa[i]->get_codigo() << endl;
		//cout << "Latitude da Parada: " << aux->listaParadasPorOndePassa[i]->get_latitude() << endl;
		//cout << "Longitude da Parada: " << aux->listaParadasPorOndePassa[i]->get_longitude() << endl;
		//cout << "Terminal(S/N): " << aux->listaParadasPorOndePassa[i]->get_terminal() << endl;
		//cout << "================================================" << endl;
		outfile << "ID da Parada: " << aux->listaParadasPorOndePassa[i]->get_ID() << endl;
		outfile << "Código da Parada: " << aux->listaParadasPorOndePassa[i]->get_codigo() << endl;
		outfile << "Latitude da Parada: " << aux->listaParadasPorOndePassa[i]->get_latitude() << endl;
		outfile << "Longitude da Parada: " << aux->listaParadasPorOndePassa[i]->get_longitude() << endl;
		outfile << "Terminal(S/N): " << aux->listaParadasPorOndePassa[i]->get_terminal() << endl;
		outfile << "================================================" << endl;  
	}
	aux = NULL;
	outfile.close();	
}

Veiculo* listaDeVeiculos::get_transporte()
{
	return transporte;
}

Veiculo* listaDeVeiculos::get_ult()
{
	return ult;
}
