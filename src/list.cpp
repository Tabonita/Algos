#include <my_list/list.hpp>

 Node::Node():prev{nullptr},data{0},next{nullptr}{
     };
Node::Node(int int_data):prev{nullptr},data{int_data},next{nullptr}{
    }
Node::~ Node(){
        }



Iterator::Iterator():it{nullptr}{};

Iterator::Iterator(Node* node):it{node}{};
Iterator::Iterator(const Iterator& iter){
        this->it = new Node;
        this->it->data = iter.it->data;
        this->it->next = iter.it->next;
        this->it->prev = iter.it->prev;
};

Node* Iterator::get_it()
    {
        return it;
    }

int Iterator::operator*()
    {
        return it->data;
    }

Iterator& Iterator::operator++()
    {
        if (it->next!=nullptr)
        {
            it = it->next;
        }
        return *this;
    }
Iterator& Iterator::operator--()
    {
        if (it->prev!=nullptr)
        {
            it = it->prev;
        }
        return *this;
    }

bool Iterator::operator==(Iterator &rhs) const
    {
        return (this->it->data == rhs.it->data && this->it->prev == rhs.it->prev && this->it->next == rhs.it->next);
    }

bool Iterator::operator!=(Iterator &rhs) const
    {
        return (this->it->data != rhs.it->data || this->it->prev != rhs.it->prev || this->it->next != rhs.it->next);
    }



Iterator& Iterator::operator=(const Iterator &rhs) 
    {
       if (this == &rhs) 
       {
        return *this; 
       }
        this->it = rhs.it;
        return *this;
    }

Iterator& Iterator::operator+(const int& num)
    {
        int counter = 0;
        while (it->next!=nullptr && counter < num)
            {
                it = it->next;
                counter++;
            }
        return *this;
        
    }
Iterator& Iterator::operator-(const int& num)
{
        int counter = 0;
        while (it->prev!=nullptr && counter < num)
            {
                it = it->prev;
                counter++;
            }
        return *this;
}

 Iterator::~ Iterator(){

    }

MyList::MyList(const std::initializer_list<int> &args)
   {
        if (args.size() == 0)
        {
            start = new Node;
            start->next = nullptr;
            start->prev = nullptr;
            start->data = 0;
            endol = start;
        }
        else if (args.size() == 1)
        {
            start = new Node(*args.begin());
            endol = new Node(args.size());
            start->prev = nullptr;
            endol->next = nullptr;
            start->next = endol;
            endol->prev = start;

        }
        else if (args.size() == 2)
        {
            std::initializer_list<int>::iterator it = args.begin();
            start = new Node(*it);
            start->prev = nullptr;
            ++it;
            Node * next = new Node (*it);
            start->next =next;
            next->prev = start;
            next->next = endol;
            endol = new Node(2);
            endol->prev = next;
            endol->next = nullptr;
        }
        else 
        {
            start = new Node(*args.begin());
            start->prev = nullptr;
            start->data = *args.begin();

            std::initializer_list<int>::iterator it = args.begin();
            Node * prev = new Node(*(it + 1));
            Node * current = new Node(*(it + 2));
            start->next = prev;
            prev->prev = start;
            prev -> next = current;
            current -> prev = prev;
            for (it = args.begin() + 3; it != args.end(); ++it)
            {
                Node * next = new Node(*(it));
                current->prev = prev;
                prev = current;
                current = next;
                current -> next = next;
                current -> prev = prev;
                prev -> next = current;

            }
            endol = new Node(args.size());
            current->next = endol;
            endol->prev = current;
            endol->next = nullptr;

        }

    }

MyList::MyList()
    {
        start = new Node;
        start->next = nullptr;
        start->prev = nullptr;
        start->data = 0;
        endol = start;
    }


MyList::~MyList()
    {

        if (start->next == nullptr )
        {
            endol = nullptr;
            delete start;
        }
        else if (start->next == endol )
        {
            delete start;
            delete endol;
        }
        else if (start->next->next == endol)
        {
            delete start->next;
            delete start;
            delete endol;
        }
        else
        {
            Node * temp = endol;
            while (true)
            {
                if(endol!=nullptr)
                {
                    endol = endol->prev;
                    delete temp;
                    temp = endol;

                }
                else
                {
                    break;
                }

            }
        }

    }

    Iterator MyList::begin()
    {
        Iterator value_to_return(start);
        return value_to_return;
    }
    Iterator MyList::end()
    {
        Iterator value_to_return(endol);
        return value_to_return;
    }

    void MyList::push_front(const int list_member)
    {
         if (start->next == nullptr ) //size = 0
         {
            start->data = list_member;
            endol = new Node(1);
            start->prev = nullptr;
            endol->next = nullptr;
            start->next = endol;
            endol->prev = start;
        }
        else //size >=1
        {
            Node * new_member = new Node(start->data);
            new_member->next = start->next;
            new_member->prev = start;
            start->next->prev = new_member;
            start->next = new_member;
            start->data = list_member;
            ++endol->data;
        }

    }
    void MyList::push_back(const int list_member)
    {
        if (start->next == nullptr )
        {
            start->data = list_member;
            endol = new Node(1);
            start->prev = nullptr;
            endol->next = nullptr;
            start->next = endol;
            endol->prev = start;
        }
        else
        {
            Node * new_member = new Node(list_member);
            new_member->next = endol;
            new_member->prev = endol->prev;
            endol->prev->next = new_member;
            endol->prev = new_member;
            ++endol->data;
        }

    }

    int MyList::front()
    {
        return start->data;

    }
    int MyList::back()
    {
        if (endol->prev!=nullptr)
        {
            return endol->prev->data;
        }
        else
        {
            return endol->data;
        }
    }

    int MyList::size()
    {
        return endol->data;
    }
    bool MyList::empty()
    {
        return start->next == nullptr;
    }
    Iterator MyList::erase(Iterator& node_to_erase)
    {
        if (node_to_erase.get_it()!=start && node_to_erase.get_it()!=endol)
        {
            Iterator value_to_return = node_to_erase;
            ++value_to_return;
            node_to_erase.get_it()->prev->next = node_to_erase.get_it()->next;
            node_to_erase.get_it()->next->prev = node_to_erase.get_it()->prev;
            node_to_erase.get_it()->next = nullptr;
            node_to_erase.get_it()->prev = nullptr;
            node_to_erase.get_it()->data = 0;
            delete node_to_erase.get_it();
            --endol->data;
            return value_to_return;
        }
        else if (node_to_erase.get_it() == start && node_to_erase.get_it()!=endol)
        {
            start = start->next;
            node_to_erase.get_it()->data = 0;
            delete node_to_erase.get_it();
            start->prev = nullptr;
            Iterator value_to_return(start);
            return value_to_return;
        }
        else
        {
            return node_to_erase;
        }

    }

    void MyList::pop_front()
    {
        if (start->next!=nullptr && start->next!=endol)
        {
            start = start->next;
            delete start->prev;
            start->prev = nullptr;
            --endol->data;

        }
        else if (start->next == endol)
        {
            delete start;
            --endol->data;
            start = endol;
        }
        else
        {
            std::cout<<"The list is empty"<<std::endl;            
        }

    }
    void MyList::pop_back()
    {
        if(endol->prev->prev!=nullptr)
        {
            endol->prev = endol->prev->prev;
            delete endol->prev->next;
            endol->prev->next = endol;
            --endol->data;
        }
        else if (endol -> prev == start)
        {
            delete start;
            --endol->data;
            start = endol;
        }
        else
        {
            std::cout<<"The list is empty"<<std::endl;
        }
    }
