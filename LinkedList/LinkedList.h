#pragma once
template<class T>
class LinkedList
{

public:

    struct Node
    {
        T value;
        Node* next = nullptr;
        Node* prev = nullptr;
    };

    struct Iterator
    {
        Node* node = nullptr;

        // Constructors
        Iterator() : node(nullptr) {}
        Iterator(Node* node) : node(node) {}

            // Increment operators
        Iterator& operator ++ () { return Next(); }
        Iterator& operator ++ (int) { return Next(); }

            // Decrement operators
        Iterator& operator -- () { return Prev(); }
        Iterator& operator -- (int) { return Prev(); }

            // Equality chek operators
        bool operator == (const Iterator& rhs) { return node == rhs.node; }
        bool operator != (const Iterator& rhs) { return node != rhs.node; }

            // Dereference operators
        T& operator * () { return node->value; }
        T* operator -> () { return &node->value; }

            // Move to the next value
        Iterator& Next()
        {
            if (node != nullptr)
                node = node->next;

            return *this;
        }

            // move to the previous value
        Iterator& Prev()
        {
            if (node != nullptr)
                node = node->prev;

            return *this;
        }
    };

    LinkedList()
    {

    }

    ~LinkedList()
    {
        // TODO:
        // cleanup the list - delete the nodes
    }

    LinkedList(std::initializer_list<T> list)
    {
        for (auto iter = list.begin(); iter != list.end(); iter++)
            PushBack(*iter);
    }

    Iterator Remove(Iterator iter)
    {
        Node* nodeToRemove = iter.node;
        Node* nextNode = nodeToRemove->next;

        if (nodeToRemove == m_first)
        {
            PopFront();
        }
        else if (nodeToRemove == m_last)
        {            
            PopBack();
        }
        else
        {
            nodeToRemove->next->prev = nodeToRemove->prev;
            nodeToRemove->prev->next = nodeToRemove->next;
            delete nodeToRemove;
        }

        return Iterator(nextNode);
    }

    Iterator Insert(Iterator iter, const T& value)
    {
        Node* currentNode = iter.node;

        Node* newNode = new Node();
        newNode->value = value;

        if (iter == begin())
        {
            PushFront(value);
            return 0;
        }
        else if (iter == end())
        {
            PushBack(value);
            return 0;
        }
        else
        {
            currentNode->prev->next = newNode;
            newNode->next = currentNode;
            newNode->prev = currentNode->prev;
            currentNode->prev = newNode;
            return Iterator(newNode);
        }
        
    }

    unsigned int Count()
    {
        int count = 0;

        Node* temp = m_first;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void NewNode(T value)
    {
        Node* n = new Node();
        n->value = value;
        n->next = nullptr;
        n->prev = nullptr;

        m_first = n;
        m_last = n;
    }

    void PushBack(T value) //adds to back
    {
        if (m_first == nullptr && m_last == nullptr)
        {
            NewNode(value);
        }
        else
        {
            Node* n = new Node();
            n->value = value;
            n->next = nullptr;
            n->prev = nullptr;

            n->prev = m_last;
            m_last->next = n;
            m_last = n;
        }
    }

    void PopBack() //remove from back
    {
        if (m_first == m_last)
        {
            delete m_last;
            m_first = nullptr;
            m_last = nullptr;            
        }
        else if (m_first != nullptr && m_last != nullptr)
        {
            m_last = m_last->prev;

            delete m_last->next;
            m_last->next = nullptr;
        }
    }

    void PushFront(T value) //adds to front
    {
        if (m_first == nullptr && m_last == nullptr)
        {
            NewNode(value);
        }
        else
        {
            Node* n = new Node();
            n->value = value;
            n->next = nullptr;
            n->prev = nullptr;

            n->next = m_first;
            m_first->prev = n;
            m_first = n;
        }
    }

    void PopFront() //remove from front
    {
        if (m_first == m_last)
        {
            delete m_first;
            m_first = nullptr;
            m_last = nullptr;
        }
        else if (m_first != nullptr && m_last != nullptr)
        {
            m_first = m_first->next;

            delete m_first->prev;
            m_first->prev = nullptr;
        }
    }

    void Sort()
    {
        bool isSorted = false;
        while (!isSorted)
        {
            isSorted = true;
            for (auto iter = begin(); iter != end() && iter.node != m_last; iter++)
            {                
                auto nextIter = Iterator(iter).Next();

                T& current = *iter;
                T& next = *nextIter;

                if (current > next)
                {
                    Swap(iter, nextIter);
                    isSorted = false;
                }
            }
        }
    }

    void Swap(Iterator a, Iterator b)
    {
        if (a.node->prev != nullptr)
        {
            a.node->prev->next = b.node;
        }

        b.node->prev = a.node->prev;

        if (b.node->next != nullptr)
        {
            b.node->next->prev = a.node;
        }

        a.node->next = b.node->next;

        a.node->prev = b.node;
        b.node->next = a.node;

        if (b.node->prev == nullptr)
        {
            m_first = b.node;
        }
        if (a.node->prev == nullptr)
        {
            m_first = a.node;
        }
        if (b.node->next == nullptr)
        {
            m_last = b.node;
        }
        if (a.node->next == nullptr)
        {
            m_last = a.node;
        }
        
    }

    void Clear()
    {
        while (!IsEmpty())
        {
            PopBack();            
        }
    }

    bool IsEmpty()
    {
        return m_last == nullptr && m_first == nullptr;
    }

    Node* FirstNode() { return m_first; }
    Node* LastNode() { return m_last; }

    Iterator begin() { return Iterator(m_first); }
    Iterator end() { return Iterator(nullptr); }

protected:

private:

    Node* m_first = nullptr;
    Node* m_last = nullptr;

};
