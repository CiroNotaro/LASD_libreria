
#ifndef HEAPVEC_HPP
#define HEAPVEC_HPP

/* ************************************************************************** */

#include "../heap.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class HeapVec : public Heap<Data>, public Vector<Data>
{
  // Must extend Heap<Data>,
  // Could extend Vector<Data>

private:

  // ...

protected:

  using Vector<Data>::size;
  using Vector<Data>::buffer;

  // ...

public:

  // Default constructor
  HeapVec() = default;

  /* ************************************************************************ */

  // Specific constructors
  HeapVec(const TraversableContainer<Data>& container); // A heap obtained from a TraversableContainer
  HeapVec(MappableContainer<Data>&& container); // A heap obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  HeapVec(const HeapVec<Data>& other);

  // Move constructor
  HeapVec(HeapVec<Data>&& other) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~HeapVec() = default;

  /* ************************************************************************ */

  // Copy assignment
  HeapVec<Data>& operator=(const HeapVec<Data>& other);

  // Move assignment
  HeapVec<Data>& operator=(HeapVec<Data>&& other);

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const HeapVec<Data>& other) const noexcept;
  bool operator!=(const HeapVec<Data>& other) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Heap)

  bool IsHeap() const noexcept override;
  void Heapify() override;

  /* ************************************************************************ */

  // Specific member function (inherited from SortableLinearContainer)

  void Sort() noexcept override;

  void Clear() override;

protected:

  // Auxiliary functions, if necessary!
  void DownHeap(uint index);
  void BuildHeap();

};

/* ************************************************************************** */

}

#include "heapvec.cpp"

#endif
