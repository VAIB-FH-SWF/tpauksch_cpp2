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

struct Person {
   string identnummer;
   string nachname;
   string vorname;
   string abteilung;
   string durchwahl;
};

class Mitarbeiter{

   public:
   //==============LIFECYCLE=============================================================
      Mitarbeiter(string identnummer = "-",
                  string nachname    = "-",
                  string vorname     = "-",
                  string abteilung   = "-",
                  string durchwahl   = "-");
      Mitarbeiter(const Mitarbeiter &other);
     ~Mitarbeiter();

   //==============ACCESSORS=============================================================
      string get_identnummer   () const;
      string get_nachname      () const;
      string get_vorname       () const;
      string get_abteilung     () const;
      string get_durchwahl     () const;
      void   print             ();

   //==============ACCESSORS=============================================================
      string set_identnummer   (string value);
      string set_nachname      (string value);
      string set_vorname       (string value);
      string set_abteilung     (string value);
      string set_durchwahl     (string value);

   //==============OPERATORS=============================================================
      Mitarbeiter& operator = ( const Mitarbeiter &other);

   private:
   //==============DATA MEMBERS==========================================================
      Person   *p;
};
