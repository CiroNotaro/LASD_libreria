
#ifndef PQHEAP_HPP
#define PQHEAP_HPP

/* ************************************************************************** */

#include "../pq.hpp"
#include "../../heap/vec/heapvec.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class PQHeap : public virtual PQ<Data>, public HeapVec<Data> 
{

protected:
  using HeapVec<Data>::size;
  using HeapVec<Data>::buffer;

public:

  // Default constructor
  PQHeap() = default;

  /* ************************************************************************ */

  // Specific constructors
  template <typename TraversableContainer>
  PQHeap(const TraversableContainer& container);// A priority queue obtained from a TraversableContainer
  template <typename MappableContainer>
  PQHeap(MappableContainer&& container);  // A priority queue obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  PQHeap(const PQHeap& other);

  // Move constructor
  PQHeap(PQHeap&& other) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~PQHeap() = default;

  /* ************************************************************************ */

  // Copy assignment
  PQHeap& operator=(const PQHeap& other);

  // Move assignment
  PQHeap& operator=(PQHeap&& other) noexcept;

  /* ************************************************************************ */

  Data& Tip() const override;      // Override PQ member (must throw std::length_error when empty)      
  void RemoveTip() override;      // Override PQ member (must throw std::length_error when empty)             
  Data TipNRemove() override;      // Override PQ member (must throw std::length_error when empty)          

  void Insert(const Data& val) override;  
  void Insert(Data&& val) override;     

  void Change(ulong index, const Data& val) override;
  void Change(ulong index, Data&& val) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from PQ)

  void Clear() override;

  /* ************************************************************************ */

  void HeapifyUp(ulong index);

}; 

/* ************************************************************************** */

} // namespace lasd

#include "pqheap.cpp"

#endif
