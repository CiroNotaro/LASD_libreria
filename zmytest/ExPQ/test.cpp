
#include <iostream>

/* ************************************************************************** */

#include "../../zlasdtest/container/container.hpp"
#include "../../zlasdtest/container/testable.hpp"
#include "../../zlasdtest/container/traversable.hpp"
#include "../../zlasdtest/container/mappable.hpp"
#include "../../zlasdtest/container/linear.hpp"

#include "../../zlasdtest/vector/vector.hpp"

#include "../../zlasdtest/pq/pq.hpp"

#include "../../zlasdtest/pq/pq.hpp"
#include "../../pq/heap/pqheap.hpp"

#include "../utils.hpp"

/* ************************************************************************** */

using namespace std;

/* ************************************************************************** */

void mystestPQInt(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of PQ<int> Test:" << endl;
  try {

    // CASO 0
    {
      print_section("0 ELEMENTS");
      lasd::PQHeap<int> pq0;

      Empty(loctestnum, loctesterr, pq0, true);
      Size(loctestnum, loctesterr, pq0, true, 0);

      RemoveTip(loctestnum, loctesterr, pq0, false);
      Tip(loctestnum, loctesterr, pq0, false, 0);
      TipNRemove(loctestnum, loctesterr, pq0, false, 0);

      Exists(loctestnum, loctesterr, pq0, false, 1);
      GetAt(loctestnum, loctesterr, pq0, false, 0, 0);

      Traverse(loctestnum, loctesterr, pq0, true, &TraversePrint<int>);
      TraversePreOrder(loctestnum, loctesterr, pq0, true, &TraversePrint<int>);
      TraversePostOrder(loctestnum, loctesterr, pq0, true, &TraversePrint<int>);

      FoldPreOrder(loctestnum, loctesterr, pq0, true, &FoldAdd<int>, 0, 0);
      FoldPostOrder(loctestnum, loctesterr, pq0, true, &FoldAdd<int>, 0, 0);
    }

    // CASO 1
    {
      print_section("1 ELEMENTS");
      lasd::PQHeap<int> pq1;
      Insert(loctestnum, loctesterr, pq1, 99);
      Empty(loctestnum, loctesterr, pq1, false);
      Size(loctestnum, loctesterr, pq1, true, 1);

      Traverse(loctestnum, loctesterr, pq1, true, &TraversePrint<int>);

      Exists(loctestnum, loctesterr, pq1, true, 99);
      GetAt(loctestnum, loctesterr, pq1, true, 0, 99);

      TraversePreOrder(loctestnum, loctesterr, pq1, true, &TraversePrint<int>);
      TraversePostOrder(loctestnum, loctesterr, pq1, true, &TraversePrint<int>);

      FoldPreOrder(loctestnum, loctesterr, pq1, true, &FoldAdd<int>, 0, 99);
      FoldPostOrder(loctestnum, loctesterr, pq1, true, &FoldAdd<int>, 0, 99);

      Tip(loctestnum, loctesterr, pq1, true, 99);
      RemoveTip(loctestnum, loctesterr, pq1, true);
      Size(loctestnum, loctesterr, pq1, true, 0);
      Empty(loctestnum, loctesterr, pq1, true);
    }

    // CASO 2
    {
      print_section("2 ELEMENTS");
      lasd::PQHeap<int> pq2;
      Insert(loctestnum, loctesterr, pq2, 4);
      Insert(loctestnum, loctesterr, pq2, 15);

      Traverse(loctestnum, loctesterr, pq2, true, &TraversePrint<int>);

      Empty(loctestnum, loctesterr, pq2, false);
      Size(loctestnum, loctesterr, pq2, true, 2);

      Exists(loctestnum, loctesterr, pq2, true, 4);
      GetAt(loctestnum, loctesterr, pq2, true, 0, 15);

      TraversePreOrder(loctestnum, loctesterr, pq2, true, &TraversePrint<int>);
      TraversePostOrder(loctestnum, loctesterr, pq2, true, &TraversePrint<int>);

      FoldPreOrder(loctestnum, loctesterr, pq2, true, &FoldAdd<int>, 0, 19);
      FoldPostOrder(loctestnum, loctesterr, pq2, true, &FoldAdd<int>, 0, 19);

      Tip(loctestnum, loctesterr, pq2, true, 15);
      TipNRemove(loctestnum, loctesterr, pq2, true, 15);
      TipNRemove(loctestnum, loctesterr, pq2, true, 4);
      Empty(loctestnum, loctesterr, pq2, true);
    }

    // CASO 3
    {
      print_section("3 ELEMENTS");
      lasd::PQHeap<int> pq3;
      Insert(loctestnum, loctesterr, pq3, 6);
      Insert(loctestnum, loctesterr, pq3, 2);
      Insert(loctestnum, loctesterr, pq3, 9);

      Traverse(loctestnum, loctesterr, pq3, true, &TraversePrint<int>);
      
      Empty(loctestnum, loctesterr, pq3, false);
      Size(loctestnum, loctesterr, pq3, true, 3);

      TraversePreOrder(loctestnum, loctesterr, pq3, true, &TraversePrint<int>);
      TraversePostOrder(loctestnum, loctesterr, pq3, true, &TraversePrint<int>);
      
      Change(loctestnum, loctesterr, pq3, true, 1, 10);

      Traverse(loctestnum, loctesterr, pq3, true, &TraversePrint<int>);
      
      FoldPreOrder(loctestnum, loctesterr, pq3, true, &FoldAdd<int>, 0, 25);
      FoldPostOrder(loctestnum, loctesterr, pq3, true, &FoldAdd<int>, 0, 25);
      
      Exists(loctestnum, loctesterr, pq3, true, 10);
      Exists(loctestnum, loctesterr, pq3, false, 1);
      
      GetAt(loctestnum, loctesterr, pq3, true, 1, 9);
      
    }

    // CASO N
    {
      print_section("N ELEMENTS");
      lasd::Vector<int> vec(10);
      SetAt(loctestnum, loctesterr, vec, true, 0, 4);
      SetAt(loctestnum, loctesterr, vec, true, 1, 3);
      SetAt(loctestnum, loctesterr, vec, true, 2, 1);
      SetAt(loctestnum, loctesterr, vec, true, 3, 0);
      SetAt(loctestnum, loctesterr, vec, true, 4, 2);
      SetAt(loctestnum, loctesterr, vec, true, 5, 5);
      SetAt(loctestnum, loctesterr, vec, true, 6, 0);
      SetAt(loctestnum, loctesterr, vec, true, 7, 8);
      SetAt(loctestnum, loctesterr, vec, true, 8, 10);
      SetAt(loctestnum, loctesterr, vec, true, 9, 6);
      
      lasd::PQHeap<int> pq(vec);

      Traverse(loctestnum, loctesterr, pq, true, &TraversePrint<int>);
      
      Empty(loctestnum, loctesterr, pq, false);
      Size(loctestnum, loctesterr, pq, true, 10);

      Tip(loctestnum, loctesterr, pq, true, 10);
      TipNRemove(loctestnum, loctesterr, pq, true, 10);
      TipNRemove(loctestnum, loctesterr, pq, true, 8);
      TipNRemove(loctestnum, loctesterr, pq, true, 6);
      
      Insert(loctestnum, loctesterr, pq, 9);
      Insert(loctestnum, loctesterr, pq, 1);
      
      TraversePreOrder(loctestnum, loctesterr, pq, true, &TraversePrint<int>);
      TraversePostOrder(loctestnum, loctesterr, pq, true, &TraversePrint<int>);
      
      Change(loctestnum, loctesterr, pq, true, 0, 0);
      Change(loctestnum, loctesterr, pq, true, 1, 7);
      
      FoldPreOrder(loctestnum, loctesterr, pq, true, &FoldAdd<int>, 0, 19);
      FoldPostOrder(loctestnum, loctesterr, pq, true, &FoldAdd<int>, 0, 19);
      
      Size(loctestnum, loctesterr, pq, true, pq.Size());   
      
      lasd::PQHeap<int> pqA;
      Insert(loctestnum, loctesterr, pqA, 1);
      Insert(loctestnum, loctesterr, pqA, 2);
      Insert(loctestnum, loctesterr, pqA, 3);

      lasd::PQHeap<int> pqB(pqA);
      EqualLinear(loctestnum, loctesterr, pqA, pqB, true);

      lasd::PQHeap<int> pqC(std::move(pqB));
      Empty(loctestnum, loctesterr, pqB, true);
      Size(loctestnum, loctesterr, pqC, true, 3);

      Insert(loctestnum, loctesterr, pqC, 4);
      EqualLinear(loctestnum, loctesterr, pqA, pqC, false);

      pqA = pqC;
      EqualLinear(loctestnum, loctesterr, pqA, pqC, true);

    }

  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of PQ<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void mystestPQDouble(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of PQ<double> Test:" << endl;
  try {

    // CASO 0
    {
      print_section("0 ELEMENTS");
      lasd::PQHeap<double> pq0;

      Empty(loctestnum, loctesterr, pq0, true);
      Size(loctestnum, loctesterr, pq0, true, 0);

      RemoveTip(loctestnum, loctesterr, pq0, false);
      Tip(loctestnum, loctesterr, pq0, false, 0.0);
      TipNRemove(loctestnum, loctesterr, pq0, false, 0.0);

      Exists(loctestnum, loctesterr, pq0, false, 1.1);
      GetAt(loctestnum, loctesterr, pq0, false, 0, 0.0);

      Traverse(loctestnum, loctesterr, pq0, true, &TraversePrint<double>);
      TraversePreOrder(loctestnum, loctesterr, pq0, true, &TraversePrint<double>);
      TraversePostOrder(loctestnum, loctesterr, pq0, true, &TraversePrint<double>);

      FoldPreOrder(loctestnum, loctesterr, pq0, true, &FoldAdd<double>, 0.0, 0.0);
      FoldPostOrder(loctestnum, loctesterr, pq0, true, &FoldAdd<double>, 0.0, 0.0);
    }

    // CASO 1
    {
      print_section("1 ELEMENTS");
      lasd::PQHeap<double> pq1;
      Insert(loctestnum, loctesterr, pq1, 99.5);
      Empty(loctestnum, loctesterr, pq1, false);
      Size(loctestnum, loctesterr, pq1, true, 1);

      Traverse(loctestnum, loctesterr, pq1, true, &TraversePrint<double>);

      Exists(loctestnum, loctesterr, pq1, true, 99.5);
      GetAt(loctestnum, loctesterr, pq1, true, 0, 99.5);

      TraversePreOrder(loctestnum, loctesterr, pq1, true, &TraversePrint<double>);
      TraversePostOrder(loctestnum, loctesterr, pq1, true, &TraversePrint<double>);

      FoldPreOrder(loctestnum, loctesterr, pq1, true, &FoldAdd<double>, 0.0, 99.5);
      FoldPostOrder(loctestnum, loctesterr, pq1, true, &FoldAdd<double>, 0.0, 99.5);

      Tip(loctestnum, loctesterr, pq1, true, 99.5);
      RemoveTip(loctestnum, loctesterr, pq1, true);
      Size(loctestnum, loctesterr, pq1, true, 0);
      Empty(loctestnum, loctesterr, pq1, true);
    }

    // CASO 2
    {
      print_section("2 ELEMENTS");
      lasd::PQHeap<double> pq2;
      Insert(loctestnum, loctesterr, pq2, 4.2);
      Insert(loctestnum, loctesterr, pq2, 15.7);

      Traverse(loctestnum, loctesterr, pq2, true, &TraversePrint<double>);

      Empty(loctestnum, loctesterr, pq2, false);
      Size(loctestnum, loctesterr, pq2, true, 2);

      Exists(loctestnum, loctesterr, pq2, true, 4.2);
      GetAt(loctestnum, loctesterr, pq2, true, 0, 15.7);

      TraversePreOrder(loctestnum, loctesterr, pq2, true, &TraversePrint<double>);
      TraversePostOrder(loctestnum, loctesterr, pq2, true, &TraversePrint<double>);

      FoldPreOrder(loctestnum, loctesterr, pq2, true, &FoldAdd<double>, 0.0, 19.9);
      FoldPostOrder(loctestnum, loctesterr, pq2, true, &FoldAdd<double>, 0.0, 19.9);

      Tip(loctestnum, loctesterr, pq2, true, 15.7);
      TipNRemove(loctestnum, loctesterr, pq2, true, 15.7);
      TipNRemove(loctestnum, loctesterr, pq2, true, 4.2);
      Empty(loctestnum, loctesterr, pq2, true);
    }

    // CASO 3
    {
      print_section("3 ELEMENTS");
      lasd::PQHeap<double> pq3;
      Insert(loctestnum, loctesterr, pq3, 6.5);
      Insert(loctestnum, loctesterr, pq3, 2.1);
      Insert(loctestnum, loctesterr, pq3, 9.3);

      Traverse(loctestnum, loctesterr, pq3, true, &TraversePrint<double>);

      Empty(loctestnum, loctesterr, pq3, false);
      Size(loctestnum, loctesterr, pq3, true, 3);

      TraversePreOrder(loctestnum, loctesterr, pq3, true, &TraversePrint<double>);
      TraversePostOrder(loctestnum, loctesterr, pq3, true, &TraversePrint<double>);

      Change(loctestnum, loctesterr, pq3, true, 1, 10.1);

      Traverse(loctestnum, loctesterr, pq3, true, &TraversePrint<double>);

      FoldPreOrder(loctestnum, loctesterr, pq3, true, &FoldAdd<double>, 0.0, 25.9);
      FoldPostOrder(loctestnum, loctesterr, pq3, true, &FoldAdd<double>, 0.0, 25.9);

      Exists(loctestnum, loctesterr, pq3, true, 10.1);
      Exists(loctestnum, loctesterr, pq3, false, 1.1);

      GetAt(loctestnum, loctesterr, pq3, true, 1, 9.3);
    }

    // CASO N
    {
      print_section("N ELEMENTS");
      lasd::Vector<double> vec(10);
      SetAt(loctestnum, loctesterr, vec, true, 0, 4.0);
      SetAt(loctestnum, loctesterr, vec, true, 1, 3.1);
      SetAt(loctestnum, loctesterr, vec, true, 2, 1.2);
      SetAt(loctestnum, loctesterr, vec, true, 3, 0.3);
      SetAt(loctestnum, loctesterr, vec, true, 4, 2.4);
      SetAt(loctestnum, loctesterr, vec, true, 5, 5.5);
      SetAt(loctestnum, loctesterr, vec, true, 6, 0.6);
      SetAt(loctestnum, loctesterr, vec, true, 7, 8.7);
      SetAt(loctestnum, loctesterr, vec, true, 8, 10.8);
      SetAt(loctestnum, loctesterr, vec, true, 9, 6.9);

      lasd::PQHeap<double> pq(vec);

      Traverse(loctestnum, loctesterr, pq, true, &TraversePrint<double>);

      Empty(loctestnum, loctesterr, pq, false);
      Size(loctestnum, loctesterr, pq, true, 10);

      Tip(loctestnum, loctesterr, pq, true, 10.8);
      TipNRemove(loctestnum, loctesterr, pq, true, 10.8);
      TipNRemove(loctestnum, loctesterr, pq, true, 8.7);
      TipNRemove(loctestnum, loctesterr, pq, true, 6.9);

      Insert(loctestnum, loctesterr, pq, 9.1);
      Insert(loctestnum, loctesterr, pq, 1.0);

      TraversePreOrder(loctestnum, loctesterr, pq, true, &TraversePrint<double>);
      TraversePostOrder(loctestnum, loctesterr, pq, true, &TraversePrint<double>);

      Change(loctestnum, loctesterr, pq, true, 0, 0.0);
      Change(loctestnum, loctesterr, pq, true, 1, 7.7);

      TraversePreOrder(loctestnum, loctesterr, pq, true, &TraversePrint<double>);

      FoldPreOrder(loctestnum, loctesterr, pq, true, &FoldAdd<double>, 0.0, 21.8);
      FoldPostOrder(loctestnum, loctesterr, pq, true, &FoldAdd<double>, 0.0, 21.8);

      Size(loctestnum, loctesterr, pq, true, pq.Size());

      lasd::PQHeap<double> pqA;
      Insert(loctestnum, loctesterr, pqA, 1.1);
      Insert(loctestnum, loctesterr, pqA, 2.2);
      Insert(loctestnum, loctesterr, pqA, 3.3);

      lasd::PQHeap<double> pqB(pqA);
      EqualLinear(loctestnum, loctesterr, pqA, pqB, true);

      lasd::PQHeap<double> pqC(std::move(pqB));
      Empty(loctestnum, loctesterr, pqB, true);
      Size(loctestnum, loctesterr, pqC, true, 3);

      Insert(loctestnum, loctesterr, pqC, 4.4);
      EqualLinear(loctestnum, loctesterr, pqA, pqC, false);

      pqA = pqC;
      EqualLinear(loctestnum, loctesterr, pqA, pqC, true);
    }


  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of PQ<double> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void mystestPQString(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of PQ<string> Test:" << endl;
  try {
    // CASO 0
    {
      print_section("0 ELEMENTS");
      lasd::PQHeap<string> pq0;

      Empty(loctestnum, loctesterr, pq0, true);
      Size(loctestnum, loctesterr, pq0, true, 0);

      RemoveTip(loctestnum, loctesterr, pq0, false);
      Tip(loctestnum, loctesterr, pq0, false, string(""));
      TipNRemove(loctestnum, loctesterr, pq0, false, string(""));

      Exists(loctestnum, loctesterr, pq0, false, string("A"));
      GetAt(loctestnum, loctesterr, pq0, false, 0, string(""));

      Traverse(loctestnum, loctesterr, pq0, true, &TraversePrint<string>);
      TraversePreOrder(loctestnum, loctesterr, pq0, true, &TraversePrint<string>);
      TraversePostOrder(loctestnum, loctesterr, pq0, true, &TraversePrint<string>);

      FoldPreOrder(loctestnum, loctesterr, pq0, true, &FoldStringConcatenate, string("?"), string("?"));
      FoldPostOrder(loctestnum, loctesterr, pq0, true, &FoldStringConcatenate, string("?"), string("?"));
    }

    // CASO 1
    {
      print_section("1 ELEMENTS");
      lasd::PQHeap<string> pq1;
      Insert(loctestnum, loctesterr, pq1, string("A"));
      Empty(loctestnum, loctesterr, pq1, false);
      Size(loctestnum, loctesterr, pq1, true, 1);

      Traverse(loctestnum, loctesterr, pq1, true, &TraversePrint<string>);

      Exists(loctestnum, loctesterr, pq1, true, string("A"));
      GetAt(loctestnum, loctesterr, pq1, true, 0, string("A"));

      TraversePreOrder(loctestnum, loctesterr, pq1, true, &TraversePrint<string>);
      TraversePostOrder(loctestnum, loctesterr, pq1, true, &TraversePrint<string>);

      FoldPreOrder(loctestnum, loctesterr, pq1, true, &FoldStringConcatenate, string("?"), string("?A"));
      FoldPostOrder(loctestnum, loctesterr, pq1, true, &FoldStringConcatenate, string("?"), string("?A"));

      Tip(loctestnum, loctesterr, pq1, true, string("A"));
      RemoveTip(loctestnum, loctesterr, pq1, true);
      Size(loctestnum, loctesterr, pq1, true, 0);
      Empty(loctestnum, loctesterr, pq1, true);
    }

    // CASO 2
    {
      print_section("2 ELEMENTS");
      lasd::PQHeap<string> pq2;
      Insert(loctestnum, loctesterr, pq2, string("B"));
      Insert(loctestnum, loctesterr, pq2, string("D"));

      Traverse(loctestnum, loctesterr, pq2, true, &TraversePrint<string>);

      Empty(loctestnum, loctesterr, pq2, false);
      Size(loctestnum, loctesterr, pq2, true, 2);

      Exists(loctestnum, loctesterr, pq2, true, string("B"));
      GetAt(loctestnum, loctesterr, pq2, true, 0, string("D"));

      TraversePreOrder(loctestnum, loctesterr, pq2, true, &TraversePrint<string>);
      TraversePostOrder(loctestnum, loctesterr, pq2, true, &TraversePrint<string>);

      FoldPreOrder(loctestnum, loctesterr, pq2, true, &FoldStringConcatenate, string("?"), string("?DB"));
      FoldPostOrder(loctestnum, loctesterr, pq2, true, &FoldStringConcatenate, string("?"), string("?BD"));

      Tip(loctestnum, loctesterr, pq2, true, string("D"));
      TipNRemove(loctestnum, loctesterr, pq2, true, string("D"));
      TipNRemove(loctestnum, loctesterr, pq2, true, string("B"));
      Empty(loctestnum, loctesterr, pq2, true);
    }

    // CASO 3
    {
      print_section("3 ELEMENTS");
      lasd::PQHeap<string> pq3;
      Insert(loctestnum, loctesterr, pq3, string("A"));
      Insert(loctestnum, loctesterr, pq3, string("C"));
      Insert(loctestnum, loctesterr, pq3, string("F"));

      Traverse(loctestnum, loctesterr, pq3, true, &TraversePrint<string>);
      
      Empty(loctestnum, loctesterr, pq3, false);
      Size(loctestnum, loctesterr, pq3, true, 3);

      TraversePreOrder(loctestnum, loctesterr, pq3, true, &TraversePrint<string>);
      TraversePostOrder(loctestnum, loctesterr, pq3, true, &TraversePrint<string>);

      Change(loctestnum, loctesterr, pq3, true, 1, string("G"));

      Traverse(loctestnum, loctesterr, pq3, true, &TraversePrint<string>);

      FoldPreOrder(loctestnum, loctesterr, pq3, true, &FoldStringConcatenate, string("?"), string("?GFC"));
      FoldPostOrder(loctestnum, loctesterr, pq3, true, &FoldStringConcatenate, string("?"), string("?CFG"));

      Exists(loctestnum, loctesterr, pq3, true, string("G"));
      Exists(loctestnum, loctesterr, pq3, true, string("C"));

      GetAt(loctestnum, loctesterr, pq3, true, 1, string("F"));
    }

    // CASO N
    {
      print_section("N ELEMENTS");
  
      lasd::Vector<string> vec(14);
      SetAt(loctestnum, loctesterr, vec, true, 0, string("E"));
      SetAt(loctestnum, loctesterr, vec, true, 1, string("D"));
      SetAt(loctestnum, loctesterr, vec, true, 2, string("B"));
      SetAt(loctestnum, loctesterr, vec, true, 3, string("A"));
      SetAt(loctestnum, loctesterr, vec, true, 4, string("C"));
      SetAt(loctestnum, loctesterr, vec, true, 5, string("F"));
      SetAt(loctestnum, loctesterr, vec, true, 6, string("A"));
      SetAt(loctestnum, loctesterr, vec, true, 7, string("I"));
      SetAt(loctestnum, loctesterr, vec, true, 8, string("K"));
      SetAt(loctestnum, loctesterr, vec, true, 9, string("L"));
      SetAt(loctestnum, loctesterr, vec, true, 10, string("H"));
      SetAt(loctestnum, loctesterr, vec, true, 11, string("D"));
      SetAt(loctestnum, loctesterr, vec, true, 12, string("J"));
      SetAt(loctestnum, loctesterr, vec, true, 13, string("G"));
  
      lasd::PQHeap<string> pq(vec);
  
      TraversePreOrder(loctestnum, loctesterr, pq, true, &TraversePrint<string>);
      TraversePostOrder(loctestnum, loctesterr, pq, true, &TraversePrint<string>);
  
      FoldPreOrder(loctestnum, loctesterr, pq, true, &FoldStringConcatenate, string("?"), string("?LKJIHFGEACDDBA"));
      FoldPostOrder(loctestnum, loctesterr, pq, true, &FoldStringConcatenate, string("?"), string("?ABDDCAEGFHIJKL"));
  
      Tip(loctestnum, loctesterr, pq, true, string("L"));
      RemoveTip(loctestnum, loctesterr, pq, true);
  
      TraversePreOrder(loctestnum, loctesterr, pq, true, &TraversePrint<string>);
      TraversePostOrder(loctestnum, loctesterr, pq, true, &TraversePrint<string>);
  
      Tip(loctestnum, loctesterr, pq, true, string("K"));
      RemoveTip(loctestnum, loctesterr, pq, true);
      Insert(loctestnum, loctesterr, pq, string("J"));
      Insert(loctestnum, loctesterr, pq, string("K"));
      TipNRemove(loctestnum, loctesterr, pq, true, string("K"));
      TipNRemove(loctestnum, loctesterr, pq, true, string("J"));
      TipNRemove(loctestnum, loctesterr, pq, true, string("J"));
  
      TraversePreOrder(loctestnum, loctesterr, pq, true, &TraversePrint<string>);
      TraversePostOrder(loctestnum, loctesterr, pq, true, &TraversePrint<string>);
  
      FoldPreOrder(loctestnum, loctesterr, pq, true, &FoldStringConcatenate, string("?"), string("?IHGEDFBAACD"));
      FoldPostOrder(loctestnum, loctesterr, pq, true, &FoldStringConcatenate, string("?"), string("?DCAABFDEGHI"));
  
      Insert(loctestnum, loctesterr, pq, string("F"));
  
      TraversePreOrder(loctestnum, loctesterr, pq, true, &TraversePrint<string>);
      TraversePostOrder(loctestnum, loctesterr, pq, true, &TraversePrint<string>);
  
      FoldPreOrder(loctestnum, loctesterr, pq, true, &FoldStringConcatenate, string("?"), string("?IHGEDFBAACDF"));
      FoldPostOrder(loctestnum, loctesterr, pq, true, &FoldStringConcatenate, string("?"), string("?FDCAABFDEGHI"));
  
      Change(loctestnum, loctesterr, pq, true, 4, string("X"));
  
      TraversePreOrder(loctestnum, loctesterr, pq, true, &TraversePrint<string>);
      TraversePostOrder(loctestnum, loctesterr, pq, true, &TraversePrint<string>);
  
      FoldPreOrder(loctestnum, loctesterr, pq, true, &FoldStringConcatenate, string("?"), string("?XIGEHFBAACDF"));
      FoldPostOrder(loctestnum, loctesterr, pq, true, &FoldStringConcatenate, string("?"), string("?FDCAABFHEGIX"));
  
      Change(loctestnum, loctesterr, pq, true, 1, string("A"));
  
      TraversePreOrder(loctestnum, loctesterr, pq, true, &TraversePrint<string>);
      TraversePostOrder(loctestnum, loctesterr, pq, true, &TraversePrint<string>);
  
      FoldPreOrder(loctestnum, loctesterr, pq, true, &FoldStringConcatenate, string("?"), string("?XHGEDFBAACAF"));
      FoldPostOrder(loctestnum, loctesterr, pq, true, &FoldStringConcatenate, string("?"), string("?FACAABFDEGHX"));
  
      Change(loctestnum, loctesterr, pq, true, 2, string("B"));
  
      TraversePreOrder(loctestnum, loctesterr, pq, true, &TraversePrint<string>);
      TraversePostOrder(loctestnum, loctesterr, pq, true, &TraversePrint<string>);
  
      FoldPreOrder(loctestnum, loctesterr, pq, true, &FoldStringConcatenate, string("?"), string("?XHFEDFBAACAB"));
      FoldPostOrder(loctestnum, loctesterr, pq, true, &FoldStringConcatenate, string("?"), string("?BACAABFDEFHX"));
    }  
  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of PQ<string> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

/* ************************************************************************** */

void runExPQ(uint & testnum, uint & testerr) {
  mystestPQInt(testnum, testerr);
  mystestPQDouble(testnum, testerr);
  mystestPQString(testnum, testerr);
  cout << endl << "Exercise 2B PQ (MY TEST) (Errors/Tests: " << testerr << "/" << testnum << ")" << endl;
}