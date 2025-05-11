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
    size = setvec.Size();
    for(ulong i = 0; i < size; i++)
    {
        vector[i] = setvec[i];
    }
}

template <typename Data>
SetVec<Data>::SetVec(SetVec<Data>&& setvec)
{
    size = setvec.Size();
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
    
}

template <typename Data>
SetVec<Data>& SetVec<Data>::operator=(SetVec<Data>&& other)
{

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
}

template <typename Data>
Data SetVec<Data>::Predecessor(Data& value) const
{
    ulong i_found = 0;
    bool found = Search(value, &i_found);

    if(!found) throw std::length_error("'value' not found!");
    if(i_found == 0) throw std::length_error("Predecessor not found!");
    
    return vector[i_found-1];
}

template <typename Data>
Data SetVec<Data>::PredecessorNRemove(Data& value)
{
    ulong i_found = 0;
    bool found = Search(value, &i_found);

    if(!found) throw std::length_error("'value' not found!");
    if(i_found == 0) throw std::length_error("Predecessor not found!");

    Data prec = vector[i_found-1];

    vector[i_found-1] = vector[size-1];
    vector.Resize(size-1);
    size--;

    return prec;
}

template <typename Data>
void SetVec<Data>::RemovePredecessor(Data& value)
{
    ulong i_found = 0;
    bool found = Search(value, &i_found);

    if(!found) throw std::length_error("'value' not found!");
    if(i_found == 0) throw std::length_error("Predecessor not found!");
    
    vector[i_found-1] = vector[size-1];
    vector.Resize(size-1);
    size--;
}

template <typename Data>
Data SetVec<Data>::Successor(Data& value) const
{
    ulong i_found = 0;
    bool found = Search(value, &i_found);

    if(!found) throw std::length_error("'value' not found!");
    if(i_found == size-1) throw std::length_error("Successor not found!");

    return vector[i_found+1];
}

template <typename Data>
Data SetVec<Data>::SuccessorNRemove(Data& value)
{
    ulong i_found = 0;
    bool found = Search(value, &i_found);

    if(!found) throw std::length_error("'value' not found!");
    if(i_found == size-1) throw std::length_error("Successor not found!");
    
    Data suc = vector[i_found+1];
    vector[i_found+1] = vector[size-1];
    vector.Resize(size-1);
    size--;

    return suc;
}

template <typename Data>
void SetVec<Data>::RemoveSuccessor(Data& value)
{
    ulong i_found = 0;
    bool found = Search(value, &i_found);

    if(!found) throw std::length_error("'value' not found!");
    if(i_found == size-1) throw std::length_error("Successor not found!");
    
    vector[i_found+1] = vector[size-1];
    vector.Resize(size-1);
    size--;
}

template <typename Data>
bool SetVec<Data>::Insert(const Data& value)
{

}

template <typename Data>
bool SetVec<Data>::Insert(Data&& value) 
{

}

template <typename Data>
bool SetVec<Data>::Remove(const Data& value) 
{

}

template <typename Data>
Data& SetVec<Data>::operator[](const ulong index)
{

}

template <typename Data>
bool SetVec<Data>::Exists(const Data& value) const noexcept
{
    
}

template <typename Data>
inline void SetVec<Data>::Clear()
{

}

template <typename Data>
bool SetVec<Data>::Search(const Data& value, ulong* index)
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

}
