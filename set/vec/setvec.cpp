#include <stdexcept>

#include "setvec.hpp"

namespace lasd 
{

template<typename Data>
SetVec<Data>::SetVec(const TraversableContainer<Data>& traversableContainer) 
{
  vector = Vector<Data>(traversableContainer);
  size = vector.Size();
  capacity = size;
  Sort();
}

template<typename Data>
SetVec<Data>::SetVec(MappableContainer<Data>&& mappableContainer) 
{
    vector = Vector<Data>(std::move(mappableContainer));
    size = vector.Size();
    capacity = size;
    Sort();
}

template<typename Data>
SetVec<Data>::SetVec(const SetVec<Data>& other) : vector(other.size)
{
  capacity = other.capacity;
  size = other.size;
  head = other.head;

  for(ulong i = 0; i < size; i++)
  {
    vector[i] = other[i];
  }
}

template<typename Data>
SetVec<Data>::SetVec(SetVec<Data>&& other) 
{
  std::swap(size, other.size);
  std::swap(capacity, other.capacity);
  std::swap(head, other.head);
  std::swap(vector, other.vector);
}

template<typename Data>
SetVec<Data>::~SetVec() 
{
  vector.Clear();
  size = 0;
}

template<typename Data>
SetVec<Data>& SetVec<Data>::operator=(const SetVec<Data>& other) 
{
  std::swap(*this, other);
  return *this;
}

template<typename Data>
SetVec<Data>& SetVec<Data>::operator=(SetVec<Data>&& other) 
{
  std::swap(size, other.size);
  std::swap(capacity, other.capacity);
  std::swap(head, other.head);
  std::swap(vector, other.vector);
  return *this;
}

template<typename Data>
bool SetVec<Data>::operator==(const SetVec<Data>& other) const 
{
  if (size != other.size) 
  {
      return false;
  }

  for (ulong i = 0; i < size; ++i) 
  {
      if (vector[(head+i)%capacity] != other.vector[(other.head+i)%other.capacity]) 
      {
          return false;
      }
  }
  return true;
}

template<typename Data>
bool SetVec<Data>::operator!=(const SetVec<Data>& other) const 
{
  return !(*this == other);
}

template<typename Data>
const Data& SetVec<Data>::operator[](ulong index) const 
{
  if(size == 0) throw std::length_error("The set-vector is empty!");
  if (index >= size) 
  {
      throw std::out_of_range("SetVec<Data> operator[] out of range!");
  }
  return vector[(head + index)%capacity];
}

template<typename Data>
const Data& SetVec<Data>::Front() const
{
    if (size == 0)
    {
        throw std::length_error("The set-vector is empty!");
    }
    return vector[head];
}

template<typename Data>
const Data& SetVec<Data>::Back() const
{
    if (size == 0) 
    {
        throw std::length_error("The set-vector is empty!");
    }
    return vector[(head + size-1)%capacity];
}

template<typename Data>
Data SetVec<Data>::Min() const 
{
  if (size == 0) 
  {
      throw std::length_error("The set-vector is empty!");
  }
  return vector[head];
}

template <typename Data>
Data SetVec<Data>::MinNRemove() 
{
  Data min = Min();
  RemoveMin();        
  return min;            
}

template <typename Data>
void SetVec<Data>::RemoveMin() 
{
  if (size == 0) 
  {
      throw std::length_error("The set-vector is empty!");
  }

  head = (head + 1) % capacity;
  size--;
}

template<typename Data>
Data SetVec<Data>::Max() const 
{
  if (size == 0) 
  {
      throw std::length_error("The set-vector is empty!");
  }
  return vector[(head + size-1)%capacity];
}

template<typename Data>
Data SetVec<Data>::MaxNRemove() 
{
  Data max = Max();      
  RemoveMax();           
  return max;            
}

template <typename Data>
void SetVec<Data>::RemoveMax() 
{
  if (size == 0) 
  {
      throw std::length_error("The set-vector is empty!");
  }
  size--;
}

template<typename Data>
Data SetVec<Data>::Predecessor(const Data& data) const 
{
  ulong predecessorIndex = BinarySearchPredecessor(data);
  return vector[predecessorIndex];
}

template<typename Data>
Data SetVec<Data>::PredecessorNRemove(const Data& data) 
{
  Data prec = Predecessor(data);
  RemovePredecessor(data);
  return prec;
}

template<typename Data>
void SetVec<Data>::RemovePredecessor(const Data& data)
{
  ulong predecessorIndex = BinarySearchPredecessor(data);

  ulong numLeft = (predecessorIndex >= head)
                                ? (predecessorIndex - head)
                                : (predecessorIndex + capacity - head);
  ulong numRight = size-1 - numLeft;

  if (numLeft < numRight) 
  {
      for (ulong i = predecessorIndex; i != head; i = (i + capacity-1)%capacity) 
      {
          vector[i] = std::move(vector[(i + capacity-1)%capacity]);
      }
      head = (head + 1)%capacity;
  }
   else 
  {
      for (ulong i = predecessorIndex; i != (head + size-1)%capacity; i = (i + 1)%capacity)
      {
          vector[i] = std::move(vector[(i + 1)%capacity]);
      }
  }
  size--;
}

template<typename Data>
Data SetVec<Data>::Successor(const Data& data) const 
{
  ulong successorIndex = BinarySearchSuccessor(data);
  return vector[successorIndex];
}

template<typename Data>
Data SetVec<Data>::SuccessorNRemove(const Data& data) 
{
  Data succ = Successor(data);
  RemoveSuccessor(data);
  return succ;
}

template<typename Data>
void SetVec<Data>::RemoveSuccessor(const Data& data) 
{
  ulong successorIndex = BinarySearchSuccessor(data);

  ulong numLeft = (successorIndex >= head)
                                ? (successorIndex - head)
                                : (successorIndex + capacity - head);
  ulong numRight = size-1 - numLeft;

  if (numLeft < numRight) 
  {
      for (ulong i = successorIndex; i != head; i = (i + capacity-1)%capacity)
      {
          vector[i] = std::move(vector[(i + capacity-1)%capacity]);
      }
      head = (head + 1)%capacity;
  } 
  else 
  {
      for (ulong i = successorIndex; i != (head + size-1)%capacity; i = (i + 1)%capacity) 
      {
          vector[i] = std::move(vector[(i + 1)%capacity]);
      }
  }
  size--;
}

template<typename Data>
bool SetVec<Data>::Insert(const Data& data) 
{
  if (vector.Empty())
  {
      capacity = 1;
      vector = Vector<Data>(capacity);
      head = 0;
      vector[0] = data;
      size = 1;
      return true;
  }

  if(BinarySearch(data) == true) return false;

  if (size == capacity) 
  {
      ulong newCapacity = capacity * 2;
      Vector<Data> newvector = Vector<Data>(newCapacity);

      for (ulong i = 0; i < size; ++i) 
      {
          ulong currentIndex = (head + i) % capacity;
          newvector[i] = std::move(vector[currentIndex]);
      }
      vector.Clear();
      vector = newvector;
      capacity = newCapacity;
      head = 0;
  }

  ulong insertIndex = size;
  for (ulong i = 0; i < size; ++i) 
  {
      ulong currentIndex = (head + i) % capacity;
      if (data < vector[currentIndex]) 
      {
          insertIndex = i;
          break;
      }
  }

  for (ulong i = size; i > insertIndex; --i) 
  {
      vector[(head + i) % capacity] = std::move(vector[(head + i - 1) % capacity]);
  }
     
  ulong newIndex = (head + insertIndex) % capacity;
  vector[newIndex] = data;
  size++;
  return true;
}

template <typename Data>
bool SetVec<Data>::Insert(Data&& data) 
{
  if (vector.Empty()) 
  {
      capacity = 1;
      vector = Vector<Data>(capacity);
      head = 0;
      vector[0] = std::move(data);
      size = 1;
      return true;
  }

  if(BinarySearch(data) == true) return false;

  if (size == capacity) 
  {
      ulong newCapacity = capacity * 2;
      Vector<Data> newvector = Vector<Data>(newCapacity);

      for (ulong i = 0; i < size; ++i) 
      {
          ulong currentIndex = (head + i) % capacity;
          newvector[i] = std::move(vector[currentIndex]);
      }
      vector.Clear();
      vector = newvector;
      capacity = newCapacity;
      head = 0;
  }

  ulong insertIndex = size;
  for (ulong i = 0; i < size; ++i) 
  {
      ulong currentIndex = (head + i) % capacity;
      if (data < vector[currentIndex]) 
      {
          insertIndex = i;
          break;
      }
  }

  for (ulong i = size; i > insertIndex; --i) 
  {
      vector[(head + i) % capacity] = std::move(vector[(head + i - 1) % capacity]);
  }  
  
  ulong newIndex = (head + insertIndex) % capacity;
  vector[newIndex] = std::move(data);
  size++;
  return true;
}

template <typename Data>
bool SetVec<Data>::Remove(const Data& data) 
{
  ulong left = 0;
  ulong right = size;
  ulong removeIndex;
  bool found = false;

  while (left < right) 
  {
      ulong mid = (left + right)/2;
      ulong midIndex = (head + mid)%capacity;
      if (vector[midIndex] == data) 
      {
          found = true;
          removeIndex = midIndex;
          break;
      } 
      else if (vector[midIndex] < data) 
      {
          left = mid + 1;
      } 
      else 
      {
          right = mid;
      }
  } 
  if(!found) return false; 

  ulong numLeft = (removeIndex >= head)
                                ? (removeIndex - head)
                                : (removeIndex + capacity - head);
  ulong numRight = size-1 - numLeft;

  if (numLeft < numRight) 
  {
      for (ulong i = removeIndex; i != head; i = (i + capacity-1)%capacity) 
      {
          vector[i] = std::move(vector[(i + capacity-1)%capacity]);
      }
      head = (head + 1)%capacity;
  } else {
      for (ulong i = removeIndex; i != (head + size-1)%capacity; i = (i + 1)%capacity) 
      {
          vector[i] = std::move(vector[(i + 1)%capacity]);
      }
  }
  size--;
  return true;
}

template <typename Data>
bool SetVec<Data>::Exists(const Data& data) const noexcept 
{
  return BinarySearch(data);
}

template<typename Data>
void SetVec<Data>::Clear() 
{
  vector.Clear();
  size = 0;
  capacity = 0;
  head = 0;
}

template <typename Data>
void SetVec<Data>::Resize(ulong newCapacity) 
{
    Vector<Data> newvector = Vector<Data>(newCapacity);
    ulong vectorToCopy = (size < newCapacity) ? size : newCapacity;
    for (ulong i = 0; i < vectorToCopy; ++i) 
    {
        ulong srcIndex = (head + i) % capacity;
        newvector[i] = std::move(vector[srcIndex]);
    }
    vector.Clear();
    vector = newvector;
    capacity = newCapacity;
    head = 0;
    size = vectorToCopy;
}

/* ************************************************************************** */

template<typename Data>
bool SetVec<Data>::BinarySearch(const Data& data) const 
{
  ulong left = 0;
  ulong right = size;

  while (left < right) 
  {
      ulong mid = (left + right)/2;
      ulong midIndex = (head + mid)%capacity;
      if (vector[midIndex] == data) 
      {
          return true;
      } 
      else if (vector[midIndex] < data)
      {
          left = mid + 1;
      } 
      else
      {
          right = mid;
      }
  }
  return false;
}

template<typename Data>
ulong SetVec<Data>::BinarySearchPredecessor(const Data& data) const 
{
  ulong left = 0;
  ulong right = size;
  ulong predecessorIndex;
  bool found = false;

  while (left < right) 
  {
      ulong mid = (left + right) / 2;
      ulong midIndex = (head + mid) % capacity;

      if (vector[midIndex] < data) 
      {
          predecessorIndex = midIndex;
          found = true;
          left = mid + 1;
      } 
      else 
      {
          right = mid;
      }
  }
  
  if(!found) throw std::length_error("Predecessor not found!");

  return predecessorIndex;
}

template<typename Data>
ulong SetVec<Data>::BinarySearchSuccessor(const Data& data) const 
{
  ulong left = 0;
  ulong right = size;
  ulong successorIndex;
  bool found = false;

  while (left < right) 
  {
      ulong mid = (left + right) / 2;
      ulong midIndex = (head + mid) % capacity;

      if (vector[midIndex] > data) 
      {
          successorIndex = midIndex;
          found = true;
          right = mid;
      } 
      else 
      {
          left = mid + 1;
      }
  }
  
  if(!found) throw std::length_error("Successor not found!");

  return successorIndex;
}

template <typename Data>
void SetVec<Data>::Sort() 
{
    if (size > 1) {
        QuickSort(0, size - 1);
    }
}

template <typename Data>
void SetVec<Data>::QuickSort(ulong left, ulong right) 
{
    if (left < right) 
    {
        ulong pivotIndex = Partition(left, right);
        if (pivotIndex > 0) QuickSort(left, pivotIndex - 1); 
        QuickSort(pivotIndex + 1, right);
    }
}

template <typename Data>
ulong SetVec<Data>::Partition(ulong left, ulong right) 
{
    Data pivot = vector[(head + right) % capacity];
    ulong i = left;

    for (ulong j = left; j < right; ++j) 
    {
        ulong jIndex = (head + j) % capacity;
        ulong iIndex = (head + i) % capacity;

        if (vector[jIndex] < pivot) 
        {
            std::swap(vector[iIndex], vector[jIndex]);
            ++i;
        }
    }

    std::swap(vector[(head + i) % capacity], vector[(head + right) % capacity]);
    return i;
}

}
