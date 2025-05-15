
#ifndef LIST_HPP
#define LIST_HPP

/* ************************************************************************** */

#include "../container/linear.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class List : virtual public MutableLinearContainer<Data>, virtual public  ClearableContainer{
  // Must extend MutableLinearContainer<Data>,
  //             ClearableContainer

private:

  // ...

protected:
  using Container::size;

  struct Node {

    // Data
    Data value;
    Node* next = nullptr;

    /* ********************************************************************** */

    // Specific constructors
    Node(const Data& value)
    {
      this->value = value;
      this->next = nullptr;
    }

    /* ********************************************************************** */

    // Copy constructor
    Node(const Node& node) 
    {
      value = node.value;
    }

    // Move constructor
    Node(Node&& node);

    /* ********************************************************************** */

    // Destructor
    virtual ~Node();

    /* ********************************************************************** */

    // Comparison operators
    bool operator==(const Node& other) const noexcept
    {
      return (this->value == other.value) && (this->next == other.next);
    }
    bool operator!=(const Node& other) const noexcept
    {
      return !(*this == other);
    }

    /* ********************************************************************** */

    // Specific member functions

    virtual Node* Clone(Node* other);

  };

  Node* head = nullptr;
  Node* tail = nullptr;

public:

  // Default constructor
  List() = default;

  /* ************************************************************************ */

  // Specific constructor
  List(const TraversableContainer<Data>& other); // A list obtained from a TraversableContainer
  List(MappableContainer<Data>&& other);  // A list obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  List(const List<Data>& other);

  // Move constructor
  List(List<Data>&& other);

  /* ************************************************************************ */

  // Destructor
  ~List() = default;

  /* ************************************************************************ */

  // Copy assignment
  List<Data>& operator=(const List<Data>& other);

  // Move assignment
  List<Data>& operator=(List<Data>&& other);

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const List<Data>& other) const noexcept;
  bool operator!=(const List<Data>& other) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  void InsertAtFront(const Data& value); // Copy of the value
  void InsertAtFront(Data&& value); // Move of the value
  void RemoveFromFront(); // (must throw std::length_error when empty)
  Data FrontNRemove(); // (must throw std::length_error when empty)

  void InsertAtBack(const Data& value); // Copy of the value
  void InsertAtBack(Data&& value); // Move of the value
  void RemoveFromBack(); // (must throw std::length_error when empty)
  Data BackNRemove(); // (must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableLinearContainer)

  Data& operator[](const ulong index) override; // Override MutableLinearContainer member (must throw std::out_of_range when out of range)

  Data& Front() override; // Override MutableLinearContainer member (must throw std::length_error when empty)

  Data& Back() override; // Override MutableLinearContainer member (must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  const Data& operator[](const ulong index) const override; // Override LinearContainer member (must throw std::out_of_range when out of range)

  const Data& Front() const override; // Override LinearContainer member (must throw std::length_error when empty)

  const Data& Back() const override; // Override LinearContainer member (must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  using typename MappableContainer<Data>::MapFun;

  void Map(MapFun fun) override; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderMappableContainer)

  void PreOrderMap(MapFun fun) override; // Override PreOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderMappableContainer)

  void PostOrderMap(MapFun fun) override;  // Override PostOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  using typename TraversableContainer<Data>::TraverseFun;

  void Traverse(TraverseFun fun) const override; // Override TraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderTraversableContainer)

  void PreOrderTraverse(TraverseFun fun) const override; // Override PreOrderTraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderTraversableContainer)

  void PostOrderTraverse(TraverseFun fun) const override; // Override PostOrderTraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  inline void Clear() override; // Override ClearableContainer member

protected:

  // Auxiliary member functions (for TraversableContainer)

  void PreOrderTraverse(TraverseFun fun, const Node* node) const;
  void PostOrderTraverse(TraverseFun fun, const Node* node) const;

  /* ************************************************************************ */

  // Auxiliary member functions (for MappableContainer)

  void PreOrderMap(MapFun fun, Node* node);
  void PostOrderMap(MapFun fun, Node* node);

};

/* ************************************************************************** */

}

#include "list.cpp"

#endif
