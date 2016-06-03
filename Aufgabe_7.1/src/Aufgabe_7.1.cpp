//=============================================================================
//             Dateiname:   Aufgabe_7.1.cpp
//                Author:   Tim Pauksch
//      Praktikumsgruppe:   [V-10:30] - Is-VAI-B2A
//      Erstellungsdatum:   30.05.2016
//          Beschreibung:   Programmierung mit C++ 2,
//                          Aufgabe 7.1, Ausnahmebehandlung,
//                          Implementierung der Klasse Datum.
//              Compiler:   g++
//=============================================================================

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "Datum.h"


using namespace std;

const int N1 = 100000;


int main(){
   cout << "Aufgabe 7.1, Ausnahmebehandlung, Implementierung der Klasse Datum." << endl;
   cout << endl;

   string ifs_file_name = "datumsliste.dat";
   uint ifsTag   = 0;
   uint ifsMonat = 0;
   uint ifsJahr  = 0;

   Datum datenFeld[N1];
   int feldIndex = 0;
   ifstream ifs;

   ifs.open(ifs_file_name.c_str());

   if (!ifs.is_open()) {
      cerr << "\nERROR : Failed to open input file: " << ifs_file_name << endl;
      exit(1);
   }

   while ((feldIndex < N1) && (ifs >> ifsTag >> ifsMonat >> ifsJahr)) {
      try {
         Datum tmp(ifsTag, ifsMonat, ifsJahr);
         datenFeld[feldIndex] = tmp;
         feldIndex++;
      } catch (int e) {
         cout << "\ERROR : Errorcode " << e << endl;
      }
   }

   ifs.close();

   cout << feldIndex << endl;

   cout << endl;
   cout << "Programmende." << endl;

   return 0;
}
