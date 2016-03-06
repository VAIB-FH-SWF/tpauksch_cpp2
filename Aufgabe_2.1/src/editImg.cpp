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

using namespace std;

//=============================================================================
// Definitionen
//=============================================================================

typedef unsigned int uint;

//=============================================================================
// Strukturen
//=============================================================================


//=============================================================================
// Funktionen
//=============================================================================

int** new_pixel_matrix( int rows, int columns ){
   int   i;                            // Größe des übergebenen Datentyps.
   int    **m;                         // Doppelter Pointer , quasi Pointer auf Pointer.
   m  =  new int*  [rows];             // Anlage eines Pointer-Arrays das die Adressen Weiterer Pointer hält.
   *m =  new int   [rows*columns];     // Generierung eines Arrays, Typ Pixel das die Länge aller aneinander Rows hat.
   for ( i=1; i<rows; i+=1 ){          // Zuordnung der Adressen in Abhängigkeit einer Zeilenlänge.
      m[i] = m[i-1] + columns;
   }
   return m;                           // Rückgabe des Pointers. ...Pointer-Pointers.
}

void zufallsbelegung(int **feld, uint hoehe, uint breite){

}

uint next_generation(int **feld1, int **feld2, uint breite, uint hoehe){

}

void print_feld(int **feld, uint hoehe, uint breite){

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



   return 0;
}
