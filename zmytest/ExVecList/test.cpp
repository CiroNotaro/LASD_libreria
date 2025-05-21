
#include <iostream>

/* ************************************************************************** */

#include "../../zlasdtest/container/container.hpp"
#include "../../zlasdtest/container/testable.hpp"
#include "../../zlasdtest/container/traversable.hpp"
#include "../../zlasdtest/container/mappable.hpp"
#include "../../zlasdtest/container/linear.hpp"

#include "../../zlasdtest/vector/vector.hpp"

#include "../../zlasdtest/list/list.hpp"

/* ************************************************************************** */

using namespace std;

/* ************************************************************************** */

void mystestVectorInt(uint & testnum, uint & testerr) 
{
    uint loctestnum = 0, loctesterr = 0;
    cout << endl << "Begin of Vector<int> Test:" << endl;
    try {
      // CASO VEC VUOTO
      {
        lasd::SortableVector<int> vec;
        lasd::SortableVector<int> vec2;
        Empty(loctestnum, loctesterr, vec, true);
        Size(loctestnum, loctesterr, vec, true, 0);
  
        GetFront(loctestnum, loctesterr, vec, false, 0);
        GetBack(loctestnum, loctesterr, vec, false, 0);
        SetAt(loctestnum, loctesterr, vec, false, 1, 0);
        GetAt(loctestnum, loctesterr, vec, false, 2, 0);
  
        Exists(loctestnum, loctesterr, vec, false, 0);
  
        TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);
        TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);
  
        FoldPreOrder(loctestnum, loctesterr, vec, true, &FoldAdd<int>, 0, 0);
        FoldPostOrder(loctestnum, loctesterr, vec, true, &FoldAdd<int>, 0, 0);

        EqualVector(loctestnum, loctesterr, vec, vec2, true);
        Size(loctestnum, loctesterr, vec2, true, 0);

      }

      // CASO VEC N
      {
        lasd::SortableVector<int> vec(5);
        Empty(loctestnum, loctesterr, vec, false);
        Size(loctestnum, loctesterr, vec, true, 5);

        SetAt(loctestnum, loctesterr, vec, true, 0, 5);
        SetAt(loctestnum, loctesterr, vec, true, 1, 4);
        SetAt(loctestnum, loctesterr, vec, true, 2, 3);
        SetAt(loctestnum, loctesterr, vec, true, 3, 2);
        SetAt(loctestnum, loctesterr, vec, true, 4, 1);

        TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);
        TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);

        GetFront(loctestnum, loctesterr, vec, true, 5);
        GetBack(loctestnum, loctesterr, vec, true, 1);

        vec.Sort();

        TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);
        TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);

        GetFront(loctestnum, loctesterr, vec, true, 1);
        GetBack(loctestnum, loctesterr, vec, true, 5);

        lasd::SortableVector<int> vec2(2);
        Empty(loctestnum, loctesterr, vec2, false);
        Size(loctestnum, loctesterr, vec2, true, 2);

        SetAt(loctestnum, loctesterr, vec2, true, 0, 1);
        SetAt(loctestnum, loctesterr, vec2, true, 1, 2);

        TraversePreOrder(loctestnum, loctesterr, vec2, true, &TraversePrint<int>);
        TraversePostOrder(loctestnum, loctesterr, vec2, true, &TraversePrint<int>);

        EqualVector(loctestnum, loctesterr, vec, vec2, false);
        
      }
    }
    catch (...) {
      loctestnum++; loctesterr++;
      cout << endl << "Unmanaged error! " << endl;
    }
    cout << "End of Vector<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}

