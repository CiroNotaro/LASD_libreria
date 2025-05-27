#include <iostream>

/* ************************************************************************** */

#include "../../zlasdtest/container/container.hpp"
#include "../../zlasdtest/container/traversable.hpp"
#include "../../zlasdtest/container/testable.hpp"
#include "../../zlasdtest/container/dictionary.hpp"
#include "../../zlasdtest/container/linear.hpp"

#include "../../zlasdtest/vector/vector.hpp"
#include "../../zlasdtest/list/list.hpp"
#include "../../zlasdtest/set/set.hpp"

#include "../../set/lst/setlst.hpp"
#include "../../set/vec/setvec.hpp"

#include "../utils.hpp"

/* ************************************************************************** */

using namespace std;

/* ************************************************************************** */


void mystestSetInt(lasd::Set<int> & set, uint & testnum, uint & testerr) 
{
    uint loctestnum = 0, loctesterr = 0;
    try 
    {
        {
            // CASO 0
            print_section("0 ELEMENTS");
            Empty(loctestnum, loctesterr, set, true);
            Size(loctestnum, loctesterr, set, true, 0);
            Predecessor(loctestnum, loctesterr, set, false, 18, 0);
            Successor(loctestnum, loctesterr, set, false, 18, 20);
            TraversePreOrder(loctestnum, loctesterr, set, true, &TraversePrint<int>);
            TraversePostOrder(loctestnum, loctesterr, set, true, &TraversePrint<int>);
            FoldPreOrder(loctestnum, loctesterr, set, true, &FoldAdd<int>, 0, 0);
            FoldPostOrder(loctestnum, loctesterr, set, true, &FoldAdd<int>, 0, 0);
        }

        {
            // CASO 1
            print_section("1 ELEMENTS");
            InsertC(loctestnum, loctesterr, set, true, 18);
            Size(loctestnum, loctesterr, set, true, 1);
            Exists(loctestnum, loctesterr, set, true, 18);
            Min(loctestnum, loctesterr, set, true, 18);
            Max(loctestnum, loctesterr, set, true, 18);
            Predecessor(loctestnum, loctesterr, set, false, 18, 0);
            Successor(loctestnum, loctesterr, set, false, 18, 20);
            TraversePreOrder(loctestnum, loctesterr, set, true, &TraversePrint<int>);
            TraversePostOrder(loctestnum, loctesterr, set, true, &TraversePrint<int>);
            FoldPreOrder(loctestnum, loctesterr, set, true, &FoldAdd<int>, 0, 18);
            FoldPostOrder(loctestnum, loctesterr, set, true, &FoldAdd<int>, 0, 18);
            Remove(loctestnum, loctesterr, set, true, 18);
            Empty(loctestnum, loctesterr, set, true);
            Size(loctestnum, loctesterr, set, true, 0);
        }

        {
            // CASO N
            print_section("N ELEMENTS");
            InsertC(loctestnum, loctesterr, set, true, 4);
            InsertC(loctestnum, loctesterr, set, true, 6);
            InsertC(loctestnum, loctesterr, set, true, 7);
            InsertC(loctestnum, loctesterr, set, true, 5);
            InsertC(loctestnum, loctesterr, set, true, 0);
            InsertC(loctestnum, loctesterr, set, true, 2);
            InsertC(loctestnum, loctesterr, set, true, 1);

            Size(loctestnum, loctesterr, set, true, 7);
            GetAt(loctestnum, loctesterr, set, true, 0, 0);
            TraversePreOrder(loctestnum, loctesterr, set, true, &TraversePrint<int>);
            TraversePostOrder(loctestnum, loctesterr, set, true, &TraversePrint<int>);
            Min(loctestnum, loctesterr, set, true, 0);
            Max(loctestnum, loctesterr, set, true, 7);
            RemoveMin(loctestnum, loctesterr, set, true);
            MinNRemove(loctestnum, loctesterr, set, true, 1);
            InsertC(loctestnum, loctesterr, set, true, -1);
            InsertC(loctestnum, loctesterr, set, true, 1);
            MaxNRemove(loctestnum, loctesterr, set, true, 7);
            Size(loctestnum, loctesterr, set, true, 6);
            InsertC(loctestnum, loctesterr, set, true, 8);
            Max(loctestnum, loctesterr, set, true, 8);
            InsertC(loctestnum, loctesterr, set, true, 9);
            Size(loctestnum, loctesterr, set, true, 8);

            Exists(loctestnum, loctesterr, set, true, 8);
            Exists(loctestnum, loctesterr, set, false, 7);
            Exists(loctestnum, loctesterr, set, true, 6);
            Exists(loctestnum, loctesterr, set, false, 0);
            Exists(loctestnum, loctesterr, set, true, -1);
            Exists(loctestnum, loctesterr, set, true, 2);

            Remove(loctestnum, loctesterr, set, true, 6);
            Remove(loctestnum, loctesterr, set, true, 2);
            Exists(loctestnum, loctesterr, set, false, 6);
            Exists(loctestnum, loctesterr, set, false, 2);

            RemoveMax(loctestnum, loctesterr, set, true);
            Max(loctestnum, loctesterr, set, true, 8);

            Predecessor(loctestnum, loctesterr, set, true, 4, 1);
            Predecessor(loctestnum, loctesterr, set, true, 5, 4);
            Successor(loctestnum, loctesterr, set, true, 2, 4);
            Successor(loctestnum, loctesterr, set, true, 4, 5);

            TraversePreOrder(loctestnum, loctesterr, set, true, &TraversePrint<int>);
            TraversePostOrder(loctestnum, loctesterr, set, true, &TraversePrint<int>);

            SuccessorNRemove(loctestnum, loctesterr, set, true, 0, 1);
            Min(loctestnum, loctesterr, set, true, -1);
            PredecessorNRemove(loctestnum, loctesterr, set, true, 7, 5);
            Max(loctestnum, loctesterr, set, true, 8);

            FoldPreOrder(loctestnum, loctesterr, set, true, &FoldAdd<int>, 0, 11);
            FoldPostOrder(loctestnum, loctesterr, set, true, &FoldAdd<int>, 0, 11);

            TraversePreOrder(loctestnum, loctesterr, set, true, &TraversePrint<int>);
            TraversePostOrder(loctestnum, loctesterr, set, true, &TraversePrint<int>);

            set.Clear();

            Empty(loctestnum, loctesterr, set, true);
            Size(loctestnum, loctesterr, set, true, 0);
        }
    }
    catch (...) {
        loctestnum++; loctesterr++;
        cout << endl << "Unmanaged error! " << endl;
    }
    cout << "End of Set<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}

void mystestSetInt(uint & testnum, uint & testerr) 
{
    uint loctestnum = 0, loctesterr = 0;
    cout << endl << "Begin of Set<int> Test" << endl;
    try 
    {
        lasd::Vector<int> vec(7);
        SetAt(loctestnum, loctesterr, vec, true, 0, 7);
        SetAt(loctestnum, loctesterr, vec, true, 1, 1);
        SetAt(loctestnum, loctesterr, vec, true, 2, 6);
        SetAt(loctestnum, loctesterr, vec, true, 3, 4);
        SetAt(loctestnum, loctesterr, vec, true, 4, 3);
        SetAt(loctestnum, loctesterr, vec, true, 5, 2);
        SetAt(loctestnum, loctesterr, vec, true, 6, 5);

        cout << endl << "Begin of SetVec<int> Test:" << endl;
        lasd::SetVec<int> setvec;
        mystestSetInt(setvec, loctestnum, loctesterr);
        cout << endl << "Begin of SetLst<int> Test:" << endl;
        lasd::SetLst<int> setlst;
        mystestSetInt(setlst, loctestnum, loctesterr);
        cout << "\n";

        /* ********************************************************************** */

        setvec.InsertAll(vec);
        setlst.InsertAll(vec);

        lasd::SetVec<int> setvec1(setvec);
        EqualSetVec(loctestnum, loctesterr, setvec, setvec1, true);

        lasd::SetVec<int> setvec2 = setvec1;
        EqualSetVec(loctestnum, loctesterr, setvec1, setvec2, true);

        lasd::SetVec<int> setvec3(std::move(setvec2));
        Empty(loctestnum, loctesterr, setvec2, true);
        Size(loctestnum, loctesterr, setvec2, true, 0);
        EqualSetVec(loctestnum, loctesterr, setvec1, setvec3, true);

        setvec2 = std::move(setvec1);
        Empty(loctestnum, loctesterr, setvec1, true);
        Size(loctestnum, loctesterr, setvec1, true, 0);
        EqualSetVec(loctestnum, loctesterr, setvec2, setvec3, true);

        lasd::SetLst<int> setlst1(setlst);
        EqualSetLst(loctestnum, loctesterr, setlst, setlst1, true);

        lasd::SetLst<int> setlst2 = setlst1;
        EqualSetLst(loctestnum, loctesterr, setlst1, setlst2, true);

        lasd::SetLst<int> setlst3(std::move(setlst2));
        Empty(loctestnum, loctesterr, setlst2, true);
        Size(loctestnum, loctesterr, setlst2, true, 0);
        EqualSetLst(loctestnum, loctesterr, setlst1, setlst3, true);

        setlst2 = std::move(setlst1);
        Empty(loctestnum, loctesterr, setlst1, true);
        Size(loctestnum, loctesterr, setlst1, true, 0);
        EqualSetLst(loctestnum, loctesterr, setlst2, setlst3, true);

        EqualLinear(loctestnum, loctesterr, setvec3, setlst2, true);

    }
    catch (...) 
    {
        loctestnum++; loctesterr++;
        cout << endl << "Unmanaged error! " << endl;
    }
    cout << "End of Set<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}


void mystestSetDouble(uint & testnum, uint & testerr) 
{
    uint loctestnum = 0, loctesterr = 0;
    cout << endl << "Begin of Set<double> Test" << endl;
    try 
    {
        // CASO 0
        {
            print_section("0 ELEMENTS");
            lasd::SetVec<double> emptyVec;
            lasd::SetLst<double> emptyLst;
            
            Empty(loctestnum, loctesterr, emptyVec, true);
            Size(loctestnum, loctesterr, emptyVec, true, 0);
            
            Empty(loctestnum, loctesterr, emptyLst, true);
            Size(loctestnum, loctesterr, emptyLst, true, 0);
            
            EqualSetVec(loctestnum, loctesterr, emptyVec, emptyVec, true);
            EqualSetLst(loctestnum, loctesterr, emptyLst, emptyLst, true);
            
            EqualLinear(loctestnum, loctesterr, emptyVec, emptyLst, true);
        }

        // CASO 1
        {
            print_section("1 ELEMENTS");
            lasd::SetVec<double> singleVec;
            InsertC(loctestnum, loctesterr, singleVec, true, 9.9);
            
            lasd::SetLst<double> singleLst;
            InsertC(loctestnum, loctesterr, singleLst, true, 9.9);
            
            Empty(loctestnum, loctesterr, singleVec, false);
            Size(loctestnum, loctesterr, singleVec, true, 1);
            
            Empty(loctestnum, loctesterr, singleLst, false);
            Size(loctestnum, loctesterr, singleLst, true, 1);
            
            TraversePreOrder(loctestnum, loctesterr, singleVec, true, &TraversePrint<double>);
            TraversePostOrder(loctestnum, loctesterr, singleVec, true, &TraversePrint<double>);
            
            TraversePreOrder(loctestnum, loctesterr, singleLst, true, &TraversePrint<double>);
            TraversePostOrder(loctestnum, loctesterr, singleLst, true, &TraversePrint<double>);
            
            EqualSetVec(loctestnum, loctesterr, singleVec, singleVec, true);
            EqualSetLst(loctestnum, loctesterr, singleLst, singleLst, true);
            
            EqualLinear(loctestnum, loctesterr, singleVec, singleLst, true);
            
            Remove(loctestnum, loctesterr, singleVec, true, 9.9);
            InsertC(loctestnum, loctesterr, singleVec, true, 9.9);
            Remove(loctestnum, loctesterr, singleVec, true, 9.9);

            Empty(loctestnum, loctesterr, singleVec, true);
            Empty(loctestnum, loctesterr, singleLst, false);
            
        }

        // CASO N
        {
            print_section("N ELEMENTS");
            lasd::List<double> baseList;
            InsertAtFront(loctestnum, loctesterr, baseList, true, 1.1);
            InsertAtBack(loctestnum, loctesterr, baseList, true, 5.0);
            InsertAtBack(loctestnum, loctesterr, baseList, true, 7.0);
            InsertAtFront(loctestnum, loctesterr, baseList, true, 2.2);
            InsertAtFront(loctestnum, loctesterr, baseList, true, 4.0);
            InsertAtBack(loctestnum, loctesterr, baseList, true, 3.3);
            
            TraversePreOrder(loctestnum, loctesterr, baseList, true, &TraversePrint<double>);
            
            lasd::SetVec<double> vecSet(baseList);
            lasd::SetLst<double> lstSet(baseList);
            
            TraversePreOrder(loctestnum, loctesterr, vecSet, true, &TraversePrint<double>);
            TraversePostOrder(loctestnum, loctesterr, vecSet, true, &TraversePrint<double>);
            
            TraversePreOrder(loctestnum, loctesterr, lstSet, true, &TraversePrint<double>);
            TraversePostOrder(loctestnum, loctesterr, lstSet, true, &TraversePrint<double>);
            
            Size(loctestnum, loctesterr, vecSet, true, 6);
            Size(loctestnum, loctesterr, lstSet, true, 6);
            
            InsertC(loctestnum, loctesterr, vecSet, true, 7.2);
            InsertC(loctestnum, loctesterr, lstSet, false, 1.1);
            
            RemovePredecessor(loctestnum, loctesterr, vecSet, true, 3.3);
            RemovePredecessor(loctestnum, loctesterr, lstSet, true, 9.3);
            
            NonEqualSetVec(loctestnum, loctesterr, vecSet, lasd::SetVec(lstSet), true);
            
            InsertC(loctestnum, loctesterr, vecSet, false, 7.2); 
            InsertC(loctestnum, loctesterr, lstSet, false, 2.2);
            
            EqualSetVec(loctestnum, loctesterr, vecSet, vecSet, true);
            EqualSetLst(loctestnum, loctesterr, lstSet, lstSet, true);
            
            EqualLinear(loctestnum, loctesterr, vecSet, lstSet, false);

            InsertC(loctestnum, loctesterr, vecSet, false, 3.3);
            
        }
    }
    catch (...) 
    {
        loctestnum++; loctesterr++;
        cout << endl << "Unmanaged error! " << endl;
    }
    cout << "End of Set<double> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}

void mystestSetString(lasd::Set<string> & set, uint & testnum, uint & testerr) 
{
    uint loctestnum = 0, loctesterr = 0;
    try 
    {
        // CASO 0
        {
            print_section("0 ELEMENTS");
            Size(loctestnum, loctesterr, set, true, 0);
            Empty(loctestnum, loctesterr, set, true);
         
            TraversePreOrder(loctestnum, loctesterr, set, true, &TraversePrint<string>);
            FoldPreOrder(loctestnum, loctesterr, set, false, &FoldStringConcatenate, string("?"), string("?A"));
            FoldPostOrder(loctestnum, loctesterr, set, false, &FoldStringConcatenate, string("?"), string("?E"));
        }

        // CASO 1
        {
            print_section("1 ELEMENTS");
            InsertC(loctestnum, loctesterr, set, true, string("C"));

            Size(loctestnum, loctesterr, set, true, 1);
            Empty(loctestnum, loctesterr, set, false);

            TraversePreOrder(loctestnum, loctesterr, set, true, &TraversePrint<string>);
            FoldPreOrder(loctestnum, loctesterr, set, true, &FoldStringConcatenate, string("?"), string("?C"));
            FoldPostOrder(loctestnum, loctesterr, set, true, &FoldStringConcatenate, string("?"), string("?C"));

            lasd::SetLst<string> set2;
            EqualLinear(loctestnum, loctesterr, set2, set, false);
        }

        // CASO N
        {
            print_section("N ELEMENTS");
            Size(loctestnum, loctesterr, set, true, 1);
            Empty(loctestnum, loctesterr, set, false);

            InsertC(loctestnum, loctesterr, set, true, string("A"));
            InsertC(loctestnum, loctesterr, set, true, string("E"));
            InsertC(loctestnum, loctesterr, set, true, string("D"));

            lasd::SetLst<string> set2(set);

            InsertC(loctestnum, loctesterr, set, true, string("B"));

            Size(loctestnum, loctesterr, set, true, 5);
            Empty(loctestnum, loctesterr, set, false);

            TraversePreOrder(loctestnum, loctesterr, set, true, &TraversePrint<string>);
            FoldPreOrder(loctestnum, loctesterr, set, true, &FoldStringConcatenate, string("?"), string("?ABCDE"));
            FoldPostOrder(loctestnum, loctesterr, set, true, &FoldStringConcatenate, string("?"), string("?EDCBA"));

            TraversePreOrder(loctestnum, loctesterr, set, true, &TraversePrint<string>);
            TraversePreOrder(loctestnum, loctesterr, set2, true, &TraversePrint<string>);

            EqualLinear(loctestnum, loctesterr, set2, set, false);
        }
    }
    catch (...) 
    {
        loctestnum++; loctesterr++;
        cout << endl << "Unmanaged error! " << endl;
    }
    cout << "End of Set<string> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}

void mystestSetString(uint & testnum, uint & testerr) {
    uint loctestnum = 0, loctesterr = 0;
    cout << endl << "Begin of Set<string> Test" << endl;
    try {

        cout << endl << "Begin of SetVec<string> Test:" << endl;
        lasd::SetVec<string> setvec;
        mystestSetString(setvec, loctestnum, loctesterr);
        cout << endl << "Begin of SetLst<string> Test:" << endl;
        lasd::SetLst<string> setlst;
        mystestSetString(setlst, loctestnum, loctesterr);
        cout << "\n";

        EqualLinear(loctestnum, loctesterr, setvec, setlst, true);

    }
    catch (...) {
        loctestnum++; loctesterr++;
        cout << endl << "Unmanaged error! " << endl;
    }
    cout << "End of Set<string> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}

void runExSetVecSetList(uint & testnum, uint & testerr)
{
    mystestSetInt(testnum, testerr);
    mystestSetDouble(testnum, testerr);
    mystestSetString(testnum, testerr);
    cout << endl << "Exercise SetVecSetList (MY TEST) (Errors/Tests: " << testerr << "/" << testnum << ")" << endl;
}