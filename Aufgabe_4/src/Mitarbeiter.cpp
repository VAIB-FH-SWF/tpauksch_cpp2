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
      void set_identnummer   (string value);
      void set_nachname      (string value);
      void set_vorname       (string value);
      void set_abteilung     (string value);
      void set_durchwahl     (string value);

   //==============OPERATORS=============================================================
      Mitarbeiter& operator = ( const Mitarbeiter &other);

   private:
   //==============DATA MEMBERS==========================================================
      Person   *p;
};

string Mitarbeiter::get_identnummer () const {
   return p->identnummer;
}

string Mitarbeiter::get_nachname () const {
   return p->nachname;
}

string Mitarbeiter::get_vorname () const {
   return p->vorname;
}

string Mitarbeiter::get_abteilung () const {
   return p->abteilung;
}

string Mitarbeiter::get_durchwahl () const {
   return p->durchwahl;
}

void Mitarbeiter::set_identnummer(string value){
   p->identnummer = value;
}

void Mitarbeiter::set_nachname   (string value){
   p->nachname    = value;
}

void Mitarbeiter::set_vorname    (string value){
   p->vorname     = value;
}

void Mitarbeiter::set_abteilung  (string value){
   p->abteilung   = value;
}

void Mitarbeiter::set_durchwahl  (string value){
   p->durchwahl   = value;
}

Mitarbeiter::~Mitarbeiter(){
   delete p;
}

void readData( string ifs_file_name ){
   ifstream ifs;
   ifs.open(ifs_file_name.c_str());

   if (!ifs.is_open()) {
      cerr << "\nERROR : Failed to open input file: " << ifs_file_name << endl;
      exit(1);
   }


//   try{
//      while(ifs >> cursor->identnummer >> cursor->nachname >> cursor->vorname >> cursor->abteilung >> cursor->durchwahl){
//
//      }
//
//   }catch(int e){
//      cout << "\ERROR : Errorcode " << e << endl;
//   }
}

int main() {


   return 0;
}
