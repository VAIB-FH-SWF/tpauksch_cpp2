//=============================================================================
//             Dateiname:   Vek3.cpp
//                Author:   Tim Pauksch
//      Praktikumsgruppe:   [V-10:30] - Is-VAI-B2A
//      Erstellungsdatum:   09.05.2016
//          Beschreibung:   Programmierung mit C++ 2,
//                          Aufgabe 6.2, Überladen von Operatoren
//                          Schnittpunkt der Schiffswege.
//              Compiler:   g++
//=============================================================================

#include <iostream>
#include <math.h>
#include <assert.h>
#include "Vec3.h"

using namespace std;

/**
 * Funktion:   Konstruktor für Verktor-Objekt
 * Eingabe:    double value_x, double value_y, double value_z
 * Ausgabe:    Leer
 */
Vek3::Vek3(double value_x, double value_y, double value_z) {
   x = value_x;
   y = value_y;
   z = value_z;
}

/**
 * Funktion:	Gibt die Länge des Vektors zurück
 * Eingabe: 	Leer
 * Ausgabe:		double laenge
 */
double Vek3::laenge() const {
   return pow((x * x + y * y + z * z), 1.0 / 2.0);
}

/**
 * Funktion:	Destruktor (Nur Testausgabe)
 * Eingabe: 	Leer
 * Ausgabe:		Leer
 */
Vek3::~Vek3() {
//   cout << "lösche Vek3-Objekt " << this << endl;
}

/**
 * Funktion:	Setzt x-Komponente des Vektors
 * Eingabe: 	double value_x
 * Ausgabe:		Pointer auf Objekt
 */
Vek3& Vek3::set_x(double value_x) {
   x = value_x;
   return *this;
}

/**
 * Funktion:   Setzt y-Komponente des Vektors
 * Eingabe:    double value_y
 * Ausgabe:    Pointer auf Objekt
 */
Vek3& Vek3::set_y(double value_y) {
   y = value_y;
   return *this;
}

/**
 * Funktion:   Setzt y-Komponente des Vektors
 * Eingabe:    double value_y
 * Ausgabe:    Pointer auf Objekt
 */
Vek3& Vek3::set_z(double value_z) {
   y = value_z;
   return *this;
}

/**
 * Funktion:   Setzt alle Komponenten des Vektors auf übergebenen Wert
 * Eingabe:    double value
 * Ausgabe:    Pointer auf Objekt
 */
Vek3& Vek3::set_all(double value) {
   x = value;
   y = value;
   z = value;
   return *this;
}

/**
 * Funktion:   Setzt alle Komponenten des Vektors auf Wert 0
 * Eingabe:    Leer
 * Ausgabe:    Pointer auf Objekt
 */
Vek3& Vek3::set_zero() {
   x = 0;
   y = 0;
   z = 0;
   return *this;
}

/**
 * Funktion:   Setzt Einheitsvektor-x
 * Eingabe:    Leer
 * Ausgabe:    Pointer auf Objekt
 */
Vek3& Vek3::set_unit_x() {
   x = 1.0;
   y = 0;
   z = 0;
   return *this;
}

/**
 * Funktion:   Setzt Einheitsvektor-y
 * Eingabe:    Leer
 * Ausgabe:    Pointer auf Objekt
 */
Vek3& Vek3::set_unit_y() {
   x = 0;
   y = 1.0;
   z = 0;
   return *this;
}

/**
 * Funktion:   Setzt Einheitsvektor-z
 * Eingabe:    Leer
 * Ausgabe:    Pointer auf Objekt
 */
Vek3& Vek3::set_unit_z() {
   x = 0;
   y = 0;
   z = 1.0;
   return *this;
}

/**
 * Funktion:   Normiert den Vektor
 * Eingabe:    Leer
 * Ausgabe:    Pointer auf Objekt
 */
Vek3& Vek3::norm() {
   double laenge = this->laenge();
   x *= laenge;
   y *= laenge;
   z *= laenge;
   return *this;
}

/**
 * Funktion:   Addiert übergebenen Vektor auf
 * Eingabe:    const Vek3 &other
 * Ausgabe:    Pointer auf Objekt
 */
Vek3& Vek3::operator +=(const Vek3 &other) {
   x += other.x;
   y += other.y;
   z += other.z;
   return *this;
}

