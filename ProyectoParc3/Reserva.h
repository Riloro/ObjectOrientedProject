#include<iostream>
#include"fecha.h"
using namespace std;

class Reserva {
private:
	int idMaterial;
	int idCliente;
	Fecha fechaReservacion;


public:
	Reserva();
	Reserva(int, int, Fecha);
	void setIdMaterial(int);
	int getIdMaterial() { return idMaterial; }
	void setIdCliente(int);
	int getIdCliente() { return idCliente; }
	void setFechaReservacion(Fecha);
	Fecha getFechaReservacion() { return fechaReservacion; }
	Fecha calculaFechaFinReserva(int);
};

Reserva::Reserva() {
	Fecha fecha;
	idCliente = 0;
	idMaterial = 0;
	fechaReservacion = fecha;
}

Reserva::Reserva(int idM, int idC, Fecha f) {

	idMaterial = idM;
	idCliente = idC;
	fechaReservacion = f;
}

void Reserva::setFechaReservacion(Fecha f) {
	fechaReservacion = f;
}

void Reserva::setIdCliente(int id) {
	idCliente = id;
}

Fecha Reserva::calculaFechaFinReserva(int dias) {
	Fecha regreso;
	regreso = fechaReservacion + dias;
	return regreso;
}

void Reserva::setIdMaterial(int id) {
	idMaterial = id;
}