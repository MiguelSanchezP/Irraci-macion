#include <iostream>
#include <cmath>
#include <fstream>
#include <windows.h>

using namespace std;

bool sonCooprimos (int num1, int num2, int num3);
double calcularConstante (int coops, int total);
void exportarAtxt(int coops, int total);
int obtenerValor (bool coops);
void exportarNums (int num1, int num2, int num3, int total);
void aproximacion(int coops, int total);
int menu ();
void ver (int coops, int total);
void resetear ();

HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);

int main () {
	bool salir = false;
	while (!salir) {
		int coops = obtenerValor (true);
		int total = obtenerValor (false);
		cout << "Aplicacion iniciada con valores: " << endl;
		cout << "Coprimos: " << coops << endl;
		cout << "Computados: " << total << endl;
		cout << "Valor de la constante inicial: ";
		SetConsoleTextAttribute (h, BACKGROUND_GREEN|BACKGROUND_BLUE|BACKGROUND_RED|BACKGROUND_INTENSITY);
		cout << calcularConstante (coops, total) << endl;
		SetConsoleTextAttribute (h, FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
		cout << endl;
		int decision = menu();
		switch (decision) {
			case 1:
				system("cls");
				aproximacion (coops, total);
				cout << "------------------------------------------------------------------" << endl;
				break;
			case 2:
				system("cls");
				ver(coops, total);
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

void aproximacion (int coops, int total) {
	int nums [5000];
	int tempNum1, tempNum2, tempNum3;
	cout << "Valor de:" << endl;
	cout << "Primer numero: ";
	cin >> tempNum1;
	cout << "Segundo numero: ";
	cin >> tempNum2;
	cout << "Tercer numero: ";
	cin >> tempNum3;
		
	if (sonCooprimos(tempNum1, tempNum2, tempNum3)) {
		cout << "\nLos numeros introducidos ";
		SetConsoleTextAttribute (h, FOREGROUND_GREEN | FOREGROUND_INTENSITY); 
		cout << "SI"; 
		SetConsoleTextAttribute (h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout << " son coprimos" << endl;
		coops += 1;
	}else {
		cout << "\nLos numeros introducidos ";
		SetConsoleTextAttribute (h, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "NO";
		SetConsoleTextAttribute (h, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << " son coprimos" << endl;
	}
	total += 1;
//	cout << "Despues de " << total << " iteraciones el valor de la constante es de: " << endl;
//	cout << calcularConstante (coops, total) << endl;
	exportarAtxt(coops, total);
	exportarNums(tempNum1, tempNum2, tempNum3, total);
	SetConsoleTextAttribute (h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "Todo ha sido exportado satisfactoriamente" << endl;
	SetConsoleTextAttribute (h, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
}

bool sonCooprimos (int num1, int num2, int num3) {
	int arrayDivsNum1 [100];
	int arrayDivsNum2 [100];
	int arrayDivsNum3 [100];
	int ronda = 1;
	cout << num1 << ": {";
	for (int i=1; i<=sqrt(num1); i++) {
		if (num1%i==0) {
			arrayDivsNum1 [ronda] = i;
			ronda++;
			arrayDivsNum1 [ronda] = num1/i;
			ronda++;
			cout << i << ", " << num1/i << ", ";
		}
	}
	cout << "}" << endl;
	arrayDivsNum1[0] = ronda;
	ronda = 1;
	cout << num2 << ": {";
	for (int i=1; i<=sqrt(num2); i++) {
		if (num2%i==0) {
			arrayDivsNum2 [ronda] = i;
			ronda++;
			arrayDivsNum2 [ronda] = num2/i;
			ronda++;
			cout << i << ", " << num2/i << ", ";
		}
	}
	cout << "}" << endl;
	arrayDivsNum2[0] = ronda;
	ronda = 1;
	cout << num3 << ": {";
	for (int i=1; i<=sqrt(num3); i++) {
		if (num3%i==0) {
			arrayDivsNum3 [ronda] = i;
			ronda++;
			arrayDivsNum3 [ronda] = num3/i;
			ronda++;
			cout << i << ", " << num3/i << ", ";
		}
	}
	cout << "}" << endl;
	arrayDivsNum3[0] = ronda;
	ronda = 1;
	int mcd = 1;
	for (int i = 1; i<arrayDivsNum1[0]; i++) {
		for (int j = 1; j<arrayDivsNum2[0]; j++) {
			for (int k = 1; k<arrayDivsNum3[0]; k++) {
				if ((arrayDivsNum1[i] == arrayDivsNum2[j])&&(arrayDivsNum2[j] == arrayDivsNum3[k])) {
					if (arrayDivsNum1[i] >= mcd) {
						mcd = arrayDivsNum1[i];
					}
				}
			}
		}
	}
	cout << "\nMCD (" << num1 << ", " << num2 << ", " << num3 << ") = ";
	SetConsoleTextAttribute (h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << mcd;
	SetConsoleTextAttribute (h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << endl;
	if (mcd == 1) {
		return true;
	}
	return false;
}

double calcularConstante (int coops, int total) {
	if (coops != 0) {
		return (double)total/(double)coops;
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

void exportarNums (int num1, int num2, int num3, int total) { 
	ofstream escritura;
	escritura.open("./Archivos/NumerosBonitos.txt", ios::app);
	escritura << total << ".-\t" << num1 << "\t" << num2 << "\t" << num3 << endl;
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

void ver (int coops, int total) {
	cout << "Despues de " << total << " iteraciones el valor de la constante es de: " << endl;
	SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << calcularConstante (coops, total) << endl;
	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}
