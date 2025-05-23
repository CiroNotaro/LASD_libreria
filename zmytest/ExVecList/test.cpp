
#include <iostream>

/* ************************************************************************** */

#include "../../zlasdtest/container/container.hpp"
#include "../../zlasdtest/container/testable.hpp"
#include "../../zlasdtest/container/traversable.hpp"
#include "../../zlasdtest/container/mappable.hpp"
#include "../../zlasdtest/container/linear.hpp"

#include "../../zlasdtest/vector/vector.hpp"

#include "../../zlasdtest/list/list.hpp"

#include "../utils.hpp"

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
        print_section("0 ELEMENT");
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

      // CASO VEC 1
      {
        print_section("1 ELEMENT");
        lasd::SortableVector<int> vec(1);
        Empty(loctestnum, loctesterr, vec, false);
        Size(loctestnum, loctesterr, vec, true, 1);

        SetAt(loctestnum, loctesterr, vec, true, 0, 5);
        SetAt(loctestnum, loctesterr, vec, false, 1, 3);

        TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);
        TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);

        GetFront(loctestnum, loctesterr, vec, true, 5);
        GetBack(loctestnum, loctesterr, vec, true, 5);

        FoldPreOrder(loctestnum, loctesterr, vec, true, &FoldAdd<int>, 0, 5);
        FoldPostOrder(loctestnum, loctesterr, vec, true, &FoldAdd<int>, 0, 5);

        vec.Sort();

        TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);
        TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);

        GetFront(loctestnum, loctesterr, vec, true, 5);
        GetBack(loctestnum, loctesterr, vec, true, 5);

        lasd::SortableVector<int> vec2(1);
        Empty(loctestnum, loctesterr, vec2, false);
        Size(loctestnum, loctesterr, vec2, true, 1);

        SetAt(loctestnum, loctesterr, vec2, true, 0, 1);

        TraversePreOrder(loctestnum, loctesterr, vec2, true, &TraversePrint<int>);
        TraversePostOrder(loctestnum, loctesterr, vec2, true, &TraversePrint<int>);

        FoldPreOrder(loctestnum, loctesterr, vec2, true, &FoldAdd<int>, 0, 1);
        FoldPostOrder(loctestnum, loctesterr, vec2, true, &FoldAdd<int>, 0, 1);

        EqualVector(loctestnum, loctesterr, vec, vec2, false);
        
      }

      // CASO VEC N
      {
        print_section("N ELEMENTS");
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

        FoldPreOrder(loctestnum, loctesterr, vec, true, &FoldAdd<int>, 0, 15);
        FoldPostOrder(loctestnum, loctesterr, vec, true, &FoldAdd<int>, 0, 15);

        print_subsection("SORT");
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

        FoldPreOrder(loctestnum, loctesterr, vec2, true, &FoldAdd<int>, 0, 3);
        FoldPostOrder(loctestnum, loctesterr, vec2, true, &FoldAdd<int>, 0, 3);

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
        print_section("0 ELEMENT");
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

      // CASO VEC 1
      {
        print_section("1 ELEMENT");
        lasd::SortableVector<double> vec(1);
        Empty(loctestnum, loctesterr, vec, false);
        Size(loctestnum, loctesterr, vec, true, 1);

        SetAt(loctestnum, loctesterr, vec, true, 0, 5.4);
        SetAt(loctestnum, loctesterr, vec, false, 1, 3.2);

        TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<double>);
        TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<double>);

        GetFront(loctestnum, loctesterr, vec, true, 5.4);
        GetBack(loctestnum, loctesterr, vec, true, 5.4);

        FoldPreOrder(loctestnum, loctesterr, vec, true, &FoldAdd<double>, 0.0, 5.4);
        FoldPostOrder(loctestnum, loctesterr, vec, true, &FoldAdd<double>, 0.0, 5.4);

        vec.Sort();

        TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<double>);
        TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<double>);

        GetFront(loctestnum, loctesterr, vec, true, 5.4);
        GetBack(loctestnum, loctesterr, vec, true, 5.4);

        lasd::SortableVector<double> vec2(1);
        Empty(loctestnum, loctesterr, vec2, false);
        Size(loctestnum, loctesterr, vec2, true, 1);

        SetAt(loctestnum, loctesterr, vec2, true, 0, 1.1);

        TraversePreOrder(loctestnum, loctesterr, vec2, true, &TraversePrint<double>);
        TraversePostOrder(loctestnum, loctesterr, vec2, true, &TraversePrint<double>);

        FoldPreOrder(loctestnum, loctesterr, vec2, true, &FoldAdd<double>, 0.0, 1.1);
        FoldPostOrder(loctestnum, loctesterr, vec2, true, &FoldAdd<double>, 0.0, 1.1);

        EqualVector(loctestnum, loctesterr, vec, vec2, false);
        
      }

      // CASO VEC N
      {
        print_section("N ELEMENTS");
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

        FoldPreOrder(loctestnum, loctesterr, vec, true, &FoldAdd<double>, 0.0, 48.7);
        FoldPostOrder(loctestnum, loctesterr, vec, true, &FoldAdd<double>, 0.0, 48.7);

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

        FoldPreOrder(loctestnum, loctesterr, vec2, true, &FoldAdd<double>, 0.0, 3.44);
        FoldPostOrder(loctestnum, loctesterr, vec2, true, &FoldAdd<double>, 0.0, 3.44);

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
      
      // CASO 0
      {
        print_section("0 ELEMENT");
        lasd::SortableVector<string> vec(0);
    
        Empty(loctestnum, loctesterr, vec, true);
        Size(loctestnum, loctesterr, vec, true, 0);
    
        GetFront(loctestnum, loctesterr, vec, false, string(""));
        GetBack(loctestnum, loctesterr, vec, false, string(""));

        SetAt(loctestnum, loctesterr, vec, false, 0, string("COBOL"));
        GetAt(loctestnum, loctesterr, vec, false, 0, string("COBOL"));

        TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<string>);
        TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<string>);
        
        FoldPreOrder(loctestnum, loctesterr, vec, true, &FoldStringConcatenate, string("X"), string("X"));
        FoldPostOrder(loctestnum, loctesterr, vec, true, &FoldStringConcatenate, string("X"), string("X"));

        TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<string>);
        TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<string>);
      }

      // CASO 1
      {
        print_section("1 ELEMENT");
        lasd::SortableVector<string> vec(1);
    
        Empty(loctestnum, loctesterr, vec, false);
        Size(loctestnum, loctesterr, vec, true, 1);
    
        SetAt(loctestnum, loctesterr, vec, true, 0, string("COBOL"));
        GetAt(loctestnum, loctesterr, vec, true, 0, string("COBOL"));
        GetAt(loctestnum, loctesterr, vec, false, 1, string("C++"));

        GetFront(loctestnum, loctesterr, vec, true, string("COBOL"));
        GetBack(loctestnum, loctesterr, vec, true, string("COBOL"));

        TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<string>);
        TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<string>);
        
        FoldPreOrder(loctestnum, loctesterr, vec, false, &FoldStringConcatenate, string(""), string(""));
        FoldPostOrder(loctestnum, loctesterr, vec, false, &FoldStringConcatenate, string(""), string(""));

        Exists(loctestnum, loctesterr, vec, true, string("COBOL"));

        print_subsection("RESIZE 0");
        vec.Resize(0);

        Empty(loctestnum, loctesterr, vec, true);
        Size(loctestnum, loctesterr, vec, true, 0);

        SetAt(loctestnum, loctesterr, vec, false, 0, string("COBOL"));
        GetAt(loctestnum, loctesterr, vec, false, 0, string("COBOL"));
        GetAt(loctestnum, loctesterr, vec, false, 1, string("C++"));

        Exists(loctestnum, loctesterr, vec, false, string("COBOL"));

      }
      
      {
        print_section("N ELEMENTS");
        lasd::SortableVector<string> vec(3);
        
        Empty(loctestnum, loctesterr, vec, false);
        Size(loctestnum, loctesterr, vec, true, 3);
    
        SetAt(loctestnum, loctesterr, vec, true, 0, string("C"));
        SetAt(loctestnum, loctesterr, vec, true, 1, string("C++"));
        SetAt(loctestnum, loctesterr, vec, true, 2, string("Java"));
        SetAt(loctestnum, loctesterr, vec, false, 3, string("COBOL"));
    
        GetFront(loctestnum, loctesterr, vec, true, string("C"));
        GetBack(loctestnum, loctesterr, vec, true, string("Java"));
    
        Exists(loctestnum, loctesterr, vec, true, string("Java"));
        Exists(loctestnum, loctesterr, vec, false, string("COBOL"));
    
        TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<string>);
        TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<string>);

        MapPreOrder(loctestnum, loctesterr, vec, true, [](string & str) { MapStringAppend(str, string("?")); });
        
        TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<string>);

        FoldPreOrder(loctestnum, loctesterr, vec, true, &FoldStringConcatenate, string("X"), string("XC?C++?Java?"));
        FoldPostOrder(loctestnum, loctesterr, vec, true, &FoldStringConcatenate, string("X"), string("XJava?C++?C?"));
    
        Exists(loctestnum, loctesterr, vec, false, string("Java"));
    
        print_subsection("COPY");
        lasd::SortableVector<string> copvec(vec);
        EqualVector(loctestnum, loctesterr, vec, copvec, true);
        MapPreOrder(loctestnum, loctesterr, copvec, true, [](string & str) { MapStringAppend(str, string("!")); });

        TraversePreOrder(loctestnum, loctesterr, copvec, true, &TraversePrint<string>);
    
        Empty(loctestnum, loctesterr, vec, false);

        print_subsection("MOVE");
        lasd::SortableVector<string> movvec(move(vec));
        Empty(loctestnum, loctesterr, vec, true);
        Empty(loctestnum, loctesterr, movvec, false);

        TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<string>);
        TraversePreOrder(loctestnum, loctesterr, movvec, true, &TraversePrint<string>);
      }
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