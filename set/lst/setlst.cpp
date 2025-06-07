#include "setlst.hpp"

namespace lasd {

template <typename Data>
SetLst<Data>::SetLst(const TraversableContainer<Data>& container)
{
  container.Traverse([&](const Data& data) 
  {
    Insert(data);
  });
}

template <typename Data>
SetLst<Data>::SetLst(MappableContainer<Data>&& container)
{
  container.Map([&](Data& data) 
  {
    Insert(std::move(data));
  });
}

template <typename Data>
SetLst<Data>::SetLst(const SetLst<Data>& other) 
{
  if (other.tail != nullptr) 
  {
    this->tail = new Node(*other.tail);
    this->head = other.head->Clone(this->tail);
    size = other.size;
  }
}

template <typename Data>
SetLst<Data>::SetLst(SetLst<Data>&& other) 
{
  std::swap(this->head, other.head);
  std::swap(this->tail, other.tail);
  std::swap(size, other.size);
}

template <typename Data>
SetLst<Data>::~SetLst() 
{
  Clear();
}

template <typename Data>
SetLst<Data>& SetLst<Data>::operator=(const SetLst<Data>& other) 
{
  if (size <= other.size) {
    if (this->tail == nullptr) {
      List<Data>* tmplist = new List<Data>(other);
      std::swap(*tmplist, *this);
      delete tmplist;
    } else {
      Node* ocur = other.head;
      for (Node* ncur = this->head; ncur != nullptr; ncur = ncur->next, ocur = ocur->next) {
        ncur->value = ocur->value;
      }
      if (ocur != nullptr) {
        Node* newtail = new Node(*other.tail);
        this->tail->next = ocur->Clone(newtail);
        this->tail = newtail;
      }
    }
  } else {
    if (other.tail == nullptr) {
      delete this->head;
      this->head = this->tail = nullptr;
    } else {
      Node* ncur = this->head;
      for (Node* ocur = other.head; ocur != nullptr; ocur = ocur->next, this->tail = ncur, ncur = ncur->next) {
        ncur->value = ocur->value;
      }
      delete ncur;
      this->tail->next = nullptr;
    }
  }
  size = other.size;
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
  if (size != other.size)
    return false;

  Node* curr1 = this->head;
  Node* curr2 = other.head;

  while (curr1 != nullptr && curr2 != nullptr) 
  {
    if (curr1->value != curr2->value)
      return false;
    curr1 = curr1->next;
    curr2 = curr2->next;
  }

  return true;
}

template <typename Data>
bool SetLst<Data>::operator!=(const SetLst<Data>& other) const noexcept 
{
  return !(*this == other);
}

template <typename Data>
Data SetLst<Data>::Min() const 
{
  if (this->head == nullptr) 
  {
      throw std::length_error("Empty Set");
  }
  return this->head->value;
}


template <typename Data>
Data SetLst<Data>::MinNRemove() 
{
  Data min = Min();
  RemoveMin();
  return min;
}

template <typename Data>
void SetLst<Data>::RemoveMin() 
{
  if (this->head == nullptr) throw std::length_error("Empty Set");

    Node* tmp = this->head;
    this->head = this->head->next;
    tmp->next = nullptr;
    delete tmp;
    --size;
    if (this->head == nullptr)
        this->tail = nullptr;
}

template <typename Data>
Data SetLst<Data>::Max() const 
{
  if (this->tail == nullptr) 
  {
    throw std::length_error("Empty Set");
  }
  return this->tail->value;
}

template <typename Data>
Data SetLst<Data>::MaxNRemove() 
{
  Data max = Max();
  RemoveMax();
  return max;
}

template <typename Data>
void SetLst<Data>::RemoveMax() 
{
	if (this->head == nullptr) throw std::length_error("Empty Set");

  if (this->head == this->tail) {
      delete this->head;
      this->head = this->tail = nullptr;
      size = 0;
      return;
  }

  Node* current = this->head;
  while (current->next != this->tail) 
  {
      current = current->next;
  }
  delete this->tail;
  this->tail = current;
  this->tail->next = nullptr;
  --size;
}

template <typename Data>
Data SetLst<Data>::Predecessor(const Data& value) const 
{
  if (this->head == nullptr || this->head->value >= value) 
  {
    throw std::length_error("Predecessor not found!");
  }

  Node* current = this->head;
  Node* predecessor = nullptr;
  while (current != nullptr && current->value < value) 
  {
      predecessor = current;
      current = current->next;
  }

  if (predecessor == nullptr) 
  {
      throw std::length_error("Predecessor not found!");
  }

  return predecessor->value;
}

template <typename Data>
Data SetLst<Data>::PredecessorNRemove(const Data& value) 
{
  Data pred = Predecessor(value);
  RemovePredecessor(value);
  return pred;
}

template <typename Data>
void SetLst<Data>::RemovePredecessor(const Data& value) 
{
  if (this->head == nullptr || this->head->value >= value) throw std::length_error("Predecessor not found!");
    Node* prev = nullptr;
    Node* current = this->head;
    Node* beforePrev = nullptr;

    while (current != nullptr && current->value < value) {
        beforePrev = prev;
        prev = current;
        current = current->next;
    }  
    if (prev == nullptr) throw std::length_error("Predecessor not found!");

    if (beforePrev != nullptr) {
        beforePrev->next = current;
    } else {
        this->head = current;
    }
    if (prev == this->tail) {
        this->tail = beforePrev;
    }
    prev->next = nullptr;
    delete prev;
    --size;
}

template <typename Data>
Data SetLst<Data>::Successor(const Data& value) const 
{
  if (this->head == nullptr || this->tail->value <= value) 
  {
    throw std::length_error("Successor not found!");
  }
  Node* current = this->head;
  while (current != nullptr && current->value <= value) 
  {
      current = current->next;
  }
  if (current == nullptr) 
  {
      throw std::length_error("Successor not found!");
  }
  return current->value;
}

template <typename Data>
Data SetLst<Data>::SuccessorNRemove(const Data& value) 
{
  Data succ = Successor(value);
  RemoveSuccessor(value);
  return succ;
}

template <typename Data>
void SetLst<Data>::RemoveSuccessor(const Data& value) 
{
  if (this->head == nullptr) throw std::length_error("Successor not found!");

    Node* current = this->head;
    Node* prev = nullptr;
    while (current != nullptr && current->value <= value) {
    	prev = current;
        current = current->next;
    }
    if (current == nullptr) throw std::length_error("Successor not found!");
    Node* toDelete = current;
    if (prev == nullptr) {
        this->head = current->next;
    } else {
        prev->next = current->next;
    }
    if (current == this->tail) {
        this->tail = prev;
    }
    toDelete->next = nullptr;
    delete toDelete;
    --size;
}

template <typename Data>
bool SetLst<Data>::Insert(const Data& value) 
{
  Node* current = this->head;
  Node* prev = nullptr;
  while (current != nullptr && current->value < value) {
      prev = current;
      current = current->next;
  }
    
  if ((current != nullptr && current->value == value)) {
      return false;
  }
  Node* newNode = new Node;
  newNode->value = value;
  newNode->next = nullptr;

  if (prev == nullptr) {
      newNode->next = this->head;
      this->head = newNode;
      if (this->tail == nullptr) this->tail = newNode;
  }
  else {
      newNode->next = current;
      prev->next = newNode;
      if (current == nullptr) this->tail = newNode;
  }
  ++size;
  return true;
}

template <typename Data>
bool SetLst<Data>::Insert(Data&& value) 
{
  Node* current = this->head;
  Node* prev = nullptr;
  while (current != nullptr && current->value < value) {
      prev = current;
      current = current->next;
  }
    
  if ((current != nullptr && current->value == value)) {
      return false;
  }
  Node* newNode = new Node;
  newNode->value = std::move(value);
  newNode->next = nullptr;

  if (prev == nullptr) {
      newNode->next = this->head;
      this->head = newNode;
      if (this->tail == nullptr) this->tail = newNode;
  }
  else {
      newNode->next = current;
      prev->next = newNode;
      if (current == nullptr) this->tail = newNode;
  }
  ++size;
  return true;
}

template <typename Data>
bool SetLst<Data>::Remove(const Data& value) 
{
  if (this->head == nullptr) return false;

  Node* current = this->head;
  Node* prev = nullptr;
  while (current != nullptr && current->value != value) {
      prev = current;
      current = current->next;
  }
  if (current == nullptr) return false;

  if (prev != nullptr) {
      prev->next = current->next;
  } else {
      this->head = current->next;
  }

  if (current == this->tail) {
      this->tail = prev;
  }
  current->next = nullptr;
  delete current;
  --size;
  return true;
}

template <typename Data>
const Data& SetLst<Data>::operator[](const ulong index) const 
{
  if (index < size) {
    Node* cur = this->head;
    for (unsigned long idx = 0; idx < index; ++idx, cur = cur->next) {}
    return cur->value;
  } else {
    throw std::out_of_range("Invalid address");
  }
}

template <typename Data>
bool SetLst<Data>::Exists(const Data& value) const noexcept 
{
  Node* curr = this->head;
  while (curr != nullptr && curr->value < value) {
      curr = curr->next;
  }
  return (curr != nullptr && curr->value == value);
}

template <typename Data>
void SetLst<Data>::Clear() 
{
  delete this->head;
  this->head = this->tail = nullptr;
  size = 0;
}

template <typename Data>
bool SetLst<Data>::Search(const Data& value, ulong* index) const 
{
  Node* current = this->head;
  ulong i = 0;

  while (current) {
    if (current->value == value) {
      *index = i;
      return true;
    }
    current = current->next;
    ++i;
  }

  *index = 0;
  return false;
}

template <typename Data>
typename SetLst<Data>::Node* SetLst<Data>::GetNodeByIndex(const ulong index) 
{
  if (index >= size)
    throw std::out_of_range("Index out of range");

  Node* current = this->head;
  for (ulong i = 0; i < index; ++i)
    current = current->next;

  return current;
}

template <typename Data>
void SetLst<Data>::Sort() noexcept {
  QuickSort(0, size - 1);
}

template <typename Data>
void SetLst<Data>::QuickSort(ulong p, ulong r) noexcept {
  if (p < r) {
    ulong q = Partition(p, r);
    if (q > 0) QuickSort(p, q);
    QuickSort(q + 1, r);
  }
}

template <typename Data>
ulong SetLst<Data>::Partition(ulong p, ulong r) noexcept {
  Data pivot = GetNodeByIndex(p)->value;
  ulong i = p - 1;
  ulong j = r + 1;

  while (true) {
    do {
      --j;
    } while (GetNodeByIndex(j)->value > pivot);

    do {
      ++i;
    } while (GetNodeByIndex(i)->value < pivot);

    if (i < j) {
      std::swap(GetNodeByIndex(i)->value, GetNodeByIndex(j)->value);
    } else {
      return j;
    }
  }
}

}
