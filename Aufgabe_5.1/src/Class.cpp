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
#include <iostream>           // Für Textausgabe in Konsole

const unsigned int N = 100;

using namespace std;

/**
 * Testklasse Class.
 * Diese Klasse hat die Aufgabe das Verständnis für die Abläufe in einer Klasse zu vertiefen.
 * Beispielsweise sind in allen Methoden Aufrufe für Konsolen-Ausgaben vorhanden um die
 * Reihenfolge des Aufrufs und die Adresse des zugehörigen Objekts zu bestimmen
 */
class Class{

   // Liste öffentlicher Elemente der Klasse.
   public:
   //==============LIFECYCLE=============================================================
     Class(int _value=0, string _name="");
     Class(const Class &other);
      // Destruktor der Klasse.
     ~Class();

   //==============ACCESSORS=============================================================
     void print ();

   //==============MUTATORS==============================================================
     Class& set_name  (string _name);
     Class& set_value (int _value);

   //==============OPERATORS=============================================================
     Class& operator = ( const Class &other);
     Class  operator + ( const Class &other);

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
Class::Class(int _value, string _name){
   value = _value;
   name  = _name;
   cout << " ==== constructor (this = " << this << ", value = " << _value << ", name = '" << _name << "' )\n";
}

/*
 * Funktion:   Kopier-Konstruktor
 * Eingabe:    const Class &other - Referenz auf Class Objekt
 * Ausgabe:    Konsolen Ausgabe
 */
Class::Class(const Class &other){
   value = other.value;
   cout << " ==== copy-constructor (this = " << this << " other = " << &other << " )\n";
}

/*
 * Funktion:   Setter-Methode für den Parameter name
 * Eingabe:    string _name - Name der Klasse
 * Ausgabe:    Konsolen Ausgabe
 */
Class& Class::set_name(string _name){
   name = _name;
   cout << " ==== set_name (this = " << this << " )\n";
   return *this;
}

/*
 * Funktion:   Setter-Methode für den Parameter value
 * Eingabe:    int _value - Integer Wert
 * Ausgabe:    Konsolen Ausgabe
 */
Class& Class::set_value(int _value){
   value = _value;
   cout << " ==== set_value (this = " << this << " )\n";
   return *this;
}

/*
 * Funktion:   Ausgabe-Methode für den Namen und den Wert des Objekts
 * Eingabe:    Leer
 * Ausgabe:    Konsolen Ausgabe
 */
void Class::print(){
   cout << "Name:"  << name  << endl;
   cout << "Value:" << value << endl;
   cout << " ==== print (this = " << this << " )\n";
}

/**
 * Funktion:   Überladung des Operators '='
 * Eingabe:    const Class &other - Referenz auf Class Objekt
 * Ausgabe:    Class& - Referenz auf das gleiche Objekt
 */
Class& Class::operator = ( const Class &other){
   value = other.value;
   cout << " ==== operator = (this = " << this << " other = " << &other << " )\n";
   return *this;
};

/**
 * Funktion:   Überladung des Operators '+'
 * Eingabe:    const Class &other - Referenz auf Class Objekt
 * Ausgabe:    Class& - Referenz auf das gleiche Objekt
 */
Class  Class::operator + ( const Class &other){
   Class Summe;
   Summe.value = other.value + value;
   cout << " ==== operator + (this = " << this << " other = " << &other << ", internal Sum = " << &Summe << ")\n";
   return Summe;
};

/**
 * Funktion:   Destruktor
 * Eingabe:    Leer
 * Ausgabe:    Konsolen Ausgabe
 */
Class::~Class(){
   cout << " ==== destructor (this = " << this << ", value = " << value << ", name = '" << name << "' )\n";
}

/**
 * Funktion:   Rückgabe des im Parameter übergebenen Objekts
 * Eingabe:    Class arg - Class Objekt
 * Ausgabe:    Class arg - In Parameterliste übergebenes Objekt
 */
Class f ( Class arg){
   return arg;
};

/**
 * Funktion:   Rückgabe der im Parameter übergebenen Objekt-Referenz
 * Eingabe:    Class arg - Class Objekt
 * Ausgabe:    Class arg - In Parameterliste übergebene Objekt-Referenz
 */
Class g ( Class *arg){
   return *arg;
};

int main() {
   /*
    * Hier werden fünf Objekte des Typs Class initialisiert mit denen
    * im weiteren Verlauf gearbeitet wird um Reihenfolgen und Effekte
    * der Operationen zu zeigen
    */
   cout << "\n ########## Vereinbarungen: ######### \n\n";
   Class x1(11, "x1");
   Class x2 = x1;       // Hier hat x2 übrigens noch den Namen aus dem Ersatzwert
   Class x3(33, "x3");
   x2.set_name("x2");

   /*
    *  Zusätzliche Vereinbarungen die nicht in der Vorgabe des Praktikum
    *  zu finden waren, die ich aber als Hilfreich empfand.
    */
   Class x4(44, "x4");
   Class x5(55, "x5");

   /*
    * Prüfausgabe für die Objekte
    */
   cout << "\n ########## Ausgabe Werte für Vereinbarungen: ######### \n\n";
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
