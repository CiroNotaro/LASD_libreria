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
    Vector<Data>::Vector(const TraversableContainer<Data>& traversableContainer) : Vector(traversableContainer.Size())
    {
        ulong i = 0;
        traversableContainer.Traverse(
            [&](const Data& data)
            {
                buffer[i] = data;
                i++;
            }
        );
    }

    template <typename Data>
    Vector<Data>::Vector(MappableContainer<Data>&& mappableContainer) : Vector(mappableContainer.Size())
    {
        ulong i = 0;
        mappableContainer.Map(
            [&](Data& data)
            {
                buffer[i] = std::move(data);
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

    template<typename Data>
    Vector<Data>::~Vector() {
        delete[] buffer;
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
        if (size == 0)
            throw std::length_error("The vector is not allocated!");

        return buffer[0];
    }

    template <typename Data>
    Data& Vector<Data>::Back()
    {
        if (size == 0)
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
        if (size == 0)
            throw std::length_error("The vector is not allocated!");

        return buffer[0];
    }

    template <typename Data>
    const Data& Vector<Data>::Back() const
    {
        if (size == 0)
            throw std::length_error("The vector is not allocated!");

        return buffer[size-1];
    }

    template <typename Data>
    void Vector<Data>::Resize(ulong size)
    {
        if (size == 0) {
            Clear();
        } else if (this->size != size) {
            Data * tmp = new Data[size] {};
            ulong minsize = (this->size < size) ? this->size : size;
            for (ulong index = 0; index < minsize; ++index) {
                std::swap(buffer[index], tmp[index]);
            }
            std::swap(buffer, tmp);
            this->size = size;
            delete[] tmp;
        }
    }

    template <typename Data>
    inline void Vector<Data>::Clear()
    {
        delete[] buffer;
        buffer = nullptr;
        size = 0;
    }

    /************************** */

    template<typename Data>
SortableVector<Data>::SortableVector(const ulong size) 
    : Vector<Data>(size) {}

template<typename Data>
SortableVector<Data>::SortableVector(const TraversableContainer<Data>& other) 
    : Vector<Data>(other) {}

template<typename Data>
SortableVector<Data>::SortableVector(MappableContainer<Data>&& other) 
    : Vector<Data>(std::move(other)) {}

template<typename Data>
SortableVector<Data>::SortableVector(const SortableVector<Data>& other) 
    : Vector<Data>(other) {}

template<typename Data>
SortableVector<Data>::SortableVector(SortableVector<Data>&& other) 
    : Vector<Data>(std::move(other)) {}

template<typename Data>
SortableVector<Data>& SortableVector<Data>::operator=(const SortableVector<Data>& other) 
{
    Vector<Data>::operator=(other);
    return *this;
}

template<typename Data>
SortableVector<Data>& SortableVector<Data>::operator=(SortableVector<Data>&& other)
{
    Vector<Data>::operator=(std::move(other));
    return *this;
}


}
