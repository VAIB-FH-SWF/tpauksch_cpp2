/*
 * Datum.h
 *
 *  Created on: 30.05.2016
 *      Author: Tim
 */

#ifndef DATUM_H_
#define DATUM_H_

typedef unsigned int uint;

class Datum {
   public:
      //==============LIFECYCLE=============================================================
      Datum();
      Datum( uint tag, uint monat, uint jahr);

      //==============ACCESSORS=============================================================
      uint getTag     () const { return tag; }
      uint getMonat   () const { return monat; }
      uint getJahr    () const { return jahr; }

   public:
      bool monatOk    ();
      bool tagOk      ();
      bool schaltjahr ();

   private:
      //==============DATA MEMBERS==========================================================
      uint tag;
      uint monat;
      uint jahr;
};

#endif /* DATUM_H_ */
