//=============================================================================
//             Dateiname:   Mitarbeiter.cpp
//                Author:   Tim Pauksch
//      Praktikumsgruppe:   [V-10:30] - Is-VAI-B2A
//      Erstellungsdatum:   11.04.2016
//          Beschreibung:   Programmierung mit C++ 2,
//                          Aufgabe 3.4, Klasse Mitarbeiter.
//                          Implementierung der Klasse Mitarbeiter.
//              Compiler:   g++
//=============================================================================
#include <iostream>           // Für Textausgabe in Konsole
#include <fstream>            // Für Dateiein- und ausgabe.
#include <iomanip>            // Für setw(3).

using namespace std;

// Struktur die die Kontaktdaten hält. Die Mitarbeiter-Objekte speichern in diesen Strukturen
// die Personendaten und halten als einzige die Speicher-Referenz.
struct Person {
   string identnummer;
   string nachname;
   string vorname;
   string abteilung;
   string durchwahl;
};

// Klassendefinition der Klasse Mitarbeiter.
class Mitarbeiter{

   // Liste öffentlicher Elemente der Klasse.
   public:
   //==============LIFECYCLE=============================================================
      // Überladener Konstruktor mit Ersatzwerten.
      Mitarbeiter(string identnummer = "-",
                  string nachname    = "-",
                  string vorname     = "-",
                  string abteilung   = "-",
                  string durchwahl   = "-");
      // Überladener Konstruktor der eine Referenz einer anderen Klasse zur Initialisierung
      // der Werte verwendet.
      Mitarbeiter(const Mitarbeiter &other);
      // Destruktor der Klasse.
     ~Mitarbeiter();

   //==============ACCESSORS=============================================================
      // Definition der Getter-Methoden für den Zugang der Struktur-Variablen.
      string get_identnummer   () const;
      string get_nachname      () const;
      string get_vorname       () const;
      string get_abteilung     () const;
      string get_durchwahl     () const;
      // Methode zur Ausgabe der Struktur-Variablen.
      void   print             ();

   //==============ACCESSORS=============================================================
      // Definition der Setter-Methoden für das Hinterlegen der Struktur-Variablen.
      void set_identnummer   (string value);
      void set_nachname      (string value);
      void set_vorname       (string value);
      void set_abteilung     (string value);
      void set_durchwahl     (string value);

   //==============OPERATORS=============================================================
      // Definition der Methode zur Überlagerung des Gleich-Operators ("="). Nimmt
      // die Referenz der Ziel-Klasse auf.
      Mitarbeiter& operator = ( const Mitarbeiter &other);

   private:
   //==============DATA MEMBERS==========================================================
      Person   *p;
};

Mitarbeiter::Mitarbeiter(string identnummer, string nachname, string vorname, string abteilung, string durchwahl){
   p = new Person;
   set_identnummer(identnummer);
   set_nachname(nachname);
   set_vorname(vorname);
   set_abteilung(abteilung);
   set_durchwahl(durchwahl);
}

Mitarbeiter::Mitarbeiter(const Mitarbeiter &other){
   p = new Person;
   p->identnummer = other.p->identnummer;
   p->nachname    = other.p->nachname;
   p->vorname     = other.p->vorname;
   p->abteilung   = other.p->abteilung;
   p->durchwahl   = other.p->durchwahl;
}

Mitarbeiter::~Mitarbeiter(){
   delete p;
}

string Mitarbeiter::get_identnummer () const {
   return p->identnummer;
}

string Mitarbeiter::get_nachname    () const {
   return p->nachname;
}

string Mitarbeiter::get_vorname     () const {
   return p->vorname;
}

string Mitarbeiter::get_abteilung   () const {
   return p->abteilung;
}

string Mitarbeiter::get_durchwahl   () const {
   return p->durchwahl;
}

void Mitarbeiter::print(){
   cout  << left
         << setw(9)  << get_identnummer()
         << setw(20) << get_nachname()
         << setw(20) << get_vorname()
         << setw(5)  << get_abteilung()
         << setw(5)  << get_durchwahl() << endl;
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

Mitarbeiter& Mitarbeiter::operator = (const Mitarbeiter &other){
   if (this != &other){
         Person *save = p;
         p = new Person;
         p->identnummer = other.p->identnummer;
         p->nachname    = other.p->nachname;
         p->vorname     = other.p->vorname;
         p->abteilung   = other.p->abteilung;
         p->durchwahl   = other.p->durchwahl;

         delete save;
   }
   return *this;
}

int main() {
   Mitarbeiter m1;
   m1.set_identnummer   ("10002220");
   m1.set_nachname      ("JAYALATH");
   m1.set_vorname       ("THILANAKA");
   m1.set_abteilung     ("QC18");
   m1.set_durchwahl     ("4701");
   m1.print();

   Mitarbeiter m2("10001222", "DOLBEL", "DAVID", "QC18", "4700");
   m2.print();

   Mitarbeiter m3(m1);

   m1.print();
   m3.print();

   m1 = m2;

   m1.print();

   return 0;
}