/**
 * Funktion:   Zieht übergebenen Vektor vom Aktuellen ab
 * Eingabe:    const Vek3 &other
 * Ausgabe:    Pointer auf Objekt
 */
Vek3& Vek3::operator -=(const Vek3 &other) {
   x -= other.x;
   y -= other.y;
   z -= other.z;
   return *this;
}

/**
 * Funktion:   Multipliziert übergebenen Vektor auf
 * Eingabe:    const Vek3 &other
 * Ausgabe:    Pointer auf Objekt
 */
Vek3& Vek3::operator *=(double skalar) {
   x *= skalar;
   y *= skalar;
   z *= skalar;
   return *this;
}

/**
 * Funktion:   Dividiert  übergebenen Vektor vom Aktuellen
 * Eingabe:    const Vek3 &other
 * Ausgabe:    Pointer auf Objekt
 */
Vek3& Vek3::operator /=(double skalar) {
   x *= 1 / skalar;
   y *= 1 / skalar;
   z *= 1 / skalar;
   return *this;
}

/**
 * Funktion:   Invertiert Vektorkomponenten
 * Eingabe:    Leer
 * Ausgabe:    Vektor-Objekt
 */
Vek3 Vek3::operator -() {
   return Vek3(-x, -y, -z);
}

/**
 * Funktion:   Dient nur der Anzeige
 * Eingabe:    Leer
 * Ausgabe:    Pointer auf aktuelles Objekt
 */
Vek3 Vek3::operator +() {
   return *this;
}

/**
 * Funktion:	Addiert zwei übergebene Vektoren miteinander und gibt den Ergebnis-Vektor zurück
 * Eingabe: 	const Vek3 &vektor_1, const Vek3 &vektor_2
 * Ausgabe:		Vek3 result
 */
Vek3 operator +(const Vek3 &vektor_1, const Vek3 &vektor_2) {
   Vek3 result;
   result.x = vektor_1.x + vektor_2.x;
   result.y = vektor_1.y + vektor_2.y;
   result.z = vektor_1.z + vektor_2.z;
   return result;
}

/**
 * Funktion:   Subtrahiert zwei übergebene Vektoren miteinander und gibt den Ergebnis-Vektor zurück
 * Eingabe:    const Vek3 &vektor_1, const Vek3 &vektor_2
 * Ausgabe:    Vek3 result
 */
Vek3 operator -(const Vek3 &vektor_1, const Vek3 &vektor_2) {
   Vek3 result;
   result.x = vektor_1.x - vektor_2.x;
   result.y = vektor_1.y - vektor_2.y;
   result.z = vektor_1.z - vektor_2.z;
   return result;
}

/**
 * Funktion:   Bildet das Skalarprodukt zweier Vektoren und gibt den Ergebnisvektor zurück.
 * Eingabe:    const Vek3 &vektor_1, const Vek3 &vektor_2
 * Ausgabe:    Vek3 result
 */
double operator *(const Vek3 &vektor_1, const Vek3 &vektor_2) {
   double result = (vektor_1.x * vektor_2.x)
                 + (vektor_1.y * vektor_2.y)
                 + (vektor_1.z * vektor_2.z);
   return result;
}

/**
 * Funktion:   Multipliziert ein übergebenen Skalarwert mit den Komponenten eines übergebenen Vektors und gibt den Ergebnisvektor zurück.
 * Eingabe:    const double skalar, const Vek3 &vektor
 * Ausgabe:    Vek3 result
 */
Vek3 operator *(const double skalar, const Vek3 &vektor) {
   Vek3 result;
   result.x = vektor.x * skalar;
   result.y = vektor.y * skalar;
   result.z = vektor.z * skalar;
   return result;
}

/**
 * Funktion:   Dividiert die Komponenten eines übergebenen Vektors mit einem übergebenen Skalarwert und gibt den Ergebnisvektor zurück.
 * Eingabe:    const Vek3 &vektor, const double skalar
 * Ausgabe:    Vek3 result
 */
Vek3 operator /(const Vek3 &vektor, const double skalar) {
   Vek3 result;
   result = vektor.x / skalar;
   result = vektor.y / skalar;
   result = vektor.z / skalar;
   return result;
}

/**
 * Funktion:   Bildet das Kreuzprodukt zweier Vektoren und gibt den Ergebnisvektor zurück.
 * Eingabe:    const Vek3 &vektor_1, const Vek3 &vektor_2
 * Ausgabe:    Vek3 result
 */
