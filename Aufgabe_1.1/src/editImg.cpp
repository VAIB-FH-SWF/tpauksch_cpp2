//=============================================================================
//             Dateiname:   editImg.cpp
//                Author:   Tim Pauksch
//      Praktikumsgruppe:   [V-08:30] - Is-VAI-B1A
//      Erstellungsdatum:   24.02.2016
//          Beschreibung:   Programmierung mit C++ 2,
//                          Aufgabe 1.1, Verwendung von Strukturen.
//                          Programm zum Lesen und manipulieren
//                          einer pgm-Datei.
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

typedef unsigned char Pixel;

//=============================================================================
// Strukturen
//=============================================================================

/*
 * Struktur zum halten der Meta- und Bildinformationen der pgm-Datei
 */
struct pgm_bild{
   char  magic[2];            // Bildtyp
   int   nx;                  // Spaltenzahl (auch Breite)
   int   ny;                  // Zeilenzahl  (auch H�he)
   int   grauwert;            // max. Grauwert
   Pixel **bild;              // Bildmatrix
};

//=============================================================================
// Funktionen
//=============================================================================

/*
 * Funktion:          Ausgabe der Metainformationen einer Struktur (F�r Test).
 * Eingabe Parameter: pgm_bild *bild - Pointer mit dem Namen 'Bild' des Typs 'pgm_bild'.
 * R�ckgabewert:      Keiner.
 */
void print_meta(pgm_bild *bild){
   cout << bild->grauwert << endl;
   cout << bild->magic[0];
   cout << bild->magic[1] << endl;
   cout << bild->nx << endl;
   cout << bild->ny << endl;
}

/*
 * Funktion:            Generierung einer Pixel-Matrix und R�ckgabe dessen Pointer.
 * Eingabe Parameter:   size_t rows    - size_t maximale Gr��e des jeweiligen Datentyps. Zeilen bzw. H�he.
 *                      size_t columns - Spalten bzw. Breite.
 * R�ckgabewert:        Pixel** m - Doppelter Pointer des Typs 'Pixel'.
 */
Pixel** new_pixel_matrix( size_t rows, size_t columns ){
   size_t   i;                         // Gr��e des �bergebenen Datentyps.
   Pixel    **m;                       // Doppelter Pointer , quasi Pointer auf Pointer.
   m  =  new Pixel*  [rows];           // Anlage eines Pointer-Arrays das die Adressen Weiterer Pointer h�lt.
   *m =  new Pixel   [rows*columns];   // Generierung eines Arrays, Typ Pixel das die L�nge aller aneinander Rows hat.
   for ( i=1; i<rows; i+=1 ){          // Zuordnung der Adressen in Abh�ngigkeit einer Zeilenl�nge.
      m[i] = m[i-1] + columns;
   }
   return m;                           // R�ckgabe des Pointers. ...Pointer-Pointers.
}

/*
 * Funktion:            L�schen der Pixel-Matrix die an der Struktur h�ngt.
 * Eingabe Parameter:   Pixel **m - Doppelter Pointer aus pgm_bild-Struktur.
 * R�ckgabewert:        Keiner.
 */
void delete_pixel_matrix( Pixel **m ){
   delete[] *m;
   delete[]  m;
}

/*
 * Funktion:            �ffnet angegebene Datei. Liest Metadaten aus Datei in
 *                      Strukturvariablen. Liest Bilddaten in Pixel-Matrix.
 * Eingabe Parameter:   pgm_bild *bild - Pointer auf pgm_bild-Struktur.
 *                      string ifs_file_name - Dateiname-String (Eingabedatei).
 * R�ckgabewert:        Keiner.
 */
void bild_lesen( pgm_bild *bild, string ifs_file_name ){

   ifstream ifs;
   int ifsInput = 0;

   ifs.open(ifs_file_name.c_str());

   if (!ifs.is_open()) {
      cerr << "\nERROR : Failed to open input file: " << ifs_file_name << endl;
      exit(1);
   }

   // Metadaten des Bildes lesen und zuordnen an Struktur.
   try{
      bild->magic[0] = ifs.get();
      bild->magic[1] = ifs.get();
      ifs >> bild->nx;
      ifs >> bild->ny;
      ifs >> bild->grauwert;

      // Pixel-Matrix f�r die �bergebene Struktur generieren.
      bild->bild = new_pixel_matrix(bild->ny,bild->nx);

      //Bilddaten einlesen
      for (int indexY = 0; indexY < bild->ny; indexY++){
         for (int indexX = 0; indexX < bild->nx; indexX++){
            ifs >> ifsInput;
            bild->bild[indexY][indexX] = ifsInput;
         }
      }
   }catch(int e){
      cout << "\ERROR : Errorcode " << e << endl;
   }
}

