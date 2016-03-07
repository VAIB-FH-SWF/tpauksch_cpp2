//=============================================================================
//             Dateiname:   editImg.cpp
//                Author:   Tim Pauksch
//      Praktikumsgruppe:   [V-08:30] - Is-VAI-B1A
//      Erstellungsdatum:   06.03.2016
//          Beschreibung:   Programmierung mit C++ 2,
//                          Aufgabe 1.1, The Game of Life.
//                          Programm zur Simulation einer
//                          vereinfachten Evolutionsart.
//              Compiler:   g++
//=============================================================================
#include <iostream>           // Für Textausgabe in Konsole
#include <fstream>            // Für Dateiein- und ausgabe.
#include <cstdlib>            // Für error(1).
#include <iomanip>            // Für setw(3).
#include <ctime>              // Für time().

using namespace std;

//=============================================================================
// Definitionen
//=============================================================================


typedef unsigned int uint;

//=============================================================================
// Strukturen
//=============================================================================

struct spielfeld{
   uint   breite;
   uint   hoehe;
   uint   rand;
   int** matrix;
};

//=============================================================================
// Funktionen
//=============================================================================

void dimensions_abfrage(spielfeld *spielfeld){
	spielfeld->rand = 1;

	cout << "Bitte Feld-Dimensionen eingeben." 	<< endl;
	cout << "Bitte Breite eingeben:" 			<< endl;
	cin  >> spielfeld->breite;
	cout << "Bitte Höhe eingeben:" 				<< endl;
	cin  >> spielfeld->hoehe;

	spielfeld->breite += 2*spielfeld->rand;
	spielfeld->hoehe  += 2*spielfeld->rand;
}

int** new_int_matrix( int hoehe, int breite ){
   int   i;                            // Größe des übergebenen Datentyps.
   int    **m;                         // Doppelter Pointer , quasi Pointer auf Pointer.
   m  =  new int*  [hoehe];            // Anlage eines Pointer-Arrays das die Adressen Weiterer Pointer hält.
   *m =  new int   [hoehe*breite];     // Generierung eines Arrays, Typ Pixel das die Länge aller aneinander Rows hat.
   for ( i=1; i<hoehe; i+=1 ){         // Zuordnung der Adressen in Abhängigkeit einer Zeilenlänge.
      m[i] = m[i-1] + breite;
   }
   return m;                           // Rückgabe des Pointers. ...Pointer-Pointers.
}

void zufallsbelegung(int **feld, uint hoehe, uint breite){
	srand(time(0));

	for (uint i = 0; i < hoehe; ++i) {
		for (uint j = 0; j < breite; ++j) {
			feld[i][j] = rand() % 2;
		}
	}
}

void setze_rand(spielfeld *spielfeld){
	for (uint i = 0; i < spielfeld->hoehe; i++) {
		if ((i < spielfeld->rand) || (i >= spielfeld->hoehe - spielfeld->rand)) {
			for (uint j = 0; j <= spielfeld->breite; j++) {
				spielfeld->matrix[i][j] = 0;
			}
		} else {
			for (uint j = 0; j <= spielfeld->breite; j++) {
				if ((j < spielfeld->rand) || (j >= spielfeld->breite - spielfeld->rand)) {
					spielfeld->matrix[i][j] = 0;
				}
			}
		}
	}
}

void zufallsbelegung_struktur(spielfeld *spielfeld) {
	zufallsbelegung(spielfeld->matrix, spielfeld->hoehe, spielfeld->breite);
	setze_rand(spielfeld);
}

void print_feld(int **feld, uint hoehe, uint breite){
	for (uint i = 0; i < hoehe; i++) {
		for (uint j = 0; j < breite; j++) {
			switch(feld[i][j]){
				case  1: cout << setw(3) << '#'; break;
				default: cout << setw(3) << ' '; break;
			}
		}
		cout << endl;
	}
}

