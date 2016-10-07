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
	string line, ident, linha, nome, type;
	stringstream x;
	char tipo;
	int id, pos;
	if (!linhafile.is_open())
	{
		cout << "O arquivo de linhas não pôde ser aberto" << endl;
	}
	else
	{
		getline(linhafile, line);
		while(!linhafile.eof())
		{
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
			pos = line.find(";");
			type = line.substr(0, pos);
			x << type;
			x >> tipo;
			line.erase(0, pos+1);

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
				while(no != NULL)
				{
					no = no->get_prox()
				}
				no->set_prox(aux);
				
			}
			
		}
	}
	delete(no);
	delete(aux);	
}

void listaDeVeiculos::ListaLinhasDeOnibus()
{
	Veiculo *aux;
	aux = new Veiculo()
	aux = transporte;
	while(aux != NULL)
	{
		cout << "ID da Linha: " << aux->get_ID() << endl;
		cout << "Código da Linha: " << aux->get_linha() << endl;
		cout << "Nome da Linha: " << aux->get_nome() << endl;
		if(aux->get_tipo() == 'O')
		{
			cout << "Tipo: Ônibus" << endl;
		}
		else
		{
			cout << "Tipo: Lotação" << endl;
		}
	}
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
