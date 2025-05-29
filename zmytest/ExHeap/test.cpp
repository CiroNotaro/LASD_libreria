
#include <iostream>

/* ************************************************************************** */

#include "../../zlasdtest/container/container.hpp"
#include "../../zlasdtest/container/testable.hpp"
#include "../../zlasdtest/container/traversable.hpp"
#include "../../zlasdtest/container/mappable.hpp"
#include "../../zlasdtest/container/linear.hpp"

#include "../../zlasdtest/vector/vector.hpp"

#include "../../zlasdtest/heap/heap.hpp"

#include "../../heap/heap.hpp"
#include "../../heap/vec/heapvec.hpp"

#include "../utils.hpp"

/* ************************************************************************** */

using namespace std;

/* ************************************************************************** */

void mystestHeapInt(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of Heap<int> Test:" << endl;
  try {

    // CASO 0
    {
        print_section("0 ELEMENTS");
        lasd::Vector<int> vec0;
        lasd::HeapVec<int> heap0(vec0);
        Empty(loctestnum, loctesterr, heap0, true);
        Size(loctestnum, loctesterr, heap0, true, 0);
        Traverse(loctestnum, loctesterr, heap0, true, &TraversePrint<int>);
        IsHeap(loctestnum, loctesterr, heap0, true);

        FoldPreOrder(loctestnum, loctesterr, heap0, true, &FoldAdd<int>, 0, 0);

        heap0.Heapify();
        Traverse(loctestnum, loctesterr, heap0, true, &TraversePrint<int>);

        FoldPreOrder(loctestnum, loctesterr, heap0, true, &FoldAdd<int>, 0, 0);
    }
    
    // CASO 1
    {
        print_section("1 ELEMENTS");
        lasd::Vector<int> vec1(1);
        SetAt(loctestnum, loctesterr, vec1, true, 0, 32);
        lasd::HeapVec<int> heap1(vec1);
        Empty(loctestnum, loctesterr, heap1, false);
        Size(loctestnum, loctesterr, heap1, true, 1);
        IsHeap(loctestnum, loctesterr, heap1, true);
        Traverse(loctestnum, loctesterr, heap1, true, &TraversePrint<int>);
        FoldPreOrder(loctestnum, loctesterr, heap1, true, &FoldAdd<int>, 0, 32);

        heap1[0] = 16;
        Empty(loctestnum, loctesterr, heap1, false);
        Size(loctestnum, loctesterr, heap1, true, 1);
        IsHeap(loctestnum, loctesterr, heap1, true);
        Traverse(loctestnum, loctesterr, heap1, true, &TraversePrint<int>);
        FoldPreOrder(loctestnum, loctesterr, heap1, true, &FoldAdd<int>, 0, 16);

        heap1.Heapify();

        heap1.Resize(0);
        Empty(loctestnum, loctesterr, heap1, true);
        Size(loctestnum, loctesterr, heap1, true, 0);
        IsHeap(loctestnum, loctesterr, heap1, true);
        Traverse(loctestnum, loctesterr, heap1, true, &TraversePrint<int>);

        FoldPreOrder(loctestnum, loctesterr, heap1, true, &FoldAdd<int>, 0, 0);

    }

    // CASO 2
    {
        print_section("2 ELEMENTS");
        lasd::Vector<int> vec2(2);
        SetAt(loctestnum, loctesterr, vec2, true, 0, 2);
        SetAt(loctestnum, loctesterr, vec2, true, 1, 1);

        lasd::HeapVec<int> heap2(vec2);
        Empty(loctestnum, loctesterr, heap2, false);
        Size(loctestnum, loctesterr, heap2, true, 2);
        IsHeap(loctestnum, loctesterr, heap2, true);
        Traverse(loctestnum, loctesterr, heap2, true, &TraversePrint<int>);
        FoldPreOrder(loctestnum, loctesterr, heap2, true, &FoldAdd<int>, 0, 3);

        heap2.Sort();
        Size(loctestnum, loctesterr, heap2, true, 2);
        IsHeap(loctestnum, loctesterr, heap2, false);
        Traverse(loctestnum, loctesterr, heap2, true, &TraversePrint<int>);

        heap2.Resize(1);
        Size(loctestnum, loctesterr, heap2, true, 1);
        IsHeap(loctestnum, loctesterr, heap2, true);
        Traverse(loctestnum, loctesterr, heap2, true, &TraversePrint<int>);
    }

    // CASO 3
    {
        print_section("3 ELEMENTS");
        lasd::Vector<int> vec2(3);
        SetAt(loctestnum, loctesterr, vec2, true, 0, 2);
        SetAt(loctestnum, loctesterr, vec2, true, 1, 1);
        SetAt(loctestnum, loctesterr, vec2, true, 2, 3);

        lasd::HeapVec<int> heap2(vec2);
        Empty(loctestnum, loctesterr, heap2, false);
        Size(loctestnum, loctesterr, heap2, true, 3);
        IsHeap(loctestnum, loctesterr, heap2, true);
        Traverse(loctestnum, loctesterr, heap2, true, &TraversePrint<int>);
        FoldPreOrder(loctestnum, loctesterr, heap2, true, &FoldAdd<int>, 0, 6);

        heap2.Sort();
        Size(loctestnum, loctesterr, heap2, true, 3);
        IsHeap(loctestnum, loctesterr, heap2, false);
        Traverse(loctestnum, loctesterr, heap2, true, &TraversePrint<int>);
        FoldPreOrder(loctestnum, loctesterr, heap2, true, &FoldAdd<int>, 0, 6);

        heap2.Resize(1);
        Size(loctestnum, loctesterr, heap2, true, 1);
        IsHeap(loctestnum, loctesterr, heap2, true);
        Traverse(loctestnum, loctesterr, heap2, true, &TraversePrint<int>);
        FoldPreOrder(loctestnum, loctesterr, heap2, true, &FoldAdd<int>, 0, 1);
    }

    // CASO N
    {
        print_section("N ELEMENTS");
        lasd::Vector<int> vec5(5);
        SetAt(loctestnum, loctesterr, vec5, true, 0, 5);
        SetAt(loctestnum, loctesterr, vec5, true, 1, 4);
        SetAt(loctestnum, loctesterr, vec5, true, 2, 2);
        SetAt(loctestnum, loctesterr, vec5, true, 3, 1);
        SetAt(loctestnum, loctesterr, vec5, true, 4, 3);

        lasd::HeapVec<int> heap5(vec5);
        Size(loctestnum, loctesterr, heap5, true, 5);
        IsHeap(loctestnum, loctesterr, heap5, true);
        TraversePreOrder(loctestnum, loctesterr, heap5, true, &TraversePrint<int>);
        FoldPreOrder(loctestnum, loctesterr, heap5, true, &FoldAdd<int>, 0, 15);

        heap5.Sort();
        IsHeap(loctestnum, loctesterr, heap5, false);
        TraversePreOrder(loctestnum, loctesterr, heap5, true, &TraversePrint<int>);
        TraversePostOrder(loctestnum, loctesterr, heap5, true, &TraversePrint<int>);

        heap5.Heapify();
        IsHeap(loctestnum, loctesterr, heap5, true);
        Traverse(loctestnum, loctesterr, heap5, true, &TraversePrint<int>);

        heap5[0] = 0;
        IsHeap(loctestnum, loctesterr, heap5, false);
        Traverse(loctestnum, loctesterr, heap5, true, &TraversePrint<int>);
        FoldPreOrder(loctestnum, loctesterr, heap5, true, &FoldAdd<int>, 0, 10);

        heap5.Heapify();
        IsHeap(loctestnum, loctesterr, heap5, true);

        Traverse(loctestnum, loctesterr, heap5, true, &TraversePrint<int>);

        heap5.Resize(3);
        IsHeap(loctestnum, loctesterr, heap5, true);
        Traverse(loctestnum, loctesterr, heap5, true, &TraversePrint<int>);
        FoldPreOrder(loctestnum, loctesterr, heap5, true, &FoldAdd<int>, 0, 9);

        heap5.Sort();
        IsHeap(loctestnum, loctesterr, heap5, false);
        Traverse(loctestnum, loctesterr, heap5, true, &TraversePrint<int>);
        FoldPreOrder(loctestnum, loctesterr, heap5, true, &FoldAdd<int>, 0, 9);
    }
  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of Heap<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void mystestHeapDouble(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of Heap<double> Test:" << endl;
  try {

    // CASO 0
    {
        print_section("0 ELEMENTS");
        lasd::Vector<double> vec0;
        lasd::HeapVec<double> heap0(vec0);
        Empty(loctestnum, loctesterr, heap0, true);
        Size(loctestnum, loctesterr, heap0, true, 0);
        Traverse(loctestnum, loctesterr, heap0, true, &TraversePrint<double>);
        IsHeap(loctestnum, loctesterr, heap0, true);

        FoldPreOrder(loctestnum, loctesterr, heap0, true, &FoldAdd<double>, 0., 0.);

        heap0.Heapify();
        Traverse(loctestnum, loctesterr, heap0, true, &TraversePrint<double>);

        FoldPreOrder(loctestnum, loctesterr, heap0, true, &FoldAdd<double>, 0., 0.);
    }
    
    // CASO 1
    {
        print_section("1 ELEMENTS");
        lasd::Vector<double> vec1(1);
        SetAt(loctestnum, loctesterr, vec1, true, 0, 32.);
        lasd::HeapVec<double> heap1(vec1);
        Empty(loctestnum, loctesterr, heap1, false);
        Size(loctestnum, loctesterr, heap1, true, 1);
        IsHeap(loctestnum, loctesterr, heap1, true);
        Traverse(loctestnum, loctesterr, heap1, true, &TraversePrint<double>);
        FoldPreOrder(loctestnum, loctesterr, heap1, true, &FoldAdd<double>, 0., 32.);

        heap1[0] = 16;
        Empty(loctestnum, loctesterr, heap1, false);
        Size(loctestnum, loctesterr, heap1, true, 1);
        IsHeap(loctestnum, loctesterr, heap1, true);
        Traverse(loctestnum, loctesterr, heap1, true, &TraversePrint<double>);
        FoldPreOrder(loctestnum, loctesterr, heap1, true, &FoldAdd<double>, 0., 16.);

        heap1.Heapify();

        heap1.Resize(0);
        Empty(loctestnum, loctesterr, heap1, true);
        Size(loctestnum, loctesterr, heap1, true, 0);
        IsHeap(loctestnum, loctesterr, heap1, true);
        Traverse(loctestnum, loctesterr, heap1, true, &TraversePrint<double>);

        FoldPreOrder(loctestnum, loctesterr, heap1, true, &FoldAdd<double>, 0., 0.);

    }

    // CASO 2
    {
        print_section("2 ELEMENTS");
        lasd::Vector<double> vec2(2);
        SetAt(loctestnum, loctesterr, vec2, true, 0, 2.1);
        SetAt(loctestnum, loctesterr, vec2, true, 1, 1.1);

        lasd::HeapVec<double> heap2(vec2);
        Empty(loctestnum, loctesterr, heap2, false);
        Size(loctestnum, loctesterr, heap2, true, 2);
        IsHeap(loctestnum, loctesterr, heap2, true);
        Traverse(loctestnum, loctesterr, heap2, true, &TraversePrint<double>);
        FoldPreOrder(loctestnum, loctesterr, heap2, true, &FoldAdd<double>, 0., 3.2);

        heap2.Sort();
        Size(loctestnum, loctesterr, heap2, true, 2);
        IsHeap(loctestnum, loctesterr, heap2, false);
        Traverse(loctestnum, loctesterr, heap2, true, &TraversePrint<double>);

        heap2.Resize(1);
        Size(loctestnum, loctesterr, heap2, true, 1);
        IsHeap(loctestnum, loctesterr, heap2, true);
        Traverse(loctestnum, loctesterr, heap2, true, &TraversePrint<double>);
    }

    // CASO 3
    {
        print_section("3 ELEMENTS");
        lasd::Vector<double> vec2(3);
        SetAt(loctestnum, loctesterr, vec2, true, 0, 2.1);
        SetAt(loctestnum, loctesterr, vec2, true, 1, 1.1);
        SetAt(loctestnum, loctesterr, vec2, true, 2, 3.2);

        lasd::HeapVec<double> heap2(vec2);
        Empty(loctestnum, loctesterr, heap2, false);
        Size(loctestnum, loctesterr, heap2, true, 3);
        IsHeap(loctestnum, loctesterr, heap2, true);
        Traverse(loctestnum, loctesterr, heap2, true, &TraversePrint<double>);
        FoldPreOrder(loctestnum, loctesterr, heap2, true, &FoldAdd<double>, 0., 6.4);

        heap2.Sort();
        Size(loctestnum, loctesterr, heap2, true, 3);
        IsHeap(loctestnum, loctesterr, heap2, false);
        Traverse(loctestnum, loctesterr, heap2, true, &TraversePrint<double>);
        FoldPreOrder(loctestnum, loctesterr, heap2, true, &FoldAdd<double>, 0., 6.4);

        heap2.Resize(1);
        Size(loctestnum, loctesterr, heap2, true, 1);
        IsHeap(loctestnum, loctesterr, heap2, true);
        Traverse(loctestnum, loctesterr, heap2, true, &TraversePrint<double>);
        FoldPreOrder(loctestnum, loctesterr, heap2, true, &FoldAdd<double>, 0., 1.1);
    }

    // CASO N
    {
        print_section("N ELEMENTS");
        lasd::Vector<double> vec5(5);
        SetAt(loctestnum, loctesterr, vec5, true, 0, 5.0);
        SetAt(loctestnum, loctesterr, vec5, true, 1, 4.0);
        SetAt(loctestnum, loctesterr, vec5, true, 2, 2.0);
        SetAt(loctestnum, loctesterr, vec5, true, 3, 1.2);
        SetAt(loctestnum, loctesterr, vec5, true, 4, 3.0);

        lasd::HeapVec<double> heap5(vec5);
        Size(loctestnum, loctesterr, heap5, true, 5);
        IsHeap(loctestnum, loctesterr, heap5, true);
        TraversePreOrder(loctestnum, loctesterr, heap5, true, &TraversePrint<double>);

        heap5.Sort();
        IsHeap(loctestnum, loctesterr, heap5, false);
        TraversePreOrder(loctestnum, loctesterr, heap5, true, &TraversePrint<double>);
        TraversePostOrder(loctestnum, loctesterr, heap5, true, &TraversePrint<double>);

        heap5.Heapify();
        IsHeap(loctestnum, loctesterr, heap5, true);
        Traverse(loctestnum, loctesterr, heap5, true, &TraversePrint<double>);

        heap5[0] = 0.;
        IsHeap(loctestnum, loctesterr, heap5, false);
        Traverse(loctestnum, loctesterr, heap5, true, &TraversePrint<double>);
        FoldPreOrder(loctestnum, loctesterr, heap5, true, &FoldAdd<double>, 0., 10.2);

        heap5.Heapify();
        IsHeap(loctestnum, loctesterr, heap5, true);

        Traverse(loctestnum, loctesterr, heap5, true, &TraversePrint<double>);

        heap5.Resize(3);
        IsHeap(loctestnum, loctesterr, heap5, true);
        Traverse(loctestnum, loctesterr, heap5, true, &TraversePrint<double>);
        FoldPreOrder(loctestnum, loctesterr, heap5, true, &FoldAdd<double>, 0., 9.);

        heap5.Sort();
        IsHeap(loctestnum, loctesterr, heap5, false);
        Traverse(loctestnum, loctesterr, heap5, true, &TraversePrint<double>);
        FoldPreOrder(loctestnum, loctesterr, heap5, true, &FoldAdd<double>, 0., 9.);
    }

  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of Heap<double> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void mystestHeapString(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of Heap<string> Test:" << endl;
  try {

    // CASO 0
    {
      print_section("0 ELEMENTS");
      lasd::Vector<string> vec0(0);
      lasd::HeapVec<string> heap0(vec0);

      TraversePreOrder(loctestnum, loctesterr, heap0, true, &TraversePrint<string>);
      TraversePostOrder(loctestnum, loctesterr, heap0, true, &TraversePrint<string>);
      FoldPostOrder(loctestnum, loctesterr, heap0, true, &FoldStringConcatenate, string("?"), string("?"));
      MapPreOrder(loctestnum, loctesterr, heap0, true, [](string & str) { MapStringAppend(str, "*"); });
      MapPostOrder(loctestnum, loctesterr, heap0, true, [](string & str) { MapStringAppend(str, "*"); });

    }

    // CASO 1
    {
      print_section("1 ELEMENTS");
      lasd::Vector<string> vec1(1);
      SetAt(loctestnum, loctesterr, vec1, true, 0, string("A"));

      lasd::HeapVec<string> heap1(vec1);
      Empty(loctestnum, loctesterr, heap1, false);
      Size(loctestnum, loctesterr, heap1, true, 1);

      TraversePreOrder(loctestnum, loctesterr, heap1, true, &TraversePrint<string>);
      TraversePostOrder(loctestnum, loctesterr, heap1, true, &TraversePrint<string>);
      MapPreOrder(loctestnum, loctesterr, heap1, true, [](string & str) { MapStringAppend(str, "*"); });
      FoldPostOrder(loctestnum, loctesterr, heap1, true, &FoldStringConcatenate, string("?"), string("?A*"));
      FoldPreOrder(loctestnum, loctesterr, heap1, true, &FoldStringConcatenate, string("?"), string("?A*"));
    }

    // CASO 2
    {
      print_section("2 ELEMENTS");
      lasd::Vector<string> vec2(2);
      SetAt(loctestnum, loctesterr, vec2, true, 0, string("B"));
      SetAt(loctestnum, loctesterr, vec2, true, 1, string("A"));

      lasd::HeapVec<string> heap2(vec2);
      Empty(loctestnum, loctesterr, heap2, false);
      Size(loctestnum, loctesterr, heap2, true, 2);

      TraversePreOrder(loctestnum, loctesterr, heap2, true, &TraversePrint<string>);
      TraversePostOrder(loctestnum, loctesterr, heap2, true, &TraversePrint<string>);
      MapPreOrder(loctestnum, loctesterr, heap2, true, [](string & str) { MapStringAppend(str, "*"); });
      FoldPostOrder(loctestnum, loctesterr, heap2, true, &FoldStringConcatenate, string("?"), string("?A*B*"));
    }

    // CASO 3
    {
      print_section("3 ELEMENTS");
      lasd::Vector<string> vec3(3);
      SetAt(loctestnum, loctesterr, vec3, true, 0, string("C"));
      SetAt(loctestnum, loctesterr, vec3, true, 1, string("A"));
      SetAt(loctestnum, loctesterr, vec3, true, 2, string("B"));

      lasd::HeapVec<string> heap3(vec3);
      Empty(loctestnum, loctesterr, heap3, false);
      Size(loctestnum, loctesterr, heap3, true, 3);

      TraversePreOrder(loctestnum, loctesterr, heap3, true, &TraversePrint<string>);
      TraversePostOrder(loctestnum, loctesterr, heap3, true, &TraversePrint<string>);
      MapPreOrder(loctestnum, loctesterr, heap3, true, [](string & str) { MapStringAppend(str, "*"); });

      FoldPostOrder(loctestnum, loctesterr, heap3, true, &FoldStringConcatenate, string("?"), string("?B*A*C*"));
    }

    // CASO N
    {
      print_section("N ELEMENTS");
      lasd::Vector<string> vec5(5);
      SetAt(loctestnum, loctesterr, vec5, true, 0, string("E"));
      SetAt(loctestnum, loctesterr, vec5, true, 1, string("B"));
      SetAt(loctestnum, loctesterr, vec5, true, 2, string("C"));
      SetAt(loctestnum, loctesterr, vec5, true, 3, string("A"));
      SetAt(loctestnum, loctesterr, vec5, true, 4, string("D"));

      lasd::HeapVec<string> heap5(vec5);
      Empty(loctestnum, loctesterr, heap5, false);
      Size(loctestnum, loctesterr, heap5, true, 5);

      TraversePreOrder(loctestnum, loctesterr, heap5, true, &TraversePrint<string>);
      TraversePostOrder(loctestnum, loctesterr, heap5, true, &TraversePrint<string>);

      MapPreOrder(loctestnum, loctesterr, heap5, true, [](string & str) { MapStringAppend(str, "*"); });
      FoldPostOrder(loctestnum, loctesterr, heap5, true, &FoldStringConcatenate, string("?"), string("?B*A*C*D*E*"));

      heap5.Sort();

      TraversePreOrder(loctestnum, loctesterr, heap5, true, &TraversePrint<string>);
      FoldPreOrder(loctestnum, loctesterr, heap5, true, &FoldStringConcatenate, string("?"), string("?A*B*C*D*E*"));

      heap5.Heapify();

      TraversePostOrder(loctestnum, loctesterr, heap5, true, &TraversePrint<string>);
      FoldPostOrder(loctestnum, loctesterr, heap5, true, &FoldStringConcatenate, string("?"), string("?B*A*C*D*E*"));

      heap5.Resize(4);
      heap5.Heapify();
      Empty(loctestnum, loctesterr, heap5, false);
      Size(loctestnum, loctesterr, heap5, true, 4);

    }

  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of Heap<string> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

/* ************************************************************************** */

void runExHeap(uint & testnum, uint & testerr) {
  mystestHeapInt(testnum, testerr);
  mystestHeapDouble(testnum, testerr);
  mystestHeapString(testnum, testerr);
  cout << endl << "Exercise 2A HEAP (MY TEST) (Errors/Tests: " << testerr << "/" << testnum << ")" << endl;
}