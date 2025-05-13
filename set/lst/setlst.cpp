#include "setlst.hpp"

namespace lasd {

template <typename Data>
SetLst<Data>::SetLst(const TraversableContainer<Data>& traversableContainer)
    : List<Data>(traversableContainer)
{
    size = traversableContainer.Size();
}

template <typename Data>
SetLst<Data>::SetLst(MappableContainer<Data>&& mappableContainer)
    : List<Data>(mappableContainer)
{
    size = mappableContainer.Size();
}

template <typename Data>
SetLst<Data>::SetLst(const SetLst<Data>& setlst)
{
    size = setlst.Size();
    for(ulong i = 0; i < size; i++)
    {
        Insert(setlst[i]);
    }
}

template <typename Data>
SetLst<Data>::SetLst(SetLst<Data>&& setlst)
{
    size = setlst.Size();
    for(ulong i = 0; i < size; i++)
    {
        Insert(std::move(setlst[i]));
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
            this->tail = new List<Data>::Node(*other.tail);
            this->head = other.head->Clone(this->tail);
            size = other.size;
        }
    }

    return *this;
}

template <typename Data>
SetLst<Data>& SetLst<Data>::operator=(SetLst<Data>&& other)
{
    std::swap(this->head, other.head);
    std::swap(this->tail, other.tail);
    std::swap(size, other.size);

    return *this;
}

template <typename Data>
bool SetLst<Data>::operator==(const SetLst<Data>& other) const noexcept
{
    return (size == other.size) && (this->head == other.head);
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

    return this->head->value;
}

template <typename Data>
Data SetLst<Data>::MinNRemove()
{
    if(size == 0) throw std::length_error("The list is empty!");    

    Data min = this->head->value;
    Node* newHead = this->head->next;
    delete this->head;
    this->head = newHead;

    size--;

    return min;
}

template <typename Data>
void SetLst<Data>::RemoveMin()
{
    if(size == 0) throw std::length_error("The list is empty!");    

    Node* newHead = this->head->next;
    delete this->head;
    this->head = newHead;

    size--;
}

template <typename Data>
Data SetLst<Data>::Max() const
{
    if(size == 0) throw std::length_error("The vector is empty!");    

    return this->tail->value;
}

template <typename Data>
Data SetLst<Data>::MaxNRemove()
{
    if(size == 0) throw std::length_error("The list is empty!");    

    Data max = this->tail->value;
    Node* newTail = GetNodeByIndex(size-2);
    newTail->next = nullptr;
    delete this->tail;
    this->tail = newTail;

    size--;

    return max;
}

template <typename Data>
void SetLst<Data>::RemoveMax()
{
    if(size == 0) throw std::length_error("The vector is empty!");    

    Node* newTail = GetNodeByIndex(size-2);
    newTail->next = nullptr;
    delete this->tail;
    this->tail = newTail;

    size--;
}

template <typename Data>
Data SetLst<Data>::Predecessor(const Data& value) const
{
    ulong i_found = 0;
    bool found = Search(value, &i_found);

    if(!found) throw std::length_error("'value' not found!");
    if(i_found == 0) throw std::length_error("Predecessor not found!");
    
    return operator[](i_found-1);
}

template <typename Data>
Data SetLst<Data>::PredecessorNRemove(const Data& value)
{
    ulong i_found = 0;
    bool found = Search(value, &i_found);

    if(!found) throw std::length_error("'value' not found!");
    if(i_found == 0) throw std::length_error("Predecessor not found!");
    if(i_found == 1) return MinNRemove();

    ulong i = 0;
    Node* current = this->head;
    Data data;
    while(current != nullptr)
    {
        if(i == i_found-2) 
        {
            data = current->next->value; //value di prec
            Node* tmp = current->next->next; //prec->next
            current->next = tmp; //prec di prec (current)
            delete current->next;
            break;
        }
        current = current->next;
        i++;
    }

    size--;

    return data;
}

template <typename Data>
void SetLst<Data>::RemovePredecessor(const Data& value)
{
    ulong i_found = 0;
    bool found = Search(value, &i_found);

    if(!found) throw std::length_error("'value' not found!");
    if(i_found == 0) throw std::length_error("Predecessor not found!");
    if(i_found == 1) {RemoveMin(); return;}
    
    ulong i = 0;
    Node* current = this->head;
    while(current != nullptr)
    {
        if(i == i_found-2) 
        {
            Node* tmp = current->next->next; //prec->next
            current->next = tmp; //prec di prec (current)
            delete current->next;
            break;
        }
        current = current->next;
        i++;
    }

    size--;
}

