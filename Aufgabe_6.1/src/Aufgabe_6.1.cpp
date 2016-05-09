//=============================================================================
//             Dateiname:   Vek3.cpp
//                Author:   Tim Pauksch
//      Praktikumsgruppe:   [V-10:30] - Is-VAI-B2A
//      Erstellungsdatum:   09.05.2016
//          Beschreibung:   Programmierung mit C++ 2,
//                          Aufgabe 6.1, Überladen von Operatoren
//                          Implementierung der Klasse Vek3.
//              Compiler:   g++
//=============================================================================
#include <iostream>           // Für Textausgabe in Konsole

const unsigned int N = 100;

using namespace std;

/**
 * Klasse Testklasse.
 * Diese Klasse hat die Aufgabe das Verständnis für die Abläufe in einer Klasse zu vertiefen.
 * Beispielsweise sind in allen Methoden Aufrufe für Konsolen-Ausgaben vorhanden um die
 * Reihenfolge des Aufrufs und die Adresse des zugehörigen Objekts zu bestimmen
 */
class Vek3{

   // Liste öffentlicher Elemente der Klasse.
   public:
   //==============LIFECYCLE=============================================================
     Vek3(double value_x=0.0, double value_y=0.0, double value_z=0.0);

     ~Vek3();

   //==============ACCESSORS=============================================================
     double get_x  () const { return x; }
     double get_y  () const { return y; }
     double get_z  () const { return z; }
     double laenge () const;

   //==============MUTATORS==============================================================
     Vek3& set      ( double value_x=0.0, double value_y=0.0, double value_z=0.0 );
     Vek3& set_x    ( double value_x );
     Vek3& set_y    ( double value_y );
     Vek3& set_z    ( double value_z );
     Vek3& set_all  ( double value );
     Vek3& set_zero ( );
     Vek3& unit_x   ( );
     Vek3& unit_y   ( );
     Vek3& unit_z   ( );
     Vek3& norm     ( );

   //==============OPERATORS=============================================================
     Vek3& operator += ( const Vek3 &other);
     Vek3& operator -= ( const Vek3 &other);
     Vek3& operator *= ( double s);
     Vek3& operator /= ( double s);

     Vek3  operator +  ( );
     Vek3  operator -  ( );

     friend Vek3     operator +  ( const Vek3   &vektor_1, const Vek3   &vektor_2 );
     friend Vek3     operator -  ( const Vek3   &vektor_1, const Vek3   &vektor_2 );
     friend double   operator *  ( const Vek3   &vektor_1, const Vek3   &vektor_2 );
     friend Vek3     operator *  ( const Vek3   &vektor,   const double skalar  );
     friend Vek3     operator *  ( const double skalar,    const Vek3   &vektor );
     friend Vek3     operator /  ( const Vek3   &vektor,   const double skalar  );
     friend Vek3     operator %  ( const Vek3   &vektor_1, const Vek3   &vektor_2 );


   private:
   //==============DATA MEMBERS==========================================================
      double x;
      double y;
      double z;
//      double laenge;
//      double unit_x;
//      double unit_y;
//      double unit_z;
};

ostream& operator << ( ostream& outputStream, const Vek3& obj );

int main() {
   return 0;
}
