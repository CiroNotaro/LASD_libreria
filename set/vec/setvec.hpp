
#ifndef SETVEC_HPP
#define SETVEC_HPP

/* ************************************************************************** */

#include "../set.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class SetVec : virtual public Set<Data>, virtual public ResizableContainer {
	// Must extend Set<Data>,
  		//             ResizableContainer

private:

protected:

  using Container::size;

  Vector<Data> vector;
  ulong capacity = 0;
  ulong head = 0;

public:

  // Default constructor
  SetVec() = default;

  /* ************************************************************************ */

  // Specific constructors
  SetVec(const TraversableContainer<Data>& traversableContainer); // A set obtained from a TraversableContainer
  SetVec(MappableContainer<Data>&& mappableContainer); // A set obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  SetVec(const SetVec& other);

  // Move constructor
  SetVec(SetVec&& other);

  /* ************************************************************************ */

  // Destructor
  virtual ~SetVec();

  /* ************************************************************************ */

  // Copy assignment
  SetVec& operator=(const SetVec& other);

  // Move assignment
  SetVec& operator=(SetVec&& other);

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const SetVec& other) const;
  bool operator!=(const SetVec& other) const;

  /* ************************************************************************ */

  // Specific member functions (inherited from OrderedDictionaryContainer)

  Data Min() const override; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
  Data MinNRemove() override; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
  void RemoveMin() override; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)

  Data Max() const override; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
  Data MaxNRemove() override; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
  void RemoveMax() override; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)

  Data Predecessor(const Data& data) const override; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
  Data PredecessorNRemove(const Data& data) override; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
  void RemovePredecessor(const Data& data) override; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)

  Data Successor(const Data& data) const override; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
  Data SuccessorNRemove(const Data& data) override; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
  void RemoveSuccessor(const Data& data) override; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  bool Insert(const Data& data) override; // Override DictionaryContainer member (copy of the value)
  bool Insert(Data&& data) override; // Override DictionaryContainer member (move of the value)
  bool Remove(const Data& data) override; // Override DictionaryContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  const Data& operator[](const ulong index) const override; // Override LinearContainer member (must throw std::out_of_range when out of range)

  const Data& Front() const override; // Override LinearContainer member (must throw std::length_error when empty)

  const Data& Back() const override; // Override LinearContainer member (must throw std::length_error when empty)

  /* ************************************************************************** */

  // Specific member function (inherited from TestableContainer)

  bool Exists(const Data& data) const noexcept override; // Override TestableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  void Clear() override; // Override ClearableContainer member
  
  void Resize(ulong) override;

protected:

  bool BinarySearch(const Data& data) const;
  ulong BinarySearchPredecessor(const Data& data) const;
  ulong BinarySearchSuccessor(const Data& data) const;


  void Sort();
  void QuickSort(ulong left, ulong right);
  ulong Partition(ulong left, ulong right);

};

/* ************************************************************************** */

}

#include "setvec.cpp"

#endif
