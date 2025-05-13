#include "traversable.hpp"

namespace lasd {

  template <typename Data>
  template <typename Accumulator>
  Accumulator TraversableContainer<Data>::Fold(FoldFun<Accumulator> fun, Accumulator acc) const
  {
    TraverseFun lambda = [&](const Data& data) {
      acc = fun(data, acc);
    };
    Traverse(
      lambda
    );
    return acc;
  }

  template <typename Data>
  inline bool TraversableContainer<Data>::Exists(const Data& value) const noexcept
  {
    bool exists = false;
    TraverseFun lambda = [&](const Data& data) {
      if(value == data)
      {
        exists = true;
        return;
      }
    };

    Traverse(lambda);

    return exists;
  }

  /**************************************************************************************************************/

  template <typename Data>
  template <typename Accumulator>
  Accumulator PreOrderTraversableContainer<Data>::PreOrderFold(FoldFun<Accumulator> fun, Accumulator acc) const
  {
    TraverseFun lambda = [&](const Data& data) {
      acc = fun(data, acc);
    };
    PreOrderTraverse(lambda
    );
    return acc;
  }

  template <typename Data>
  void PreOrderTraversableContainer<Data>::Traverse(TraverseFun fun) const
  {
    PreOrderTraverse(fun);
  }

  /**************************************************************************************************************/

  template <typename Data>
  template <typename Accumulator>
  Accumulator PostOrderTraversableContainer<Data>::PostOrderFold(FoldFun<Accumulator> fun, Accumulator acc) const
  {
    TraverseFun lambda = [&](const Data& data) {
      acc = fun(data, acc);
    };
    PostOrderTraverse(
      lambda
    );
    return acc;
  }

  template <typename Data>
  void PostOrderTraversableContainer<Data>::Traverse(TraverseFun fun) const
  {
    PostOrderTraverse(fun);
  }

}
