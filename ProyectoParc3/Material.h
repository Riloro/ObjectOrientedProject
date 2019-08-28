/*
	Ricardo López Rodríguez | A01066515
	04-03-2018
	Clases de Proyecto #3
*/

#ifndef MATERIAL_H
#define MATERIAL_H



#include <iostream>
#include <string>
using namespace std;
//Calse abstracta
class Material {
protected:
	int idMaterial; // id del Material
	string titulo; //Nombre del material
public:
	Material();
	Material(int, string);
	void setIdMaterial(int);
	void setTitulo(string);
	int getIdMaterial() { return idMaterial; }
	string getTitulo() { return titulo; }
	virtual void muestraDatos() = 0;
	virtual int cantidadDiasPrestamo() = 0;
};

Material::Material() {
	idMaterial = 0;
	titulo = "";
}

Material::Material(int idMaterial, string titulo)
{
	this->idMaterial = idMaterial;
	this->titulo = titulo;
}

void Material::setIdMaterial(int material)
{
	idMaterial = material;
}

void Material::setTitulo(string title)
{
	titulo = title;
}

#endif // !1