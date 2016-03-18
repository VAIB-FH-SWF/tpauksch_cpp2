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
#include <ctime>              // F�r time().


using namespace std;

//=============================================================================
// Definitionen
//=============================================================================

const int N1 = 1;
typedef unsigned int uint;

//=============================================================================
// Strukturen
//=============================================================================

/*
 * Struktur zum halten der Dimensions-Gr��en und der Spielfeld-Matrix.
 */
struct spielfeld {
   uint   breite;
   uint   hoehe;
   int**  matrix;
};

/*
 * Struktur zum halten Metainformationen des Spiels.
 * 1. Population der Zellen
 * 2. Generationszyklus
 */
struct metainfos {
   uint   population;
   uint   zyklus;
   void   init_metainfos();
};

/*
 * Funktion:            Initialisierung der Metainfo.
 * Eingabe Parameter:   Keiner.
 * R�ckgabewert:        Keiner.
 */
void metainfos::init_metainfos() {
   population = 0;
   zyklus     = 1;
}

//=============================================================================
// Funktionen
//=============================================================================

/*
 * Funktion:            Benutzerabfrage nach der Breite und der H�he des Spielfeldes.
 *                      F�r den Spielfeldrand wird noch zweimal die Randbreite N1
 *                      addiert.
 * Eingabe Parameter:   spielfeld *spielfeld - Pointer auf Spielfeldstruktur.
 * R�ckgabewert:        Keiner.
 */
void dimensions_abfrage(spielfeld *spielfeld) {
	cout << "Bitte Feld-Dimensionen eingeben." 	<< endl;
	cout << "Bitte Breite eingeben:" 			   << endl;
	cin  >> spielfeld->breite;
	cout << "Bitte H�he eingeben:" 				   << endl;
	cin  >> spielfeld->hoehe;

	spielfeld->breite += 2*N1;
	spielfeld->hoehe  += 2*N1;
}

/*
 * Funktion:            Generierung einer Pixel-Matrix und R�ckgabe dessen Pointers.
 * Eingabe Parameter:   int hoehe    - Zeilen bzw. H�he der Matrix.
 *                      int breite   - Spalten bzw. Breite der Matrix.
 * R�ckgabewert:        Pixel** m    - Doppelter Pointer des Typs 'Pixel'.
 */
int** new_int_matrix( int hoehe, int breite ) {
   int   i;                            // Gr��e des �bergebenen Datentyps.
   int    **m;                         // Doppelter Pointer , quasi Pointer auf Pointer.
   m  =  new int*  [hoehe];            // Anlage eines Pointer-Arrays das die Adressen Weiterer Pointer h�lt.
   *m =  new int   [hoehe*breite];     // Generierung eines Arrays, Typ Pixel das die L�nge aller aneinander Rows hat.
   for ( i=1; i<hoehe; i+=1 ){         // Zuordnung der Adressen in Abh�ngigkeit einer Zeilenl�nge.
      m[i] = m[i-1] + breite;
   }
   return m;                           // R�ckgabe des Pointers.
}

/*
 * Funktion:            Belegung des Spielfeldrandes mit Nullen.
 * Eingabe Parameter:   spielfeld *spielfeld - Pointer auf Spielfeld-Struktur.
 * R�ckgabewert:        Keiner.
 */
void setze_rand(spielfeld *spielfeld) {
   for (uint i = 0; i < spielfeld->hoehe; i++) {
      if ((i < N1) || (i >= spielfeld->hoehe - N1)) {
         for (uint j = 0; j <= spielfeld->breite - N1; j++) {
            spielfeld->matrix[i][j] = 0;
         }
      } else {
         for (uint j = 0; j <= spielfeld->breite - N1; j++) {
            if ((j < N1) || (j >= spielfeld->breite - N1)) {
               spielfeld->matrix[i][j] = 0;
            }
         }
      }
   }
}

/*
 * Funktion:            Zuf�llige Belegung des Spielfeldes mit 1 und 0.
 * Eingabe Parameter:   int **feld  - Pointer der auf die Spielfeld-Matrix zeigt.
 *                      uint hoehe  - H�he des Spielfeldes.
 *                      uint breite - Breite des Spielfeldes.
 * R�ckgabewert:        Keiner.
 */
void zufallsbelegung(int **feld, uint hoehe, uint breite) {
   srand(time(0));

   for (uint i = N1; i < hoehe - N1; i++) {
      for (uint j = N1; j < breite - N1; j++) {
         feld[i][j] = rand() % 2;
      }
   }
}

