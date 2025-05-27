#include "ExVecList/test.hpp"
#include "ExSetVecSetList/test.hpp"
#include "ExHeap/test.hpp"
#include "ExPQ/test.hpp"

/* ************************************************************************** */

#include <iostream>

using namespace std;

/* ************************************************************************** */

void mytest() {
  cout << endl << "~*~#~*~ MY TEST ~*~#~*~ " << endl;

  uint loctestnum, loctesterr;
  uint stestnum = 0, stesterr = 0;

  loctestnum = 0; loctesterr = 0;
  runExVecList(loctestnum, loctesterr);
  stestnum += loctestnum; stesterr += loctesterr;

  loctestnum = 0; loctesterr = 0;
  runExSetVecSetList(loctestnum, loctesterr);
  stestnum += loctestnum; stesterr += loctesterr;

  cout << endl << "Exercise 1 (MY TEST) (Errors/Tests: " << stesterr << "/" << stestnum << ")\n";

  loctestnum = 0; loctesterr = 0;
  runExHeap(loctestnum, loctesterr);
  stestnum += loctestnum; stesterr += loctesterr;

  loctestnum = 0; loctesterr = 0;
  runExPQ(loctestnum, loctesterr);
  stestnum += loctestnum; stesterr += loctesterr;

  cout << endl << "Exercise 1 (MY TEST) (Errors/Tests: " << stesterr << "/" << stestnum << ")\n";
}
