#include "dictionary.hpp"

#include <stdexcept>

namespace lasd {

    template <typename Data>
    inline bool DictionaryContainer<Data>::InsertAll(const TraversableContainer<Data> container)
    {
        bool flag = true;
        
        container.Traverse(
            [&](const Data& value){
                flag &= Insert(value);
            }
        );
        
        return flag;
    }

    template <typename Data>
    inline bool DictionaryContainer<Data>::InsertAll(MappableContainer<Data>&& container)
    {
        bool flag = true;
        
        container.Map(
            [&](Data& value){
                flag &= Insert(value);
            }
        );
        
        return flag;
    }
    
    template <typename Data>
    inline bool DictionaryContainer<Data>::RemoveAll(const TraversableContainer<Data>& container)
    {
        bool flag = true;
        
        container.Traverse(
            [&](const Data& value){
                flag &= Remove(value);
            }
        );
        
        return flag;
    }

    template <typename Data>
    inline bool DictionaryContainer<Data>::InsertSome(const TraversableContainer<Data> container)
    {
        bool flag = false;
        
        container.Traverse(
            [&](const Data& value){
                flag |= Insert(value);
            }
        );
        
        return flag;
    }

    template <typename Data>
    inline bool DictionaryContainer<Data>::InsertSome(MappableContainer<Data>&& container)
    {
        bool flag = false;
        
        container.Map(
            [&](Data& value){
                flag |= Insert(value);
            }
        );
        
        return flag;
    }
    
    template <typename Data>
    inline bool DictionaryContainer<Data>::RemoveSome(const TraversableContainer<Data>& container)
    {
        bool flag = false;
        
        container.Traverse(
            [&](const Data& value){
                flag |= Remove(value);
            }
        );
        
        return flag;
    }

    /**************************************************************************************************************/

    template <typename Data>
    Data OrderedDictionaryContainer<Data>::Min() const
    {
        if(Empty())
            throw std::length_error("The container is empty!");

        Data min;
        ulong i = 0;
        Traverse([&](const Data& data)
        {
            if(i == 0) min = data;

            if(data < min)
            {
                min = data;
            }

            i++;
        });

        return min;
    }

    template <typename Data>
    Data OrderedDictionaryContainer<Data>::MinNRemove()
    {
        if(Empty())
            throw std::length_error("The container is empty!");
    }

    template <typename Data>
    void OrderedDictionaryContainer<Data>::RemoveMin()
    {
        if(Empty())
            throw std::length_error("The container is empty!");
    }

    template <typename Data>
    Data OrderedDictionaryContainer<Data>::Max() const
    {
        if(Empty())
            throw std::length_error("The container is empty!");

        Data max;
        ulong i = 0;
        Traverse([&](const Data& data)
        {
            if(i == 0) max = data;

            if(data > max)
            {
                max = data;
            }

            i++;
        });

        return max;
    }

    template <typename Data>
    Data OrderedDictionaryContainer<Data>::MaxNRemove()
    {
        if(Empty())
            throw std::length_error("The container is empty!");
    }

    template <typename Data>
    void OrderedDictionaryContainer<Data>::RemoveMax()
    {
        if(Empty())
            throw std::length_error("The container is empty!");
    }

    template <typename Data>
    Data OrderedDictionaryContainer<Data>::Predecessor(Data& value) const
    {
        Data x;
        ulong i = 0;
        Traverse([&](const Data& data)
        {
            if(x == data)
                return;

            i++;
        });

        ulong count = 0;
        Traverse([&](const Data& data)
        {
            if(i-1 == count)
            {
                x = data;
                return;
            }

            if(cout >= size)
            {
                throw std::length_error("Predecessor not found!");
            }

            count++;
        });

        return x;
    }

    template <typename Data>
    Data OrderedDictionaryContainer<Data>::PredecessorNRemove(Data& value)
    {

    }

    template <typename Data>
    void OrderedDictionaryContainer<Data>::RemovePredecessor(Data& value)
    {

    }

    template <typename Data>
    Data OrderedDictionaryContainer<Data>::Successor(Data& value) const
    {
        Data x;
        ulong i = 0;
        Traverse([&](const Data& data)
        {
            if(x == data)
                return;

            i++;
        });

        ulong count = 0;
        Traverse([&](const Data& data)
        {
            if(i+1 == count)
            {
                x = data;
                return;
            }

            if(cout >= size)
            {
                throw std::length_error("Successor not found!");
            }

            count++;
        });

        return x;
    }

    template <typename Data>
    Data OrderedDictionaryContainer<Data>::SuccessorNRemove(Data& value)
    {

    }

    template <typename Data>
    void OrderedDictionaryContainer<Data>::RemoveSuccessor(Data& value)
    {

    }
}