/*
 * Funktion:            �ffnet angegebene Datei. Schreibt Metadaten aus Struktur in
 *                      Dateikopf. Schreibt Bilddaten aus Struktur in Datei.
 * Eingabe Parameter:   pgm_bild *bild - Pointer auf pgm_bild-Struktur.
 *                      string ofs_file_name - Dateiname-String (Ausgabedatei).
 * R�ckgabewert:        Keiner.
 */
void bild_schreiben( pgm_bild *bild, string ofs_file_name ){
   ofstream ofs;
   ofs.open(ofs_file_name.c_str());

   if (!ofs.is_open()) {
      cerr << "\nERROR : Failed to open input file: " << ofs_file_name << endl;
      exit(1);
   }

   // Metadaten des Bildes in Datei schreiben.
   try{
      ofs << bild->magic[0] << bild->magic[1] << endl;
      ofs << bild->nx << endl;
      ofs << bild->ny << endl;
      ofs << bild->grauwert << endl;

      //Bilddaten schreiben
      for (int indexY = 0; indexY < bild->ny; indexY++){
         for (int indexX = 0; indexX < bild->nx; indexX++){
            ofs << setw(4) << (int)bild->bild[indexY][indexX];
         }
         ofs << endl;
      }
   }catch(int e){
      cout << "\ERROR : Errorcode " << e << endl;
   }
}

/*
 * Funktion:            Kopiert die Metadaten aus der einen Struktur in die andere.
 * Eingabe Parameter:   pgm_bild *bild1 - Pointer auf Quell-pgm_bild-Struktur.
 *                      pgm_bild *bild2 - Pointer auf Ziel-pgm_bild-Struktur.
 * R�ckgabewert:        Keiner.
 */
void kopiere_bildkopf( pgm_bild *bild1, pgm_bild *bild2 ){
   bild2->nx = bild1->nx;
   bild2->ny = bild1->ny;
   bild2->grauwert = bild1->grauwert;
   bild2->magic[0] = bild1->magic[0];
   bild2->magic[1] = bild1->magic[1];
}

/*
 * Funktion:            Zielpixel wird durch Generierung des Mittelwerts aus
 *                      Originalpixel und umliegenden gebildet.
 * Eingabe Parameter:   pgm_bild *bild1 - Pointer auf Quell-pgm_bild-Struktur.
 *                      pgm_bild *bild2 - Pointer auf Ziel-pgm_bild-Struktur.
 * R�ckgabewert:        Keiner.
 */
void glaetten( pgm_bild *bild1, pgm_bild *bild2 ){
   for (int i = 0; i < bild1->ny; i++) {
      for (int j = 0; j < bild1->nx; j++){
         int summ = 0;
         if ((i - 1 >= 0) && (j - 1 >= 0)){
            if ((i + 1 < bild1->ny) && (j + 1 < bild1->nx)){
               summ += bild1->bild[i - 1][j - 1];
               summ += bild1->bild[i - 1][j];
               summ += bild1->bild[i - 1][j + 1];

               summ += bild1->bild[i][j - 1];
               summ += bild1->bild[i][j];
               summ += bild1->bild[i][j + 1];

               summ += bild1->bild[i + 1][j - 1];
               summ += bild1->bild[i + 1][j];
               summ += bild1->bild[i + 1][j + 1];

               bild2->bild[i][j] = summ / 9;
            }
         }
      }
   }
}

/*
 * Funktion:            Umkehrung der Bildwerte in Abh�ngigkeit vom Maximalwert.
 * Eingabe Parameter:   pgm_bild *bild1 - Pointer auf Quell-pgm_bild-Struktur.
 *                      pgm_bild *bild2 - Pointer auf Ziel-pgm_bild-Struktur.
 * R�ckgabewert:        Keiner.
 */
void invertieren( pgm_bild *bild1, pgm_bild *bild2 ){
   for (int i = 0; i < bild1->ny; i++) {
      for (int j = 0; j < bild1->nx; j++) {
         bild2->bild[i][j] = bild1->grauwert - bild1->bild[i][j];
      }
   }
}

/*
 * Funktion:            Kantengl�ttung. Analoge Funktionsweise zur Funktion glaetten().
 *                      Was f�r ein fauler Kommentar -.-
 * Eingabe Parameter:   pgm_bild *bild1 - Pointer auf Quell-pgm_bild-Struktur.
 *                      pgm_bild *bild2 - Pointer auf Ziel-pgm_bild-Struktur.
 * R�ckgabewert:        Keiner.
 */
