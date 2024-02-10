#include <iostream>

class Node
{
    friend class Iterator;
    friend class MyList;
    private:
    Node * prev = nullptr;
    int data = 0;
    Node * next = nullptr;

   public:
   Node();
   Node(int int_data);
   ~ Node();
};


class Iterator
{
    private:
    Node* it = nullptr;

    public:
    Iterator();
    Iterator(Node* node);
    Iterator(const Iterator& iter);
    ~ Iterator();
    Node* get_it();
    int operator*();
    Iterator& operator++();
    Iterator& operator--();
    bool operator==(Iterator &rhs) const;
    bool operator!=( Iterator &rhs) const;
    Iterator& operator=(const Iterator &rhs);
    Iterator& operator+(const int& num);
    Iterator& operator-(const int& num);





};

class MyList
{
    friend class Iterator;
    private:
    Node * start;
    Node * endol;

    public:

    MyList(const std::initializer_list<int> &args);
    MyList();
    ~MyList();

    Iterator begin();
    Iterator end();
    void push_front(const int list_member);
    void push_back(const int list_member);
    int front();
    int back();
    int size();
    bool empty();
    Iterator erase(Iterator& node_to_erase);
    void pop_front();
    void pop_back();



};