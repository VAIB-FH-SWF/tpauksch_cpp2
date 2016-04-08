//=============================================================================
//             Dateiname:   readPersonList.cpp
//                Author:   Tim Pauksch
//      Praktikumsgruppe:   [V-10:30] - Is-VAI-B2A
//      Erstellungsdatum:   06.04.2016
//          Beschreibung:   Programmierung mit C++ 2,
//                          Aufgabe 3.4, Verkettete Listen.
//                          Personenbeschreibung in einer Liste.
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

//=============================================================================
// Strukturen
//=============================================================================

struct mitarbeiter {
   string         identnummer;
   string         nachname;
   string         vorname;
   string         abteilung;
   unsigned int   durchwahl;
   mitarbeiter    *next;
};



//=============================================================================
// Funktionen
//=============================================================================

/*
 * Funktion:            Öffnet die Personendaten-Datei, liest die Werte in eine Struktur
 *                      und gibt diese formatiert aus.
 * Eingabe Parameter:   Keiner.
 * Rückgabewert:        Keiner.
 */
void readData( string ifs_file_name, mitarbeiter* cursor, mitarbeiter* ma){
   ifstream ifs;
   ifs.open(ifs_file_name.c_str());

   if (!ifs.is_open()) {
      cerr << "\nERROR : Failed to open input file: " << ifs_file_name << endl;
      exit(1);
   }

   cursor = ma;

   // Einlesen der Werte, aktuellen Wert von curser->next auf nächstes Element setzen, curser auf nächste Struktur setzten.
   try{
      while(ifs >> cursor->identnummer >> cursor->nachname >> cursor->vorname >> cursor->abteilung >> cursor->durchwahl){
         cursor->next = new mitarbeiter;
         cursor = cursor->next;
      }

      cursor->next = NULL;

   }catch(int e){
      cout << "\ERROR : Errorcode " << e << endl;
   }
}

/*
 * Funktion:            Sucht angegeben Wert "durchwahl" in Liste und gibt Vor- und Nachname wieder.
 * Eingabe Parameter:   unsigned int durchwahl
 *                      Pointer mitarbeiter *ma
 *                      Pointer mitarbeiter *curser
 * Rückgabewert:        Pointer ergebnisZeiger - Zeiger auf Ergebnisfeld.
 */
mitarbeiter* findDurchwahl(unsigned int durchwahl, mitarbeiter *ma, mitarbeiter *curser){
   mitarbeiter *ergebnisZeiger = NULL;
   curser = ma;

   while((curser->next != NULL)){
      if (curser->durchwahl == durchwahl){
          ergebnisZeiger = curser;
      }
      curser = curser->next;
   }

   return ergebnisZeiger;
};

/*
 * Funktion:            Löschen der Listenelemente,
 * Eingabe Parameter:   Pointer mitarbeiter *ma
 *                      Pointer mitarbeiter *curser
 * Rückgabewert:        Keiner.
 */
void listeAbbauen(mitarbeiter* ma, mitarbeiter *curser){
   do {
      curser = ma->next;
      delete ma;
      ma = curser->next;
   } while ((ma->next != NULL));
}

//=============================================================================
// Hauptprogramm
//=============================================================================

int main() {
   mitarbeiter liste;
   mitarbeiter *ergebnis;

   mitarbeiter *ma      = &liste;
   mitarbeiter *cursor  = 0;


//   //Tests:
//   //Für Test "Leer":
//   readData("personen_leer.dat", *&cursor, *&ma);

//   // Für Test "Ein Element":
//   readData("personen_ein_Element.dat", *&cursor, *&ma);
//
//   // Für Test "Erstes Element":
//   readData("personen.dat", *&cursor, *&ma);
//   ergebnis = findDurchwahl(4700, *&ma, *&cursor);
//
//   // Für Test "Letzte Element":
//   readData("personen.dat", *&cursor, *&ma);
//   ergebnis = findDurchwahl(4752, *&ma, *&cursor);

   readData("personen.dat", *&cursor, *&ma);
   ergebnis = findDurchwahl(4731, *&ma, *&cursor);

   if(ergebnis != NULL){
      cout << ergebnis->vorname << " " << ergebnis->nachname << endl;
   }else{
      cout << "Keine Ergebnisse gefunden." << endl;
   }

   listeAbbauen(&liste, *&cursor);
   return 0;
}
