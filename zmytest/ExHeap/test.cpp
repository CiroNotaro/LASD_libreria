
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

    lasd::Vector<double> vec(14);
    SetAt(loctestnum, loctesterr, vec, true, 0, 4.5);
    SetAt(loctestnum, loctesterr, vec, true, 1, 3.25);
    SetAt(loctestnum, loctesterr, vec, true, 2, 1.125);
    SetAt(loctestnum, loctesterr, vec, true, 3, 0.0);
    SetAt(loctestnum, loctesterr, vec, true, 4, 2.25);
    SetAt(loctestnum, loctesterr, vec, true, 5, 5.5);
    SetAt(loctestnum, loctesterr, vec, true, 6, 0.0);
    SetAt(loctestnum, loctesterr, vec, true, 7, 8.25);
    SetAt(loctestnum, loctesterr, vec, true, 8, 10.5);
    SetAt(loctestnum, loctesterr, vec, true, 9, 11.5);
    SetAt(loctestnum, loctesterr, vec, true, 10, 7.25);
    SetAt(loctestnum, loctesterr, vec, true, 11, 3.125);
    SetAt(loctestnum, loctesterr, vec, true, 12, 9.5);
    SetAt(loctestnum, loctesterr, vec, true, 13, 6.25);

    lasd::HeapVec<double> heap(vec);

    TraversePreOrder(loctestnum, loctesterr, heap, true, &TraversePrint<double>);
    TraversePreOrder(loctestnum, loctesterr, heap, true, &TraversePrint<double>);

    heap.Sort();

    TraversePreOrder(loctestnum, loctesterr, heap, true, &TraversePrint<double>);
    TraversePostOrder(loctestnum, loctesterr, heap, true, &TraversePrint<double>);

    heap.Heapify();

    TraversePreOrder(loctestnum, loctesterr, heap, true, &TraversePrint<double>);
    TraversePreOrder(loctestnum, loctesterr, heap, true, &TraversePrint<double>);

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

    lasd::HeapVec<string> heap(vec);

    TraversePreOrder(loctestnum, loctesterr, heap, true, &TraversePrint<string>);
    TraversePostOrder(loctestnum, loctesterr, heap, true, &TraversePrint<string>);

    MapPreOrder(loctestnum, loctesterr, heap, true, [](string & str) { MapStringAppend(str, string("*")); });
    MapPreOrder(loctestnum, loctesterr, heap, true, [](string & str) { MapStringAppend(str, string(" ")); });

    TraversePreOrder(loctestnum, loctesterr, heap, true, &TraversePrint<string>);
    TraversePostOrder(loctestnum, loctesterr, heap, true, &TraversePrint<string>);

    FoldPostOrder(loctestnum, loctesterr, heap, true, &FoldStringConcatenate, string("?"), string("?A* B* D* D* C* A* E* G* F* H* I* J* K* L* "));
    FoldPreOrder(loctestnum, loctesterr, heap, true, &FoldStringConcatenate, string("?"), string("?L* K* J* I* H* F* G* E* A* C* D* D* B* A* "));

    heap.Sort();

    TraversePreOrder(loctestnum, loctesterr, heap, true, &TraversePrint<string>);
    TraversePostOrder(loctestnum, loctesterr, heap, true, &TraversePrint<string>);

    FoldPostOrder(loctestnum, loctesterr, heap, true, &FoldStringConcatenate, string("?"), string("?L* K* J* I* H* G* F* E* D* D* C* B* A* A* "));
    FoldPreOrder(loctestnum, loctesterr, heap, true, &FoldStringConcatenate, string("?"), string("?A* A* B* C* D* D* E* F* G* H* I* J* K* L* "));

    heap.Heapify();

    TraversePreOrder(loctestnum, loctesterr, heap, true, &TraversePrint<string>);
    TraversePostOrder(loctestnum, loctesterr, heap, true, &TraversePrint<string>);

    FoldPostOrder(loctestnum, loctesterr, heap, true, &FoldStringConcatenate, string("?"), string("?B* D* A* D* A* C* F* E* J* H* G* K* I* L* "));
    FoldPreOrder(loctestnum, loctesterr, heap, true, &FoldStringConcatenate, string("?"), string("?L* I* K* G* H* J* E* F* C* A* D* A* D* B* "));

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