Vek3 operator %(const Vek3 &vektor_1, const Vek3 &vektor_2) {
   Vek3 result;
   result.x = (vektor_1.y * vektor_2.z) - (vektor_1.z * vektor_2.y);
   result.y = (vektor_1.z * vektor_2.x) - (vektor_1.x * vektor_2.z);
   result.z = (vektor_1.x * vektor_2.y) - (vektor_1.y * vektor_2.x);
   return result;
}

/**
 * Funktion:   Lösung eines vektoriell dargestellten linearen Gleichungssystems nach der Sarrusschen Regel
 * Eingabe:    Vek3 s1, Vek3 s2, Vek3 s3, Vek3 r
 * Ausgabe:    Vek3 result - Lösungsvektor
 */
Vek3 lingl3 ( Vek3 s1, Vek3 s2, Vek3 s3, Vek3 r) {
   double D_0 = (s1 % s2) * s3;
   double D_0_Betrag = (D_0 * D_0) / D_0;

   // Prüfung auf Nenner = 0 bzw. Kollinearität (Ja, das Wort gibt es. Ich habe nachgesehen).
   assert (D_0_Betrag != 0);

   double D_1 = (r  % s2) * s3;
   double D_2 = (s1 % r ) * s3;
   double D_3 = (s1 % s2) * r ;

   double x1 = D_1 / D_0;
   double x2 = D_2 / D_0;
   double x3 = D_3 / D_0;

   Vek3 result(x1, x2, x3);
   return result;
}

/**
 * Funktion:   Ermittlung des Schnittpunkts für Funktion lingl3 (Auflösung der Gradengleichung)
 * Eingabe:    Vek3 stuetzvektor, double lambda, Vek3 richtungsvektor
 * Ausgabe:    Vek3 result - Schnittpunkt
 */
Vek3 schnittpunkt_lingl3(Vek3 stuetzvektor, double lambda, Vek3 richtungsvektor) {
   Vek3 result = stuetzvektor + (lambda * richtungsvektor);
   return result;
}

/**
 * Funktion:	Überladener Operator für den Ausgabestream um Vek3-Objekte formatiert auszugeben
 * Eingabe: 	ostream & os, const Vek3 & obj
 * Ausgabe:		ostream os
 */
ostream& operator <<(ostream & os, const Vek3 & obj) {
   os << "{ " << obj.get_x() << ", " << obj.get_y() << ", " << obj.get_z() << " }";
   return os;
}

int main(){
   cout << "Aufgabe 6.2, Überladen von Operatoren Schnittpunkt der Schiffswege." << endl;
   cout << endl;

   // Stützvektor der Ebenengleichung_1
   Vek3 p1(1,  1, 0);

   // Spaltenvektoren der Matrix für Lösung des Gleichungssystems nach Sarrusschen Regel
   Vek3 s1(2,  2, 0);
   Vek3 s2(1, -3, 0);
   Vek3 s3(0,  0, 1);

   // Rechte Seite des Gleichungssystems
   Vek3 r (7, -1, 0);

   // Ermittlung des Lösungsvektors
   Vek3 loesungsvektor = lingl3 ( s1, s2, s3, r );

   // Ermittlung des Schnittpunkts
   Vek3 schittpunkt    = schnittpunkt_lingl3 (p1, loesungsvektor.get_x(), s1);

   // Ergebnisausgaben
   cout << "Lösungsvektor " << loesungsvektor << endl;
   cout << "Schittpunkt "   << schittpunkt    << endl;

   cout << "Die Dauer für das Erreichen des Schnittpunktes für Schiff_1 beträgt: " << loesungsvektor.get_x() << "h" << endl;
   cout << "Die Dauer für das Erreichen des Schnittpunktes für Schiff_2 beträgt: " << loesungsvektor.get_y() << "h" << endl;

   /*
    * Zu Aufgabe 6.2:
    * Der bloße Schnittpunkt sagt nichts über das gleichzeitige Erreichen dessen aus. Entscheidend sind die Längen der Vektoren,
    * die etwas über die Geschwindigkeit der Schiffe aussagen. Ebenso wie Lambda_1 und Lambda_2 die etwas über die Dauer des
    * Erreichens aussagen. Diese müssten schon gleich sein damit beide auch gleichzeitig ankommen.
    */

   cout << endl;
   cout << "Programmende." << endl;

   return 0;
}