/*
 * Funktion:            �berl�d die gleichnamige Funktion, so dass nur das Spielfeld
 *                      �bergeben werden muss. Initialisiert gleichzeitig die Funktion
 *                      die den Rand setzt.
 * Eingabe Parameter:   spielfeld *spielfeld - Pointer auf Spielfeld-Struktur.
 * R�ckgabewert:        Keiner.
 */
void zufallsbelegung(spielfeld *spielfeld) {
	zufallsbelegung(spielfeld->matrix, spielfeld->hoehe, spielfeld->breite);
	setze_rand(spielfeld);
}

/*
 * Funktion:            Ausgabe der Spielfeld-Matrix inklusive Tausch der Zeichen.
 * Eingabe Parameter:   int **feld  - Pointer der auf die Spielfeld-Matrix zeigt.
 *                      uint hoehe  - H�he des Spielfeldes.
 *                      uint breite - Breite des Spielfeldes.
 * R�ckgabewert:        Keiner.
 */
void print_feld(int **feld, uint hoehe, uint breite) {
   for (uint i = N1; i < hoehe - N1; i++) {
      for (uint j = N1; j < breite - N1; j++) {
         switch (feld[i][j]) {
         case 1:
            cout << setw(3) << '#';
            break;
         default:
            cout << setw(3) << '.';
            break;
         }
      }
      cout << endl;
   }
}

/*
 * Funktion:            �berl�d die gleichnamige Funktion, so dass nur das Spielfeld
 *                      �bergeben werden muss.
 * Eingabe Parameter:   spielfeld *spielfeld - Pointer auf Spielfeld-Struktur.
 * R�ckgabewert:        Keiner.
 */
void print_feld(spielfeld *spielfeld) {
   print_feld(spielfeld->matrix, spielfeld->hoehe, spielfeld->breite);
}

/*
 * Funktion:            Kopiert H�he und Breite einer Struktur auf die andere.
 * Eingabe Parameter:   spielfeld *spielfeld1 - Quell-Spielfeld-Struktur
 *                      spielfeld *spielfeld2 - Ziel-Spielfeld-Struktur
 * R�ckgabewert:        Keiner.
 */
void kopiere_struktur_kopf(spielfeld *spielfeld1, spielfeld *spielfeld2) {
   spielfeld2->breite = spielfeld1->breite;
   spielfeld2->hoehe  = spielfeld1->hoehe;
}

/*
 * Funktion:            Kopiert die Inhalte einer Spielfeld-Matrix auf die andere.
 * Eingabe Parameter:   int** feld1 - Pointer der auf die Quell-Spielfeld-Matrix zeigt.
 *                      int** feld2 - Pointer der auf die Ziel-Spielfeld-Matrix zeigt.
 *                      uint hoehe  - H�he des Spielfeldes.
 *                      uint breite - Breite des Spielfeldes.
 * R�ckgabewert:        Keiner.
 */
void kopiere_matrix(int** feld1, int** feld2, uint breite, uint hoehe) {
   for (uint i = 0; i < hoehe; i++) {
      for (uint j = 0; j < breite; j++) {
         feld2[i][j] = feld1[i][j];
      }
   }
}

/*
 * Funktion:            �berl�d die gleichnamige Funktion, so dass nur die Spielfeld-Matrizen
 *                      �bergeben werden m�ssen.
 * Eingabe Parameter:   spielfeld *spielfeld1 - Pointer auf Quell-Spielfeld-Struktur.
 *                      spielfeld *spielfeld2 - Pointer auf Ziel-Spielfeld-Struktur.
 * R�ckgabewert:        Keiner.
 */
void kopiere_matrix(spielfeld *spielfeld1, spielfeld *spielfeld2) {
   kopiere_matrix(spielfeld2->matrix, spielfeld1->matrix, spielfeld1->breite, spielfeld1->hoehe);
}

/*
 * Funktion:            Vergleicht die Inhalte der Quell-Spielfeld-Matrix mit denen der
 *                      Ziel-Spielfeld-Matrix.
 * Eingabe Parameter:   int** feld1 - Pointer der auf die Quell-Spielfeld-Matrix zeigt.
 *                      int** feld2 - Pointer der auf die Ziel-Spielfeld-Matrix zeigt.
 *                      uint hoehe  - H�he des Spielfeldes.
 *                      uint breite - Breite des Spielfeldes.
 * R�ckgabewert:        boolean - true bei Gleichheit.
 */