void mystestVectorDouble(uint & testnum, uint & testerr) 
{
    uint loctestnum = 0, loctesterr = 0;
    cout << endl << "Begin of Vector<Double> Test:" << endl;
    try {
      // CASO VEC VUOTO
      {
        lasd::SortableVector<double> vec;
        lasd::SortableVector<double> vec2;
        Empty(loctestnum, loctesterr, vec, true);
        Size(loctestnum, loctesterr, vec, true, 0);
  
        GetFront(loctestnum, loctesterr, vec, false, 0.0);
        GetBack(loctestnum, loctesterr, vec, false, 0.0);
        SetAt(loctestnum, loctesterr, vec, false, 1, 1.3);
        GetAt(loctestnum, loctesterr, vec, false, 2, 1.3);
  
        Exists(loctestnum, loctesterr, vec, false, 0.0);
  
        TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<double>);
        TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<double>);
  
        FoldPreOrder(loctestnum, loctesterr, vec, true, &FoldAdd<double>, 0.0, 0.0);
        FoldPostOrder(loctestnum, loctesterr, vec, true, &FoldAdd<double>, 0.0, 0.0);

        EqualVector(loctestnum, loctesterr, vec, vec2, true);
        Size(loctestnum, loctesterr, vec2, true, 0);

      }

      // CASO VEC N
      {
        lasd::SortableVector<double> vec(5);
        Empty(loctestnum, loctesterr, vec, false);
        Size(loctestnum, loctesterr, vec, true, 5);

        SetAt(loctestnum, loctesterr, vec, true, 0, 5.4);
        SetAt(loctestnum, loctesterr, vec, true, 1, 40.2);
        SetAt(loctestnum, loctesterr, vec, true, 2, 0.0);
        SetAt(loctestnum, loctesterr, vec, true, 3, 2.1);
        SetAt(loctestnum, loctesterr, vec, true, 4, 1.0);

        TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<double>);
        TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<double>);

        GetFront(loctestnum, loctesterr, vec, true, 5.4);
        GetBack(loctestnum, loctesterr, vec, true, 1.0);

        vec.Sort();

        TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<double>);
        TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<double>);

        GetFront(loctestnum, loctesterr, vec, true, 0.0);
        GetBack(loctestnum, loctesterr, vec, true, 40.2);

        lasd::SortableVector<double> vec2(2);
        Empty(loctestnum, loctesterr, vec2, false);
        Size(loctestnum, loctesterr, vec2, true, 2);

        SetAt(loctestnum, loctesterr, vec2, true, 0, 1.1);
        SetAt(loctestnum, loctesterr, vec2, true, 1, 2.34);

        TraversePreOrder(loctestnum, loctesterr, vec2, true, &TraversePrint<double>);
        TraversePostOrder(loctestnum, loctesterr, vec2, true, &TraversePrint<double>);

        EqualVector(loctestnum, loctesterr, vec, vec2, false);
        
      }
    }
    catch (...) {
      loctestnum++; loctesterr++;
      cout << endl << "Unmanaged error! " << endl;
    }
    cout << "End of Vector<Double> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}

void mystestVectorString(uint & testnum, uint & testerr) {
    uint loctestnum = 0, loctesterr = 0;
    cout << endl << "Begin of Vector<string> Test:" << endl;
    try {
      lasd::SortableVector<string> vec(2);
  
      Empty(loctestnum, loctesterr, vec, false);
      Size(loctestnum, loctesterr, vec, true, 2);
  
      SetAt(loctestnum, loctesterr, vec, true, 0, string("A"));
      SetAt(loctestnum, loctesterr, vec, true, 1, string("B"));
  
      GetFront(loctestnum, loctesterr, vec, true, string("A"));
      GetBack(loctestnum, loctesterr, vec, true, string("B"));
  
      Exists(loctestnum, loctesterr, vec, true, string("A"));
  
      MapPreOrder(loctestnum, loctesterr, vec, true, [](string & str) { MapStringAppend(str, string(" ")); });
      TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<string>);
      FoldPreOrder(loctestnum, loctesterr, vec, true, &FoldStringConcatenate, string("X"), string("XA B "));
      FoldPostOrder(loctestnum, loctesterr, vec, true, &FoldStringConcatenate, string("X"), string("XB A "));
  
      Exists(loctestnum, loctesterr, vec, false, string("A"));
  
      lasd::SortableVector<string> copvec(vec);
      EqualVector(loctestnum, loctesterr, vec, copvec, true);
      MapPreOrder(loctestnum, loctesterr, vec, true, [](string & str) { MapStringAppend(str, string("!")); });
      NonEqualVector(loctestnum, loctesterr, vec, copvec, true);
  
      copvec = move(vec);
      FoldPreOrder(loctestnum, loctesterr, copvec, true, &FoldStringConcatenate, string("?"), string("?A !B !"));
  
      lasd::SortableVector<string> movvec(move(vec));
      FoldPreOrder(loctestnum, loctesterr, movvec, true, &FoldStringConcatenate, string("?"), string("?A B "));
      movvec.Sort();
      FoldPreOrder(loctestnum, loctesterr, movvec, true, &FoldStringConcatenate, string("?"), string("?A B "));
      SetAt(loctestnum, loctesterr, vec, false, 1, string(""));
      vec.Resize(1);
      SetAt(loctestnum, loctesterr, vec, true, 0, string("X"));
  
      movvec.Clear();
      Empty(loctestnum, loctesterr, movvec, true);
    }
    catch (...) {
      loctestnum++; loctesterr++;
      cout << endl << "Unmanaged error! " << endl;
    }
    cout << "End of Vector<string> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
    testnum += loctestnum;
    testerr += loctesterr;
  }

void mystestVector(uint & testnum, uint & testerr) 
{
    uint loctestnum = 0, loctesterr = 0;
    mystestVectorInt(loctestnum, loctesterr);
    mystestVectorDouble(loctestnum, loctesterr);
    mystestVectorString(loctestnum, loctesterr);
    testnum += loctestnum;
    testerr += loctesterr;
    cout << endl << "Exercise VecList - Vector (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
}

void runExVecList(uint & testnum, uint & testerr) 
{
  mystestVector(testnum, testerr);
  cout << endl << "Exercise VecList (MY TEST) (Errors/Tests: " << testerr << "/" << testnum << ")" << endl;
}