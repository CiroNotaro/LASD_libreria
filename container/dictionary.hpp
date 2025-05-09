
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
class OrderedDictionaryContainer : virtual public DictionaryContainer<Data> {
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

  virtual Data Min() const = 0; // (concrete function must throw std::length_error when empty)
  virtual Data MinNRemove() = 0; // (concrete function must throw std::length_error when empty)
  virtual void RemoveMin() = 0; // (concrete function must throw std::length_error when empty)

  virtual Data Max() const = 0; // (concrete function must throw std::length_error when empty)
  virtual Data MaxNRemove() = 0; // (concrete function must throw std::length_error when empty)
  virtual void RemoveMax() = 0; // (concrete function must throw std::length_error when empty)

  virtual Data Predecessor(Data& value) const = 0; // (concrete function must throw std::length_error when not found)
  virtual Data PredecessorNRemove(Data& value) = 0; // (concrete function must throw std::length_error when not found)
  virtual void RemovePredecessor(Data& value) = 0; // (concrete function must throw std::length_error when not found)

  virtual Data Successor(Data& value) const = 0; // (concrete function must throw std::length_error when not found)
  virtual Data SuccessorNRemove(Data& value) = 0; // (concrete function must throw std::length_error when not found)
  virtual void RemoveSuccessor(Data& value) = 0; // (concrete function must throw std::length_error when not found)
};

/* ************************************************************************** */

}

#include "dictionary.cpp"

#endif
