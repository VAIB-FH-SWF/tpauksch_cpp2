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
#include <iostream>           // F�r Textausgabe in Konsole
#include <fstream>            // F�r Dateiein- und ausgabe.
#include <cstdlib>            // F�r error(1).
#include <iomanip>            // F�r setw(3).

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
   int   i;                            // Gr��e des �bergebenen Datentyps.
   int    **m;                         // Doppelter Pointer , quasi Pointer auf Pointer.
   m  =  new int*  [rows];             // Anlage eines Pointer-Arrays das die Adressen Weiterer Pointer h�lt.
   *m =  new int   [rows*columns];     // Generierung eines Arrays, Typ Pixel das die L�nge aller aneinander Rows hat.
   for ( i=1; i<rows; i+=1 ){          // Zuordnung der Adressen in Abh�ngigkeit einer Zeilenl�nge.
      m[i] = m[i-1] + columns;
   }
   return m;                           // R�ckgabe des Pointers. ...Pointer-Pointers.
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
