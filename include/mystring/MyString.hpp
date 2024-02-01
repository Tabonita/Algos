#pragma once
#include <iostream>
#include <cstring>

class MyString 
{
    private:
    char * str;
    public:
    friend std::ostream& operator<< (std::ostream& os, const MyString & s);
    MyString();
    MyString(const char &c);
    MyString (const char * other);
    MyString(const MyString& source);
    MyString(MyString &&source);
    ~MyString();
    char& at (int index);
    char& operator[](int index);
    char * c_str() const;
    size_t size() const;
    char back() const;
    char front() const;
    bool empty () const;
    MyString& substr(int pos, size_t len) ;
    bool starts_with(const MyString& part_str) const;
    bool ends_with(const MyString& part_str) const;
    void push_back(char c);
    MyString& operator+=( const MyString & other);
    MyString& operator+( const MyString & other);
    MyString& operator+(const char & c);
    std::ostream& operator<< (std::ostream& os);
    MyString& operator=(MyString & source);
    MyString& operator=(MyString && source);
    bool operator==( MyString &source);
    bool operator==(MyString &&source);


};