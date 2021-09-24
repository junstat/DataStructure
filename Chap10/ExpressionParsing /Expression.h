/*-- Expression.h ---------------------------------------------------------
  This header file contains the declaration of a class Expression that
  models the parsing of simplified arithmetic expressions given by the
  syntax rules:
      expression --> term + term | term - term | term
      term --> factor * factor | factor / factor | factor
      factor --> (expression) | letter | digit

  Basic Operations:
  Constructor:        Constructs a default empty expression
  read():             Inputs string to be checked for a well-formed
                        expression
  isWellFormed():     Checks if entire string is a well-formed expression
                        according to the preceding syntax rules
 ------------------------------------------------------------------------*/

#include <iostream>

using namespace std;

class Expression
{
public:
  Expression();

  bool read(istream &in);

  bool isWellFormed();

  bool validExpression();

  bool validTerm();

  bool validTFactor();

  char nextChar();

private:
  string myExpr;
  int myPosition;
};