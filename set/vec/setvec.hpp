
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

  const Data& Front() const override; // Override LinearContainer member (must throw std::length_error when empty)

  const Data& Back() const override; // Override LinearContainer member (must throw std::length_error when empty)

  /* ************************************************************************** */

  // Specific member function (inherited from TestableContainer)

  bool Exists(const Data& value) const noexcept override; // Override TestableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  inline void Clear() override; // Override ClearableContainer member

  void Resize(ulong size) override;

protected:

  // Auxiliary functions, if necessary!
  bool Search(const Data& value, ulong* index) const;
  bool Search(Data&& value, ulong* index) const;

  void Sort() noexcept;

  void QuickSort(ulong p, ulong r) noexcept;

  ulong Partition(ulong p, ulong r) noexcept;

};

/* ************************************************************************** */

}

#include "setvec.cpp"

#endif
