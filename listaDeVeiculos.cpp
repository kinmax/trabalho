#include "listaDeVeiculos.h"

listaDeVeiculos::listaDeVeiculos()
{
	transporte = NULL;
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
			/*Leitura do arquivo linhas.csv e atribuição das variáveis*/
			getline(linhafile, line);
			pos = line.find(";");
			ident = line.substr(0, pos);
			x << ident;
			x >> id;
			line.erase(0, pos+1);
			pos = line.find(";");
			nome = line.substr(0, pos);
			line.erase(0, pos+1);
			pos = line.find(";");
			linha = line.substr(0, pos);
			line.erase(0, pos+1);
			pos = line.find("\n");
			type = line.substr(0, pos);
			y << type;
			y >> tipo;
			line.erase(0, pos+1);

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
				no = transporte;
				while(no->get_prox() != NULL)
				{
					no = no->get_prox();
				}
				no->set_prox(aux);
				
			}
			
		}
	}
	aux = no = NULL;
	delete(aux);
	delete(no);
		
}

void listaDeVeiculos::ListaLinhasDeOnibus()
{
	Veiculo *aux;
	aux = new Veiculo();
	aux = transporte;
	while(aux != NULL)
	{
		cout << "ID da Linha: " << aux->get_ID() << endl;
		cout << "Código da Linha: " << aux->get_linha() << endl;
		cout << "Nome da Linha: " << aux->get_nome() << endl;
		if(aux->get_tipo() == 'O')
		{
			cout << "Tipo de Veículo: Ônibus" << endl;
		}
		else
		{
			cout << "Tipo de Veículo: Lotação" << endl;
		}
		cout << "========================================================" << endl;
	}
	aux = NULL;
	delete(aux);
	
}

void listaDeVeiculos::ListaParadasDaLinha(string _linha)
{
	int i, n = 0;
	for(i = 0; i < 100; i++)
	{
		if (transporte->listaParadasPorOndePassa[i] != NULL)
		{
			n++;
		}
	}
	for(i = 0; i < n; i++)
	{
		cout << transporte->listaParadasPorOndePassa[i]->get_ID() << endl; 
	}	
}

Veiculo* listaDeVeiculos::get_transporte()
{
	return transporte;
}
