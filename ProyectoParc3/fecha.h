#include<iostream>
#include<string>
using namespace std;

class Fecha {
private:
	int dd;
	int mm;
	int aa;
	bool esBiciesto(int);
	string nombreMes(int);

public:
	Fecha();
	Fecha(int, int, int);
	int getDia() { return dd; }
	int getAnio() { return aa; }
	int getMes() { return mm; }
	void setFecha(int d, int m, int a) { dd = d; mm = m; aa = a; }
	friend bool operator >(Fecha, Fecha);
	friend bool operator >= (Fecha, Fecha);
	friend bool operator <(Fecha, Fecha);
	friend bool operator <= (Fecha, Fecha);
	friend bool operator == (Fecha, Fecha);
    friend Fecha operator + (Fecha,int);
	friend istream& operator >> (istream &is,Fecha &dato);
	friend ostream& operator << (ostream &os, Fecha dato);	
};



Fecha::Fecha() {
	dd = 1;
	mm = 1;
	aa = 0;
}

Fecha::Fecha(int dd, int mm, int aa) {
	this->dd = dd;
	this->mm = mm;
	this->aa = aa;
}

bool operator > (Fecha f1, Fecha f2) {

	if (f1.aa > f2.aa) {
		return true;
	}
	else if (f1.aa == f2.aa)
	{
		if (f1.mm > f2.mm) {
			return true;
		}
		else if (f1.mm == f2.mm)
		{
			return f1.dd > f2.dd ? true : false;
		}
		else {
			return false;
		}
	}
	else
	{
		return false;
	}


}

