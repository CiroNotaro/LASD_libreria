#include "traversable.hpp"

namespace lasd {

    template <typename Data>
    template <typename Accumulator>
    Accumulator TraversableContainer<Data>::Fold(FoldFun<Accumulator> fun, Accumulator acc) const
    {
        Traverse(
            [&](const Data& data) {
              acc = fun(data, acc);
            }
          );
        return acc;
    }

    template <typename Data>
    inline bool TraversableContainer<Data>::Exists(const Data& value) const noexcept
    {
        bool exists = false;
        Traverse([&](const Data& data){
            if(value == data)
            {
                exists = true;
                return;
            }
        });

        return exists;
    }

    /**************************************************************************************************************/
    
    template <typename Data>
    template <typename Accumulator>
    Accumulator PreOrderTraversableContainer<Data>::PreOrderFold(FoldFun<Accumulator> fun, Accumulator acc)
    {
        PreOrderTraverse(
            [&](const Data& data) {
              acc = fun(data, acc);
            }
          );
          return acc;
    }

    template <typename Data>
    void PreOrderTraversableContainer<Data>::Traverse(TraverseFun& fun)
    {
        PreOrderTraverse(fun);
    }

    /**************************************************************************************************************/

    template <typename Data>
    template <typename Accumulator>
    Accumulator PostOrderTraversableContainer<Data>::PostOrderFold(FoldFun<Accumulator> fun, Accumulator acc)
    {
        PostOrderTraverse(
            [&](const Data& data) {
              acc = fun(data, acc);
            }
          );
          return acc;
    }

    template <typename Data>
    void PostOrderTraversableContainer<Data>::Traverse(TraverseFun& fun)
    {
        PostOrderTraverse(fun);
    }

}