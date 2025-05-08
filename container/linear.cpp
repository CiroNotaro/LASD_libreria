
#include "linear.hpp"

namespace lasd {

    template<typename Data>
    bool LinearContainer<Data>::operator==(const LinearContainer<Data>& other) const noexcept 
    {
      if (size == other.size) {
        for (ulong index = 0; index < size; ++index) {
          if (operator[](index) != other.operator[](index)) {
            return false;
          }
        }
        return true;
      } else {
        return false;
      }
    }
    
    template<typename Data>
    inline bool LinearContainer<Data>::operator!=(const LinearContainer<Data>& other) const noexcept 
    {
      return !(*this == other);
    }

    template <typename Data>
    void LinearContainer<Data>::PreOrderTraverse(TraverseFun& fun) const
    {
        PreOrderTraverse(fun);
    }
  

    template <typename Data>
    void LinearContainer<Data>::PostOrderTraverse(TraverseFun& fun) const
    {
        PostOrderTraverse(fun);
    }

    template <typename Data>
    void LinearContainer<Data>::Traverse(TraverseFun& fun) const
    {
        PreOrderTraverse(fun);
    }

    template<typename Data>
    inline void LinearContainer<Data>::PreOrderTraverse(TraverseFun& fun) const
    {
        for (ulong i = 0; i < size; i++) {
          fun(operator[](i));
        }
    }

    template<typename Data>
    inline void LinearContainer<Data>::PostOrderTraverse(TraverseFun& fun) const
    {
        for (ulong i = size-1; i >= 0; i--)
        {
          fun(operator[](i));
        }
    }

    /* ************************************************************************** */

    template<typename Data>
    void MutableLinearContainer<Data>::Map(MapFun& fun) const
    {
        PreOrderMap(fun);
    }

    template<typename Data>
    void MutableLinearContainer<Data>::PreOrderMap(MapFun& fun) const
    {
      for (ulong i = 0; i < size; i++) 
      {
        fun(operator[](i));
      }
    }

    template<typename Data>
    void MutableLinearContainer<Data>::PostOrderMap(MapFun& fun) const
    {
        for (ulong i = size-1; i >= 0; i--)
        {
            fun(operator[](i));
        }
    }

    /* ************************************************************************** */

    template<typename Data>
    void SortableLinearContainer<Data>::Sort() noexcept
    {
      for (ulong i = 0; i < size-1; i++)
      {
        ulong minIndex = i;

        for (ulong j = i+1; j < size; j++)
        {
          if(operator[](j) < operator[](minIndex))
          {
            minIndex = j
          }
        }

        Data tmp = operator[](i);             // tmp = a
        operator[](i) = operator[](minIndex); // a = b
        operator[](minIndex) = tmp;           // b = a
      }
    }

}
