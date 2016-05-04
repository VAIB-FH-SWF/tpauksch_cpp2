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
   cout << " ==== construktor (this = " << this << " )\n";
}

Class::Class(const Class &other){
   value = other.value;
   cout << " ==== copy-construktor (this = " << this << " other = " << &other << " )\n";
}

Class& Class::set_name(string _name){
   name = _name;
   return *this;
   cout << " ==== set_name (this = " << this << " )\n";
}

Class& Class::set_value(int _value){
   value = _value;
   return *this;
   cout << " ==== set_value (this = " << this << " )\n";
}

void Class::print(){
   cout << "Name:"  << name  << endl;
   cout << "Value:" << value << endl;
   cout << " ==== print (this = " << this << " )\n";
}

Class& Class::operator = ( const Class &other){
   value = other.value;
   return *this;
   cout << " ==== operator = (this = " << this << " other = " << &other << " )\n";
};

Class  Class::operator + ( const Class &other){
   Class Summe;
   Summe.value = other.value + value;
   return Summe;
   cout << " ==== operator + (this = " << this << " other = " << &other << " )\n";
};

Class::~Class(){
   cout << " ==== destructor (this = " << this << " )\n";
}

Class f ( Class arg){
   return arg;
};

Class g ( Class *arg){
   return *arg;
};

int main() {
   Class x1(11, "x1");
   Class x2 = x1;
   Class x3(33, "x3");
   x2.set_name("x2");
   return 0;
}
