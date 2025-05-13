#include "setvec.hpp"

#include <stdexcept>

namespace lasd {

template <typename Data>
SetVec<Data>::SetVec(const TraversableContainer<Data>& traversableContainer)
{
    vector = Vector<Data>(traversableContainer);
    size = vector.Size();
}

template <typename Data>
SetVec<Data>::SetVec(MappableContainer<Data>&& mappableContainer)
{
    vector = Vector<Data>(mappableContainer);
    size = vector.Size();
}

template <typename Data>
SetVec<Data>::SetVec(const SetVec<Data>& setvec)
{
    size = setvec.size;
    for(ulong i = 0; i < size; i++)
    {
        vector[i] = setvec[i];
    }
}

template <typename Data>
SetVec<Data>::SetVec(SetVec<Data>&& setvec)
{
    size = setvec.size;
    for(ulong i = 0; i < size; i++)
    {
        vector[i] = std::move(setvec[i]);
    }
}

template <typename Data>
SetVec<Data>::~SetVec()
{
    vector.Clear();
    size = 0;
}

template <typename Data>
SetVec<Data>& SetVec<Data>::operator=(const SetVec<Data>& other)
{
    if(this != &other)
    {
        vector = other.vector;
        size = other.size;
    }

    return *this;
}

template <typename Data>
SetVec<Data>& SetVec<Data>::operator=(SetVec<Data>&& other)
{
    if(this != &other)
    {
        vector = std::move(other.vector);
        size = other.size;
        other.size = 0;
    }

    return *this;
}

template <typename Data>
bool SetVec<Data>::operator==(const SetVec<Data>& other) const noexcept
{
    return (size == other.size) && (vector == other.vector);
}

template <typename Data>
bool SetVec<Data>::operator!=(const SetVec<Data>& other) const noexcept
{
    return !(*this == other);
}

template <typename Data>
Data SetVec<Data>::Min() const
{
    if(size == 0) throw std::length_error("The vector is empty!");    

    Data min = vector[0];
    for(ulong i = 1; i < size; i++)
    {
        if(vector[i] < min)
        {
            min = vector[i];
        }
    }

    return min;
}

template <typename Data>
Data SetVec<Data>::MinNRemove()
{
    if(size == 0) throw std::length_error("The vector is empty!");    

    Data min = vector[0];
    ulong index = 0;
    for(ulong i = 1; i < size; i++)
    {
        if(vector[i] < min)
        {
            min = vector[i];
            index = i;
        }
    }

    vector[index] = vector[size-1];
    vector.Resize(--size);

    return min;
}

template <typename Data>
void SetVec<Data>::RemoveMin()
{
    if(size == 0) throw std::length_error("The vector is empty!");    

    Data min = vector[0];
    ulong index = 0;
    for(ulong i = 1; i < size; i++)
    {
        if(vector[i] < min)
        {
            min = vector[i];
            index = i;
        }
    }

    vector[index] = vector[size-1];
    vector.Resize(--size);
}

template <typename Data>
Data SetVec<Data>::Max() const
{
    if(size == 0) throw std::length_error("The vector is empty!");    

    Data max = vector[0];
    for(ulong i = 1; i < size; i++)
    {
        if(vector[i] > max)
        {
            max = vector[i];
        }
    }

    return max;
}

template <typename Data>
Data SetVec<Data>::MaxNRemove()
{
    if(size == 0) throw std::length_error("The vector is empty!");    

    Data max = vector[0];
    ulong index = 0;
    for(ulong i = 1; i < size; i++)
    {   
        if(vector[i] > max)
        {
            max = vector[i];
           index = i;
        }
    }

    vector[index] = vector[size-1];
    vector.Resize(--size);

    Sort();
    return max;
}

template <typename Data>
void SetVec<Data>::RemoveMax()
{
    if(size == 0) throw std::length_error("The vector is empty!");    

    Data max = vector[0];
    ulong index = 0;
    for(ulong i = 1; i < size; i++)
    {
        if(vector[i] > max)
        {
            max = vector[i];
            index = i;
        }
    }

    vector[index] = vector[size-1];
    vector.Resize(--size);

    Sort();
}

template <typename Data>
Data SetVec<Data>::Predecessor(const Data& value) const
{
    ulong i_found = 0;
    bool found = Search(value, &i_found);

    if(!found) throw std::length_error("'value' not found!");
    if(i_found == 0) throw std::length_error("Predecessor not found!");
    
    return vector[i_found-1];
}

template <typename Data>
Data SetVec<Data>::PredecessorNRemove(const Data& value)
{
    ulong i_found = 0;
    bool found = Search(value, &i_found);

    if(!found) throw std::length_error("'value' not found!");
    if(i_found == 0) throw std::length_error("Predecessor not found!");

    Data prec = vector[i_found-1];

    vector[i_found-1] = vector[size-1];
    vector.Resize(size-1);
    size--;

    Sort();
    return prec;
}

template <typename Data>
void SetVec<Data>::RemovePredecessor(const Data& value)
{
    ulong i_found = 0;
    bool found = Search(value, &i_found);

    if(!found) throw std::length_error("'value' not found!");
    if(i_found == 0) throw std::length_error("Predecessor not found!");
    
    vector[i_found-1] = vector[size-1];
    vector.Resize(size-1);
    size--;

    Sort();
}

template <typename Data>
Data SetVec<Data>::Successor(const Data& value) const
{
    ulong i_found = 0;
    bool found = Search(value, &i_found);

    if(!found) throw std::length_error("'value' not found!");
    if(i_found == size-1) throw std::length_error("Successor not found!");

    return vector[i_found+1];
}

template <typename Data>
Data SetVec<Data>::SuccessorNRemove(const Data& value)
{
    ulong i_found = 0;
    bool found = Search(value, &i_found);

    if(!found) throw std::length_error("'value' not found!");
    if(i_found == size-1) throw std::length_error("Successor not found!");
    
    Data suc = vector[i_found+1];
    vector[i_found+1] = vector[size-1];
    vector.Resize(size-1);
    size--;

    Sort();
    return suc;
}

template <typename Data>
void SetVec<Data>::RemoveSuccessor(const Data& value)
{
    ulong i_found = 0;
    bool found = Search(value, &i_found);

    if(!found) throw std::length_error("'value' not found!");
    if(i_found == size-1) throw std::length_error("Successor not found!");
    
    vector[i_found+1] = vector[size-1];
    vector.Resize(size-1);
    size--;

    Sort();
}

template <typename Data>
bool SetVec<Data>::Insert(const Data& value)
{
    if(Exists(value)) return false;

    size++;
    vector.Resize(size);
    vector[size-1] = value;
    Sort();

    return true;
}

template <typename Data>
bool SetVec<Data>::Insert(Data&& value) 
{
    if(Exists(value)) return false;

    size++;
    vector.Resize(size);
    vector[size-1] = value;
    Sort();

    return true;
}

template <typename Data>
bool SetVec<Data>::Remove(const Data& value) 
{
    ulong index = 0;
    bool found = Search(value, &index);

    if(!found) return false;

    vector[index] = vector[size-1];
    vector.Resize(size-1);
    size--;
    Sort();
    return true;
}

template <typename Data>
const Data& SetVec<Data>::operator[](const ulong index) const
{
    if(index >= size) throw std::out_of_range("Index is out of range!");
    return vector[index];
}

template <typename Data>
const Data& SetVec<Data>::Front() const
{
    vector.Front();
}

template <typename Data>
const Data& SetVec<Data>::Back() const
{
    vector.Back();
}

template <typename Data>
bool SetVec<Data>::Exists(const Data& value) const noexcept
{
    for(ulong i = 0; i < size; i++)
    {
        if(value == vector[i])
            return true;
    }
    return false;
}

template <typename Data>
inline void SetVec<Data>::Clear()
{
    vector.Clear();
    size = 0;
}

template <typename Data>
void SetVec<Data>::Resize(ulong size)
{
  vector.Resize(size);
}

template <typename Data>
bool SetVec<Data>::Search(const Data& value, ulong* index) const
{
    for(ulong i = 0; i < size; i++)
    {
        if(value == vector[i])
        {
            *index = i;
            return true;
        }
    }

    *index = 0;
    return false;
}

template <typename Data>
bool SetVec<Data>::Search(Data&& value, ulong* index) const
{
    for(ulong i = 0; i < size; i++)
    {
        if(value == vector[i])
        {
            *index = i;
            return true;
        }
    }

    *index = 0;
    return false;
}

template<typename Data>
void SetVec<Data>::Sort() noexcept 
{
  QuickSort(0, size - 1);
}

template<typename Data>
void SetVec<Data>::QuickSort(ulong p, ulong r) noexcept 
{
  if (p < r) {
    ulong q = Partition(p, r);
    QuickSort(p, q);
    QuickSort(q + 1, r);
  }
}

template<typename Data>
ulong SetVec<Data>::Partition(ulong p, ulong r) noexcept 
{
  Data x = vector[p];
  ulong i = p - 1;
  ulong j = r + 1;
  do {
    do { j--; }
    while (x < vector[j]);
    do { i++; }
    while (x > vector[i]);
    if (i < j) { std::swap(vector[i], vector[j]); }
  }
  while (i < j);
  return j;
}

}
