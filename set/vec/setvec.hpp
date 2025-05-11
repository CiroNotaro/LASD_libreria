
#ifndef SETVEC_HPP
#define SETVEC_HPP

/* ************************************************************************** */

#include "../set.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class SetVec : virtual public Set<Data>, virtual public ResizableContainer{
  // Must extend Set<Data>,
  //             ResizableContainer

private:

  Vector<Data> vector;

protected:

  using Container::size;

  // ...

public:

  // Default constructor
  SetVec() = default;

  /* ************************************************************************ */

  // Specific constructors
  SetVec(const TraversableContainer<Data>& traversableContainer); // A set obtained from a TraversableContainer
  SetVec(MappableContainer<Data>&& mappableContainer); // A set obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  SetVec(const SetVec<Data>&);

  // Move constructor
  SetVec(SetVec<Data>&&);

  /* ************************************************************************ */

  // Destructor
  ~SetVec();

  /* ************************************************************************ */

  // Copy assignment
  SetVec<Data>& operator=(const SetVec<Data>& other);

  // Move assignment
  SetVec<Data>& operator=(SetVec<Data>&& other);

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const SetVec<Data>& other) const noexcept;
  bool operator!=(const SetVec<Data>& other) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from OrderedDictionaryContainer)

  Data Min() const override;
  Data MinNRemove() override;
  void RemoveMin() override;

  Data Max() const override;
  Data MaxNRemove() override;
  void RemoveMax() override;

  Data Predecessor(Data& value) const override;
  Data PredecessorNRemove(Data& value) override;
  void RemovePredecessor(Data& value) override;

  Data Successor(Data& value) const override;
  Data SuccessorNRemove(Data& value) override;
  void RemoveSuccessor(Data& value) override;
  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  bool Insert(const Data& value) override; // Override DictionaryContainer member (copy of the value)
  bool Insert(Data&& value) override; // Override DictionaryContainer member (move of the value)
  bool Remove(const Data& value) override; // Override DictionaryContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  Data& operator[](const ulong index) override; // Override LinearContainer member (must throw std::out_of_range when out of range)

  /* ************************************************************************** */

  // Specific member function (inherited from TestableContainer)

  bool Exists(const Data& value) const noexcept override; // Override TestableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  inline void Clear() override; // Override ClearableContainer member

protected:

  // Auxiliary functions, if necessary!
  bool Search(const Data& value, ulong* index);

  void Sort() noexcept;

  void QuickSort(ulong p, ulong r) noexcept;

  ulong Partition(ulong p, ulong r) noexcept;

};

/* ************************************************************************** */

}

#include "setvec.cpp"

#endif
