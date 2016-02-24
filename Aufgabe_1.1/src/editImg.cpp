//=============================================================================
//              Filename:   editImg.cpp
//
//          Beschreibung:   Programmierung mit C++ 2,
//                          Aufgabe 1.1,
//                          Verwendung von Strukturen.
//
//              Aufgabe:    1.1
//
//      Praktikumsgruppe:   [V-08:30] - Is-VAI-B1A
//                Author:   Tim Pauksch
//      Erstellungsdatum:   24.02.2016
//    Letzte Anpassungen:   24.02.2016
//
//               Version:   1.0
//              Compiler:   g++
//=============================================================================
#include <iostream>

using namespace std;

//=============================================================================
// Definitionen
//=============================================================================

typedef unsigned int Pixel;

//=============================================================================
// Strukturen
//=============================================================================

struct pgm_bild{
   char  magic[2];            // Bildtyp
   int   nx;                  // Zeilenzahl
   int   ny;                  // Spaltenzahl
   int   grauwert;            // max. Grauwert
   Pixel	**bild;              // Bildmatrix
};

//=============================================================================
// Funktionen
//=============================================================================

void bild_lesen( pgm_bild *bild, string ifs_file_name ){

}

void bild_schreiben( pgm_bild *bild, string ofs_file_name ){

}

void delete_pixel_matrix( Pixel **m ){
   delete[] *m;
   delete[]  m;
}

Pixel** new_pixel_matrix( size_t rows, size_t columns ){
   size_t   i;
   Pixel    **m;
   m  =  new Pixel*  [rows];
   *m =  new Pixel   [rows*columns];
   for ( i=1; i<rows; i+=1 ){
      m[i] = m[i-1] + columns;
   }
   return m;
}

void glaetten( pgm_bild *bild1, pgm_bild *bild2 ){
   for (int i = 0; i < bild1->ny; i++) {
      for (int j = 0; j < bild1->nx; j++) {
         int summ = 0;
         if ((i - 1 >= 0) || (j - 1 >= 0)) {
            summ += bild1[i - 1][j - 1];
            summ += bild1[i - 1][j];
            summ += bild1[i - 1][j + 1];

            summ += bild1[i][j - 1];
            summ += bild1[i][j];
            summ += bild1[i][j + 1];

            summ += bild1[i + 1][j - 1];
            summ += bild1[i + 1][j];
            summ += bild1[i + 1][j + 1];

            bild2[i][j] = summ / 9;
         }
      }
   }
}

void invertieren( pgm_bild *bild1, pgm_bild *bild2 ){
   for (int i = 0; i < bild1->ny; i++) {
      for (int j = 0; j < bild1->nx; j++) {
         bild2[i][j] = bild1->grauwert - bild1[i][j];
      }
   }
}

void kantenbildung( pgm_bild *bild1, pgm_bild *bild2 ){
   for (int i = 0; i < bild1->ny; i++) {
      for (int j = 0; j < bild1->nx; j++) {
         int summ = 0;
         if ((i - 1 >= 0) || (j - 1 >= 0)) {
            summ += bild1[i - 1][j - 1] * 0;
            summ += bild1[i - 1][j] * -1;
            summ += bild1[i - 1][j + 1] * 0;

            summ += bild1[i][j - 1] * -1;
            summ += bild1[i][j] * 4;
            summ += bild1[i][j + 1] * -1;

            summ += bild1[i + 1][j - 1] * 0;
            summ += bild1[i + 1][j] * -1;
            summ += bild1[i + 1][j + 1] * 0;

            bild2[i][j] = abs(summ / 9);
         }
      }
   }
}

void kopiere_bildkopf( pgm_bild *bild1, pgm_bild *bild2 ){

}

//=============================================================================
// Hauptprogramm
//=============================================================================

int main() {

   cout << "Aufgabe 1.1 - Verwendung von Strukturen." << endl;

   return 0;
}
