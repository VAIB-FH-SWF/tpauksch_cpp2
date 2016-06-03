/*
 * Datum.cpp
 *
 *  Created on: 30.05.2016
 *      Author: Tim
 */

#include "Datum.h"
#include <iostream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

ostream& operator <<(ostream & os, const Datum & obj) {
   os << setfill('0') << setw(2) << obj.getTag  () << "."
      << setfill('0') << setw(2) << obj.getMonat() << "."
      << setfill('0') << setw(4) << obj.getJahr ();
   return os;
}

Datum::Datum(){
   this->tag   = 0;
   this->monat = 0;
   this->jahr  = 0;
}

Datum::Datum( uint tag, uint monat, uint jahr ) {
   this->tag   = tag;
   this->monat = monat;
   this->jahr  = jahr;

   if (!tagOk()){
      cout << "Ungültige Datumsangabe in: " << *this << endl;
   }else if (!monatOk()){
      cout << "Ungültige Datumsangabe in: " << *this << endl;
   }
}

bool Datum::monatOk (){
   if (monat <= 12 && monat >= 1){
      return true;
   }
   return false;
};

bool Datum::schaltjahr (){
   uint tmpJahr = this->jahr;
   bool result  = false;

   if (0 == (tmpJahr % 4)){
      result = true;
      if (0 == (tmpJahr % 100)){
         result = false;
         if (0 == (tmpJahr % 400)){
            result = true;
         }
      }
   }
   return result;
};

bool Datum::tagOk (){
   uint max = 0;

   switch (this->monat) {
      case 2:
         if(this->schaltjahr()){
             max = 29;
         } else {
             max = 28;
         };break;
      case 4:  max = 30 ;break;
      case 6:  max = 30 ;break;
      case 9:  max = 30 ;break;
      case 11: max = 30 ;break;
      default: max = 31 ;
   }

   if (this->tag <= max && this->tag >= 0){
      return true;
   }

   return false;
};
