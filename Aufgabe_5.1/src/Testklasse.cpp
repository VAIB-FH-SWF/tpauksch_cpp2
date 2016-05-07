//=============================================================================
//             Dateiname:   Mitarbeiter.cpp
//                Author:   Tim Pauksch
//      Praktikumsgruppe:   [V-10:30] - Is-VAI-B2A
//      Erstellungsdatum:   11.04.2016
//          Beschreibung:   Programmierung mit C++ 2,
//                          Aufgabe 5.1, Reihenfolge und Wirkung von
//                          Methodenaufrufen.
//                          Implementierung einer Testklasse.
//              Compiler:   g++
//=============================================================================
#include <iostream>           // F�r Textausgabe in Konsole

const unsigned int N = 100;

using namespace std;

/**
 * Klasse Testklasse.
 * Diese Klasse hat die Aufgabe das Verst�ndnis f�r die Abl�ufe in einer Klasse zu vertiefen.
 * Beispielsweise sind in allen Methoden Aufrufe f�r Konsolen-Ausgaben vorhanden um die
 * Reihenfolge des Aufrufs und die Adresse des zugeh�rigen Objekts zu bestimmen
 */
class Testklasse{

   // Liste �ffentlicher Elemente der Klasse.
   public:
   //==============LIFECYCLE=============================================================
     Testklasse(int _value=0, string _name="");
     Testklasse(const Testklasse &other);
      // Destruktor der Klasse.
     ~Testklasse();

   //==============ACCESSORS=============================================================
     void print ();

   //==============MUTATORS==============================================================
     Testklasse& set_name  (string _name);
     Testklasse& set_value (int _value);

   //==============OPERATORS=============================================================
     Testklasse& operator = ( const Testklasse &other);
     Testklasse  operator + ( const Testklasse &other);

   private:
   //==============DATA MEMBERS==========================================================
      int    value;
      string name;
};

/*
 * Funktion:   Konstruktor mit Ersatzwerten
 * Eingabe:    int _value - Integer Wert
 *             string _name - Name der Klasse
 * Ausgabe:    Konsolen Ausgabe
 */
Testklasse::Testklasse(int _value, string _name){
   value = _value;
   name  = _name;
   cout << " ==== constructor (this = " << this << ", value = " << _value << ", name = '" << _name << "' )\n";
}

/*
 * Funktion:   Kopier-Konstruktor
 * Eingabe:    const Testklasse &other - Referenz auf Testklasse Objekt
 * Ausgabe:    Konsolen Ausgabe
 */
Testklasse::Testklasse(const Testklasse &other){
   value = other.value;
   cout << " ==== copy-constructor (this = " << this << " other = " << &other << " )\n";
}

/*
 * Funktion:   Setter-Methode f�r den Parameter name
 * Eingabe:    string _name - Name der Klasse
 * Ausgabe:    Konsolen Ausgabe
 */
Testklasse& Testklasse::set_name(string _name){
   name = _name;
   cout << " ==== set_name (this = " << this << " )\n";
   return *this;
}

/*
 * Funktion:   Setter-Methode f�r den Parameter value
 * Eingabe:    int _value - Integer Wert
 * Ausgabe:    Konsolen Ausgabe
 */
Testklasse& Testklasse::set_value(int _value){
   value = _value;
   cout << " ==== set_value (this = " << this << " )\n";
   return *this;
}

/*
 * Funktion:   Ausgabe-Methode f�r den Namen und den Wert des Objekts
 * Eingabe:    Leer
 * Ausgabe:    Konsolen Ausgabe
 */
void Testklasse::print(){
   cout << "Name:"  << name  << endl;
   cout << "Value:" << value << endl;
   cout << " ==== print (this = " << this << " )\n";
}

/**
 * Funktion:   �berladung des Operators '='
 * Eingabe:    const Testklasse &other - Referenz auf Testklasse Objekt
 * Ausgabe:    Testklasse& - Referenz auf das gleiche Objekt
 */
Testklasse& Testklasse::operator = ( const Testklasse &other){
   value = other.value;
   cout << " ==== operator = (this = " << this << " other = " << &other << " )\n";
   return *this;
};

/**
 * Funktion:   �berladung des Operators '+'
 * Eingabe:    const Testklasse &other - Referenz auf Testklasse Objekt
 * Ausgabe:    Testklasse& - Referenz auf das gleiche Objekt
 */
