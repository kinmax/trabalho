#include "listaDeVeiculos.h"

listaDeVeiculos::listaDeVeiculos()
{
	transporte = NULL;
}

void listaDeVeiculos::carregaVeiculos(const char *_fileName)
{
	Veiculo *aux, *prim, *ult;
	transporte = new Veiculo();
	aux = prim = ult = transporte;	
	ifstream linhafile;
	linhafile.open(*_fileName, ios::in);
	string line, ident, linha, nome, type;
	stringstream x;
	char tipo;
	int id;
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
			pos = line.find(";")
			linha = line.substr(0, pos);
			line.erase(0, pos+1);
			pos = line.find(";")
			type = line.substr(0, pos);
			x << type;
			x >> tipo;
			line.erase(0, pos+1);

			if (prim == NULL)
			{
				prim = new Veiculo();
				prim->set_ID(id);
				prim->set_nome(nome);
				prim->set_linha(linha);
				prim->set_tipo(tipo);
				ult = prim;
			}
			else
			{
				aux = new Veiculo();
				aux->set_ID(id);
				aux->set_nome(nome);
				aux->set_linha(linha);
				aux->set_tipo(tipo);
				ult->set_prox(aux);
				ult = aux;
			}
			
		}
	}	
}

void listaDeVeiculos::ListaLinhasDeOnibus()
{
}

void listaDeVeiculos::ListaParadasDaLinha(string _linha)
{
}
