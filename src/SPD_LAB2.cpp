//============================================================================
// Name        : SPD_LAB2.cpp
// Author      : Mariusz
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]) {

	int n = 0; // Liczba danych
	int P[100], W[100], D[100]; //Wprowadzone dane

int Kolejnosc[100]; //kolejnosc zadan
	string s;

	ifstream data("witi.data.txt");

	while (s != "data.10:") {
		data >> s;
	}

	data >> n;

	// wczytywanie danych
	for (int i = 0; i < n; i++){
		data >> P[i] >> W[i] >> D[i];
		Kolejnosc[i] = i;
	}

	int N = pow(2,n);
	int *F = new int[N];
	int *C = new int[N];
	F[0] = 0;

	for (int SET = 1; SET < N; SET++) {
		C[SET] = 0;
		for( int i = 0, b = 1; i<n; i++, b*=2) if(SET&b) C[SET]+=P[i];  // Liczymy c dla danego zbioru
		F[SET] = 999999;
		for( int i = 0, b = 1; i<n; i++, b*=2) if(SET&b) {
			F[SET] = min(F[SET],F[SET-b] + W[i] * max(0, C[SET] - D[i]));
		//	cout << "to wynosi : " << F[SET] << endl;
		}

	}

	int minimum;
	int indeks = 0;
	int SET = pow(2,n)- 1;

 	for(int k=0; k < n; k++){
		minimum = 999999;
		for( int i = 0, b = 1; i<n; i++, b*=2) if(SET&b){
			int M_PAST = minimum;
			minimum = min(minimum ,F[SET-b] + W[i]*max(0,C[SET]-D[i]));
			if(M_PAST>minimum){
				indeks = i;
				cout << " :: " << k << " "<< F[SET-b]  << endl;
			}
		}

		SET = SET - pow(2,indeks);

		Kolejnosc[k] = indeks;


	}



	int p = pow(2,n) - 1;
	cout << " Suma witi :"  << F[p];
	cout << " Kolejnosc to: ";
	for( int i =0; i <n; i++){
		cout << Kolejnosc[i] + 1 << "  ";
	}





//	system("pause");
	return 0;

}