bool vergleiche_matrix(int** feld1, int** feld2, uint breite, uint hoehe) {
   for (uint i = 0; i < hoehe; i++) {
      for (uint j = 0; j < breite; j++) {
         if (feld1[i][j] != feld2[i][j]) {
            return false;
         };
      }
   }
   return true;
}

/*
 * Funktion:            �berl�d die gleichnamige Funktion, so dass nur die Spielfeld-Matrizen
 *                      �bergeben werden m�ssen.
 * Eingabe Parameter:   spielfeld *spielfeld1 - Pointer auf Quell-Spielfeld-Struktur.
 *                      spielfeld *spielfeld2 - Pointer auf Ziel-Spielfeld-Struktur.
 * R�ckgabewert:        boolean - true bei Gleichheit.
 */
bool vergleiche_matrix(spielfeld *spielfeld1, spielfeld *spielfeld2){
   return vergleiche_matrix(spielfeld1->matrix, spielfeld2->matrix, spielfeld1->breite, spielfeld1->hoehe);
}

/*
 * Funktion:            Z�hlt alle Stellen die mit 1 belegt sind und gibt die Summe zur�ck.
 * Eingabe Parameter:   int **feld  - Pointer der auf die Spielfeld-Matrix zeigt.
 *                      uint hoehe  - H�he des Spielfeldes.
 *                      uint breite - Breite des Spielfeldes.
 * R�ckgabewert:        uint        - Summe der Zellen.
 */
uint get_population(int **feld, uint breite, uint hoehe) {
   uint population = 0;

   for (uint i = 0; i < hoehe; i++) {
      for (uint j = 0; j < breite; j++) {
         if (feld[i][j] == 1) {
            population++;
         };
      }
   }
   return population;
}

/*
 * Funktion:            �berl�d die gleichnamige Funktion, so dass nur die Spielfeld-Matrizen
 *                      �bergeben werden m�ssen.
 * Eingabe Parameter:   spielfeld *spielfeld - Pointer auf Spielfeld-Struktur.
 * R�ckgabewert:        uint                 - Summe der Zellen.
 */
uint get_population(spielfeld *spielfeld) {
   return get_population(spielfeld->matrix, spielfeld->breite, spielfeld->hoehe);
}

/*
 * Funktion:            Belegt abh�ngig von den Werten der Quell-Spielfeld-Matrix unter
 *                      Anwendung des Spielschemas von "Game-of-Life" die Felder der
 *                      Ziel-Spielfeld-Matrix und gibt die aktuelle Population zur�ck.
 * Eingabe Parameter:   int** feld1 - Pointer der auf die Quell-Spielfeld-Matrix zeigt.
 *                      int** feld2 - Pointer der auf die Ziel-Spielfeld-Matrix zeigt.
 *                      uint hoehe  - H�he des Spielfeldes.
 *                      uint breite - Breite des Spielfeldes.
 * R�ckgabewert:        uint        - Summe der Zellen bzw. Population.
 */
uint next_generation(int **feld1, int **feld2, uint breite, uint hoehe) {
   for (uint i = N1; i < hoehe - N1; i++) {
      for (uint j = N1; j < breite - N1; j++) {

         int zelle = feld1[i][j];
         int summe = 0;

         summe += feld1[i - 1][j - 1];
         summe += feld1[i - 1][j];
         summe += feld1[i - 1][j + 1];

         summe += feld1[i][j - 1];
         summe += feld1[i][j + 1];

         summe += feld1[i + 1][j - 1];
         summe += feld1[i + 1][j];
         summe += feld1[i + 1][j + 1];

         if (zelle == 0 && summe == 3) {
            feld2[i][j] = 1;
         }

         if (zelle == 1 && summe < 2) {
            feld2[i][j] = 0;
         }

         if (zelle == 1) {
            if (summe == 3 || summe == 2) {
               feld2[i][j] = 1;
            }
         }

         if (zelle == 1 && summe > 3) {
            feld2[i][j] = 0;
         }
      }
   }
   return get_population(feld2, breite, hoehe);
}

/*
 * Funktion:            �berl�d die gleichnamige Funktion, so dass nur die Spielfeld-Matrizen
 *                      �bergeben werden m�ssen.
 * Eingabe Parameter:   spielfeld *spielfeld1 - Pointer auf Quell-Spielfeld-Struktur.
 *                      spielfeld *spielfeld2 - Pointer auf Ziel-Spielfeld-Struktur.
 * R�ckgabewert:        uint - Summe der Zellen bzw. Population.
 */
