void listaDeParadas::listaDeParadas()
{
	locais = NULL;
}

void exibe_locais()
{
}

void carregaParadas()
{
	ifstream paradafile;
	paradafile.open(*_fileName, ios::in);
	string line;
	string ident, name, lat, lon;
	int pos, ID;
	float latitude, longitude;
	stringstream x, y, z;
	if (!linhafile.is_open())
	{
		cout << "O arquivo de paradas não pôde ser aberto" << endl;
	}
	else
	{
		paradafile.getline(paradafile, line);
		while(!paradafile.eof())
		{
			paradafile.getline(paradafile, line);
			pos = line.find(";");
			ident = line.substr(0, pos);
			x << ident;
			x >> ID;
			line.erase(0, pos+1);
			pos = line.find(";");
			name = line.substr(0, pos);
			line.erase(0, pos+1);
			pos = line.find(",");
			y << line.substr(0, pos);
			y << ".";
			line.erase(0, pos+1);
			pos = line.find(";");
			y << line.substr(0, 8);
			y >> latitude;
			line.erase(0, pos+1);
			pos = line.find(",");
			y << line.substr(0, pos);
			y << ".";
			line.erase(0, pos+1);
			pos = line.find(";");
			y << line.substr(0, 8);
			y >> longitude;

			
			
			
		}
		
	}
}
