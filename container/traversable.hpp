
#ifndef TRAVERSABLE_HPP
#define TRAVERSABLE_HPP

/* ************************************************************************** */

#include <functional>

/* ************************************************************************** */

#include "testable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class TraversableContainer : virtual public TestableContainer<Data>{
  // Must extend TestableContainer<Data>

private:

  // ...

protected:
  // ...

public:

  // Destructor
  virtual ~TraversableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  TraversableContainer<Data>& operator=(const TraversableContainer<Data>&) = delete; // Copy assignment of abstract types is not possible.

  // Move assignment
  TraversableContainer<Data>& operator=(TraversableContainer<Data>&) = delete; // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const TraversableContainer<Data>& other) const noexcept = delete; // Comparison of abstract types might be possible.
  bool operator!=(const TraversableContainer<Data>& other) const noexcept = delete; // Comparison of abstract types might be possible.

  /* ************************************************************************ */

  // Specific member function

  using TraverseFun = std::function<void(const Data &)>;

  virtual void Traverse(TraverseFun fun) const = 0;

  template <typename Accumulator>
  using FoldFun = std::function<Accumulator(const Data &, const Accumulator &)>;

  template <typename Accumulator>
  Accumulator Fold(FoldFun<Accumulator> fun, Accumulator acc) const;

  /* ************************************************************************ */

  // Specific member function (inherited from TestableContainer)

  inline bool Exists(const Data& value) const noexcept override; // Override TestableContainer member

};

/* ************************************************************************** */

template <typename Data>
class PreOrderTraversableContainer : virtual public TraversableContainer<Data>{
  // Must extend TraversableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~PreOrderTraversableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  PreOrderTraversableContainer<Data>& operator=(const PreOrderTraversableContainer<Data>&) = delete; // Copy assignment of abstract types is not possible.

  // Move assignment
  PreOrderTraversableContainer<Data>& operator=(PreOrderTraversableContainer<Data>&&) = delete; // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const PreOrderTraversableContainer<Data>& other) const noexcept = delete; // Comparison of abstract types might be possible.
  bool operator!=(const PreOrderTraversableContainer<Data>& other) const noexcept = delete; // Comparison of abstract types might be possible.

  /* ************************************************************************ */

  // Specific member function

  using typename TraversableContainer<Data>::TraverseFun;

  virtual void PreOrderTraverse(TraverseFun fun) const = 0;

  template <typename Accumulator>
  using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;

  template <typename Accumulator>
  Accumulator PreOrderFold(FoldFun<Accumulator> fun, Accumulator acc) const;

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  void Traverse(TraverseFun fun) const override; // Override TraversableContainer member

};

/* ************************************************************************** */

template <typename Data>
class PostOrderTraversableContainer : virtual public TraversableContainer<Data>{
  // Must extend TraversableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~PostOrderTraversableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  PostOrderTraversableContainer<Data>& operator=(const PostOrderTraversableContainer<Data>&) = delete; // Copy assignment of abstract types is not possible.

  // Move assignment
  PostOrderTraversableContainer<Data>& operator=(PostOrderTraversableContainer<Data>&&) = delete; // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const PostOrderTraversableContainer<Data>& other) const noexcept = delete; // Comparison of abstract types might be possible.
  bool operator!=(const PostOrderTraversableContainer<Data>& other) const noexcept = delete; // Comparison of abstract types might be possible.

  /* ************************************************************************ */

  // Specific member function

  using typename TraversableContainer<Data>::TraverseFun;

  virtual void PostOrderTraverse(TraverseFun fun) const = 0;

  template <typename Accumulator>
  using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;

  template <typename Accumulator>
  Accumulator PostOrderFold(FoldFun<Accumulator> fun, Accumulator acc) const;

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  void Traverse(TraverseFun fun) const override; // Override TraversableContainer member

};

/* ************************************************************************** */

}

#include "traversable.cpp"

#endif
