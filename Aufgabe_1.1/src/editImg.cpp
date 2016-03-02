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
#include <fstream>
#include <cstdlib>   // Für error(1)

using namespace std;

//=============================================================================
// Definitionen
//=============================================================================

const int N = 10;
typedef unsigned char Pixel;

//=============================================================================
// Strukturen
//=============================================================================

struct pgm_bild{
   char  magic[2];            // Bildtyp
   int   nx;                  // Spaltenzahl
   int   ny;                  // Zeilenzahl
   int   grauwert;            // max. Grauwert
   Pixel	*bild[N];              // Bildmatrix
};

//=============================================================================
// Funktionen
//=============================================================================

void print_meta(pgm_bild *bild){
   cout << bild->grauwert << endl;
   cout << bild->magic[0];
   cout << bild->magic[1] << endl;
   cout << bild->nx << endl;
   cout << bild->ny << endl;
}

void bild_lesen( pgm_bild *bild, string ifs_file_name ){

   ifstream ifs;
   ifs.open(ifs_file_name.c_str());

   if (!ifs.is_open()) {
      cerr << "\nERROR : Failed to open input file." << ifs_file_name << "."
            << endl;
      exit(1);
   }

   // Metadateien des Bildes lesen
   try{
      bild->magic[0] = ifs.get();
      bild->magic[1] = ifs.get();
      ifs >> bild->nx;
      ifs >> bild->ny;
      ifs >> bild->grauwert;
   }catch(int e){
      cout << "\ERROR : Errorcode " << e << endl;
   }

   //Bilddaten einlesen
   //for (int indexY = 0; indexY < bild->ny; indexY++){
      //for (int indexX = 0; indexX < bild->nx; indexX++){
         //ifs >> bild->bild[0][1];

      //}
   //}
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

void invertieren( pgm_bild *bild1, pgm_bild *bild2 ){
   for (int i = 0; i < bild1->ny; i++) {
      for (int j = 0; j < bild1->nx; j++) {
         bild2->bild[i][j] = bild1->grauwert - bild1->bild[i][j];
      }
   }
}

void kantenbildung( pgm_bild *bild1, pgm_bild *bild2 ){
   for (int i = 0; i < bild1->ny; i++) {
      for (int j = 0; j < bild1->nx; j++) {
         int summ = 0;
         if ((i - 1 >= 0) || (j - 1 >= 0)) {
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

void kopiere_bildkopf( pgm_bild *bild1, pgm_bild *bild2 ){

}

void initFeld(Pixel *bildFeld[N]){
   for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
         bildFeld[N][N] = 0;
      }
   }
}
//=============================================================================
// Hauptprogramm
//=============================================================================

int main() {

   cout << "Aufgabe 1.1 - Verwendung von Strukturen." << endl;
   Pixel bildFeld[N][N];
   initFeld(&bildFeld[0][0]);

   pgm_bild bildStruktur;
   bildStruktur.bild[N] = &bildFeld[0][0];

   //cout << bildStruktur.bild[0][0];
   //bild_lesen(&bildStruktur,"dreifach.pgm");
   //print_meta(&bildStruktur);
   return 0;
}