bool operator < (Fecha f1, Fecha f2) {

	if (f1.aa < f2.aa) {
		return true;
	}
	else if (f1.aa == f2.aa)
	{
		if (f1.mm < f2.mm) {
			return true;
		}
		else if (f1.mm == f2.mm)
		{
			return f1.dd < f2.dd ? true : false;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}


bool operator ==(Fecha f1, Fecha f2) {

	return (f1.aa == f2.aa && f1.mm == f2.mm == f1.dd == f2.dd) ? true : false;
	
}

istream& operator>>(istream &is, Fecha &f)
{
	is >> f.dd;
	is >> f.mm;
	is >> f.aa;

	return is;
}



string Fecha::nombreMes(int mes) {
	string palabra = "";

	switch (mes){
	case 1:
		palabra =  "Ene";
		break;
	case 2:
		palabra = "Feb";
		break;
	case 3:
		palabra = "Mar";
		break;
	case 4:
		palabra = "Abr";
		break;
	case 5:
		palabra = "May";
		break;
	case 6:
		palabra = "Jun";
		break;
	case 7:
		palabra = "Jul";
		break;
	case 8:
		palabra = "Ago";
		break;
	case 9:
		cout << "Sept";
		break;
	case 10:
		palabra = "Oct";
		break;
	case 11:
		palabra = "Nov";
		break;
	case 12:
		palabra = "Dic";
		break;

	default:
		break;
	}

	return palabra;

}
ostream& operator<<(ostream &os, Fecha f) {
	int opcion = f.mm;
	
	os << f.dd << "/" << f.nombreMes(f.mm)<< "/" << f.aa;

	return os;

}

bool operator <=(Fecha f1, Fecha f2) {

	return (f1 < f2 || f1 == f2) ? true : false;
}

bool operator >=(Fecha f1, Fecha f2) {

	return (f1 > f2 || f1 == f2) ? true : false;
}

bool Fecha:: esBiciesto(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		return true;
	}
	return false;
}

Fecha operator + (Fecha f1, int numeroEntero)
{
	Fecha f3;
	f3 = f1;

	switch (f1.mm) {
	case 1:
		if (f1.dd + numeroEntero <= 31)
		{
			f3.dd = f1.dd + numeroEntero;
		}
		else
		{
			int restantesDias = 31 - f1.dd;
			numeroEntero = numeroEntero - restantesDias;
			f3.mm = 2;
			f3.dd = numeroEntero;
		}
		break;
	case 2:
		if (f1.esBiciesto(f1.aa))
		{
			if (f1.dd + numeroEntero <= 29)
			{
				f3.dd = f1.dd + numeroEntero;
			}
			else
			{
				int restantesDias = 29 - f1.dd;
				numeroEntero = numeroEntero - restantesDias;
				f3.mm = 3;
				f3.dd = numeroEntero;
			}
		}
		else
		{
			if (f1.dd + numeroEntero <= 28)
			{
				f3.dd = f1.dd + numeroEntero;
			}
			else
			{
				int restantesDias = 28 - f1.dd;
				numeroEntero = numeroEntero - restantesDias;
				f3.mm = 3;
				f3.dd = numeroEntero;
			}
		}
		break;
	case 3:
		if (f1.dd + numeroEntero <= 31)
		{
			f3.dd = f1.dd + numeroEntero;
		}
		else
		{
			int restantesDias = 31 - f1.dd;
			numeroEntero = numeroEntero - restantesDias;
			f3.mm = 4;
			f3.dd = numeroEntero;
		}
		break;
	case 4:
		if (f1.dd + numeroEntero <= 30)
		{
			f3.dd = f1.dd + numeroEntero;
		}
		else
		{
			int restantesDias = 30 - f1.dd;
			numeroEntero = numeroEntero - restantesDias;
			f3.mm = 5;
			f3.dd = numeroEntero;
		}
		break;
	case 5:
		if (f1.dd + numeroEntero <= 31)
		{
			f3.dd = f1.dd + numeroEntero;
		}
		else
		{
			int restantesDias = 31 - f1.dd;
			numeroEntero = numeroEntero - restantesDias;
			f3.mm = 6;
			f3.dd = numeroEntero;
		}
		break;
	case 6:
		if (f1.dd + numeroEntero <= 30)
		{
			f3.dd = f1.dd + numeroEntero;
		}
		else
		{
			int restantesDias = 30 - f1.dd;
			numeroEntero = numeroEntero - restantesDias;
			f3.mm = 7;
			f3.dd = numeroEntero;
		}
		break;
	case 7:
		if (f1.dd + numeroEntero <= 31)
		{
			f3.dd = f1.dd + numeroEntero;
		}
		else
		{
			int restantesDias = 31 - f1.dd;
			numeroEntero = numeroEntero - restantesDias;
			f3.mm = 8;
			f3.dd = numeroEntero;
		}
		break;
	case 8:
		if (f1.dd + numeroEntero <= 31)
		{
			f3.dd = f1.dd + numeroEntero;
		}
		else
		{
			int restantesDias = 31 - f1.dd;
			numeroEntero = numeroEntero - restantesDias;
			f3.mm = 9;
			f3.dd = numeroEntero;
		}
		break;
	case 9:
		if (f1.dd + numeroEntero <= 30)
		{
			f3.dd = f1.dd + numeroEntero;
		}
		else
		{
			int restantesDias = 30 - f1.dd;
			numeroEntero = numeroEntero - restantesDias;
			f3.mm = 10;
			f3.dd = numeroEntero;
		}
		break;
	case 10:
		if (f1.dd + numeroEntero <= 31)
		{
			f3.dd = f1.dd + numeroEntero;
		}
		else
		{
			int restantesDias = 31 - f1.dd;
			numeroEntero = numeroEntero - restantesDias;
			f3.mm = 11;
			f3.dd = numeroEntero;
		}
		break;
	case 11:
		if (f1.dd + numeroEntero <= 30)
		{
			f3.dd = f1.dd + numeroEntero;
		}
		else
		{
			int restantesDias = 30 - f1.dd;
			numeroEntero = numeroEntero - restantesDias;
			f3.mm = 12;
			f3.dd = numeroEntero;
		}
		break;
	case 12:
		if (f1.dd + numeroEntero <= 31)
		{
			f3.dd = f1.dd + numeroEntero;
		}
		else
		{
			int restantesDias = 31 - f1.dd;
			numeroEntero = numeroEntero - restantesDias;
			f3.mm = 1;
			f3.dd = numeroEntero;
			f3.aa = f1.aa + 1;
		}
		break;

	default:

		break;
	}
	return f3;

}

