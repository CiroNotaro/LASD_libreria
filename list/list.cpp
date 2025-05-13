#include "list.hpp"

#include <stdexcept>

namespace lasd {

    template<typename Data>
    List<Data>::Node::Node(Node&& node)
    {
        std::swap(value, node.value);
        std::swap(next, node.next);
    }

    template<typename Data>
    List<Data>::Node::~Node()
    {
        delete next;
    }

    template<typename Data>
    typename List<Data>::Node * List<Data>::Node::Clone(Node* tail) {
        if (next == nullptr) {
            return tail;
        } else {
            Node* node = new Node(value);
            node->next = next->Clone(tail);
            return node;
        }
    }

    /******************************************************************* */

    template<typename Data>
    List<Data>::List(const TraversableContainer<Data>& other)
    {
        Traverse([&](const Data& data)
        {
            InsertAtBack(data);
        });
    }

    template<typename Data>
    List<Data>::List(MappableContainer<Data>&& other)
    {
        
        Map([&](const Data& data)
        {
            InsertAtBack(data);
        });
    }

    template<typename Data>
    List<Data>::List(const List<Data>& other)
    {
        if (other.tail != nullptr) 
        {
            tail = new Node(*other.tail);
            head = other.head->Clone(tail);
            size = other.size;
        }
    }

    template<typename Data>
    List<Data>::List(List<Data>&& other)
    {
        std::swap(tail, other.tail);
        std::swap(head, other.head);
        std::swap(size, other.size);
    }

    template<typename Data>
    List<Data>& List<Data>::operator=(const List<Data>& other)
    {
        if(this != &other)
        {
            Clear();

            if(other.tail != nullptr)
            {
                tail = new Node(*other.tail);
                head = other.head->Clone(tail);
                size = other.size;
            }
        }

        return *this;
    }

    template<typename Data>
    List<Data>& List<Data>::operator=(List<Data>&& other)
    {
        std::swap(head, other.head);
        std::swap(tail, other.tail);
        std::swap(size, other.size);
        return *this;
    }

    template<typename Data>
    bool List<Data>::operator==(const List<Data>& other) const noexcept
    {
        return (size == other.size) && (head == other.head);
    }
    
    template<typename Data>
    bool List<Data>::operator!=(const List<Data>& other) const noexcept
    {
        return !(*this == other);
    }

    template<typename Data>
    void List<Data>::InsertAtFront(const Data& value)
    {
        Node* node = new Node(value);
        node->next = head;
        head = node;
        if(tail == nullptr)
            tail = head;
        size++;
    }

    template<typename Data>
    void List<Data>::InsertAtFront(Data&& value)
    {
        Node* node = new Node(std::move(value));
        node->next = head;
        head = node;
        if(tail == nullptr)
            tail = head;
        size++;
    }

    template<typename Data>
    void List<Data>::RemoveFromFront()
    {
        Node* newHead = head->next;
        delete head;
        head = newHead;
        size--;
    }

    template<typename Data>
    Data List<Data>::FrontNRemove()
    {
        Data data = head->value;
        Node* newHead = head->next;
        delete head;
        head = newHead;
        size--;
        return data;
    }

    template<typename Data>
    void List<Data>::InsertAtBack(const Data& value)
    {
        Node* newTail = new Node(value);

        if(tail != nullptr)
            tail->next = newTail;

        tail = newTail;
        size++;
    }

    template<typename Data>
    void List<Data>::InsertAtBack(Data&& value)
    {
        Node* newTail = new Node(std::move(value));

        if(tail != nullptr)
            tail->next = newTail;
            
        tail = newTail;
        size++;
    }

    template<typename Data>
    void List<Data>::RemoveFromBack()
    {
        if(tail == nullptr){ throw std::length_error("Empty list!");}

        Node* current = head;
        while(current->next != tail)
            current = current->next;
        
        delete tail;
        current->next = nullptr;
        size--;
    }

    template<typename Data>
    Data List<Data>::BackNRemove()
    {
        if(tail == nullptr){ throw std::length_error("Empty list!");}

        Data data = tail->value;

        Node* current = head;
        while(current->next != tail)
            current = current->next;
        
        delete tail;
        current->next = nullptr;
        size--;
        return data;
    }

    template<typename Data>
    Data& List<Data>::operator[](const ulong index) 
    {
        if(index >= size)
            throw std::out_of_range("index is out of range!");

        ulong i = 0;
        Node* current = head;

        while(current != nullptr)
        {
            if(i == index) 
                return head->value;
            current = current->next;
            i++;
        }
    }

    template<typename Data>
    Data& List<Data>::Front() 
    {
        return head->value;
    }

    template<typename Data>
    Data& List<Data>::Back() 
    {
        return tail->value;
    }

    template<typename Data>
    const Data& List<Data>::operator[](const ulong index) const
    {
        if(index >= size)
        throw std::out_of_range("index is out of range!");

        ulong i = 0;
        Node* current = head;

        while(current != nullptr)
        {
            if(i == index) 
                return head->value;
            current = current->next;
            i++;
        }

        return head->value;
    }

    template<typename Data>
    const Data& List<Data>::Front() const 
    {
        return head->value;
    } 

    template<typename Data>
    const Data& List<Data>::Back() const
    {
        return tail->value;
    }

    template<typename Data>
    void List<Data>::Map(MapFun fun)
    {
        PreOrderMap(fun, head);
    }

    template<typename Data>
    void List<Data>::PreOrderMap(MapFun fun)
    {
        PreOrderMap(fun, head);
    }

    template<typename Data>
    void List<Data>::PostOrderMap(MapFun fun)
    {
        PostOrderMap(fun, head);
    }

    template<typename Data>
    void List<Data>::Traverse(TraverseFun fun) const
    {
        PreOrderTraverse(fun, head);
    }

    template<typename Data>
    void List<Data>::PreOrderTraverse(TraverseFun fun) const 
    {
        PreOrderTraverse(fun, head);
    }

    template<typename Data>
    void List<Data>::PostOrderTraverse(TraverseFun fun) const
    {
        PostOrderTraverse(fun, head);
    }

    template<typename Data>
    inline void List<Data>::Clear() 
    {
        // TODO DEALLOCA

        delete head;
        head = tail = nullptr;
        size = 0;
    }

    template<typename Data>
    void List<Data>::PreOrderTraverse(TraverseFun fun, const Node* node) const
    {
        while(node != nullptr) 
        {
            fun(node->value);
            node = node->next;
        }
    }

    template<typename Data>
    void List<Data>::PostOrderTraverse(TraverseFun fun, const Node* node) const
    {
        if(node != nullptr) 
        {
            PostOrderTraverse(fun, node->next);
            fun(node->value);
        }
    }

    template<typename Data>
    void List<Data>::PreOrderMap(MapFun fun, Node* node)
    {
        while(node != nullptr) 
        {
            fun(node->value);
            node = node->next;
        }
    }

    template<typename Data>
    void List<Data>::PostOrderMap(MapFun fun, Node* node)
    {
        if(node != nullptr) 
        {
            PostOrderMap(fun, node->next);
            fun(node->value);
        }
    }

}
