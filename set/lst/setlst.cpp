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
    : List<Data>(std::move(mappableContainer))
{
    size = mappableContainer.Size();
    Sort();
}

template <typename Data>
SetLst<Data>::SetLst(const SetLst<Data>& setlst)
{
    for(ulong i = 0; i < setlst.size; i++)
    {
        Insert(setlst[i]);
    }
    size = setlst.size;
}

template <typename Data>
SetLst<Data>::SetLst(SetLst<Data>&& setlst)
{
    this->head = setlst.head;
    this->tail = setlst.tail;
    this->size = setlst.size;

    setlst.head = nullptr;
    setlst.tail = nullptr;
    setlst.size = 0;
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

    Clear();

    if(other.tail != nullptr)
    {
        this->tail = new List<Data>::Node(*other.tail);
        this->head = other.head->Clone(this->tail);
        size = other.size;
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
    if(size != other.size)
            return false;

    Node* current = this->head;
    Node* currentOther = other.head;

    while(current != nullptr && currentOther != nullptr)
    {
        if(current->value != currentOther->value)
            return false;
        current = current->next;
        currentOther = currentOther->next;
    }

    return (current == nullptr && currentOther == nullptr);
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
        this->head->next = nullptr;
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
    if(size == 0) throw std::length_error("Prececessor not found!");
    
    for(ulong i = size-1; i >= 0; i--)
    {
        if(value > operator[](i))
            return operator[](i);
    }

    throw std::length_error("Prececessor not found!");
}

template <typename Data>
Data SetLst<Data>::PredecessorNRemove(const Data& value)
{
    if(size == 0) throw std::length_error("Prececessor not found!");
    if(size == 1) throw std::length_error("Prececessor not found!");

    // Caso N
    for(ulong i = size-1; i >= 0; i--)
    {
        if(value > operator[](i))
        {
            Node* precNode = GetNodeByIndex(i);
            Node* precPrec = GetNodeByIndex(i-1);
            Data prec = precNode->value;

            precPrec->next = precNode->next;
            precNode->next = nullptr;
            delete precNode;
            size--;
            Sort();
            return prec;
        }

        if(i == 0) break;
    }

    throw std::length_error("Prececessor not found!");
}

template <typename Data>
void SetLst<Data>::RemovePredecessor(const Data& value)
{
    if (size < 2) {
        throw std::length_error("Predecessor not found!");
    }

    // Caso speciale: il primo elemento è già >= value → nessun predecessore
    if (!(operator[](0) < value)) {
        throw std::length_error("Predecessor not found!");
    }

    // Scorri per trovare l'elemento più grande < value
    ulong i = 1;
    while (i < size && !(operator[](i) >= value)) {
        i++;
    }

    // i è la posizione del primo >= value
    ulong indexToRemove = i - 1;

    // Rimozione nodo in posizione indexToRemove
    if (indexToRemove == 0) {
        // Rimuovi testa
        Node* toDelete = this->head;
        this->head = this->head->next;
        toDelete->next = nullptr;
        delete toDelete;
    } else {
        Node* prev = GetNodeByIndex(indexToRemove - 1);
        Node* toDelete = prev->next;
        prev->next = toDelete->next;
        if (toDelete == this->tail) {
            this->tail = prev;
        }
        toDelete->next = nullptr;
        delete toDelete;
    }

    size--;
}

template <typename Data>
Data SetLst<Data>::Successor(const Data& value) const
{
    if(size == 0) throw std::length_error("Sucessor not found!");
    
    for(ulong i = 0; i < size; i++)
    {
        if(value < operator[](i))
            return operator[](i);
    }

    throw std::length_error("Sucessor not found!");
}

template <typename Data>
Data SetLst<Data>::SuccessorNRemove(const Data& value)
{
    if(size == 0) throw std::length_error("Successor not found!");

    Node* current = this->head;
    Node* prec = nullptr;

    while(current != nullptr)
    {
        if(value < current->value)
        {
            if(current == this->tail)
            {
                prec->next = nullptr;
                Data ret = this->tail->value;
                delete this->tail;
                this->tail = prec;
                size--;
                Sort();
                return ret;
            }else if(current == this->head)
            {
                Data ret = this->head->value;
                Node* oldHead = this->head;

                this->head = this->head->next;
                oldHead->next = nullptr;
                delete oldHead;
                size--;
                Sort();
                return ret;
            }else{
                Data ret = current->value;
                prec->next = current->next;
                current->next = nullptr;
                delete current;
                size--;
                Sort();
                return ret;
            }
        }

        prec = current;
        current = prec->next;
    }

    throw std::length_error("Successor not found!");
}

template <typename Data>
void SetLst<Data>::RemoveSuccessor(const Data& value)
{
    if(size == 0) throw std::length_error("Successor not found!");

    Node* current = this->head;
    Node* prec = nullptr;

    while(current != nullptr)
    {
        if(value < current->value)
        {
            if(current == this->tail)
            {
                prec->next = nullptr;
                delete this->tail;
                this->tail = prec;
                size--;
                Sort();
                return;
            }else if(current == this->head)
            {
                Node* oldHead = this->head;

                this->head = this->head->next;
                oldHead->next = nullptr;
                delete oldHead;
                size--;
                Sort();
                return;
            }else{
                prec->next = current->next;
                current->next = nullptr;
                delete current;
                size--;
                Sort();
                return;
            }
        }

        prec = current;
        current = prec->next;
    }

    throw std::length_error("Successor not found!");
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
bool SetLst<Data>::Remove(const Data& value) {
    if (this->head == nullptr) // Lista vuota
    {
        return false;
    }

    Node* current = this->head;
    Node* prev = nullptr;

    // Scorri la lista finché trovi un nodo >= value
    while (current != nullptr && current->value < value) {
        prev = current;
        current = current->next;
    }

    // Se non trovato o non corrisponde al valore esatto
    if (current == nullptr || current->value != value)
        return false;

    // Caso 1: nodo da rimuovere è la testa
    if (current == this->head) {
        this->head = this->head->next;
        if (this->tail == current)
            this->tail = nullptr;
    }
    // Caso 2: nodo da rimuovere è la coda
    else if (current == this->tail) {
        this->tail = prev;
        prev->next = nullptr;
    }
    // Caso 3: nodo in mezzo
    else {
        prev->next = current->next;
    }

    current->next = nullptr;
    delete current;
    --size;
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
            break;
        current = current->next;
        i++;
    }

    return current->value;
}

template <typename Data>
bool SetLst<Data>::Exists(const Data& value) const noexcept
{
    if(size == 0) return false;
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
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
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
