//=============================================================================
//             Dateiname:   Mitarbeiter.cpp
//                Author:   Tim Pauksch
//      Praktikumsgruppe:   [V-10:30] - Is-VAI-B2A
//      Erstellungsdatum:   11.04.2016
//          Beschreibung:   Programmierung mit C++ 2,
//                          Aufgabe 4.2, Klasse Mitarbeiter.
//                          Feld von Mitarbeiter-Objekten.
//              Compiler:   g++
//=============================================================================
#include <iostream>           // F�r Textausgabe in Konsole
#include <fstream>            // F�r Dateiein- und ausgabe.
#include <cstdlib>            // F�r error(1).
#include <iomanip>            // F�r setw(3).


const unsigned int N = 100;

using namespace std;

// Struktur die die Kontaktdaten h�lt. Die Mitarbeiter-Objekte speichern in diesen Strukturen
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

   // Liste �ffentlicher Elemente der Klasse.
   public:
   //==============LIFECYCLE=============================================================
      /*
       * �berladener Konstruktor mit Ersatzwerten. Wenn ein Objekt des Typs Mitarbeiter erstellt wird
       * wie z.B. Mitarbeiter m1 = new Mitarbeiter(); werden trotz leerer Parameterliste die Standardwerte
       * "-" als Attribute verwendet. Im Script wird an dieser Stelle von "Ersatzwert" gesprochen.
       */
      Mitarbeiter(string identnummer = "-",
                  string nachname    = "-",
                  string vorname     = "-",
                  string abteilung   = "-",
                  string durchwahl   = "-");
      /*
       * �berladener Konstruktor der eine Referenz einer anderen Klasse zur Initialisierung
       * der Werte verwendet.
       */
      Mitarbeiter(const Mitarbeiter &other);
      // Destruktor der Klasse.
     ~Mitarbeiter();

   //==============ACCESSORS=============================================================
      // Definition der Getter-Methoden f�r den Zugang der Struktur-Variablen.
      string get_identnummer   () const;
      string get_nachname      () const;
      string get_vorname       () const;
      string get_abteilung     () const;
      string get_durchwahl     () const;
      // Methode zur Ausgabe der Struktur-Variablen.
      void   print             ();

   //==============ACCESSORS=============================================================
      // Definition der Setter-Methoden f�r das Hinterlegen der Struktur-Variablen.
      void set_identnummer   (string value);
      void set_nachname      (string value);
      void set_vorname       (string value);
      void set_abteilung     (string value);
      void set_durchwahl     (string value);

   //==============OPERATORS=============================================================
      // Definition der Methode zur �berlagerung des Gleich-Operators ("="). Nimmt
      // die Referenz der Ziel-Klasse auf.
      Mitarbeiter& operator = ( const Mitarbeiter &other);

   private:
   //==============DATA MEMBERS==========================================================
      Person   *p;
};

/*
 * Funktion:   Init der Werte mit Konstruktor
 * Eingabe:    string identnummer,
 *             string nachname,
 *             string vorname
 *             string abteilung,
 *             string durchwahl
 * Ausgabe:    leer
 */
Mitarbeiter::Mitarbeiter(string identnummer, string nachname, string vorname, string abteilung, string durchwahl){
   p = new Person;
   set_identnummer(identnummer);
   set_nachname(nachname);
   set_vorname(vorname);
   set_abteilung(abteilung);
   set_durchwahl(durchwahl);
}

/*
 * Funktion:   R�ckgabe der Identnummer
 * Eingabe:    Mitarbeiter &other - Pointer
 * Ausgabe:    leer
 */
Mitarbeiter::Mitarbeiter(const Mitarbeiter &other){
   p = new Person;
   p->identnummer = other.p->identnummer;
   p->nachname    = other.p->nachname;
   p->vorname     = other.p->vorname;
   p->abteilung   = other.p->abteilung;
   p->durchwahl   = other.p->durchwahl;
}

//Destruktor
Mitarbeiter::~Mitarbeiter(){
   delete p;
}

/*
 * Funktion:   R�ckgabe der Identnummer
 * Eingabe:    leer
 * Ausgabe:    String identnummer
 */
string Mitarbeiter::get_identnummer () const {
   return p->identnummer;
}

