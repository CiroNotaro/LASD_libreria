
#ifndef HEAP_HPP
#define HEAP_HPP

/* ************************************************************************** */

#include "../container/linear.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Heap : public virtual SortableLinearContainer<Data>,
             public virtual ClearableContainer 
{
  // Must extend SortableLinearContainer<Data>,
  //             ClearableContainer

private:

protected:

public:

  // Destructor
  virtual ~Heap() = default;

  /* ************************************************************************ */

  // Copy assignment
  Heap<Data>& operator=(const Heap<Data>& other) = delete;

  // Move assignment
  Heap<Data>& operator=(Heap<Data>&& other) = delete;

  /* ************************************************************************ */

  // Specific member functions

  virtual bool IsHeap() const noexcept = 0;
  virtual void Heapify() = 0;
};

/* ************************************************************************** */

}

#endif
