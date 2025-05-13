#include "dictionary.hpp"

#include <stdexcept>

namespace lasd {

    template <typename Data>
    inline bool DictionaryContainer<Data>::InsertAll(const TraversableContainer<Data>& container)
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
    inline bool DictionaryContainer<Data>::InsertSome(const TraversableContainer<Data>& container)
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
}