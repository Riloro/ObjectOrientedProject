/*
	Proyecto del tercer Parcial
	Ricardo López Rodríguez | A01066515 
	04/19/2018
	Este programa trata de simular un sistema de reservaciones para bibliotecas,
	en el cual los usuarios pueden consultar los distintos tipos de materiales
	que se encuentran ocupados de acuerdo a un archivo de texto, pero además
	cada usuario es capaz de reservar un nuevo tipo de material para que quede
	registrado en el sistema de biblioteca.
*/

#include<iostream>
#include<fstream>
#include<string>
#include "Material.h"
#include"Reserva.h"
#include"Libro.h"
#include"Disco.h"
#include"Software.h"
using namespace std;


/*
	Nombre: fechaInicio

	Descripcion: Esta función regresa las fechas de reserva
	de los materiales que furon solicitados por el usiario por medio
	de una fecha específica

	Parametros: sizeReserva(tamaño del array de reservas),
	idMaterial(id del material), reservas[](array de reservas).

	return: reservaras[i].getFechaReservacion() 
*/
Fecha fechaInicio(int sizeReserva, int idMaterial, Reserva reservas[]) {
	Fecha f;
	for (int i = 0; i < sizeReserva; i++)
	{
		if (reservas[i].getIdMaterial() == idMaterial) {
			f = reservas[i].getFechaReservacion();
		}
	}
	return f;
}
/*
	Nombre: fechaFin

	Descripcion: Esta función se encarga de regresa la cantidad de días
	permitida para prestar un material dependiendo de su tipo (Disco,libro,software).

	Parametros: sizeMaterial(tamaño del array de materiales),
	idMaterial(id del material), *materiales[](array de apuntadores de materiales).

	return: dias  (Cantidad de dias de prestamo pertmitidos para el material dado por si id)
*/
int fechaFin(int sizeMaterial, int idMaterial, Material *materiales[]) {
	int dias = 0;

	for (int i = 0; i < sizeMaterial;  i++)
	{
		if (idMaterial == materiales[i]->getIdMaterial()) {

			dias = materiales[i]->cantidadDiasPrestamo();
		}
	}
	return dias;
}
/*
	Nombre: nombreMaterial

	Descripcion: Esta función se encarga de buscar dentro del array de apuntadores
	de materiales el nombre de un material dependiendo de su id.

	Parametros: sizeMaterial(tamaño del array de materiales),
	idMaterial(id del material), *materiales[](array de apuntadores de materiales).

	return: nombreMaterial 
*/
string nombreMaterial(int sizeMaterial, int idMaterial, Material *materiales[]) {
	string nombreMaterial;
	for (int i = 0; i < sizeMaterial; i++)
	{
		if (idMaterial == materiales[i]->getIdMaterial()) {

			nombreMaterial = materiales[i]->getTitulo();
		}

	}
	return nombreMaterial;
}
/*
	Nombre: verificacionId

	Descripcion: Esta función se encarga verificar que el Id del material dado por el 
	usuario este dentro del archivo .txt, esto lo logra comparando el id dado anteriormente con
	cada id registrado el archivo de texto.

	Parametros: sizeMaterial(tamaño del array de materiales),
	idMaterial(id del material), *materiales[](array de apuntadores de materiales).

	return: verificación  (Regresa un true o false dependiendo si existe o no el id)
*/
bool verificacionId(int sizeMaterial, int idMaterial, Material *materiales[]) {
	bool verificacion = false;
	
	for (int  i = 0; i < sizeMaterial; i++)
	{
		if (idMaterial == materiales[i]->getIdMaterial()) {
			verificacion = true;
		}
	}

	if (verificacion == false) {
		cout << "El id no se encuentra en la base de datos :(" << endl;
	}
	return verificacion;
}
/*
	Nombre: muestraReserva

	Descripcion: Esta función se encarga de mostrar todos los materiales que no se 
	encuentran disponibles. El usuario introduce una fecha y la función compara con el rengo de fechas
	de cada material dentro del array de apuntadores.

	Parametros: reservas[](array de reservas), sizeReserva(tamaño del array de reservas),
	fecha(fecha dada por el usuario), materiales (array de apuntadores de materiales), sizeMaterial (tamaño del array de materiales).

	return: 
*/
void muestraReservas(Reserva reservas[], int sizeReserva, Fecha fecha, Material *materiales[], int sizeMaterial) {
	for (int i = 0; i < sizeReserva; i++)
	{
		if (fecha >= reservas[i].getFechaReservacion() && fecha <= reservas[i].calculaFechaFinReserva(fechaFin(sizeMaterial, reservas[i].getIdMaterial(), materiales))) {
			cout << "Nombre del material: "<<nombreMaterial(sizeMaterial, reservas[i].getIdMaterial(), materiales)<<endl;
			cout << "Id del cliente: " << reservas[i].getIdCliente() << endl;
		}
	}
}
/*
	Nombre: rangoReserva

	Descripcion: Esta función se encarga de verificar que la fecha dada por el usuario no se 
	encuentre entre el rango de una fecha ocupada por el material para reservar el material exitosamente.

	Parametros: f1 (fecha dada),
	f1(fecha en el array de cada material), materiales (array de apuntadores de materiales), sizeMaterial (tamaño del array de materiales).

	return: true o false (Dependiendo si se la fecha se encuentra en el rango de inicio y fin de el material, o no)
*/
bool rangoDeReserva(Fecha f1, Fecha f2, int idMaterial, Material *materiales[], int sizeMateriales) {
	// Con un operador ternario se evalua la fecha dada por el usuario en el rango de cada fecha del material dentro del array.
	return ((f1 >= f2 && f1 <= f2 + fechaFin(sizeMateriales, idMaterial, materiales)) || (f1 + fechaFin(sizeMateriales, idMaterial, materiales) >= f2 && f1 + fechaFin(sizeMateriales, idMaterial, materiales) <= f2 + fechaFin(sizeMateriales, idMaterial, materiales))) ? true : false;
}
/*
Nombre: reservaActual

Descripcion: Esta función se encarga de verificar que la fecha donde el usuario deseea
reservar el material no se encuentre ocupada actualmente.

Parametros: reservas[](array de reservas), sizeReserva(tamaño del array de reservas),
fecha(fecha dada por el usuario), materiales (array de apuntadores de materiales), sizeMaterial (tamaño del array de materiales).

return: true o false (Dependiendo si se la fecha se encuentra en el rango de inicio y fin de el material, o no)
*/
bool reservaActual(Reserva reservas[], int sizeReserva, Fecha fecha, Material *materiales[], int sizeMaterial, int idMaterial) {
	for (int i = 0; i < sizeReserva; i++)
	{
		if (reservas[i].getIdMaterial() == idMaterial) {
			if (rangoDeReserva(fecha, reservas[i].getFechaReservacion(), idMaterial, materiales, sizeMaterial)) {
				cout << "No se encuentra disponible en esta fehca, intentalo con otra fecha :(" << endl;
				return false;
			}
		}
	}
	return true;
}
/*
Nombre: main

Descripcion: Esta función se encarga de leer los archivos .txt, declarar cada variable que necesitrá el programa y
crear el menú donde el usuario elegira entre 6 opciones diferentes para ejecutar.

return: 0
*/
int main() {
	//Declaración de arreglos y objetos de tipo fstream.
	Material *materiales[20];
	Reserva reservaciones[50];
	ifstream material;
	ifstream reserva;
	material.open("Material.txt");
	reserva.open("Reserva.txt");
	//Se verifica que los archivos hayan sido abiertos exitosamente
	if (!material.is_open() && !reserva.is_open()) {
		cout << "Error al abrir el archivo" << endl;
	}
	else {
		int id = 0;
		string titulo = "";
		char tipo = 'w';
		string sistema = "";
		string autor = "";
		int paginaDuracion = 0;
		int sizeMaterial = 0;
		int dia = 0;
		int mes = 0;
		int year = 0;
		int idCliente = 0;
		int sizeReserva = 0;
		char opcion = 'z';
		Fecha fecha;
		Reserva nuevaReserva;
		//Este ciclo se encarga de leer cada dato dentro del archivo material.txt
		while (material >> id >> titulo >> tipo) {
			//Dependiendo del identificador del material leído en el archivo, se leeran los datos restantes
			switch (tipo)
			{
			case 'L':
				//Se lee el dato restante del archivo material, este es autor ya que es L (libro)
				material >> paginaDuracion >> autor;
				//Se crea un apuntador que apunta a un nuevo objeto de tipo libro
				materiales[sizeMaterial++] = new Libro(paginaDuracion, autor, id, titulo);
				break;
			case 'D':
				material >> paginaDuracion;
				materiales[sizeMaterial++] = new Disco(paginaDuracion, id, titulo);
				break;
			case 'S':
				material >> sistema;
				materiales[sizeMaterial++] = new Software(sistema, id, titulo);
				break;
			default:
				break;
			}
		}
		//Este ciclo se encarga de leer los datos que estan dentro del archivo reserva.txt
		while (reserva>>dia>> mes>>year>>id>>idCliente){
			//Se cre un objeto de tipo Fecha con los datos leidos
			Fecha fecha(dia,mes,year);
			//Se crea un objeto de tipo Reserva con los datos leidos
			Reserva reserva(id, idCliente, fecha);
			//se carga el array de Reservaciones con los objetos crados previamente
			reservaciones[sizeReserva] = reserva;
			sizeReserva++;
		}
		//Se creo un cilo do-while para que se repita el menu hasta que el usuario decida salir 
		do
		{
			cout << "a.- Consultar la lista de Materiales" << endl;
			cout << "b.- Consultar la lista de reservaciones" << endl;
			cout << "c.-Consultar las reservaciones de un material dado" << endl;
			cout << "d.-Consular las reservaciones de una fecha dada" << endl;
			cout << "e.-Hacer una reservación" << endl;
			cout << "f.-Terminar" << endl;
			cout << "Por favor ingresa la letra de la opcion que deseas ejeutar" << endl;
			cin >> opcion;
			//Dependiendo de la opción elegida, se ejecutara el case asignado para esta
			switch (opcion)
			{
			case 'a':
				//Este ciclo solo se encarga de mostrar los datos de cada material dentro del array materiales
				for (int i = 0; i < sizeMaterial; i++) {
					materiales[i]->muestraDatos();
					cout << endl;
				}
				break;
			case 'b':
				//Este ciclo se encarga de mostar todos los datos de las reservaciones que se encuentran dentro del su array
				for (int j = 0; j < sizeReserva; j++)
				{
					cout << "Fecha inicio: "<<reservaciones[j].getFechaReservacion()<< endl;
					cout <<"Id cliente: "<< reservaciones[j].getIdCliente() << endl; 
					cout <<"Nombre Material: "<< nombreMaterial(sizeMaterial, reservaciones[j].getIdMaterial(), materiales)<<endl;
					cout << "Fecha de entrega: " << reservaciones[j].getFechaReservacion() + fechaFin(sizeMaterial, reservaciones[j].getIdMaterial(), materiales)<<endl;
					cout << endl;
					cout << "-------------------------------------------------------------------------" << endl;
				}
				break;
			case 'c':	
				//Se crea un cilo para que el usuario no pueda salir hasta que ponga un id de material valido
				do{
					cout << "Ingresa el id del material para mostrar su informacion de reserva" << endl;
					cin >> id;

				} while (!verificacionId(sizeMaterial, id, materiales));
				//Si el id fue verificado se muestran todos los tados del material dado por el usuario
				cout <<"Nombre material: "<< nombreMaterial(sizeMaterial, id, materiales)<<endl;
				cout << "Fecha de inicio: " << fechaInicio(sizeReserva, id, reservaciones) << endl;
				cout << "Fecha de entrega: " << fechaInicio(sizeReserva, id, reservaciones) + fechaFin(sizeMaterial, id, materiales) << endl;
				break;
			case 'd':
				//El usuario da una fecha para mostrar todos lo materiales que se encuentran ocupados en esta
				cout << "Ingresa la fecha para ver las reservaciones echas en esta" << endl;
				cin >> fecha;
				//se manda llamar a la funcion muestraReservas para que muestre los materiales ocupados
				muestraReservas(reservaciones, sizeReserva, fecha, materiales, sizeMaterial);
				break;
			case 'e':
				//En esta opcion el usuario es capaz de realizar su propia reserva de un material existente dentro del archivo de texto
				cout << "Ingresa tu id de Cliente" << endl;
				cin >> idCliente;
				//Este ciclo se repite hasta que el usuario haya ingresado un id de material que si existe
				do {
					cout << "Ingresa el id del material del material que deseeas reservar" << endl;
					cin >> id;
				} while (!verificacionId(sizeMaterial,id,materiales));
				//Este ciclo se repite hasta que el usuario haya ingresado una fecha donde el material se encuentra libre
				do {
					cout << "Ingresa la fecha en la que quieres reservar" << endl;
					cin >> fecha;
				} while (!reservaActual(reservaciones,sizeReserva,fecha,materiales,sizeMaterial,id));
				cout << "Recervacion Exitosa :)" << endl;
				//Se carga la reserva echa por el usuario al array de reservaciones

				nuevaReserva.setFechaReservacion(fecha);
				nuevaReserva.setIdCliente(idCliente);
				nuevaReserva.setIdMaterial(id);
				reservaciones[sizeReserva++] = nuevaReserva;
				
				break;
			case 'f':
				
				break;
			default:
				break;
			}
		} while (opcion != 'f');
	}
	//se cierran los archivos .txt
	material.close();
	reserva.close();
	cin.get();
	return 0;

}





