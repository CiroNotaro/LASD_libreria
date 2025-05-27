#include <iostream>

/* ************************************************************************** */

#include "../../zlasdtest/container/container.hpp"
#include "../../zlasdtest/container/testable.hpp"
#include "../../zlasdtest/container/dictionary.hpp"
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
        print_section("0 ELEMENTS");
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
        print_section("1 ELEMENTS");
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
        print_section("0 ELEMENTS");
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
        print_section("1 ELEMENTS");
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

void mystestVectorString(uint & testnum, uint & testerr) 
{
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of Vector<string> Test:" << endl;
  try {
    
    // CASO 0
    {
      print_section("0 ELEMENTS");
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
      print_section("1 ELEMENTS");
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

      vec.Resize(0);

      Empty(loctestnum, loctesterr, vec, true);
      Size(loctestnum, loctesterr, vec, true, 0);

      SetAt(loctestnum, loctesterr, vec, false, 0, string("COBOL"));
      GetAt(loctestnum, loctesterr, vec, false, 0, string("COBOL"));
      GetAt(loctestnum, loctesterr, vec, false, 1, string("C++"));

      Exists(loctestnum, loctesterr, vec, false, string("COBOL"));

    }

    // CASO N
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
  
      lasd::SortableVector<string> copvec(vec);
      EqualVector(loctestnum, loctesterr, vec, copvec, true);
      MapPreOrder(loctestnum, loctesterr, copvec, true, [](string & str) { MapStringAppend(str, string("!")); });

      TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<string>);
      TraversePreOrder(loctestnum, loctesterr, copvec, true, &TraversePrint<string>);
  
      Empty(loctestnum, loctesterr, vec, false);

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

// LIST //

void mystestListInt(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of List<int> Test:" << endl;
  try {
    // CASO 0
    {
      print_section("0 ELEMENTS");
      lasd::List<int> lst;
      Empty(loctestnum, loctesterr, lst, true);
      Size(loctestnum, loctesterr, lst, true, 0);

      GetFront(loctestnum, loctesterr, lst, false, 0);
      GetBack(loctestnum, loctesterr, lst, false, 0);

      Exists(loctestnum, loctesterr, lst, false, 0);

      TraversePreOrder(loctestnum, loctesterr, lst, true, &TraversePrint<int>);
      TraversePostOrder(loctestnum, loctesterr, lst, true, &TraversePrint<int>);

      FoldPreOrder(loctestnum, loctesterr, lst, true, &FoldAdd<int>, 0, 0);
      FoldPostOrder(loctestnum, loctesterr, lst, true, &FoldAdd<int>, 0, 0);

      RemoveFromFront(loctestnum, loctesterr, lst, false);
      FrontNRemove(loctestnum, loctesterr, lst, false, 0);

      RemoveFromBack(loctestnum, loctesterr, lst, false);
      BackNRemove(loctestnum, loctesterr, lst, false, 0);

      Exists(loctestnum, loctesterr, lst, false, 0);
    }

    // CASO 1
    {
      print_section("1 ELEMENTS");
      lasd::List<int> lst;
      Empty(loctestnum, loctesterr, lst, true);
      Size(loctestnum, loctesterr, lst, true, 0);

      InsertAtFront(loctestnum, loctesterr, lst, true, 5);
      Empty(loctestnum, loctesterr, lst, false);
      Size(loctestnum, loctesterr, lst, true, 1);

      GetFront(loctestnum, loctesterr, lst, true, 5);
      GetBack(loctestnum, loctesterr, lst, true, 5);

      Exists(loctestnum, loctesterr, lst, true, 5);

      TraversePreOrder(loctestnum, loctesterr, lst, true, &TraversePrint<int>);
      TraversePostOrder(loctestnum, loctesterr, lst, true, &TraversePrint<int>);

      FoldPreOrder(loctestnum, loctesterr, lst, true, &FoldAdd<int>, 0, 5);
      FoldPostOrder(loctestnum, loctesterr, lst, true, &FoldAdd<int>, 0, 5);

      RemoveFromFront(loctestnum, loctesterr, lst, true);
      InsertAtFront(loctestnum, loctesterr, lst, true, 5);
      FrontNRemove(loctestnum, loctesterr, lst, true, 5);
      FrontNRemove(loctestnum, loctesterr, lst, false, 3);
      TraversePreOrder(loctestnum, loctesterr, lst, true, &TraversePrint<int>);

      InsertAtFront(loctestnum, loctesterr, lst, true, 5);

      RemoveFromBack(loctestnum, loctesterr, lst, true);
      InsertAtFront(loctestnum, loctesterr, lst, true, 5);
      BackNRemove(loctestnum, loctesterr, lst, true, 5);
      BackNRemove(loctestnum, loctesterr, lst, false, 3);
      TraversePreOrder(loctestnum, loctesterr, lst, true, &TraversePrint<int>);

      Exists(loctestnum, loctesterr, lst, false, 0);
    }

    // CASO N
    {
      print_section("N ELEMENTS");
      lasd::List<int> lst;
      
      InsertAtFront(loctestnum, loctesterr, lst, true, -7);
      InsertAtFront(loctestnum, loctesterr, lst, true, 14);
      InsertAtFront(loctestnum, loctesterr, lst, true, 3);
      InsertAtFront(loctestnum, loctesterr, lst, true, 8);
      InsertAtFront(loctestnum, loctesterr, lst, true, -1);
      InsertAtBack(loctestnum, loctesterr, lst, true, 42);
      InsertAtBack(loctestnum, loctesterr, lst, true, -5);
      InsertAtBack(loctestnum, loctesterr, lst, true, 19);

      GetFront(loctestnum, loctesterr, lst, true, -1);
      GetBack(loctestnum, loctesterr, lst, true, 19);

      SetFront(loctestnum, loctesterr, lst, true, 0);
      SetBack(loctestnum, loctesterr, lst, true, 100);

      GetAt(loctestnum, loctesterr, lst, true, 2, 3);
      SetAt(loctestnum, loctesterr, lst, true, 2, -99);

      GetFront(loctestnum, loctesterr, lst, true, 0);
      GetBack(loctestnum, loctesterr, lst, true, 100);
      Exists(loctestnum, loctesterr, lst, true, 42);

      TraversePreOrder(loctestnum, loctesterr, lst, true, &TraversePrint<int>);
      TraversePostOrder(loctestnum, loctesterr, lst, true, &TraversePrint<int>);

      FoldPreOrder(loctestnum, loctesterr, lst, true, &FoldAdd<int>, 0, 53);
      FoldPostOrder(loctestnum, loctesterr, lst, true, &FoldMultiply<int>, 1, 0);

      RemoveFromFront(loctestnum, loctesterr, lst, true);
      FrontNRemove(loctestnum, loctesterr, lst, true, 8);
      FoldPostOrder(loctestnum, loctesterr, lst, true, &FoldAdd<int>, 0, 45);

      lasd::List<int> coplst(lst);
      EqualList(loctestnum, loctesterr, lst, coplst, true);
      EqualLinear(loctestnum, loctesterr, lst, coplst, true);

      MapPreOrder(loctestnum, loctesterr, lst, true, &MapIncrement<int>);
      TraversePreOrder(loctestnum, loctesterr, lst, true, &TraversePrint<int>);
      NonEqualList(loctestnum, loctesterr, lst, coplst, true);

      InsertAtFront(loctestnum, loctesterr, lst, true, -99);
      InsertAtBack(loctestnum, loctesterr, lst, true, 77);

      TraversePostOrder(loctestnum, loctesterr, lst, true, &TraversePrint<int>);
      TraversePostOrder(loctestnum, loctesterr, coplst, true, &TraversePrint<int>);

      coplst = lst;
      EqualList(loctestnum, loctesterr, lst, coplst, true);
      EqualLinear(loctestnum, loctesterr, lst, coplst, true);

      MapPreOrder(loctestnum, loctesterr, lst, true, &MapIncrement<int>);
      NonEqualList(loctestnum, loctesterr, lst, coplst, true);

      FrontNRemove(loctestnum, loctesterr, lst, true, -98);
      TraversePostOrder(loctestnum, loctesterr, lst, true, &TraversePrint<int>);

      lasd::List<int> coplstz(coplst);
      coplstz.Clear();
      coplstz = lst;
      EqualList(loctestnum, loctesterr, lst, coplstz, true);

      coplstz = coplst;
      GetBack(loctestnum, loctesterr, coplstz, true, 77);
      SetBack(loctestnum, loctesterr, coplstz, true, -77);
      TraversePostOrder(loctestnum, loctesterr, coplstz, true, &TraversePrint<int>);

      FoldPreOrder(loctestnum, loctesterr, lst, true, &FoldAdd<int>, 0, 135);

      coplst = std::move(lst);
      FoldPreOrder(loctestnum, loctesterr, lst, true, &FoldAdd<int>, 0, 29);
      TraversePostOrder(loctestnum, loctesterr, lst, true, &TraversePrint<int>);
      TraversePostOrder(loctestnum, loctesterr, coplst, true, &TraversePrint<int>);

      lst = coplst;
      TraversePostOrder(loctestnum, loctesterr, lst, true, &TraversePrint<int>);

      lasd::List<int> movlst(std::move(lst));
      FoldPreOrder(loctestnum, loctesterr, movlst, true, &FoldAdd<int>, 0, 135);
      FrontNRemove(loctestnum, loctesterr, movlst, true, -97);

      InsertAtBack(loctestnum, loctesterr, lst, true, 88);
      MapPreOrder(loctestnum, loctesterr, lst, true, &TraversePrint<int>);

    }

  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of List<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void mystestListDouble(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of List<double> Test:" << endl;
  try {
    // CASO 0
    {
      print_section("0 ELEMENTS");
      lasd::List<double> lst;
      Empty(loctestnum, loctesterr, lst, true);
      Size(loctestnum, loctesterr, lst, true, 0.0);

      GetFront(loctestnum, loctesterr, lst, false, 0.0);
      GetBack(loctestnum, loctesterr, lst, false, 0.0);

      Exists(loctestnum, loctesterr, lst, false, 0.0);

      TraversePreOrder(loctestnum, loctesterr, lst, true, &TraversePrint<double>);
      TraversePostOrder(loctestnum, loctesterr, lst, true, &TraversePrint<double>);

      FoldPreOrder(loctestnum, loctesterr, lst, true, &FoldAdd<double>, 0.0, 0.0);
      FoldPostOrder(loctestnum, loctesterr, lst, true, &FoldAdd<double>, 0.0, 0.0);

      RemoveFromFront(loctestnum, loctesterr, lst, false);
      FrontNRemove(loctestnum, loctesterr, lst, false, 0.0);

      RemoveFromBack(loctestnum, loctesterr, lst, false);
      BackNRemove(loctestnum, loctesterr, lst, false, 0.0);

      Exists(loctestnum, loctesterr, lst, false, 0.0);
    }

    // CASO 1
    {
      print_section("1 ELEMENTS");
      lasd::List<double> lst;
      Empty(loctestnum, loctesterr, lst, true);
      Size(loctestnum, loctesterr, lst, true, 0.0);

      InsertAtFront(loctestnum, loctesterr, lst, true, 5.0);
      Empty(loctestnum, loctesterr, lst, false);
      Size(loctestnum, loctesterr, lst, true, 1.0);

      GetFront(loctestnum, loctesterr, lst, true, 5.0);
      GetBack(loctestnum, loctesterr, lst, true, 5.0);

      Exists(loctestnum, loctesterr, lst, true, 5.0);

      TraversePreOrder(loctestnum, loctesterr, lst, true, &TraversePrint<double>);
      TraversePostOrder(loctestnum, loctesterr, lst, true, &TraversePrint<double>);

      FoldPreOrder(loctestnum, loctesterr, lst, true, &FoldAdd<double>, 0.0, 5.0);
      FoldPostOrder(loctestnum, loctesterr, lst, true, &FoldAdd<double>, 0.0, 5.0);

      RemoveFromFront(loctestnum, loctesterr, lst, true);
      InsertAtFront(loctestnum, loctesterr, lst, true, 5.0);
      FrontNRemove(loctestnum, loctesterr, lst, true, 5.0);
      FrontNRemove(loctestnum, loctesterr, lst, false, 3.0);
      TraversePreOrder(loctestnum, loctesterr, lst, true, &TraversePrint<double>);

      RemoveFromBack(loctestnum, loctesterr, lst, false);
      InsertAtFront(loctestnum, loctesterr, lst, true, 5.0);
      BackNRemove(loctestnum, loctesterr, lst, true, 5.0);
      BackNRemove(loctestnum, loctesterr, lst, false, 3.0);
      BackNRemove(loctestnum, loctesterr, lst, false, 1.0);

      TraversePreOrder(loctestnum, loctesterr, lst, true, &TraversePrint<double>);

      Exists(loctestnum, loctesterr, lst, false, 0.0);
    }

    // CASO N
    {
      print_section("N ELEMENTS");
      lasd::List<double> lst;
      
      InsertAtFront(loctestnum, loctesterr, lst, true, 7.0);
      InsertAtFront(loctestnum, loctesterr, lst, true, 14.0);
      InsertAtFront(loctestnum, loctesterr, lst, true, 3.0);
      InsertAtFront(loctestnum, loctesterr, lst, true, 8.0);
      InsertAtFront(loctestnum, loctesterr, lst, true, 1.0);
      InsertAtBack(loctestnum, loctesterr, lst, true, 42.0);
      InsertAtBack(loctestnum, loctesterr, lst, true, 5.0);
      InsertAtBack(loctestnum, loctesterr, lst, true, 19.0);

      GetFront(loctestnum, loctesterr, lst, true, 1.0);
      GetBack(loctestnum, loctesterr, lst, true, 19.0);

      SetFront(loctestnum, loctesterr, lst, true, 0.0);
      SetBack(loctestnum, loctesterr, lst, true, 100.0);

      GetAt(loctestnum, loctesterr, lst, true, 2, 3.0);
      SetAt(loctestnum, loctesterr, lst, true, 2, 99.0);

      GetFront(loctestnum, loctesterr, lst, true, 0.0);
      GetBack(loctestnum, loctesterr, lst, true, 100.0);
      Exists(loctestnum, loctesterr, lst, true, 42.0);

      TraversePreOrder(loctestnum, loctesterr, lst, true, &TraversePrint<double>);
      TraversePostOrder(loctestnum, loctesterr, lst, true, &TraversePrint<double>);

      FoldPostOrder(loctestnum, loctesterr, lst, true, &FoldMultiply<double>, 1.0, 0.0);

      RemoveFromFront(loctestnum, loctesterr, lst, true);
      FrontNRemove(loctestnum, loctesterr, lst, true, 8.0);
      FoldPostOrder(loctestnum, loctesterr, lst, true, &FoldAdd<double>, 0.0, 267.0);

      lasd::List<double> coplst(lst);
      EqualList(loctestnum, loctesterr, lst, coplst, true);
      EqualLinear(loctestnum, loctesterr, lst, coplst, true);

      MapPreOrder(loctestnum, loctesterr, lst, true, &MapIncrement<double>);
      TraversePreOrder(loctestnum, loctesterr, lst, true, &TraversePrint<double>);
      NonEqualList(loctestnum, loctesterr, lst, coplst, true);

      InsertAtFront(loctestnum, loctesterr, lst, true, -99.0);
      InsertAtBack(loctestnum, loctesterr, lst, true, 77.0);

      TraversePostOrder(loctestnum, loctesterr, lst, true, &TraversePrint<double>);
      TraversePostOrder(loctestnum, loctesterr, coplst, true, &TraversePrint<double>);

      coplst = lst;
      EqualList(loctestnum, loctesterr, lst, coplst, true);
      EqualLinear(loctestnum, loctesterr, lst, coplst, true);

      MapPreOrder(loctestnum, loctesterr, lst, true, &MapIncrement<double>);
      NonEqualList(loctestnum, loctesterr, lst, coplst, true);

      FrontNRemove(loctestnum, loctesterr, lst, true, -98.0);
      TraversePostOrder(loctestnum, loctesterr, lst, true, &TraversePrint<double>);

      lasd::List<double> coplstz(coplst);
      coplstz.Clear();
      coplstz = lst;
      EqualList(loctestnum, loctesterr, lst, coplstz, true);

      coplstz = coplst;
      GetBack(loctestnum, loctesterr, coplstz, true, 77.0);
      SetBack(loctestnum, loctesterr, coplstz, true, -77.0);
      TraversePostOrder(loctestnum, loctesterr, coplstz, true, &TraversePrint<double>);

      coplst = std::move(lst);
      FoldPreOrder(loctestnum, loctesterr, lst, true, &FoldAdd<double>, 0.0, 251.0);
      TraversePostOrder(loctestnum, loctesterr, lst, true, &TraversePrint<double>);
      TraversePostOrder(loctestnum, loctesterr, coplst, true, &TraversePrint<double>);

      lst = coplst;
      TraversePostOrder(loctestnum, loctesterr, lst, true, &TraversePrint<double>);

      lasd::List<double> movlst(std::move(lst));
      FrontNRemove(loctestnum, loctesterr, movlst, true, 101.0);

      InsertAtBack(loctestnum, loctesterr, lst, true, 88.0);
      MapPreOrder(loctestnum, loctesterr, lst, true, &TraversePrint<double>);

    }

  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of List<double> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void mystestListString(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of List<string> Test:" << endl;

  try {
    // CASO 0
    {
      print_section("0 ELEMENTS");
      lasd::List<string> lst;
      Empty(loctestnum, loctesterr, lst, true);
      Size(loctestnum, loctesterr, lst, true, 0);
      TraversePreOrder(loctestnum, loctesterr, lst, true, &TraversePrint<string>);
      FoldPreOrder(loctestnum, loctesterr, lst, true, &FoldStringConcatenate, string("X"), string("X"));
      FoldPostOrder(loctestnum, loctesterr, lst, true, &FoldStringConcatenate, string("X"), string("X"));
      RemoveFromFront(loctestnum, loctesterr, lst, false);
      RemoveFromBack(loctestnum, loctesterr, lst, false);
      FrontNRemove(loctestnum, loctesterr, lst, false, string("X"));
      BackNRemove(loctestnum, loctesterr, lst, false, string("X"));
      GetFront(loctestnum, loctesterr, lst, false, string("X"));
      GetBack(loctestnum, loctesterr, lst, false, string("X"));
    }

    // CASO 1
    {
      print_section("1 ELEMENTS");
      lasd::List<string> lst;

      InsertAtFront(loctestnum, loctesterr, lst, true, string("One"));

      Empty(loctestnum, loctesterr, lst, false);
      Size(loctestnum, loctesterr, lst, true, 1);
      GetFront(loctestnum, loctesterr, lst, true, string("One"));
      GetBack(loctestnum, loctesterr, lst, true, string("One"));
      Exists(loctestnum, loctesterr, lst, true, string("One"));

      MapPreOrder(loctestnum, loctesterr, lst, true, [](string & str) { MapStringAppend(str, "!"); });
      TraversePreOrder(loctestnum, loctesterr, lst, true, &TraversePrint<string>);
      FoldPreOrder(loctestnum, loctesterr, lst, true, &FoldStringConcatenate, string("X"), string("XOne!"));
      FoldPostOrder(loctestnum, loctesterr, lst, true, &FoldStringConcatenate, string("X"), string("XOne!"));

      lst.Clear();

      InsertAtBack(loctestnum, loctesterr, lst, true, string("One"));

      Empty(loctestnum, loctesterr, lst, false);
      Size(loctestnum, loctesterr, lst, true, 1);
      GetFront(loctestnum, loctesterr, lst, true, string("One"));
      GetBack(loctestnum, loctesterr, lst, true, string("One"));
      Exists(loctestnum, loctesterr, lst, true, string("One"));

      FrontNRemove(loctestnum, loctesterr, lst, true, string("One"));
      InsertAtFront(loctestnum, loctesterr, lst, true, string("One"));
      BackNRemove(loctestnum, loctesterr, lst, true, string("One"));
      InsertAtBack(loctestnum, loctesterr, lst, true, string("One"));

      MapPreOrder(loctestnum, loctesterr, lst, true, [](string & str) { MapStringAppend(str, "!"); });
      TraversePreOrder(loctestnum, loctesterr, lst, true, &TraversePrint<string>);
      FoldPreOrder(loctestnum, loctesterr, lst, true, &FoldStringConcatenate, string("X"), string("XOne!"));
      FoldPostOrder(loctestnum, loctesterr, lst, true, &FoldStringConcatenate, string("X"), string("XOne!"));

      lasd::List<string> coplst(lst);
      EqualList(loctestnum, loctesterr, lst, coplst, true);
      RemoveFromFront(loctestnum, loctesterr, coplst, true);
      NonEqualList(loctestnum, loctesterr, lst, coplst, true);
    }

    // CASO N
    {
      print_section("N ELEMENTS");
      lasd::List<string> lst;

      InsertAtFront(loctestnum, loctesterr, lst, true, string("A"));
      InsertAtBack(loctestnum, loctesterr, lst, true, string("B"));
      InsertAtFront(loctestnum, loctesterr, lst, true, string("C"));
      InsertAtBack(loctestnum, loctesterr, lst, true, string("D"));
      InsertAtFront(loctestnum, loctesterr, lst, true, string("E"));

      FrontNRemove(loctestnum, loctesterr, lst, true, string("E"));
      GetFront(loctestnum, loctesterr, lst, true, string("C"));
      InsertAtFront(loctestnum, loctesterr, lst, true, string("E"));

      BackNRemove(loctestnum, loctesterr, lst, true, string("D"));
      GetBack(loctestnum, loctesterr, lst, true, string("B"));
      InsertAtBack(loctestnum, loctesterr, lst, true, string("D"));

      Size(loctestnum, loctesterr, lst, true, 5);
      GetFront(loctestnum, loctesterr, lst, true, string("E"));
      GetBack(loctestnum, loctesterr, lst, true, string("D"));
      Exists(loctestnum, loctesterr, lst, true, string("B"));
      Exists(loctestnum, loctesterr, lst, false, string("Z"));

      MapPreOrder(loctestnum, loctesterr, lst, true, [](string & str) { MapStringAppend(str, "_"); });
      TraversePreOrder(loctestnum, loctesterr, lst, true, &TraversePrint<string>);
      FoldPreOrder(loctestnum, loctesterr, lst, true, &FoldStringConcatenate, string(">"), string(">E_C_A_B_D_"));
      FoldPostOrder(loctestnum, loctesterr, lst, true, &FoldStringConcatenate, string(">"), string(">D_B_A_C_E_"));

      lasd::List<string> coplst(lst);
      EqualList(loctestnum, loctesterr, lst, coplst, true);
      InsertAtBack(loctestnum, loctesterr, lst, true, string("X"));
      InsertAtFront(loctestnum, loctesterr, lst, true, string("Y"));
      NonEqualList(loctestnum, loctesterr, lst, coplst, true);

      coplst = move(lst);
      TraversePreOrder(loctestnum, loctesterr, coplst, true, &TraversePrint<string>);
      FoldPreOrder(loctestnum, loctesterr, coplst, true, &FoldStringConcatenate, string("#"), string("#YE_C_A_B_D_X"));
    }

  } catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }

  cout << "End of List<string> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void myTestVectorListInt(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of Vector/List<int> Test:" << endl;
  try {
    // CASO 0
    {
      print_section("0 ELEMENTS");
      lasd::SortableVector<int> vec0(0);
      lasd::List<int> lst0;
      EqualLinear(loctestnum, loctesterr, vec0, lst0, true);
    }

    // CASO 1
    {
      print_section("1 ELEMENTS");
      lasd::SortableVector<int> vec1(1);
      SetAt(loctestnum, loctesterr, vec1, true, 0, 99);

      lasd::List<int> lst1;
      InsertAtFront(loctestnum, loctesterr, lst1, true, 99);

      EqualLinear(loctestnum, loctesterr, vec1, lst1, true);
    }

    // CASO N
    {
      print_section("N ELEMENTS");
      lasd::SortableVector<int> vec(5);
      SetAt(loctestnum, loctesterr, vec, true, 0, 10);
      SetAt(loctestnum, loctesterr, vec, true, 1, 20);
      SetAt(loctestnum, loctesterr, vec, true, 2, 30);
      SetAt(loctestnum, loctesterr, vec, true, 3, 40);
      SetAt(loctestnum, loctesterr, vec, true, 4, 50);

      lasd::List<int> lst;
      InsertAtFront(loctestnum, loctesterr, lst, true, 50);
      InsertAtFront(loctestnum, loctesterr, lst, true, 40);
      InsertAtFront(loctestnum, loctesterr, lst, true, 30);
      InsertAtFront(loctestnum, loctesterr, lst, true, 20);
      InsertAtFront(loctestnum, loctesterr, lst, true, 10);

      EqualLinear(loctestnum, loctesterr, vec, lst, true);

      lasd::SortableVector<int> copvec(lst);
      EqualVector(loctestnum, loctesterr, vec, copvec, true);

      lasd::SortableVector<int> copvecx(vec);
      EqualVector(loctestnum, loctesterr, copvecx, copvec, true);

      lasd::List<int> coplst(vec);
      EqualList(loctestnum, loctesterr, lst, coplst, true);

      lasd::List<int> coplstx(lst);
      EqualList(loctestnum, loctesterr, coplstx, coplst, true);
    }

  } catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of Vector/List<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void myTestVectorListDouble(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of Vector/List<double> Test:" << endl;
  try {
    // CASO 0
    {
      print_section("0 ELEMENTS");
      lasd::SortableVector<double> vec0(0);
      lasd::List<double> lst0;
      EqualLinear(loctestnum, loctesterr, vec0, lst0, true);
    }

    // CASO 1
    {
      print_section("1 ELEMENTS");
      lasd::SortableVector<double> vec1(1);
      SetAt(loctestnum, loctesterr, vec1, true, 0, 0.2);

      lasd::List<double> lst1;
      InsertAtBack(loctestnum, loctesterr, lst1, true, 0.2);

      EqualLinear(loctestnum, loctesterr, vec1, lst1, true);
    }

    // CASO N
    {
      print_section("N ELEMENTS");
      lasd::SortableVector<double> vec(5);
      SetAt(loctestnum, loctesterr, vec, true, 0, 1.1);
      SetAt(loctestnum, loctesterr, vec, true, 1, 2.2);
      SetAt(loctestnum, loctesterr, vec, true, 2, 3.3);
      SetAt(loctestnum, loctesterr, vec, true, 3, 4.4);
      SetAt(loctestnum, loctesterr, vec, true, 4, 5.5);

      lasd::List<double> lst;
      InsertAtBack(loctestnum, loctesterr, lst, true, 1.1);
      InsertAtBack(loctestnum, loctesterr, lst, true, 2.2);
      InsertAtBack(loctestnum, loctesterr, lst, true, 3.3);
      InsertAtBack(loctestnum, loctesterr, lst, true, 4.4);
      InsertAtBack(loctestnum, loctesterr, lst, true, 5.5);

      EqualLinear(loctestnum, loctesterr, vec, lst, true);

      lasd::SortableVector<double> copvec(lst);
      EqualVector(loctestnum, loctesterr, vec, copvec, true);

      lasd::SortableVector<double> copvecx(vec);
      EqualVector(loctestnum, loctesterr, copvecx, copvec, true);

      lasd::List<double> coplst(vec);
      EqualList(loctestnum, loctesterr, lst, coplst, true);

      lasd::List<double> coplstx(lst);
      EqualList(loctestnum, loctesterr, coplstx, coplst, true);
    }

  } catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of Vector/List<double> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void myTestVectorListString(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of Vector/List<string> Test:" << endl;
  try {
    // CASO 0
    {
      print_section("0 ELEMENTS");
      lasd::SortableVector<string> vec0(0);
      lasd::List<string> lst0;
      EqualLinear(loctestnum, loctesterr, vec0, lst0, true);
    }

    // CASO 1
    {
      print_section("1 ELEMENTS");
      lasd::SortableVector<string> vec1(1);
      SetAt(loctestnum, loctesterr, vec1, true, 0, string("X"));

      lasd::List<string> lst1;
      InsertAtFront(loctestnum, loctesterr, lst1, true, string("X"));

      EqualLinear(loctestnum, loctesterr, vec1, lst1, true);
    }

    // CASO N
    {
      print_section("N ELEMENTS");
      lasd::SortableVector<string> vec(5);
      SetAt(loctestnum, loctesterr, vec, true, 0, string("C++"));
      SetAt(loctestnum, loctesterr, vec, true, 1, string("C"));
      SetAt(loctestnum, loctesterr, vec, true, 2, string("COBOL"));
      SetAt(loctestnum, loctesterr, vec, true, 3, string("PHP"));
      SetAt(loctestnum, loctesterr, vec, true, 4, string("Java"));

      lasd::List<string> lst;
      InsertAtBack(loctestnum, loctesterr, lst, true, string("A"));
      InsertAtBack(loctestnum, loctesterr, lst, true, string("B"));
      InsertAtBack(loctestnum, loctesterr, lst, true, string("C"));
      InsertAtBack(loctestnum, loctesterr, lst, true, string("D"));
      InsertAtBack(loctestnum, loctesterr, lst, true, string("E"));

      EqualLinear(loctestnum, loctesterr, vec, lst, false);

      lasd::SortableVector<string> copvec(lst);
      EqualVector(loctestnum, loctesterr, vec, copvec, false);
      lasd::SortableVector<string> copvecx(vec);
      EqualVector(loctestnum, loctesterr, copvecx, copvec, false);

      lasd::List<string> coplst(vec);
      EqualList(loctestnum, loctesterr, lst, coplst, false);
      lasd::List<string> coplstx(lst);
      EqualList(loctestnum, loctesterr, coplstx, coplst, false);

      Size(loctestnum, loctesterr, vec, true, 5);
      TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<string>);
      Size(loctestnum, loctesterr, copvec, true, 5);
      TraversePreOrder(loctestnum, loctesterr, copvec, true, &TraversePrint<string>);

      lasd::List<string> coplsty(move(vec));
      EqualList(loctestnum, loctesterr, coplst, coplsty, true);
      Size(loctestnum, loctesterr, vec, true, 5);
      TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<string>);
      TraversePreOrder(loctestnum, loctesterr, copvec, true, &TraversePrint<string>);
      EqualVector(loctestnum, loctesterr, vec, copvec, false);

      Size(loctestnum, loctesterr, lst, true, 5);
      TraversePreOrder(loctestnum, loctesterr, lst, true, &TraversePrint<string>);
      Size(loctestnum, loctesterr, coplst, true, 5);
      TraversePreOrder(loctestnum, loctesterr, coplst, true, &TraversePrint<string>);

      lasd::SortableVector<string> copvecy(move(lst));
      EqualVector(loctestnum, loctesterr, copvec, copvecy, true);
      Size(loctestnum, loctesterr, lst, true, 5);
      TraversePreOrder(loctestnum, loctesterr, lst, true, &TraversePrint<string>);
      TraversePreOrder(loctestnum, loctesterr, coplst, true, &TraversePrint<string>);
      EqualList(loctestnum, loctesterr, lst, coplst, false);
    }

  } catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of Vector/List<string> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
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

void mystestList(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  mystestListInt(loctestnum, loctesterr);
  mystestListDouble(loctestnum, loctesterr);
  mystestListString(loctestnum, loctesterr);
  testnum += loctestnum;
  testerr += loctesterr;
  cout << endl << "Exercise 1A VecList - List (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
}

void mystestVectorList(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  myTestVectorListInt(loctestnum, loctesterr);
  myTestVectorListDouble(loctestnum, loctesterr);
  myTestVectorListString(loctestnum, loctesterr);
  testnum += loctestnum;
  testerr += loctesterr;
  cout << endl << "Exercise 1A VecList - List (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
}

void runExVecList(uint & testnum, uint & testerr) 
{
  mystestVector(testnum, testerr);
  mystestList(testnum, testerr);
  mystestVectorList(testnum, testerr);
  cout << endl << "Exercise VecList (MY TEST) (Errors/Tests: " << testerr << "/" << testnum << ")" << endl;
}