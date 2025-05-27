
#ifndef PQ_HPP
#define PQ_HPP

/* ************************************************************************** */

#include "../container/linear.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class PQ : virtual public LinearContainer<Data>,
            ClearableContainer
{
  // Must extend LinearContainer<Data>,
  //             ClearableContainer

private:

protected:

public:

  // Destructor
  virtual ~PQ() = default;

  /* ************************************************************************ */

  // Copy assignment
  PQ& operator=(const PQ& other) = delete; // Copy assignment of abstract types is not possible.

  // Move assignment
  PQ& operator=(PQ&& other) = delete; // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual Data& Tip() const = 0; // (concrete function must throw std::length_error when empty)
  virtual void RemoveTip() = 0; // (concrete function must throw std::length_error when empty)
  virtual Data TipNRemove() = 0; // (concrete function must throw std::length_error when empty)

  // type Insert(argument) specifiers; // Copy of the value
  virtual void Insert(const Data& val) = 0;

  // type Insert(argument) specifiers; // Move of the value
  virtual void Insert(Data&& val) = 0;

  // type Change(argument) specifiers; // Copy of the value
  virtual void Change(ulong index, const Data& val) = 0;

  // type Change(argument) specifiers; // Move of the value
  virtual void Change(ulong index, Data&& val) = 0;
  
};

/* ************************************************************************** */

}

#endif
