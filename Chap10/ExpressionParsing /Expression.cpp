#include <string>
#include <cctype>
#include "Expression.h"

Expression::Expression()
    : myExpr("#"), myPosition(-1)
{}

bool Expression::read(istream &in)
{
  cout << "\nEnter arithmetic expression (# to stop): ";
  getline(in, myExpr);
  return (myExpr == "#");
}

bool Expression::isWellFormed()
{
  return validExpression() && myPosition == myExpr.length() - 1;
}

bool Expression::validExpression()
{
  if (validTerm())
  {
    char symbol = nextChar();
    if (symbol == '+' || symbol == '-')
      return validTerm();
    myPosition--;
    return true;
  }
  return false;
}




