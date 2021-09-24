//
// @Time   : 2021/9/5 21:49
// @Author : junstat@163.com

#include <iostream>

using namespace std;

#include "Time.h"

/*** Utility Functions -- Prototypes ***/

int toMilitary(unsigned hours, unsigned minutes, char am_pm);

void Time::set(unsigned hours, unsigned minutes, char am_pm)
{
  // Check class invariant
  if (hours >= 1 && hours <= 12 &&
      minutes >= 0 && minutes <= 59 &&
      (am_pm == 'A' || am_pm == 'P'))
  {
    myHours = hours;
    myMinutes = minutes;
    myAMorPM = am_pm;
    myMilTime = toMilitary(hours, minutes, am_pm);
  }
  else
    cerr << "** Can't set time with these values **\n";
  // Object's data members remain unchanged
}

void Time::display(ostream &out) const
{
  out << myHours << ':'
      << (myMinutes < 10 ? "0" : "") << myMinutes
      << ' ' << myAMorPM << ".M. ("
      << myMilTime << " mil. time)";
}

int toMilitary(unsigned int hours, unsigned int minutes, char am_pm)
{
  if (hours == 12)
    hours = 0;

  return hours * 100 + minutes + (am_pm == 'P' ? 1200 : 0);
}




