
#include "heapvec.hpp"

namespace lasd 
{

    template <typename Data>
    void HeapVec<Data>::DownHeap(uint index) 
    {
      uint left = 2 * index + 1;
      uint right = 2 * index + 2;
      uint largest = index;
    
      if (left < size && buffer[left] > buffer[largest]) 
      {
        largest = left;
      }

      if (right < size && buffer[right] > buffer[largest]) 
      {
        largest = right;
      }

      if (largest != index) 
      {
        std::swap(buffer[index], buffer[largest]);
        DownHeap(largest);
      }
    }

    template <typename Data>
    void HeapVec<Data>::BuildHeap() 
    {
        if (size == 0) return;
        
        for (ulong i = (size / 2) - 1; i < size; --i) 
        {
            DownHeap(i);
        }
    }

    template <typename Data>
    HeapVec<Data>::HeapVec(const TraversableContainer<Data>& container) 
    {
        this->Resize(container.Size());

        unsigned long i = 0;
        container.Traverse([this, &i](const Data& val) {
            (*this)[i++] = val;
        });

        BuildHeap();
    }

    template <typename Data>
    HeapVec<Data>::HeapVec(MappableContainer<Data>&& container) 
    {
        this->Resize(container.Size());

        unsigned long i = 0;
        container.Map([this, &i](Data& val) {
            (*this)[i++] = std::move(val);
        });

        BuildHeap();
    }

    template <typename Data>
    HeapVec<Data>::HeapVec(const HeapVec<Data>& other) : Vector<Data>(other) {}

    template <typename Data>
    HeapVec<Data>::HeapVec(HeapVec<Data>&& other) noexcept : Vector<Data>(std::move(other)) {}

    template <typename Data>
    HeapVec<Data>& HeapVec<Data>::operator=(const HeapVec<Data>& other) 
    {
        Vector<Data>::operator=(other);
        return *this;
    }

    template <typename Data>
    HeapVec<Data>& HeapVec<Data>::operator=(HeapVec<Data>&& other) 
    {
        Vector<Data>::operator=(std::move(other));
        return *this;
    }

    template <typename Data>
    bool HeapVec<Data>::operator==(const HeapVec<Data>& other) const noexcept 
    {
        return Vector<Data>::operator==(other);
    }

    template <typename Data>
    bool HeapVec<Data>::operator!=(const HeapVec<Data>& other) const noexcept 
    {
        return !(*this == other);
    }

    template <typename Data>
    bool HeapVec<Data>::IsHeap() const noexcept 
    {
        for (uint i = 0; i < size / 2; ++i) 
        {
            uint left = 2 * i + 1;
            uint right = 2 * i + 2;
            if (left < size && buffer[i] < buffer[left]) return false;
            if (right < size && buffer[i] < buffer[right]) return false;
        }
        return true;
    }

    template <typename Data>
    void HeapVec<Data>::Heapify() 
    {
        BuildHeap();
    }

    template <typename Data>
    void HeapVec<Data>::Sort() noexcept
    {
        BuildHeap();

        for (uint i = size - 1; i > 0; --i) 
        {
            std::swap(buffer[0], buffer[i]);
            uint tempSize = i;
            uint index = 0;

            while (true) 
            {
                uint left = 2 * index + 1;
                uint right = 2 * index + 2;
                uint largest = index;

                if (left < tempSize && buffer[left] > buffer[largest]) {
                    largest = left;
                }
                if (right < tempSize && buffer[right] > buffer[largest]) {
                    largest = right;
                }
                if (largest == index) break;

                std::swap(buffer[index], buffer[largest]);
                index = largest;
            }
        }
    }

    template <typename Data>
    void HeapVec<Data>::Clear() {
        Vector<Data>::Clear();
    }

}
