// This code implementation is the intellectual property of
// the RD44 GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4UItokenNum.hh,v 2.0 1998/07/02 17:08:13 gunter Exp $
// GEANT4 tag $Name: geant4-00 $
//
// G4UItokenNum.hh

#ifndef G4UItokenNum_hh
#define G4UItokenNum_hh 1
#include "globals.hh"


enum  tokenNum {
  IDENTIFIER = 257,
  CONSTINT   = 258,
  CONSTDOUBLE= 259,
  CONSTCHAR  = 260,
  CONSTSTRING= 261,
  GT         = 262,
  GE         = 263,
  LT         = 264,
  LE         = 265,
  EQ         = 266,
  NE         = 267,
  //LOGICALNOT = 268,
  LOGICALOR  = 269,
  LOGICALAND = 270
};


typedef struct yystype {
    tokenNum      type;
    double   D;
    int      I;
    char     C;
    G4String S;
    int operator==(const yystype &right) const
    { return (this == &right); }
} yystype;
 
#endif