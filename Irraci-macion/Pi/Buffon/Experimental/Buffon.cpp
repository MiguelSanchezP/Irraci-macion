/*#include <iostream>

#define longitud 6.6
#define distancia 5

using namespace std;

int obtenerValor (bool c);

int main () {
	int palillos;
	int cruces;
	cout << "Cantidad de palillos: ";
	cin >> palillos;
	cout << "Cantidad de cruces: ";
	cin >> cruces;
	pi = (2*palillosTotal*longitud)/(cruces*distancia);
}

int obtenerValor (bool c) {
	char datos [12];
	ifstream lectura;
	lectura.open("./Archivos/NumerosFuncional.txt");
	lectura.getline(datos, 12);
	lectura.close();
	int posG = 0;
	int posP = 0;
	for (int i = 0; i<12; i++) {
		if (datos[i] == '-') {
			posG = i;
		}
		if (datos[i] == '.') {
			posP = i;
		}
	}
	char coops [posG];
	char total [posP-posG-1];
	int valor = 0;
	if (c) {
		for (int i = 0; i<posG; i++) {
			coops[i]=datos[i];
		}
		for (int i = 0; i<posG; i++) {
			valor = valor*10+(coops[i]-48);
		}
	}else{
		int k = 0;
		for (int i = posG+1; i<posP; i++) {
			total[k] = datos[i];
			k++;
		}
		for (int i = 0; i<(posP-posG-1); i++) {
			valor = valor*10+(total[i]-48);
		}
	}
	return valor;
}
*/

#include <iostream>
#include <cmath>
#include <fstream>
#include <windows.h>

#define distancia 5
#define longitud 6.6
#define Pi 3.14159265397932384626433

using namespace std;

double calcularPi (int coops, int total);
void exportarAtxt(int coops, int total);
int obtenerValor (bool coops);
void exportarNums (int num1, int num2);
void aproximacion(int coops, int total);
int menu ();
void ver (int coops, int total);
void resetear ();

HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);

int main () {
	bool salir = false;
	cout.precision(10);
	while (!salir) {
		int cruces = obtenerValor (true);
		int total = obtenerValor (false);
		cout << "Aplicacion iniciada con valores: " << endl;
		cout << "Cruces: " << cruces << endl;
		cout << "Totales: " << total << endl;
		cout << "Pi aproximado: ";
		SetConsoleTextAttribute (h, BACKGROUND_GREEN|BACKGROUND_BLUE|BACKGROUND_RED|BACKGROUND_INTENSITY);
		cout << fixed << calcularPi (cruces, total) << endl;
		SetConsoleTextAttribute (h, FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
		cout << "Hay un error de ";
		SetConsoleTextAttribute (h, FOREGROUND_RED|FOREGROUND_INTENSITY);
		cout << fixed << calcularPi(cruces, total)-Pi << endl;
		SetConsoleTextAttribute (h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
		cout << endl;
		int decision = menu();
		switch (decision) {
			case 1:
				system("cls");
				aproximacion (cruces, total);
				cout << "------------------------------------------------------------------" << endl;
				break;
			case 2:
				system("cls");
				ver(cruces, total);
				cout << "------------------------------------------------------------------" << endl;
				break;
			case 3:
				system("cls");
				resetear();
				cout << "------------------------------------------------------------------" << endl;
				break;
			case 715:
				system("cls");
				salir=true;
				break;
			default:
				system("cls");
				cout << "Entrada no valida" << endl;
				cout << "------------------------------------------------------------------" << endl;
				break;
		}
	}
	return 0;
}

void aproximacion (int crucesTotal, int total) {
	int nums [5000];
	int cruces, palillos;
	cout << "Cantidad de: " << endl;
	cout << "Cruces: ";
	cin >> cruces;
	cout << "Palillos: ";
	cin >> palillos;
	exportarAtxt(crucesTotal+cruces, total+palillos);
	exportarNums(cruces, palillos);
	SetConsoleTextAttribute (h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "Todo ha sido exportado satisfactoriamente" << endl;
	SetConsoleTextAttribute (h, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
}

double calcularPi (int cruces, int total) {
	if (cruces != 0) {
		return (double)(2*total*longitud)/(cruces*distancia);
	}
	return 0;
}

void exportarAtxt (int coops, int total) {
	ofstream escritura;
	escritura.open("./Archivos/NumerosFuncional.txt", ios::trunc);
	escritura << coops << "-" << total << ".";
	escritura.close();
}

int obtenerValor (bool c) {
	char datos [12];
	ifstream lectura;
	lectura.open("./Archivos/NumerosFuncional.txt");
	lectura.getline(datos, 12);
	lectura.close();
	int posG = 0;
	int posP = 0;
	for (int i = 0; i<12; i++) {
		if (datos[i] == '-') {
			posG = i;
		}
		if (datos[i] == '.') {
			posP = i;
		}
	}
	char coops [posG];
	char total [posP-posG-1];
	int valor = 0;
	if (c) {
		for (int i = 0; i<posG; i++) {
			coops[i]=datos[i];
		}
		for (int i = 0; i<posG; i++) {
			valor = valor*10+(coops[i]-48);
		}
	}else{
		int k = 0;
		for (int i = posG+1; i<posP; i++) {
			total[k] = datos[i];
			k++;
		}
		for (int i = 0; i<(posP-posG-1); i++) {
			valor = valor*10+(total[i]-48);
		}
	}
	return valor;
}

void exportarNums (int num1, int num2) { 
	ofstream escritura;
	escritura.open("./Archivos/NumerosBonitos.txt", ios::app);
	escritura << num1 << "\t" << num2 << endl;
	escritura.close();
}

int menu () {
	int decision;
	cout << "MENU" << endl;
	cout << "----" << endl;
	cout << "1.Aproximacion" << endl;
	cout << "2.Ver datos actuales" << endl;
	cout << "3.Resetear" << endl;
	cout << "715.Salir" << endl;
	cout << "\nDecision: ";
	cin >> decision;
	return decision;
}


void resetear () {
	char decision;
	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "Estas seguro de querer resetear la aplicacion [S/N]? ";
	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cin >> decision;
	if (decision == 'S' || decision == 's') {
		ofstream escritura;
		escritura.open("./Archivos/NumerosFuncional.txt", ios::trunc);
		escritura.close();
		escritura.open("./Archivos/NumerosBonitos.txt", ios::trunc);
		escritura.close();
		SetConsoleTextAttribute (h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "Aplicacion reseteada" << endl;
		SetConsoleTextAttribute (h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	}else{
		cout << "Abortando" << endl;
	}
}

void ver (int cruces, int total) {
	cout.precision(10);
	cout << "Despues de " << total << " palillos lanzados el valor de pi es de: " << endl;
	SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << fixed << calcularPi (cruces, total) << endl;
	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "Con un error presente de: " << endl;
	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << fixed << calcularPi(cruces, total)-Pi << endl;
	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}
