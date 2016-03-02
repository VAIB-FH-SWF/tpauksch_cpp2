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
#include <cstdlib>  // Für error(1)
#include <iomanip>  // Für setw(3)

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
   Pixel **bild;              // Bildmatrix
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

void delete_pixel_matrix( Pixel **m ){
   delete[] *m;
   delete[]  m;
}

void bild_lesen( pgm_bild *bild, string ifs_file_name ){

   ifstream ifs;
   int ifsInput = 0;

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

void bild_schreiben( pgm_bild *bild, string ofs_file_name ){
   ofstream ofs;
   ofs.open(ofs_file_name.c_str());

   if (!ofs.is_open()) {
      cerr << "\nERROR : Failed to open input file." << ofs_file_name << "." << endl;
      exit(1);
   }

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
      delete_pixel_matrix(bild->bild);
   }catch(int e){
      cout << "\ERROR : Errorcode " << e << endl;
   }
}

void kopiere_bildkopf( pgm_bild *bild1, pgm_bild *bild2 ){
   bild2->nx = bild1->nx;
   bild2->ny = bild1->ny;
   bild2->grauwert = bild1->grauwert;
   bild2->magic[0] = bild1->magic[0];
   bild2->magic[1] = bild1->magic[1];
}

void glaetten( pgm_bild *bild1, pgm_bild *bild2 ){
   for (int i = 0; i < bild1->ny; i++) {
      for (int j = 0; j < bild1->nx; j++) {
         int summ = 0;
         if ((i - 1 >= 0) && (j - 1 >= 0)) {
            summ += bild1->bild[i - 1][j - 1];
            summ += bild1->bild[i - 1][j];
            summ += bild1->bild[i - 1][j + 1];

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
//=============================================================================
// Hauptprogramm
//=============================================================================

int main() {

   cout << "Aufgabe 1.1 - Verwendung von Strukturen." << endl;

   // Definition der Struktur, die die Metadaten und den Zeiger auf das Pixel Arraiy hält
   pgm_bild bildStruktur;
   pgm_bild bildStruktur2;

   bild_lesen(&bildStruktur, "dreifach.pgm");

   bildStruktur2.bild = new_pixel_matrix(bildStruktur2.ny, bildStruktur2.nx);
   kopiere_bildkopf(&bildStruktur, &bildStruktur2);

//   glaetten(&bildStruktur, &bildStruktur2);
   bild_schreiben(&bildStruktur, "dreifachOut.pgm");

   return 0;
}
