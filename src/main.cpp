#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Oblicz długość uszeregowania zadań dla danej maski i liczby zadan
int Oblicz_C_dla_danej_maski(int *_Maska, int _P[], int _N) {
    int C = 0;
    
    for (int i = 0; i < _N; ++i) {
        int pom = _Maska[i] * _P[i];
        C += pom;
    }
    
    return C;
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

	for (int i = 0; i < N; i++) {
		data >> P[i] >> W[i] >> D[i];
		//K[i] = i;
	}

	for (int i = 0; i < N; i++) {
		C += P[i];
		S_witi += W[i] * max(0, C - D[i]);

	}

    cout << Oblicz_C_dla_danej_maski(Maska,P,N) << endl;
    
	cout << "Suma WITI wynosi: " << S_witi << endl;

    delete[] Maska;
    
	system("pause");
    
	return 0;
}