template <typename Data>
Data SetLst<Data>::Successor(const Data& value) const
{
    ulong i_found = 0;
    bool found = Search(value, &i_found);

    if(!found) throw std::length_error("'value' not found!");
    if(i_found == size-1) throw std::length_error("Successor not found!");

    return operator[](i_found+1);
}

template <typename Data>
Data SetLst<Data>::SuccessorNRemove(const Data& value)
{
    ulong i_found = 0;
    bool found = Search(value, &i_found);

    if(!found) throw std::length_error("'value' not found!");
    if(i_found == size-1) throw std::length_error("Successor not found!");
    if(i_found == size-2) return MaxNRemove();

    ulong i = 0;
    Node* current = this->head;
    Data data;
    while(current != nullptr)
    {
        if(i == i_found) 
        {
            data = current->next->value;
            Node* tmp = current->next->next;
            current->next = tmp;
            delete current->next;
            break;
        }
        current = current->next;
        i++;
    }

    size--;

    return data;
}

template <typename Data>
void SetLst<Data>::RemoveSuccessor(const Data& value)
{
    ulong i_found = 0;
    bool found = Search(value, &i_found);

    if(!found) throw std::length_error("'value' not found!");
    if(i_found == size-1) throw std::length_error("Successor not found!");
    if(i_found == size-2) {RemoveMax(); return;}

    ulong i = 0;
    Node* current = this->head;
    while(current != nullptr)
    {
        if(i == i_found) 
        {
            Node* tmp = current->next->next;
            current->next = tmp;
            delete current->next;
            break;
        }
        current = current->next;
        i++;
    }

    size--;
}

template <typename Data>
bool SetLst<Data>::Insert(const Data& value)
{
    if(Exists(value)) return false;
    size++;

    Node* node = new List<Data>::Node(value);

    if(node->value < this->head->value)
    {
        node->next = this->head;
        this->head = node;

        return true;
    }else if(node->value > this->tail->value)
    {
        this->tail->next = node;
        this->tail = node;

        return true;
    }

    Node* current = this->head;
    Node* prec = nullptr;
    while(current != nullptr)
    {
        if(node->value < current->value) 
        {
            node->next = current;
            prec->next = node;
            break;
        }
        prec = current;
        current = current->next;
    }

    return true;
}

template <typename Data>
bool SetLst<Data>::Insert(Data&& value) 
{
    if(Exists(value)) return false;
    size++;

    Node* node = new List<Data>::Node(value);

    if(node->value < this->head->value)
    {
        node->next = this->head;
        this->head = node;

        return true;
    }else if(node->value > this->tail->value)
    {
        this->tail->next = node;
        this->tail = node;

        return true;
    }

    Node* current = this->head;
    Node* prec = nullptr;
    while(current != nullptr)
    {
        if(node->value < current->value) 
        {
            node->next = current;
            prec->next = node;
            break;
        }
        prec = current;
        current = current->next;
    }

    return true;
}

template <typename Data>
bool SetLst<Data>::Remove(const Data& value) 
{
    ulong index = 0;
    bool found = Search(value, &index);

    if(!found) return false;

    Node* node = GetNodeByIndex(index);

    if(node == this->head)
    {
        RemoveMin();

        return true;
    }else if(node == this->tail)
    {
        RemoveMax();

        return true;
    }

    Node* current = this->head;
    Node* prec = nullptr;
    while(current != nullptr)
    {
        if(node == current)
        {
            prec->next = current->next;
            delete current;
            break;
        }
        prec = current;
        current = current->next;
    }

    size--;
    return true;
}

template <typename Data>
const Data& SetLst<Data>::operator[](const ulong index) const
{
    if(index >= size)
            throw std::out_of_range("index is out of range!");

    ulong i = 0;
    Node* current = this->head;

    while(current != nullptr)
    {
        if(i == index) 
            return this->head->value;
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

    delete this->head;
    this->head = this->tail = nullptr;
    size = 0;
}

template<typename Data>
bool SetLst<Data>::Search(const Data& value, ulong* index) const
{
    for(ulong i = 0; i < size; i++)
    {
        if(value == operator[](i))
        {
            *index = i;
            return true;
        }
    }

    *index = 0;
    return false;
}


template<typename Data>
bool SetLst<Data>::Search(Data& value, ulong* index) const
{
    for(ulong i = 0; i < size; i++)
    {
        if(value == operator[](i))
        {
            *index = i;
            return true;
        }
    }

    *index = 0;
    return false;
}

template<typename Data>
typename SetLst<Data>::Node* SetLst<Data>::GetNodeByIndex(const ulong index)
{
    if(index >= size)
    throw std::out_of_range("index is out of range!");

    ulong i = 0;
    Node* current = this->head;

    while(current != nullptr)
    {
    if(i == index) 
        return current;
    current = current->next;
    i++;
    }

    return nullptr;
}
}
