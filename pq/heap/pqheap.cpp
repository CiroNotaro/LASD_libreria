#include "pqheap.hpp"
#include <stdexcept>
#include <utility>

namespace lasd 
{


  template <typename Data>
  PQHeap<Data>::PQHeap(const TraversableContainer<Data>& container) : HeapVec<Data>(container) {}

  template <typename Data>
  PQHeap<Data>::PQHeap(MappableContainer<Data>&& container) : HeapVec<Data>(std::move(container)) {}

  template <typename Data>
  PQHeap<Data>::PQHeap(const PQHeap<Data>& other)
    : HeapVec<Data>(other) {}


  template <typename Data>
  PQHeap<Data>::PQHeap(PQHeap<Data>&& other) noexcept
    : HeapVec<Data>(std::move(other)) {}


  template <typename Data>
  PQHeap<Data>& PQHeap<Data>::operator=(const PQHeap<Data>& other) {
    HeapVec<Data>::operator=(other);
    return *this;
  }

  template <typename Data>
  PQHeap<Data>& PQHeap<Data>::operator=(PQHeap<Data>&& other) noexcept {
    HeapVec<Data>::operator=(std::move(other));
    return *this;
  }

  template <typename Data>
  Data& PQHeap<Data>::Tip() const {
    if (this->Empty()) {
      throw std::length_error("Priority queue is empty.");
    }

    return buffer[0];
  }


  template <typename Data>
  void PQHeap<Data>::RemoveTip() {
    if (this->Empty()) {
      throw std::length_error("Priority queue is empty.");
    }

    if (size == 1) 
    {
      size = 0;
      this->Resize(0);
      return;
    }

    std::swap(buffer[0], buffer[size - 1]);
    size--;
    this->DownHeap(0);
    this->Resize(size);
  }

  template <typename Data>
  Data PQHeap<Data>::TipNRemove() {
    if (this->Empty()) {
      throw std::length_error("Priority queue is empty.");
    }

    Data val = buffer[0];
    RemoveTip();
    return val;
  }

  template <typename Data>
  void PQHeap<Data>::Insert(const Data& val) {
    this->Vector<Data>::Resize(size + 1);
    uint index = size - 1;
    buffer[index] = val;

    HeapifyUp(index);
  }

  template <typename Data>
  void PQHeap<Data>::Insert(Data&& val) 
  {
    this->Vector<Data>::Resize(size + 1);
    uint index = size - 1;
    buffer[index] = std::move(val);

    HeapifyUp(index);
  }

  template <typename Data>
  void PQHeap<Data>::Change(ulong index, const Data& val) 
  {
    if (index >= size) {
      throw std::out_of_range("Index out of range.");
    }

    buffer[index] = val;
    this->DownHeap(index);

    HeapifyUp(index);
  }

  template <typename Data>
  void PQHeap<Data>::Change(ulong index, Data&& val) 
  {
    if (index >= size) 
    {
      throw std::out_of_range("Index out of range.");
    }

    buffer[index] = std::move(val);
    this->DownHeap(index);

    HeapifyUp(index);
  }

  template <typename Data>
  void PQHeap<Data>::Clear() 
  {
    HeapVec<Data>::Clear();
  }


  template <typename Data>
  void PQHeap<Data>::HeapifyUp(ulong index)
  {
    unsigned int i = index;
    while (i > 0) 
    {
      unsigned int parent = (i - 1) / 2;
      if (buffer[i] > buffer[parent]) 
      {
        std::swap(buffer[i], buffer[parent]);
        i = parent;
      } else {
        break;
      }
    }
  }

/* ************************************************************************** */

} // namespace lasd
