#include <iostream>
#include "Material.h"

class Disco : public Material {
	//Atributos
private:
	int duracion; //Duracion del disco
	//Metodos
public:
	Disco();
	Disco(int,int,string);
	void muestraDatos();
	int cantidadDiasPrestamo();
	void setDuracion(int);
	int getDuracion() { return duracion; }
};

Disco::Disco() {
	duracion = 0;
}
Disco::Disco(int tiempo, int id, string title) : Material (id, title)
{
	duracion = tiempo;
}
void Disco::setDuracion(int dura)
{
	duracion = dura;
}

void Disco::muestraDatos() {
	cout << "Titulo: " << this->getTitulo() << endl;
	cout << "id: " << this->getIdMaterial() << endl;
	cout <<"Duracion:"<< duracion << endl;
}

int Disco::cantidadDiasPrestamo()
{
	return 3;
}
