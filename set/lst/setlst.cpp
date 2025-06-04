#include "setlst.hpp"

namespace lasd {

template <typename Data>
SetLst<Data>::SetLst(const TraversableContainer<Data>& container)
    : List<Data>(container) 
{
  size = container.Size();
  Sort();
}

template <typename Data>
SetLst<Data>::SetLst(MappableContainer<Data>&& container)
    : List<Data>(std::move(container)) 
{
  size = container.Size();
  Sort();
}

template <typename Data>
SetLst<Data>::SetLst(const SetLst<Data>& other) 
{
  for (ulong i = 0; i < other.size; ++i) 
  {
    Insert(other[i]);
  }
  size = other.size;
}

template <typename Data>
SetLst<Data>::SetLst(SetLst<Data>&& other) 
{
  this->head = other.head;
  this->tail = other.tail;
  size = other.size;

  other.head = nullptr;
  other.tail = nullptr;
  other.size = 0;
}

template <typename Data>
SetLst<Data>::~SetLst() 
{
  Clear();
}

template <typename Data>
SetLst<Data>& SetLst<Data>::operator=(const SetLst<Data>& other) 
{
  if (this != &other) 
  {
    Clear();
    for (ulong i = 0; i < other.size; ++i) 
    {
      Insert(other[i]);
    }
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
  if (size == 0)
    throw std::length_error("Empty set");
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
  if (size == 0)
    throw std::length_error("Empty set");

  Node* temp = this->head;
  this->head = this->head->next;
  temp->next = nullptr;
  delete temp;
  if (--size == 0)
  this->tail = nullptr;
}

template <typename Data>
Data SetLst<Data>::Max() const 
{
  if (size == 0)
    throw std::length_error("Empty set");
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
  if (size == 0)
    throw std::length_error("Empty set");

  if (size == 1) 
  {
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
  this->tail->next = nullptr; 
  delete this->tail;
  this->tail = current;
  this->tail->next = nullptr;
  --size;
}

template <typename Data>
Data SetLst<Data>::Predecessor(const Data& value) const 
{
  for (ulong i = size - 1; i > 0; --i) 
  {
    if (operator[](i) < value)
      return operator[](i);
  }
  throw std::length_error("No predecessor found");
}

template <typename Data>
Data SetLst<Data>::PredecessorNRemove(const Data& value) 
{
  for (ulong i = size - 1; i > 0; --i) 
  {
    if (operator[](i) < value) {
      Data result = operator[](i);
      Node* node = GetNodeByIndex(i);
      Node* prev = (i > 0) ? GetNodeByIndex(i - 1) : nullptr;

      if (prev)
        prev->next = node->next;
      else
      this->head = node->next;

      if (node == this->tail)
      this->tail = prev;

      node->next = nullptr;
      delete node;
      --size;
      return result;
    }
  }
  throw std::length_error("No predecessor to remove");
}

template <typename Data>
void SetLst<Data>::RemovePredecessor(const Data& value) 
{
  PredecessorNRemove(value);
}

template <typename Data>
Data SetLst<Data>::Successor(const Data& value) const 
{
  for (ulong i = 0; i < size; ++i) 
  {
    if (operator[](i) > value)
      return operator[](i);
  }
  throw std::length_error("No successor found");
}

template <typename Data>
Data SetLst<Data>::SuccessorNRemove(const Data& value) 
{
  Node* current = this->head;
  Node* prev = nullptr;

  while (current != nullptr) {
    if (current->value > value) 
    {
      Data result = current->value;
      if (current == this->head) 
      {
        this->head = this->head->next;
      } else 
      {
        prev->next = current->next;
      }
      if (current == this->tail)
      this->tail = prev;

      current->next = nullptr;
      delete current;
      --size;
      return result;
    }
    prev = current;
    current = current->next;
  }

  throw std::length_error("No successor to remove");
}

template <typename Data>
void SetLst<Data>::RemoveSuccessor(const Data& value) 
{
  SuccessorNRemove(value);
}

template <typename Data>
bool SetLst<Data>::Insert(const Data& value) 
{
  if (Exists(value))
    return false;

  Node* node = new Node(value);

  if (!this->head) {
    this->head = this->tail = node;
  } else if (value < this->head->value) {
    node->next = this->head;
    this->head = node;
  } else if (value > this->tail->value) {
    this->tail->next = node;
    this->tail = node;
  } else {
    Node* current = this->head;
    while (current->next && current->next->value < value)
      current = current->next;
    node->next = current->next;
    current->next = node;
  }

  ++size;
  return true;
}

template <typename Data>
bool SetLst<Data>::Insert(Data&& value) 
{
  return Insert(static_cast<const Data&>(value));
}

template <typename Data>
bool SetLst<Data>::Remove(const Data& value) 
{
  Node* current = this->head;
  Node* prev = nullptr;

  while (current && current->value < value) {
    prev = current;
    current = current->next;
  }

  if (!current || current->value != value)
    return false;

  if (current == this->head) {
    this->head = this->head->next;
    if (this->tail == current)
    this->tail = nullptr;
  } else {
    prev->next = current->next;
    if (current == this->tail)
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
  if (index >= size)
    throw std::length_error("Index out of range");

  Node* current = this->head;
  for (ulong i = 0; i < index; ++i)
    current = current->next;

  return current->value;
}

template <typename Data>
bool SetLst<Data>::Exists(const Data& value) const noexcept 
{
  Node* current = this->head;
  while (current) {
    if (current->value == value)
      return true;
    current = current->next;
  }
  return false;
}

template <typename Data>
void SetLst<Data>::Clear() 
{
  while (this->head != nullptr) 
  {
    Node* temp = this->head;
    this->head = this->head->next;
    temp->next = nullptr;
    delete temp;
  }
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