uint next_generation(spielfeld *spielfeld1, spielfeld *spielfeld2){
   return next_generation(spielfeld1->matrix, spielfeld2->matrix, spielfeld1->breite, spielfeld1->hoehe);
}

/*
 * Funktion:            Erstellt eine Spielfeld-Matrix und ordnet diese der Spielfeld-Struktur zu.
 *                      Dann wird das Spielfeld mit Nullen initialisiert.
 * Eingabe Parameter:   spielfeld *spielfeld - Pointer auf Spielfeld-Struktur.
 * R�ckgabewert:        Keiner.
 */
void init_int_matrix(spielfeld *spielfeld){
	spielfeld->matrix = new_int_matrix(spielfeld->hoehe, spielfeld->breite);

	for (uint i = 0; i < spielfeld->hoehe; i++) {
		for (uint j = 0; j < spielfeld->breite; j++) {
			spielfeld->matrix[i][j] = 0;
		}
	}
}

/*
 * Funktion:            Benutzerabfrage f�r neuen Durchlauf oder Programmende.
 * Eingabe Parameter:   Keiner.
 * R�ckgabewert:        Boolean - Bei false wird das Programm abgebrochen.
 */
bool benutzer_abfrage(){
	char input;

	cout << "Eingabem�glichkeiten:"  << endl;
	cout << "c = Neuer Zyklus"       << endl;
	cout << "q = Beenden"            << endl;
	cin  >> input;

   switch (input) {
   case 'q':
      return false;
   default:
      return true;
   }

}

/*
 * Funktion:            Diese Funktion steuert den Spielablauf. Es wird eine neue Generation erstellt
 *                      und die Population in die Metadaten geschrieben. Dann wird sowohl die Spielfeld-
 *                      Matrix als auch die Generation und die Population in der Konsole ausgegeben.
 *                      Wenn ein stabiler Zustand erreicht wird gibt die Funktion true zur�ck sonst
 *                      wird die Matrix f�r den neuen Zyklus kopiert, der Z�hler f�r den Zyklus
 *                      hochgesetzt und false zur�ck gegeben.
 * Eingabe Parameter:   metainfos *metaInfos  - Pointer f�r Struktur f�r Population und Zyklusz�hler.
 *                      spielfeld *spielfeld1 - Pointer auf Quell-Spielfeld-Struktur.
 *                      spielfeld *spielfeld2 - Pointer auf Ziel-Spielfeld-Struktur.
 * R�ckgabewert:        boolean - true bei erreichen eines stabilen Zustandes.
 */
bool verarbeitung(metainfos *metaInfos, spielfeld *spielfeld1, spielfeld *spielfeld2){
      metaInfos->population = next_generation(spielfeld1, spielfeld2);
      print_feld(spielfeld1);

      cout << "Generation: " <<  metaInfos->zyklus     << endl;
      cout << "Population: " <<  metaInfos->population << endl;
      cout << endl;

      if (vergleiche_matrix(spielfeld1, spielfeld2)){
         cout << "Stabiler Zustand erreicht." << endl;
         return true;
      }else{
         kopiere_matrix(spielfeld1, spielfeld2);
      }

      metaInfos->zyklus++;
      return false;
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

   // Deklarieren der Strukturen
   spielfeld spielfeld1;
   spielfeld spielfeld2;
   metainfos metainfos;

   // Initialisieren der Metainformationen
   metainfos.init_metainfos();

   // Dimensionen, H�he und Breite, einlesen.
   dimensions_abfrage		   (&spielfeld1);

   // Kopieren der Dimensionen auf die Zweite Spielfeld-Struktur
   kopiere_struktur_kopf	   (&spielfeld1, &spielfeld2);

   // Initialisierung der Spielfeld-Matrizen
   init_int_matrix			   (&spielfeld1);
   init_int_matrix			   (&spielfeld2);

   // Zufallsbelegung des ersten Spielfelds
   zufallsbelegung         	(&spielfeld1);

   // Eigentlicher Spielablauf
	while (benutzer_abfrage()) {
	   if (verarbeitung(&metainfos, &spielfeld1, &spielfeld2)){
	      break;
	   }
	}

	// Speicherfreigabe
   delete_int_matrix(spielfeld1.matrix);
   delete_int_matrix(spielfeld2.matrix);

   cout << "Programm beendet. " << endl;
   return 0;
}
