//=============================================================================
//             Dateiname:   LinkedList.cpp
//                Author:   Tim Pauksch
//      Praktikumsgruppe:   [V-10:30] - Is-VAI-B2A
//      Erstellungsdatum:   23.03.2016
//          Beschreibung:   Programmierung mit C++ 2,
//                          Aufgabe 3.1, Verkettete Listen.
//                          Einfach verkettete Liste aus
//                          statischen Elementen.
//              Compiler:   g++
//=============================================================================
#include <iostream>           // Für Textausgabe in Konsole
#include <fstream>            // Für Dateiein- und ausgabe.
#include <cstdlib>            // Für error(1).
#include <iomanip>            // Für setw(3).

using namespace std;

//=============================================================================
// Strukturen
//=============================================================================

struct Element {
   long            key;                         // Schlüssel des Listenelements.
   long            info;                        // die im Listenenlement zu verwaltende Information.
   struct Element *next;                        // Zeiger auf das Nächste Element.
   void            init_Element();              // Initialisierung der Element-Werte.
   void            setKey(long key);
   void            setInfo(long info);
   void            setNext(Element *element);
};

/*
 * Funktion:            Initialisiert die Strukturelemente.
 * Eingabe Parameter:   Keiner.
 * Rückgabewert:        Keiner.
 */
void Element::init_Element(){
   key  = 0;
   info = 0;
   next = NULL;
}

/*
 * Funktion:            Setzt den key-Wert.
 * Eingabe Parameter:   long key.
 * Rückgabewert:        Keiner.
 */
void Element::setKey(long key){
   this->key = key;
}

/*
 * Funktion:            Setzt den info-Wert.
 * Eingabe Parameter:   long info.
 * Rückgabewert:        Keiner.
 */
void Element::setInfo(long info){
   this->info = info;
}

/*
 * Funktion:            Setzt die Adresse des nächsten Elements.
 * Eingabe Parameter:   Pointer des Typs Element.
 * Rückgabewert:        Keiner.
 */
void Element::setNext(Element *element){
   this->next = element;
}

/*
 * Funktion:            Findet das Element mit dem zugehörigen Key und gibt
 *                      einen Pointer auf die Adresse zurück.
 * Eingabe Parameter:   Pointer des Typs Element.
 * Rückgabewert:        Keiner.
 */
Element* findKey(long key, Element *listenanker, Element *curser){
   Element *ergebnisZeiger = NULL;
   curser = listenanker;

   while((curser->next != NULL)){
      if (curser->key == key){
          ergebnisZeiger = curser;
      }
      curser = curser->next;
   }

   return ergebnisZeiger;
};

//=============================================================================
// Hauptprogramm
//=============================================================================

int main() {

   // Initialisierung der Pointer.
   Element* listenanker = NULL;
   Element* cursor      = NULL;
   Element* ergebnis    = NULL;

   // Initialisierung der Elemente.
   Element element1;
   Element element2;
   Element element3;
   Element element4;

   // Initialisierung der Element-Werte.
   element1.init_Element();
   element2.init_Element();
   element3.init_Element();
   element4.init_Element();

   // Setzen der Element-Werte.
   element1.setKey(1);
   element2.setKey(2);
   element3.setKey(3);
   element4.setKey(4);

   element1.setInfo(11);
   element2.setInfo(22);
   element3.setInfo(33);
   element4.setInfo(44);

   element1.setNext(&element2);
   element2.setNext(&element3);
   element3.setNext(&element4);
   element4.setNext(NULL);

   // Zuordnung der ersten Adresse an den Listenanker.
   listenanker = &element1;

   // Suche über die Verkettete Liste.
   ergebnis = findKey(3, *&listenanker, *&cursor);

   // Ausgabe
   cout << "Listenelement gefunden: " << ergebnis << endl;
   cout << "key  = " << setw(10) << ergebnis->key << endl;
   cout << "info = " << setw(10) << ergebnis->info << endl;
   cout << "next = " << setw(10) << ergebnis->next << endl;

   return 0;
}
