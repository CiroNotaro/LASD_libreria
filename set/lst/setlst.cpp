#include "setlst.hpp"

namespace lasd {

template <typename Data>
SetLst<Data>::SetLst(const TraversableContainer<Data>& traversableContainer)
    : List(traversableContainer)
{
    size = traversableContainer.Size();
}

template <typename Data>
SetLst<Data>::SetLst(MappableContainer<Data>&& mappableContainer)
    : List(mappableContainer)
{
    size = mappableContainer.Size();
}

template <typename Data>
SetLst<Data>::SetLst(const SetLst<Data>& setlst)
{
    size = setlst.Size();
    for(ulong i = 0; i < size; i++)
    {
        operator[](i) = setlst[i];
    }
}

template <typename Data>
SetLst<Data>::SetLst(SetLst<Data>&& setlst)
{
    size = setlst.Size();
    for(ulong i = 0; i < size; i++)
    {
        operator[](i) = std::move(setlst[i]);
    }
}

template <typename Data>
SetLst<Data>::~SetLst()
{
    Clear();
    size = 0;
}

template <typename Data>
SetLst<Data>& SetLst<Data>::operator=(const SetLst<Data>& other)
{
    if(this != &other)
    {
        Clear();

        if(other.tail != nullptr)
        {
            tail = new Node(*other.tail);
            head = other.head->Clone(tail);
            size = other.size;
        }
    }

    return *this;
}

template <typename Data>
SetLst<Data>& SetLst<Data>::operator=(SetLst<Data>&& other)
{
    std::swap(head, other.head);
    std::swap(tail, other.tail);
    std::swap(size, other.size);

    return *this;
}

template <typename Data>
bool SetLst<Data>::operator==(const SetLst<Data>& other) const noexcept
{
    return (size == other.size) && (head == other.head);
}

template <typename Data>
bool SetLst<Data>::operator!=(const SetLst<Data>& other) const noexcept
{
    return !(*this == other);
}

template <typename Data>
Data SetLst<Data>::Min() const
{
    if(size == 0) throw std::length_error("The list is empty!");    

    Data min = operator[](0);
    for(ulong i = 1; i < size; i++)
    {
        if(operator[](i) < min)
        {
            min = operator[](i);
        }
    }

    return min;
}

template <typename Data>
Data SetLst<Data>::MinNRemove()
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
void SetLst<Data>::RemoveMin()
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
Data SetLst<Data>::Max() const
{
    if(size == 0) throw std::length_error("The vector is empty!");    

    Data max = operator[](0);
    for(ulong i = 1; i < size; i++)
    {
        if(operator[](i) > max)
        {
            max = operator[](i);
        }
    }

    return max;
}

template <typename Data>
Data SetLst<Data>::MaxNRemove()
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
void SetLst<Data>::RemoveMax()
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
Data SetLst<Data>::Predecessor(Data& value) const
{
    ulong i_found = 0;
    bool found = Search(value, &i_found);

    if(!found) throw std::length_error("'value' not found!");
    if(i_found == 0) throw std::length_error("Predecessor not found!");
    
    return operator[](i_found-1);
}

template <typename Data>
Data SetLst<Data>::PredecessorNRemove(Data& value)
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
void SetLst<Data>::RemovePredecessor(Data& value)
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
Data SetLst<Data>::Successor(Data& value) const
{
    ulong i_found = 0;
    bool found = Search(value, &i_found);

    if(!found) throw std::length_error("'value' not found!");
    if(i_found == size-1) throw std::length_error("Successor not found!");

    return operator[](i_found+1);
}

template <typename Data>
Data SetLst<Data>::SuccessorNRemove(Data& value)
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
void SetLst<Data>::RemoveSuccessor(Data& value)
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
bool SetLst<Data>::Insert(const Data& value)
{
    if(Exists(value)) return false;

    size++;
    vector.Resize(size);
    vector[size-1] = value;
    Sort();

    return true;
}

template <typename Data>
bool SetLst<Data>::Insert(Data&& value) 
{
    if(Exists(value)) return false;

    size++;
    vector.Resize(size);
    vector[size-1] = value;
    Sort();

    return true;
}

template <typename Data>
bool SetLst<Data>::Remove(const Data& value) 
{
    ulong index = 0;
    bool found = Search(value, &value);

    if(!found) return false;

    vector[index] = vector[size-1];
    vector.Resize(size-1);
    size--;
    Sort();
    return true;
}

template <typename Data>
Data& SetLst<Data>::operator[](const ulong index)
{
    if(index >= size)
            throw std::out_of_range("index is out of range!");

    ulong i = 0;
    Node* current = head;

    while(current != nullptr)
    {
        if(i == index) 
            return head->value;
        current = current->next;
        i++;
    }
}

template <typename Data>
bool SetLst<Data>::Exists(const Data& value) const noexcept
{
    for(ulong i = 0; i < size; i++)
    {
        if(value == operator[](i))
            return true;
    }
    return false;
}

template<typename Data>
inline void SetLst<Data>::Clear()
{
    // TODO DEALLOCA

    delete head;
    head = tail = nullptr;
    size = 0;
}

template<typename Data>
bool SetLst<Data>::Search(const Data& value, ulong* index)
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
void SetLst<Data>::Sort() noexcept 
{
    QuickSort(0, size - 1);
}

template<typename Data>
void SetLst<Data>::QuickSort(ulong p, ulong r) noexcept 
{
    if (p < r) {
    ulong q = Partition(p, r);
    QuickSort(p, q);
    QuickSort(q + 1, r);
    }
}

template<typename Data>
ulong SetLst<Data>::Partition(ulong p, ulong r) noexcept 
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
