#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Oblicz długość uszeregowania zadań dla danej maski i liczby zadan
int Oblicz_C_dla_danej_maski(int *_Maska, int _P[], int _N) {
    
    int C = 0;
    
    // Odwrotna kolejnosc iteracji Maski ponieważ dla F(0001) 1 oznacza zadanie 1 a nie 4
    int j = _N;
    for(int i = 0; i < _N; ++i) {
        if(j == 0) break;
        j--;
        
        int pom = _Maska[j] * _P[i];
        C += pom;
    }
    
    return C;
}

// Oblicz kary dla N zadan konczacych sie w czasie C
int *Oblicz_K(int _C, int _N, int _W[], int _D[]) {
    
    int *K = new int[_N]; // tablica kar
    
    for (int i = 0; i < _N; ++i) {
        // wyliczenie kary dla i-tego zadania i podanego C zaleznego od maski
        K[i] = _W[i] * max(0, _C - _D[i] );
    }
    
    return K;
}

int Rekurencyjny_algorytm_PD() {
    
    return 0;
}

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
    
    
    
    
    
    // Utworzenie maski rozmiarem odpowiadajacej liczbie wczytanych zadan
    int *Maska = new int[N];
    
    // przykladowa maska dla data.10
    Maska[0] = 1;
    Maska[1] = 1;
    Maska[2] = 1;
    Maska[3] = 1;
    Maska[4] = 1;
    Maska[5] = 1;
    Maska[6] = 1;
    Maska[7] = 1;
    Maska[8] = 1;
    Maska[9] = 1;
    
    C = Oblicz_C_dla_danej_maski(Maska,P,N);
    
    // Utworzenie tablicy kar
    int *Kary = new int[N];
    
    // Obliczenie tablicy kar dla obliczonego C dla tej maski
    Kary = Oblicz_K(C,N,W,D);
    
    
    
    
    
    for (int i = 0; i < N; i++) {
        C += P[i];
        S_witi += W[i] * max(0, C - D[i]);
        
    }
    
	cout << "Suma WITI wynosi: " << S_witi << endl;

    delete[] Maska;
    
	system("pause");
    
	return 0;
}
