#include <iostream>
#include <cmath>

using namespace std;

bool sonCooprimos (int num1, int num2, int num3);
double calcularConstante (int coops, int total);

int main () {
	int ronda = 1;
	int coops = 0;
	int total = 0;
	while (true) {
		int nums [5000];
		int tempNum1, tempNum2, tempNum3;
		cout << "num1: ";
		cin >> tempNum1;
		cout << "num2: ";
		cin >> tempNum2;
		cout << "num3: ";
		cin >> tempNum3;
			
		if (sonCooprimos(tempNum1, tempNum2, tempNum3)) {
			cout << "\nLos numeros introducidos son coprimos" << endl;
			coops += 1;
		}else {
			cout << "\nLos numeros introducidos NO son coprimos" << endl;
		}
		total += 1;
		cout << "Despues de " << ronda << " iteraciones el valor de la constante es de: " << endl;
		cout << calcularConstante (coops, total) << endl;
		ronda+=1;
	}
	return 0;
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
//						cout << "LLegado con val " << arrayDivsNum1[i] << endl;
						mcd = arrayDivsNum1[i];
					}
				}
			}
		}
	}
	cout << "\nMCD (" << num1 << ", " << num2 << ", " << num3 << ") = " << mcd << endl;
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