Testklasse  Testklasse::operator + ( const Testklasse &other){
   Testklasse Summe;
   Summe.value = other.value + value;
   cout << " ==== operator + (this = " << this << " other = " << &other << ", internal Sum = " << &Summe << ")\n";
   return Summe;
};

/**
 * Funktion:   Destruktor
 * Eingabe:    Leer
 * Ausgabe:    Konsolen Ausgabe
 */
Testklasse::~Testklasse(){
   cout << " ==== destructor (this = " << this << ", value = " << value << ", name = '" << name << "' )\n";
}

/**
 * Funktion:   R�ckgabe des im Parameter �bergebenen Objekts
 * Eingabe:    Testklasse arg - Testklasse Objekt
 * Ausgabe:    Testklasse arg - In Parameterliste �bergebenes Objekt
 */
Testklasse f ( Testklasse arg){
   return arg;
};

/**
 * Funktion:   R�ckgabe der im Parameter �bergebenen Objekt-Referenz
 * Eingabe:    Testklasse arg - Testklasse Objekt
 * Ausgabe:    Testklasse arg - In Parameterliste �bergebene Objekt-Referenz
 */
Testklasse g ( Testklasse *arg){
   return *arg;
};

int main() {
   /*
    * Hier werden f�nf Objekte des Typs Testklasse initialisiert mit denen
    * im weiteren Verlauf gearbeitet wird um Reihenfolgen und Effekte
    * der Operationen zu zeigen
    */
   cout << "\n ########## Vereinbarungen: ######### \n\n";
   Testklasse x1(11, "x1");
   Testklasse x2 = x1;       // Hier hat x2 �brigens noch den Namen aus dem Ersatzwert
   Testklasse x3(33, "x3");
   x2.set_name("x2");

   /*
    *  Zus�tzliche Vereinbarungen die nicht in der Vorgabe des Praktikum
    *  zu finden waren, die ich aber als Hilfreich empfand.
    */
   Testklasse x4(44, "x4");
   Testklasse x5(55, "x5");

   /*
    * Pr�fausgabe f�r die Objekte
    */
   cout << "\n ########## Ausgabe Werte f�r Vereinbarungen: ######### \n\n";
   x1.print();
   x2.print();
   x3.print();
   x4.print();
   x5.print();

   // Einfache Zuweisung mit Hilfe der Zuweisungsoperators '='
   cout << "\n ########## Einfache Zuweisung: x4 = x3 ######### \n\n";
   x4 = x3;
   x4.print();

   // 1.Addition: Objekt mit Konstante
   cout << "\n ########## 1.Addition: x5 = x4 + 1 ######### \n\n";
   x5 = x4 + 1;
   x4.print();
   x5.print();

   // 2.Addition: Objekt mit Objekt und Zuweisung zu drittem
   cout << "\n ########## 2.Addition: x5 = x4 + x3 ######### \n\n";
   x5 = x4 + x3;
   x5.print();

   // Einfache Funktionsaufrufe
   cout << "\n ########## Einfacher Funktionsaufruf: x3 = f(x2) ######### \n\n";
   x3 = f(x2);
   x3.print();

   cout << "\n ########## Einfacher Funktionsaufruf: x3 = g(&x4) ######### \n\n";
   x3 = g(&x4);
   x3.print();

   // Funktionsaufrufe mit Additionen
   cout << "\n ########## Funktionsaufruf mit einer Addition: x3 = x1 + f(x2) ######### \n\n";
   x3 = x1 + f(x2);
   x3.print();

   cout << "\n ########## Funktionsaufruf mit einer Addition: x3 = x1 + g(&x4) ######### \n\n";
   x3 = x1 + g(&x4);
   x3.print();

   // Wertzuweisungen
   cout << "\n ########## Zuweisung einer int-Konstanten: x3 = 234 ######### \n\n";
   x3 = 234;
   x3.print();

   cout << "\n ########## Verwendung der Methode set_value(): x3.set_value(333) ######### \n\n";
   x3.set_value(333);
   x3.print();

   // Kontrollausgaben vor Aufruf der Destruktoren
   cout << "\n ########## Ausgabe der Adressen vor Aufruf des Destruktors: ######### \n\n";
   cout << "Adresse von x1: " << &x1 << endl;
   cout << "Adresse von x2: " << &x2 << endl;
   cout << "Adresse von x3: " << &x3 << endl;
   cout << "Adresse von x4: " << &x4 << endl;
   cout << "Adresse von x5: " << &x5 << endl;

   return 0;
}
