#include "setlst.hpp"

namespace lasd {

template <typename Data>
SetLst<Data>::SetLst(const TraversableContainer<Data>& traversableContainer)
    : List<Data>(traversableContainer)
{
    size = traversableContainer.Size();
    Sort();
}

template <typename Data>
SetLst<Data>::SetLst(MappableContainer<Data>&& mappableContainer)
    : List<Data>(mappableContainer)
{
    size = mappableContainer.Size();
    Sort();
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
    if (size == 0)
        throw std::length_error("The list is empty!");

    Data min = this->head->value;
    RemoveMin();
    return min;
}

template <typename Data>
void SetLst<Data>::RemoveMin()
{
    if (size == 0) 
        throw std::length_error("The list is empty!");

    // Caso con un solo elemento
    if (size == 1)
    {
        delete this->head;
        this->head = nullptr;
        this->tail = nullptr;
        size--;
        return;
    }

    // Caso con più elementi
    Node* newHead = this->head->next;
    this->head->next = nullptr;
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
    if (size == 0)
        throw std::length_error("The list is empty!");

    Data max = this->tail->value;
    RemoveMax();
    return max;
}

template <typename Data>
void SetLst<Data>::RemoveMax()
{
    if (size == 0)
        throw std::length_error("The list is empty!");

    // Caso con un solo elemento
    if (size == 1)
    {
        delete this->tail;
        this->head = nullptr;
        this->tail = nullptr;
        size--;
        return;
    }

    // Caso con più elementi
    Node* current = this->head;
    while (current->next != this->tail) {
        current = current->next;
    }
    delete this->tail;
    current->next = nullptr;
    this->tail = current;
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

    if (i_found == 0) 
        throw std::length_error("Predecessor not found!");
    if (i_found == 1) 
        return MinNRemove();

    ulong i = 0;
    Node* current = this->head;

    while (current != nullptr)
    {
        if (i == i_found - 2)
        {
            Node* toDelete = current->next;
            Data data = toDelete->value;
            current->next = toDelete->next;
            toDelete->next = nullptr;
            delete toDelete;
            size--;
            return data;
        }
        current = current->next;
        i++;
    }

    throw std::logic_error("Unexpected error in PredecessorNRemove.");
}

template <typename Data>
void SetLst<Data>::RemovePredecessor(const Data& value)
{
    ulong i_found = 0;
    bool found = Search(value, &i_found);
    
    if (i_found == 0) throw std::length_error("Predecessor not found!");
    if (i_found == 1) { RemoveMin(); return; }

    ulong i = 0;
    Node* current = this->head;
    while (current != nullptr)
    {
        if (i == i_found - 2)
        {
            Node* toDelete = current->next;
            current->next = toDelete->next;
            toDelete->next = nullptr;
            delete toDelete;
            size--;
            return;
        }
        current = current->next;
        i++;
    }
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

    if (!found) 
        throw std::length_error("'value' not found!");
    if (i_found == size - 1) 
        throw std::length_error("Successor not found!");
    if (i_found == size - 2) 
        return MaxNRemove();

    ulong i = 0;
    Node* current = this->head;

    while (current != nullptr)
    {
        if (i == i_found) 
        {
            Node* toDelete = current->next;
            Data data = toDelete->value;
            current->next = toDelete->next;
            toDelete->next = nullptr;
            delete toDelete;
            size--;
            return data;
        }
        current = current->next;
        i++;
    }

    // Non dovrebbe mai arrivare qui
    throw std::logic_error("Unexpected error in SuccessorNRemove.");
}

template <typename Data>
void SetLst<Data>::RemoveSuccessor(const Data& value)
{
    ulong i_found = 0;
    bool found = Search(value, &i_found);

    if (!found) throw std::length_error("'value' not found!");
    if (i_found == size - 1) throw std::length_error("Successor not found!");
    if (i_found == size - 2) { RemoveMax(); return; }

    ulong i = 0;
    Node* current = this->head;
    while (current != nullptr)
    {
        if (i == i_found)
        {
            Node* toDelete = current->next;
            current->next = toDelete->next;
            toDelete->next = nullptr;
            delete toDelete;
            size--;
            return;
        }
        current = current->next;
        i++;
    }
}

template <typename Data>
bool SetLst<Data>::Insert(const Data& value) {
    if (Exists(value)) return false;
    size++;

    Node* node = new typename List<Data>::Node(value);

    if (this->head == nullptr) {
        this->head = this->tail = node;
        return true;
    }

    if (value < this->head->value) {
        node->next = this->head;
        this->head = node;
        return true;
    }

    if (value > this->tail->value) {
        this->tail->next = node;
        this->tail = node;
        return true;
    }

    Node* current = this->head->next;
    Node* prec = this->head;

    while (current != nullptr && value > current->value) {
        prec = current;
        current = current->next;
    }

    node->next = current;
    prec->next = node;

    if (current == nullptr) {  // Inserito in fondo
        this->tail = node;
    }

    return true;
}


template <typename Data>
bool SetLst<Data>::Insert(Data&& value) {
    if (Exists(value)) return false;
    size++;

    Node* node = new typename List<Data>::Node(value);

    if (this->head == nullptr) {
        this->head = this->tail = node;
        return true;
    }

    if (value < this->head->value) {
        node->next = this->head;
        this->head = node;
        return true;
    }

    if (value > this->tail->value) {
        this->tail->next = node;
        this->tail = node;
        return true;
    }

    Node* current = this->head->next;
    Node* prec = this->head;

    while (current != nullptr && value > current->value) {
        prec = current;
        current = current->next;
    }

    node->next = current;
    prec->next = node;

    if (current == nullptr) {  // Inserito in fondo
        this->tail = node;
    }

    return true;
}

template <typename Data>
bool SetLst<Data>::Remove(const Data& value) 
{
    ulong index = 0;
    if (!Search(value, &index)) 
        return false;

    Node* node = GetNodeByIndex(index);

    // Caso 1: nodo da rimuovere è la testa
    if (node == this->head) {
        RemoveMin();
    }
    // Caso 2: nodo da rimuovere è la coda
    else if (node == this->tail) {
        RemoveMax();
    }
    // Caso 3: nodo in mezzo
    else {
        Node* current = this->head;
        while (current->next != nullptr && current->next != node) {
            current = current->next;
        }

        if (current->next == node) {
            current->next = node->next;
            node->next = nullptr; ///
            delete node;
            --size;
        }
    }

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
            return current->value;
        current = current->next;
        i++;
    }
}

template <typename Data>
bool SetLst<Data>::Exists(const Data& value) const noexcept
{
    for(ulong i = 0; i < this->size; i++)
    {
        if(value == operator[](i))
            return true;
    }
    return false;
}

template<typename Data>
inline void SetLst<Data>::Clear()
{
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
ulong SetLst<Data>::Partition(ulong p, ulong r) noexcept {
  Node* pivotNode = this->head;
  for (ulong k = 0; k < p; ++k) {
    pivotNode = pivotNode->next;
  }
  Data x = pivotNode->value;

  ulong i = p - 1;
  ulong j = r + 1;

  while (true) {

    do {
      j--;
    } while (x < GetNodeByIndex(j)->value);

    do {
      i++;
    } while (x > GetNodeByIndex(i)->value);

    if (i < j) {
      Node* nodeI = GetNodeByIndex(i);
      Node* nodeJ = GetNodeByIndex(j);
      std::swap(nodeI->value, nodeJ->value);
    } else {
      return j;
    }
  }
}

}
