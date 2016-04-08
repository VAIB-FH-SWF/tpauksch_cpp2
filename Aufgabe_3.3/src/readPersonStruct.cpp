//=============================================================================
//             Dateiname:   readPersonStruct.cpp
//                Author:   Tim Pauksch
//      Praktikumsgruppe:   [V-10:30] - Is-VAI-B2A
//      Erstellungsdatum:   06.04.2016
//          Beschreibung:   Programmierung mit C++ 2,
//                          Aufgabe 3.3, Verkettete Listen.
//                          Personenbeschreibung als Struktur.
//              Compiler:   g++
//=============================================================================
#include <iostream>           // F�r Textausgabe in Konsole
#include <fstream>            // F�r Dateiein- und ausgabe.
#include <cstdlib>            // F�r error(1).
#include <iomanip>            // F�r setw(3).

using namespace std;

//=============================================================================
// Strukturen
//=============================================================================

struct Mitarbeiter {
   string         identnummer;
   string         nachname;
   string         vorname;
   string         abteilung;
   unsigned int   durchwahl;
};

//=============================================================================
// Funktionen
//=============================================================================

/*
 * Funktion:            �ffnet die Personendaten-Datei, liest die Werte in eine Struktur
 *                      und gibt diese formatiert aus.
 * Eingabe Parameter:   Keiner.
 * R�ckgabewert:        Keiner.
 */
void readData( string ifs_file_name ){
   ifstream ifs;
   ifs.open(ifs_file_name.c_str());

   if (!ifs.is_open()) {
      cerr << "\nERROR : Failed to open input file: " << ifs_file_name << endl;
      exit(1);
   }

   Mitarbeiter buffer;
   int satz = 0;

   try{
      while(ifs >> buffer.identnummer >> buffer.nachname >> buffer.vorname >> buffer.abteilung >> buffer.durchwahl){
         satz++;
         cout  << left
               << setw(9)  << buffer.identnummer
               << setw(20) << buffer.nachname
               << setw(20) << buffer.vorname
               << setw(5)  << buffer.abteilung
               << setw(5)  << buffer.durchwahl << endl;
      }


   }catch(int e){
      cout << "\ERROR : Errorcode " << e << endl;
   }
}


//=============================================================================
// Hauptprogramm
//=============================================================================

int main() {
   readData("personen.dat");
}
