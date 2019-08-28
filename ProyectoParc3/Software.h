#include <iostream>
#include "Material.h"

class Software : public Material {
	//Atributos
private:
	string sistemaOper; //Nombre del sistema operativo
	//Metodos
public:
	Software();
	Software(string, int , string);
	void setSistemaOper(string);
	string getSistemaOper();
	void muestraDatos();
	int cantidadDiasPrestamo();
};

Software::Software() {
	sistemaOper = "";
}

Software::Software(string sistema, int id, string title) : Material(id,title)
{
	sistemaOper = sistema;
}

void Software::setSistemaOper(string sistema)
{
	sistemaOper = sistema;
}

string Software::getSistemaOper()
{
	return sistemaOper;
}
void Software::muestraDatos()
{
	cout << "Titulo: " << this->getTitulo()<<endl;
	cout << "id: " << this->getIdMaterial()<<endl;
	cout << "Sistema operativo: " << sistemaOper<<endl;
}

int Software::cantidadDiasPrestamo()
{
	return 1;
}

