/*
 * Vec3.h
 *
 *  Created on: 09.05.2016
 *      Author: Tim
 */

#ifndef VEC3_H_
#define VEC3_H_

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
     Vek3& set          ( double value_x=0.0, double value_y=0.0, double value_z=0.0 );
     Vek3& set_x        ( double value_x );
     Vek3& set_y        ( double value_y );
     Vek3& set_z        ( double value_z );
     Vek3& set_all      ( double value );
     Vek3& set_zero     ( );
     Vek3& set_unit_x   ( );
     Vek3& set_unit_y   ( );
     Vek3& set_unit_z   ( );
     Vek3& norm         ( );

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
};

#endif /* VEC3_H_ */
