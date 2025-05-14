
#include "linear.hpp"

namespace lasd {

    template<typename Data>
    bool LinearContainer<Data>::operator==(const LinearContainer<Data>& other) const noexcept 
    {
      if (this->size == other.size) {
        for (ulong index = 0; index < this->size; ++index) {
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
    void LinearContainer<Data>::PreOrderTraverse(TraverseFun fun) const
    {
        for (ulong i = 0; i < this->size; i++)
        {
            fun(operator[](i));
        }
    }
  

    template <typename Data>
    void LinearContainer<Data>::PostOrderTraverse(TraverseFun fun) const
    {
      if(this->size == 0)
        return;

      for (ulong i = this->size; i-- > 0;)
      {
        
          fun(operator[](i));
      }
    }

    template <typename Data>
    void LinearContainer<Data>::Traverse(TraverseFun fun) const
    {
        PreOrderTraverse(fun);
    }

    /* ************************************************************************** */

    template<typename Data>
    void MutableLinearContainer<Data>::Map(MapFun fun)
    {
        PreOrderMap(fun);
    }

    template<typename Data>
    void MutableLinearContainer<Data>::PreOrderMap(MapFun fun)
    {
      for (ulong i = 0; i < this->size; i++)
      {
        fun(operator[](i));
      }
    }

    template<typename Data>
    void MutableLinearContainer<Data>::PostOrderMap(MapFun fun)
    {
      if(this->size == 0)
        return;

      for (ulong i = this->size; i-- > 0;)
      {
        
          fun(operator[](i));
      }
    }

    /* ************************************************************************** */

    template<typename Data>
    void SortableLinearContainer<Data>::Sort() noexcept 
    {
      QuickSort(0, this->size - 1);
    }

    template<typename Data>
    void SortableLinearContainer<Data>::QuickSort(ulong p, ulong r) noexcept 
    {
      if (p < r) {
        ulong q = Partition(p, r);
        QuickSort(p, q);
        QuickSort(q + 1, r);
      }
    }

    template<typename Data>
    ulong SortableLinearContainer<Data>::Partition(ulong p, ulong r) noexcept 
    {
      Data x = this->operator[](p);
      ulong i = p - 1;
      ulong j = r + 1;
      do {
        do { j--; }
        while (x < this->operator[](j));
        do { i++; }
        while (x > this->operator[](i));
        if (i < j) { std::swap(this->operator[](i), this->operator[](j)); }
      }
      while (i < j);
      return j;
    }

}