void print_feld_struktur(spielfeld *spielfeld){
	print_feld(spielfeld->matrix, spielfeld->hoehe, spielfeld->breite);
}

int pruefe_nachbarn(int **feld, int position_x, int position_y){
	int summe = 0;

	summe += feld[position_x - 1][position_y - 1];
	summe += feld[position_x - 1][position_y];
	summe += feld[position_x - 1][position_y + 1];

	summe += feld[position_x][position_y - 1];
	summe += feld[position_x][position_y + 1];

	summe += feld[position_x + 1][position_y - 1];
	summe += feld[position_x + 1][position_y];
	summe += feld[position_x + 1][position_y + 1];

	if (summe == 2 || summe == 3){
		return 1;
	}else if (summe < 2 || summe > 3){
		return 0;
	}

	return 0;
}

uint next_generation(int **feld1, int **feld2, uint breite, uint hoehe){
	for (uint i = 1; i < hoehe-1; i++) { // hier auf rand achten
		for (uint j = 1; j < breite-1; j++) {

			int summe = 0;

			summe += feld1[i - 1][j - 1];
			summe += feld1[i - 1][j];
			summe += feld1[i - 1][j + 1];

			summe += feld1[i][j - 1];
			summe += feld1[i][j + 1];

			summe += feld1[i + 1][j - 1];
			summe += feld1[i + 1][j];
			summe += feld1[i + 1][j + 1];

			if (summe == 2 || summe == 3){
				feld2[i][j] = 1;
			}else if (summe < 2 || summe > 3){
				feld2[i][j] = 0;
			}

		}
	}

	return 1;
}

uint next_generation_struktur(spielfeld *spielfeld1, spielfeld *spielfeld2, int counter) {
	return next_generation(
		spielfeld1->matrix,
		spielfeld2->matrix,
		spielfeld1->hoehe,
		spielfeld1->breite
	);
}

void kopiere_struktur_kopf(spielfeld *spielfeld1, spielfeld *spielfeld2){
	spielfeld2->breite = spielfeld1->breite;
	spielfeld2->hoehe  = spielfeld1->hoehe;
	spielfeld2->rand   = spielfeld1->rand;


}

void init_int_matrix(spielfeld *spielfeld){
	spielfeld->matrix = new_int_matrix(spielfeld->hoehe, spielfeld->breite);

	for (uint i = 0; i < spielfeld->hoehe; ++i) {
		for (uint j = 0; j < spielfeld->breite; ++j) {
			spielfeld->matrix[i][j] = 0;
		}
	}
}

void delete_int_matrix(int **m){
	delete[] *m;
	delete[]  m;
}

//=============================================================================
// Hauptprogramm
//=============================================================================

int main() {
   cout << "Aufgabe 2.1 - The Game of Life." << endl;

   /*
    * Aus praktischen Gründen lege ich erst die Strukturen an und lese dann die Spielfeldgrößen ein,
    * also anders als es die Reihenfolge des Scripts vorsieht.
    */

   char input = 48;
   int counter = 0;

   spielfeld spielfeld1;
   spielfeld spielfeld2;

   dimensions_abfrage		(&spielfeld1);
   init_int_matrix			(&spielfeld1);
   kopiere_struktur_kopf	(&spielfeld1, &spielfeld2);

   init_int_matrix			(&spielfeld2);
   zufallsbelegung_struktur	(&spielfeld1);
   zufallsbelegung_struktur	(&spielfeld2);

   //while(input != 'q'){
	   counter += next_generation (spielfeld1.matrix, spielfeld2.matrix, spielfeld1.breite, spielfeld1.hoehe);
	   print_feld_struktur		(&spielfeld2);

	   cout << "Zum Abbrechhen bitte 'q' eingeben." << endl;
	   cin >> input;
	   cout << endl;
   //}

   delete_int_matrix(spielfeld1.matrix);
   delete_int_matrix(spielfeld2.matrix);

   return 0;
}
