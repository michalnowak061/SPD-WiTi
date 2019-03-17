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

using namespace std;

int main(int argc, char *argv[]) {
	int N = 0; // Liczba danych
	int P[100], W[100], D[100]; //Wprowadzone dane
	int C = 0, S_witi = 0;
	//int K[100]; //kolejnosc zadan
	string s;

	ifstream data("witi.data.txt");

	while (s != "data.10:") {
		data >> s;
	}

	data >> N;

	for (int i = 0; i < N; i++) {
		data >> P[i] >> W[i] >> D[i];
		//K[i] = i;
	}

	for (int i = 0; i < N; i++) {
		C += P[i];
		S_witi += W[i] * max(0, C - D[i]);

	}

	cout << " suma WITI  wynosi: " << S_witi << endl;

	system("pause");
	return 0;

}
