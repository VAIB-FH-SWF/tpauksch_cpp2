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
#include <fstream>            // Für Dateiein- und ausgabe.
#include <cstdlib>            // Für error(1).
#include <iomanip>            // Für setw(3).


const unsigned int N = 100;

using namespace std;

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

Class::Class(int _value, string _name){
   value = _value;
   name  = _name;
   cout << " ==== constructor (this = " << this << ", value = " << _value << ", name = '" << _name << "' )\n";
}

Class::Class(const Class &other){
   value = other.value;
   cout << " ==== copy-constructor (this = " << this << " other = " << &other << " )\n";
}

Class& Class::set_name(string _name){
   name = _name;
   cout << " ==== set_name (this = " << this << " )\n";
   return *this;
}

Class& Class::set_value(int _value){
   value = _value;
   cout << " ==== set_value (this = " << this << " )\n";
   return *this;
}

void Class::print(){
   cout << "Name:"  << name  << endl;
   cout << "Value:" << value << endl;
   cout << " ==== print (this = " << this << " )\n";
}

Class& Class::operator = ( const Class &other){
   value = other.value;
   cout << " ==== operator = (this = " << this << " other = " << &other << " )\n";
   return *this;
};

Class  Class::operator + ( const Class &other){
   Class Summe;
   Summe.value = other.value + value;
   cout << " ==== operator + (this = " << this << " other = " << &other << " )\n";
   return Summe;
};

Class::~Class(){
   cout << " ==== destructor (this = " << this << ", value = " << value << ", name = '" << name << "' )\n";
}

Class f ( Class arg){
   return arg;
};

Class g ( Class *arg){
   return *arg;
};

int main() {
   cout << "\n ########## Vereinbarungen: ######### \n\n";
   Class x1(11, "x1");
   Class x2 = x1;
   Class x3(33, "x3");
   x2.set_name("x2");

   // Zusätzliche Vereinbarungen
   Class x4(44, "x4");
   Class x5(55, "x5");

   cout << "\n ########## Ausgabe Werte für Vereinbarungen: ######### \n\n";
   x1.print();
   x2.print();
   x3.print();
   x4.print();
   x5.print();

   // Einfache Zuweisung mit Hilfe der Zuweisungsoperators =
   cout << "\n ########## Einfache Zuweisung: x4 = x3 ######### \n\n";
   x4 = x3;
   x4.print();

   // 1.Addition: Objekt mit Konstanter
   cout << "\n ########## 1.Addition: x5 = x4 + 1 ######### \n\n";
   x5 = x4 + 1;
   x5.print();

   // 2.Addition: Objekt mit Objekt und Zuweisung zu drittem
   cout << "\n ########## 2.Addition: x5 = x4 + x3 ######### \n\n";
   x5 = x4 + x3;
   x5.print();

   // Einfacher Funktionsaufruf
   cout << "\n ########## Einfacher Funktionsaufruf: x3 = f(x2) ######### \n\n";
   x3 = f(x2);
   x3.print();

   cout << "\n ########## Einfacher Funktionsaufruf: x3 = g(&x4) ######### \n\n";
   x3 = g(&x4);
   x3.print();

   cout << "\n ########## Funktionsaufruf mit einer Addition: x3 = x1 + f(x2) ######### \n\n";
   x3 = x1 + f(x2);
   x3.print();

   cout << "\n ########## Funktionsaufruf mit einer Addition: x3 = x1 + g(&x4) ######### \n\n";
   x3 = x1 + g(&x4);
   x3.print();

   cout << "\n ########## Zuweisung einer int-Konstanten: x3 = 234 ######### \n\n";
   x3 = 234;
   x3.print();

   cout << "\n ########## Verwendung der Methode set_value(): x3.set_value(333) ######### \n\n";
   x3.set_value(333);
   x3.print();

   cout << "\n ########## Ausgabe der Adressen vor Aufruf des Destruktors: ######### \n\n";
   cout << "Adresse von x1: " << &x1 << endl;
   cout << "Adresse von x2: " << &x2 << endl;
   cout << "Adresse von x3: " << &x3 << endl;
   cout << "Adresse von x4: " << &x4 << endl;
   cout << "Adresse von x5: " << &x5 << endl;
   return 0;
}
