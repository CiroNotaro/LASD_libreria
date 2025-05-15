
#ifndef SETLST_HPP
#define SETLST_HPP

/* ************************************************************************** */

#include "../set.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class SetLst : virtual public Set<Data>, virtual public List<Data>{
  // Must extend Set<Data>,
  //             List<Data>

private:

  // ...

protected:

  using Container::size;
  using typename List<Data>::Node;

  // ...

public:

  // Default constructor
  SetLst() = default;

  /* ************************************************************************ */

  // Specific constructors
  SetLst(const TraversableContainer<Data>& traversableContainer); // A set obtained from a TraversableContainer
  SetLst(MappableContainer<Data>&& mappableContainer); // A set obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  SetLst(const SetLst<Data>&);

  // Move constructor
  SetLst(SetLst<Data>&&);

  /* ************************************************************************ */

  // Destructor
  ~SetLst();

  /* ************************************************************************ */

  // Copy assignment
  SetLst<Data>& operator=(const SetLst<Data>& other);

  // Move assignment
  SetLst<Data>& operator=(SetLst<Data>&& other);

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const SetLst<Data>& other) const noexcept;
  bool operator!=(const SetLst<Data>& other) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from OrderedDictionaryContainer)

  Data Min() const override;
  Data MinNRemove() override;
  void RemoveMin() override;

  Data Max() const override;
  Data MaxNRemove() override;
  void RemoveMax() override;

  Data Predecessor(const Data& value) const override;
  Data PredecessorNRemove(const Data& value) override;
  void RemovePredecessor(const Data& value) override;

  Data Successor(const Data& value) const override;
  Data SuccessorNRemove(const Data& value) override;
  void RemoveSuccessor(const Data& value) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  bool Insert(const Data& value) override; // Override DictionaryContainer member (copy of the value)
  bool Insert(Data&& value) override; // Override DictionaryContainer member (move of the value)
  bool Remove(const Data& value) override; // Override DictionaryContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  const Data& operator[](const ulong index) const override; // Override LinearContainer member (must throw std::out_of_range when out of range)

  /* ************************************************************************** */

  // Specific member function (inherited from TestableContainer)

  bool Exists(const Data& value) const noexcept override; // Override TestableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  inline void Clear() override; // Override ClearableContainer member

protected:

  // Auxiliary functions, if necessary!
  bool Search(const Data& value, ulong* index) const;
  bool Search(Data& value, ulong* index) const;

  void Sort() noexcept;

  void QuickSort(ulong p, ulong r) noexcept;

  ulong Partition(ulong p, ulong r) noexcept;

  Node* GetNodeByIndex(const ulong index);

};

/* ************************************************************************** */

}

#include "setlst.cpp"

#endif
