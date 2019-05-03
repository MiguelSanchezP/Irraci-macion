#include <iostream>
#include <cmath>

using namespace std;

bool sonCooprimos (int num1, int num2, int num3);
double calcularConstante (int coops, int total);

int main () {
	
	int coops = 0;
	int total = 0;
	while (true) {
	int nums [5000];
	int tempNum1, tempNum2, tempNum3;
	int ronda = 1;
	cout << "num1: ";
	cin >> tempNum1;
	cout << "num2: ";
	cin >> tempNum2;
	cout << "num3: ";
	cin >> tempNum3;
	ronda += 1;
	
		
	if (sonCooprimos(tempNum1, tempNum2, tempNum3)) {
		cout << "\nTus numeros son coops" << endl;
		coops += 1;
		total += 1;
	}else {
		cout << "\nTus numeros NO son coops" << endl;
		total += 1;
	}
	
	cout << calcularConstante (coops, total) << endl;
}
	return 0;
}

bool sonCooprimos (int num1, int num2, int num3) {
	int arrayDivsNum1 [100];
	int arrayDivsNum2 [100];
	int arrayDivsNum3 [100];
	int ronda = 1;
	for (int i=1; i<=sqrt(num1); i++) {
		if (num1%i==0) {
			arrayDivsNum1 [ronda] = i;
			ronda++;
			arrayDivsNum1 [ronda] = num1/i;
			ronda++;
			cout << num1 << ": " << i << ". "<< num1/i << endl;
		}
	}
	arrayDivsNum1[0] = ronda;
	ronda = 1;
	for (int i=1; i<=sqrt(num2); i++) {
		if (num2%i==0) {
			arrayDivsNum2 [ronda] = i;
			ronda++;
			arrayDivsNum2 [ronda] = num2/i;
			ronda++;
		}
	}
	arrayDivsNum2[0] = ronda;
	ronda = 1;
	for (int i=1; i<=sqrt(num3); i++) {
		if (num3%i==0) {
			arrayDivsNum3 [ronda] = i;
			ronda++;
			arrayDivsNum3 [ronda] = num3/i;
			ronda++;
		}
	}
	arrayDivsNum3[0] = ronda;
	ronda = 1;
	int mcd = 1;
	for (int i = 0; i<=arrayDivsNum1[0]; i++) {
		for (int j = 0; j<=arrayDivsNum2[0]; j++) {
			for (int k = 0; k<=arrayDivsNum3[0]; k++) {
				if ((arrayDivsNum1[i] == arrayDivsNum2[j])&&(arrayDivsNum2[j] == arrayDivsNum3[k])) {
					if (arrayDivsNum1[i] >= mcd) {
						mcd = arrayDivsNum1[i];
					}
				}
			}
		}
	}
	if (mcd == 1) {
		return true;
	}
	return false;
}

double calcularConstante (int coops, int total) {
	double AperyConst = (double)total/(double)coops;
	cout << AperyConst << endl;
	return AperyConst;
}
