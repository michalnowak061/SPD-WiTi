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

int dlugosc_uszeregowania(int etykieta, int P[]) {
	int pom = -1; // zmienna do znajdowania najwiêkszej liczby
	int c = 0;

	while (pow(2, pom + 1) <= etykieta)
		pom++; // mamy najwiêksz¹ dostêpna potêgê 2 w danym wywo³aniu

	for (int i = pom; i >= 0; i--) {

		if (etykieta >= pow(2, i)) {
			c += P[i];
			etykieta = etykieta - pow(2, i);
		}

	}

	return c;
}

int rekurencja(int etykieta, int N, int glebokosc, int P[], int W[], int D[]) {

	if (glebokosc == 0) {
		cout << " koniec !!!!!!!!!!!!!" << endl;
		return 0;
	}
	int maska = etykieta;
	int pom = -1; // zmienna do znajdowania najwiêkszej liczby

	for (int i = 0; i < glebokosc; i++) {
		while (pow(2, pom + 1) <= maska)
			pom++; // mamy najwiêksz¹ dostêpna potêgê 2 w danym wywo³aniu
		rekurencja(etykieta - pow(2, pom), N, glebokosc - 1, P, W, D);
		maska = maska - pow(2, pom);
		pom = 0;
	}

	return 0;
}

int main(int argc, char *argv[]) {
	int N = 0; // Liczba danych
	int P[100], W[100], D[100]; //Wprowadzone dane
//int C = 0,
	int S_witi = 0;
	int etykieta = 0;
//int K[100]; //kolejnosc zadan
	string s;

	ifstream data("witi.data.txt");

	while (s != "data.10:") {
		data >> s;
	}

	data >> N;

	for (int i = 0; i < N; i++) {
		data >> P[i] >> W[i] >> D[i];
	}

// liczymy sumê zamieniamy na 2^x
	for (int i = 0; i < N; i++) {
		etykieta += pow(2, i);
	}

//S_witi = rekurencja(etykieta, N,N, P, W, D );


	cout << " etykietka : " << etykieta << endl;
	cout << " S_witi : " << S_witi << endl;

	system("pause");
	return 0;

}
