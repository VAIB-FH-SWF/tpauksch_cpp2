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
// Definitionen
//=============================================================================

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

void Element::init_Element(){
   key  = 0;
   info = 0;
   next = NULL;
}

void Element::setKey(long key){
   this->key = key;
}

void Element::setInfo(long info){
   this->info = info;
}

void Element::setNext(Element *element){
   this->next = element;
}

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
// Funktionen
//=============================================================================

//=============================================================================
// Hauptprogramm
//=============================================================================

int main() {
   Element* listenanker = NULL;
   Element* cursor      = NULL;
   Element* ergebnis    = NULL;

   Element element1;
   Element element2;
   Element element3;
   Element element4;

   element1.init_Element();
   element2.init_Element();
   element3.init_Element();
   element4.init_Element();

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


   listenanker = &element1;
   ergebnis = findKey(3, *&listenanker, *&cursor);

   cout << "Listenelement gefunden: " << ergebnis << endl;
   cout << "key  = " << setw(10) << ergebnis->key << endl;
   cout << "info = " << setw(10) << ergebnis->info << endl;
   cout << "next = " << setw(10) << ergebnis->next << endl;

}
