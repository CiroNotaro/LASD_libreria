#include "vector.hpp"

namespace lasd 
{

    template <typename Data>
    Vector<Data>::Vector(const ulong size)
    {
        this->size = size;
        buffer = new Data[size];
    }

    template <typename Data>
    Vector<Data>::Vector(const TraversableContainer<Data>& traversableContainer)
    {
        this->size = traversableContainer.Size();
        buffer = new Data[this->size];
        ulong i = 0;
        Traverse(
            [&](const Data& data)
            {
                buffer[i] = data;size < newsize
                i++;
            }
        );
    }

    template <typename Data>
    Vector<Data>::Vector(const MappableContainer<Data>& mappableContainer)
    {
        this->size = mappableContainer.Size();
        buffer = new Data[this->size];
        ulong i = 0;
        Map(
            [&](const Data& data)
            {
                buffer[i] = data;
                i++;
            }
        );
    }

    template <typename Data>
    Vector<Data>::Vector(const Vector<Data>& other)
    {
        size = other.size;
        buffer = new Data[size];
        std::copy(other.buffer, other.buffer + size, buffer);
    }

    template <typename Data>
    Vector<Data>::Vector(Vector<Data>&& other)
    {
        std::swap(size, other.size);
        std::swap(buffer, other.buffer);
    }

    template <typename Data>
    Vector<Data>& Vector<Data>::operator=(const Vector<Data>& other)
    {
        Vector<Data>* tmp = new Vector<Data>(other);
        std::swap(*tmp, *this);
        delete tmp;
        return *this;
    }

    template <typename Data>
    Vector<Data>& Vector<Data>::operator=(Vector<Data>&& other)
    {
        std::swap(size, other.size);
        std::swap(buffer, other.buffer);
        return *this;
    }

    template <typename Data>
    bool Vector<Data>::operator==(const Vector<Data>& other) const noexcept
    {
        if(size != other.size) return false;

        for(ulong i = 0; i < size; i++)
        {
            if(buffer[i] != other.buffer[i])
                return false;
        }

        return true;
    }

    template <typename Data>
    bool Vector<Data>::operator!=(const Vector<Data>& other) const noexcept
    {
        return !(*this == other);
    }

    template <typename Data>
    Data& Vector<Data>::operator[](const ulong index) 
    {
        if(index >= size)
            throw std::out_of_range("index >= size");

        return buffer[index];
    }

    template <typename Data>
    Data& Vector<Data>::Front()
    {
        if(buffer == nullptr)
            throw std::length_error("The vector is not allocated!");

        return buffer[0];
    }

    template <typename Data>
    Data& Vector<Data>::Back()
    {
        if(buffer == nullptr)
            throw std::length_error("The vector is not allocated!");

        return buffer[size-1];
    }

    template <typename Data>
    const Data& Vector<Data>::operator[](const ulong index) const
    {
        if(index >= size)
            throw std::out_of_range("index >= size");

        return buffer[index];
    }

    template <typename Data>
    const Data& Vector<Data>::Front() const
    {
        if(buffer == nullptr)
        t   hrow std::length_error("The vector is not allocated!");

        return buffer[0];
    }

    template <typename Data>
    const Data& Vector<Data>::Back() const
    {
        if(buffer == nullptr)
            throw std::length_error("The vector is not allocated!");

        return buffer[size-1];
    }

    template <typename Data>
    void Vector<Data>::Resize(ulong size)
    {
        if(size == 0)
        {
            Clear();
        }else{
            Data* newBuffer = new Data[size];
            for(ulong i = 0; i < size; i++)
                newBuffer[i] = buffer[i];
            delete[] buffer;
            buffer = newBuffer;
            this->size = size;
        }
    }

    template <typename Data>
    inline void Vector<Data>::Clear()
    {
        delete[] buffer;
        buffer = nullptr;
        size = 0;
    }

}
