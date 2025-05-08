
#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

/* ************************************************************************** */

#include "testable.hpp"
#include "mappable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class DictionaryContainer : virtual public TestableContainer<Data> {
  // Must extend TestableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~DictionaryContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  DictionaryContainer<Data>& operator=(const DictionaryContainer<Data>&) = delete; // Copy assignment of abstract types is not possible.

  // Move assignment
  DictionaryContainer<Data>& operator=(DictionaryContainer<Data>&&) = delete;  // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const DictionaryContainer<Data> other) const noexcept = delete; // Comparison of abstract types is not possible.
  bool operator!=(const DictionaryContainer<Data> other) const noexcept = delete; // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual bool Insert(const Data& value) = 0; // Copy of the value
  virtual bool Insert(Data&& value) = 0;      // Move of the value
  virtual bool Remove(const Data& value) = 0;

  inline virtual bool InsertAll(const TraversableContainer<Data> container);    // Copy of the value; From TraversableContainer; True if all are inserted
  inline virtual bool InsertAll(MappableContainer<Data>&& container);           // Move of the value; From MappableContainer; True if all are inserted
  inline virtual bool RemoveAll(const TraversableContainer<Data>& container);   // From TraversableContainer; True if all are removed

  inline virtual bool InsertSome(const TraversableContainer<Data> container);   // Copy of the value; From TraversableContainer; True if some is inserted
  inline virtual bool InsertSome(MappableContainer<Data>&& container);          // Move of the value; From MappableContainer; True if some is inserted
  inline virtual bool RemoveSome(const TraversableContainer<Data>& container);  // From TraversableContainer; True if some is removed

};

/* ************************************************************************** */

template <typename Data>
class OrderedDictionaryContainer : virtual public DictionaryContainer<Data>, virtual public PreOrderMappableContainer<Data> {
  // Must extend DictionaryContainer<Data>

private:

protected:
  using Container::size;

public:

  // Destructor
  virtual ~OrderedDictionaryContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  OrderedDictionaryContainer<Data>& operator=(const OrderedDictionaryContainer<Data>&) = delete; // Copy assignment of abstract types is not possible.

  // Move assignment
  OrderedDictionaryContainer<Data>& operator=(OrderedDictionaryContainer<Data>&&) = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const OrderedDictionaryContainer<Data>& other) const noexcept = delete; // Comparison of abstract types is not possible.
  bool operator!=(const OrderedDictionaryContainer<Data>& other) const noexcept = delete; // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member functions

  Data Min() const; // (concrete function must throw std::length_error when empty)
  Data MinNRemove(); // (concrete function must throw std::length_error when empty)
  void RemoveMin(); // (concrete function must throw std::length_error when empty)

  Data Max() const; // (concrete function must throw std::length_error when empty)
  Data MaxNRemove(); // (concrete function must throw std::length_error when empty)
  void RemoveMax(); // (concrete function must throw std::length_error when empty)

  Data Predecessor(Data& value) const; // (concrete function must throw std::length_error when not found)
  Data PredecessorNRemove(Data& value); // (concrete function must throw std::length_error when not found)
  void RemovePredecessor(Data& value); // (concrete function must throw std::length_error when not found)

  Data Successor(Data& value) const; // (concrete function must throw std::length_error when not found)
  Data SuccessorNRemove(Data& value); // (concrete function must throw std::length_error when not found)
  void RemoveSuccessor(Data& value); // (concrete function must throw std::length_error when not found)
};

/* ************************************************************************** */

}

#include "dictionary.cpp"

#endif
