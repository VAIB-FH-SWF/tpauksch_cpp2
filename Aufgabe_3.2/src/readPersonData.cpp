//=============================================================================
//             Dateiname:   LinkedList.cpp
//                Author:   Tim Pauksch
//      Praktikumsgruppe:   [V-10:30] - Is-VAI-B2A
//      Erstellungsdatum:   23.03.2016
//          Beschreibung:   Programmierung mit C++ 2,
//                          Aufgabe 3.1, Verkettete Listen.
//                          Einfach verkettete Liste aus
//                          statischen Elementen.
//              Compiler:   g++
//=============================================================================
#include <iostream>           // Für Textausgabe in Konsole
#include <fstream>            // Für Dateiein- und ausgabe.
#include <cstdlib>            // Für error(1).
#include <iomanip>            // Für setw(3).

using namespace std;

//=============================================================================
// Hauptprogramm
//=============================================================================

int main() {
   string         ifs_file_name = "personen.dat";
   string         identnummer;
   string         nachname;
   string         vorname;
   string         abteilung;
   unsigned int   durchwahl;
   unsigned int   satz = 0;

   ifstream ifs;
   ifs.open(ifs_file_name.c_str());

   if (!ifs.is_open()) {
      cerr << "\nERROR : Failed to open input file: " << ifs_file_name << endl;
      exit(1);
   }

   try{
      while(ifs >> identnummer >> nachname >> vorname >> abteilung >> durchwahl){
         satz++;
         cout  << left
               << setw(9)  << identnummer
               << setw(20) << nachname
               << setw(20) << vorname
               << setw(5)  << abteilung
               << setw(5)  << durchwahl << endl;
      }


   }catch(int e){
      cout << "\ERROR : Errorcode " << e << endl;
   }
}