void kantenbildung( pgm_bild *bild1, pgm_bild *bild2 ){
   for (int i = 0; i < bild1->ny; i++) {
      for (int j = 0; j < bild1->nx; j++) {
         int summ = 0;
         if ((i - 1 >= 0) && (j - 1 >= 0)){
            if ((i + 1 < bild1->ny) && (j + 1 < bild1->nx)){
               summ += bild1->bild[i - 1][j - 1] * 0;
               summ += bild1->bild[i - 1][j] * -1;
               summ += bild1->bild[i - 1][j + 1] * 0;

               summ += bild1->bild[i][j - 1] * -1;
               summ += bild1->bild[i][j] * 4;
               summ += bild1->bild[i][j + 1] * -1;

               summ += bild1->bild[i + 1][j - 1] * 0;
               summ += bild1->bild[i + 1][j] * -1;
               summ += bild1->bild[i + 1][j + 1] * 0;

               bild2->bild[i][j] = abs(summ / 9);
            }
         }
      }
   }
}

/*
 * Funktion:            Ausgabe des Texts der Benutzerabfrage und einlesen der Benutzereingabe.
 * Eingabe Parameter:   Keiner.
 * R�ckgabewert:        char userInput - Benutzereingabe.
 */
char abfrage(){
   char userInput;

   cout << "Bitte w�hlen sie eine Bearbeitungsart: " << endl;
   cout << "g: Gl�ttung" << endl;
   cout << "i: Invertierung" << endl;
   cout << "k: Kantenbildung" << endl;
   cout << "e: Programm beenden" << endl;
   cout << endl;
   cout << "Auswahl: " << endl;

   cin >> userInput;
   return userInput;
}

/*
 * Funktion:            Aufruf der Manipulationsfunktionen in Abh�ngigkeit von der Benutzereingabe.
 * Eingabe Parameter:   char userInput  - Benutzereingabe.
 *                      pgm_bild *bild1 - Pointer auf Quell-pgm_bild-Struktur.
 *                      pgm_bild *bild2 - Pointer auf Ziel-pgm_bild-Struktur.
 * R�ckgabewert:        Keiner.
 */
void funktionswahl(char userInput, pgm_bild *bild1, pgm_bild *bild2 ){
   switch (userInput) {
   case 'g':
      glaetten(bild1, bild2);
      break;
   case 'i':
      invertieren(bild1, bild2);
      break;
   case 'k':
      kantenbildung(bild1, bild2);
      break;
   case 'e':
      delete_pixel_matrix(bild1->bild);
      delete_pixel_matrix(bild2->bild);
      cout << "Programm beendet." << endl;
      exit(1);
   default:
      cout << "Falsche eingabe. Bitte wiederholen" << endl;
      cin >> userInput;
      funktionswahl(userInput, bild1, bild2);
   }
}

//=============================================================================
// Hauptprogramm
//=============================================================================

int main() {
   cout << "Aufgabe 1.1 - Verwendung von Strukturen." << endl;

   // Initialisierung der Beiden Bildstrukturen.
   pgm_bild bildStruktur;
   pgm_bild bildStruktur2;

   string eingabeDatei;
   string ausgabeDatei;

   // Eingabedatei angeben
   cout << "Bitte Eingabedatei angeben." << endl;
   cin >> eingabeDatei;

   // Ausgabedatei angeben
   cout << "Bitte Ausgabedatei angeben." << endl;
   cin >> ausgabeDatei;

   // Einlesen der Metadaten und Schreiben der Bildinformationen in die erste Struktur.
   // Generierung der Pixel-Matrix f�r die erste Struktur und Zuordnung zum Pointer.
   bild_lesen(&bildStruktur, eingabeDatei);

   // Kopieren der Metadaten aus der ersten Struktur in die Zweite.
   kopiere_bildkopf(&bildStruktur, &bildStruktur2);

   // Generierung der Pixel-Matrix f�r die zweite Struktur und Zuordnung zum Pointer.
   bildStruktur2.bild = new_pixel_matrix(bildStruktur2.ny, bildStruktur2.nx);

   // Funktionswahl und eingebettete Benutzerabfrage.
   funktionswahl(abfrage(), &bildStruktur, &bildStruktur2);

   // Funktion zum Schreiben der Struktur-Bilddaten in eine Ausgabedatei.
   bild_schreiben(&bildStruktur2, ausgabeDatei);

   cout << "Vorgang abgeschlossen. Programm beendet." << endl;

   //L�schen der Bild-Matrizen
   delete_pixel_matrix(bildStruktur.bild);
   delete_pixel_matrix(bildStruktur2.bild);

   return 0;
}