/*
 * Funktion:   R�ckgabe des Nachnamen
 * Eingabe:    leer
 * Ausgabe:    String nachname
 */
string Mitarbeiter::get_nachname    () const {
   return p->nachname;
}

/*
 * Funktion:   R�ckgabe des Vornamen
 * Eingabe:    leer
 * Ausgabe:    String vorname
 */
string Mitarbeiter::get_vorname     () const {
   return p->vorname;
}

/*
 * Funktion:   R�ckgabe der Abteilung
 * Eingabe:    leer
 * Ausgabe:    String abteilung
 */
string Mitarbeiter::get_abteilung   () const {
   return p->abteilung;
}

/*
 * Funktion:   R�ckgabe der Durchwahl
 * Eingabe:    leer
 * Ausgabe:    String durchwahl
 */
string Mitarbeiter::get_durchwahl   () const {
   return p->durchwahl;
}

/*
 * Funktion:   Drucken der von den Getter-Methoden erhaltenen Werte
 * Eingabe:    leer
 * Ausgabe:    leer
 */
void Mitarbeiter::print(){
   cout  << left
         << get_identnummer()    << ", "
         << get_nachname()       << ", "
         << get_vorname()        << ", "
         << get_abteilung()      << ", "
         << get_durchwahl()      << endl;
}

/*
 * Funktion:   �bernahme der Identnummer in Variable
 * Eingabe:    string identnummer
 * Ausgabe:    leer
 */
void Mitarbeiter::set_identnummer(string value){
   p->identnummer = value;
}

/*
 * Funktion:   �bernahme des Nachnamen in Variable
 * Eingabe:    string nachname
 * Ausgabe:    leer
 */
void Mitarbeiter::set_nachname   (string value){
   p->nachname    = value;
}

/*
 * Funktion:   �bernahme des Vornamen in Variable
 * Eingabe:    string vorname
 * Ausgabe:    leer
 */
void Mitarbeiter::set_vorname    (string value){
   p->vorname     = value;
}

/*
 * Funktion:   �bernahme der Abteilung in Variable
 * Eingabe:    string abteilung
 * Ausgabe:    leer
 */
void Mitarbeiter::set_abteilung  (string value){
   p->abteilung   = value;
}

/*
 * Funktion:   �bernahme der Durchwahl in Variable
 * Eingabe:    string durchwahl
 * Ausgabe:    leer
 */
void Mitarbeiter::set_durchwahl  (string value){
   p->durchwahl   = value;
}

/*
 * Funktion:   �berladung des Gleich-Operators
 * Eingabe:    Mitarbeiter &other
 * Ausgabe:    Pointer auf Mitarbeiter
 */
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

void checkFileStatus(const string& ifs_file_name, ifstream& ifs) {
   if (!ifs.is_open()) {
      cerr << "\nERROR : Failed to open input file: " << ifs_file_name << endl;
      exit(1);
   }
}

int main() {
   string ifs_file_name = "personen.dat";
   ifstream ifs;
   Mitarbeiter mitarbeiterListe[N];

   ifs.open(ifs_file_name.c_str());
   checkFileStatus(ifs_file_name, ifs);

   string identnummer = "";
   string nachname = "";
   string vorname = "";
   string abteilung = "";
   string durchwahl = "";

   int datensatz = 0;


   // Einlesen der Werte, aktuellen Wert von curser->next auf n�chstes Element setzen, curser auf n�chste Struktur setzten.
   try{
      for (int i = 0; i < 100; i++) {
         if (ifs >> identnummer >> nachname >> vorname >> abteilung >> durchwahl){
            mitarbeiterListe[i].set_identnummer(identnummer);
            mitarbeiterListe[i].set_nachname(nachname);
            mitarbeiterListe[i].set_vorname(vorname);
            mitarbeiterListe[i].set_abteilung(abteilung);
            mitarbeiterListe[i].set_durchwahl(durchwahl);

            datensatz++;
         }
      }
   }catch(int e){
      cout << "\ERROR : Errorcode " << e << endl;
   }
   ifs.close();

   for (int i = 0; i < datensatz; i++){
      cout << i << " : ";
      mitarbeiterListe[i].print();
   }

   return 0;
}
