#include <iostream>
#include "Material.h"

class Libro : public Material {
	//Atributos
private:
	int numPag;  //numero de paginas del libro
	string autor; // autor del libro
	//Metodos
public:
	Libro();
	Libro(int, string,int, string);
	void setNumPag(int);
	void setAutor(string);
	int getNumPag() { return numPag; }
	string getAutor() { return autor; }
	int cantidadDiasPrestamo();
	void muestraDatos();
};

Libro::Libro() {
	numPag = 0;
	autor = "";
}

Libro::Libro(int paginas, string aut, int id, string title) : Material(id,title)
{
	numPag = paginas;
	autor = aut;
}

void Libro::setNumPag(int pp)
{
	numPag = pp;
}

void Libro::setAutor(string autor)
{
	this->autor = autor;
}

int Libro::cantidadDiasPrestamo()
{
	return 10;
}

 void Libro::muestraDatos()
{
	 cout << "Titilo: " << this->getTitulo()<<endl;
	 cout << "id: " << this->getIdMaterial() << endl;
	 cout << "Numero de paginas: " << numPag<<endl;
	 cout << "Autor: " << autor << endl;
}