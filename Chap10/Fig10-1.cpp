//
// @Time   : 2021/9/19 21:35
// @Author : junstat@163.com

#include <iostream>

using namespace std;

double power(double x, unsigned n);

unsigned factorial(unsigned n);

unsigned fib(unsigned n);

void recBinarySearch(int a[], int first, int last,
                     int item, bool &found, int &loc);

void testPower() {
  cout << "3 ^ 5 = " << power(3, 5) << endl;
}

void testFactorial() {
  int n = 5;
  for (int i = 0; i <= n; i++)
    cout << i << "! = " << factorial(i) << endl;
}

void testRecBinarySearch() {
  int nums[] = {11, 22, 33, 44, 55, 66, 77, 88, 99};
  int numsLen = sizeof(nums) / sizeof(nums[0]);
  bool found = false;
  int loc = -1;
  int item = 66;
  recBinarySearch(nums, 0, numsLen - 1, item, found, loc);
  if (found)
    cout << "found " << item << " in the array, nums[" << loc << "] = " << nums[loc] << endl;
  else
    cout << "not found." << endl;
}

int main(int argc, char **argv) {
  testRecBinarySearch();
  return 0;
}

// 计算x的n次幂
double power(double x, unsigned n) {
  if (n == 0)
    return 1.0;
  // else
  return x * power(x, n - 1);
}

unsigned factorial(unsigned n) {
  if (n == 0 || n == 1)
    return 1;
  // else
  return n * factorial(n - 1);
}

// Example of Inappropriate Recursion: Fibonacci Numbers
unsigned fib(unsigned n)
/*-------------------------------------------------------------------------
  Precondition:  None.
  Postcondition: n-th Fibonacci number is returned.
 ------------------------------------------------------------------------*/
{
  if (n <= 2)
    return 1;       // anchor case
  // else
  return fib(n - 1) + fib(n - 2);     // inductive case (n > 2)
}


void recBinarySearch(int a[], int first, int last,
                     int item, bool &found, int &loc)
/*-------------------------------------------------------------------------
  Recursively search sub(list) a[first], ..., a[last]
  for item using a binary search.

  Precondition:  Elements of a are in ascending order;
      items has the same type as the array elements;
  Postcondition: found == true and loc == position of item
      if the search is successful; otherwise, found is false.
 ------------------------------------------------------------------------*/
{
  if (first > last)     // anchor 1 --- empty sublist
    found = false;
  else {                        // inductive case:
    loc = (first + last) / 2;
    if (item < a[loc])
      recBinarySearch(a, first, loc - 1, item, found, loc);
    else if (item > a[loc])
      recBinarySearch(a, loc + 1, last, item, found, loc);
    else
      found = true;     // anchor 2 -- item found
  }
}