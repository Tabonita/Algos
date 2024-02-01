 #include <mystring/MyString.hpp>


std::ostream& operator<< (std::ostream& os, const MyString & s)
{
    os<<s.str;
    return os;

}


MyString::MyString():str{nullptr}
{

    str = new char[1]; 
    str[0] = '\0';
    //std::cout<<"Default Constr have been called for "<<str<<std::endl;
};

MyString::MyString(const char& c):str{nullptr}
{
    str = new char[2];
    str[0]=c;
    str[1]='\0';
    //std::cout<<"Char Constr have been called for "<<str<<std::endl;
}

MyString::MyString (const char * other):str{nullptr}
{

    str = new char[strlen(other)];
    strcpy(str,other);
    //std::cout<<"Char * Constr have been called for "<<str<<std::endl;
}


MyString::MyString(const MyString& source)
{
    str = new char[strlen(source.str)];
    strcpy(str,source.str);
    //std::cout<<"Copy Constr have been called for "<<str<<std::endl;
}


MyString::MyString (MyString &&source):str{source.str}
{
    source.str = nullptr;
   //std::cout<<"Move Constr have been called for "<<str<<std::endl;
}

MyString::~MyString()
{

    if (str!= nullptr)
    {
        //std::cout<<"Destructor for " << str << " have been called"<<std::endl;
        delete [] str;

    }


}

char& MyString::at (int index)
{
    // if (index < 0 || index >= static_cast<int>(strlen(str)) || *str == '\0')
    // {
    //     //throw std::out_of_range("Index is out of range");
    //     std::cout<<"Index is out of range"<<std::endl;
    // }
    // else{
        return str[index];
    // }
}
char& MyString::operator[](int index)
{
    return str[index];
}
char * MyString::c_str() const
{
    return str;
}
size_t MyString::size() const
{
    if (*str != '\0')
    {
        return strlen(str);
    }
    else
    {
        return 0;
    }

}
char MyString::back() const
{

    return str[strlen(str)-1];


}
char MyString::front() const
{

    return str[0];

}
bool MyString::empty () const
{
    return (strlen(str) == 0);

}
MyString& MyString::substr(int pos, size_t len)
{

    // if (*str!= '\0')
    // {
        if(strlen(str) > pos+len )
        {   char * new_str = new char [len];
            new_str = strncpy(new_str,str+pos,len);
            MyString * substring  = new MyString(new_str); 
            return *substring;    
        }
        else
        {
            MyString * substring = new MyString();
            return *substring;
        }

    // }
    // else
    // {
    //     throw std::out_of_range("String is empty");
    // }
}
bool MyString::starts_with(const MyString& part_str) const
{
    if (*str!= '\0' && *part_str.str!= '\0')
    {
        size_t result = strncmp(part_str.str,str,part_str.size());

        if (result == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }


}
bool MyString::ends_with(const MyString& part_str) const
{
    if (*str!= '\0' && *part_str.str!='\0')
    {
        size_t result = strncmp(part_str.str,str+strlen(str)-part_str.size(),part_str.size());

        if (result == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
void MyString::push_back(char c)
{
    char * new_str = new char [strlen(str)+2];
    strcpy(new_str,str);
    new_str[strlen(str)] = c;
    new_str[strlen(str) + 1] = '\0';
    delete [] str;
    str = new_str;
    new_str = nullptr;
}
MyString& MyString::operator+=(const MyString & other)
{
    if (*str!='\0' && *other.str!='\0')
    {
        char * new_str = new char [strlen(str)+strlen(other.str)+1];
        new_str = strcpy(new_str, str);
        new_str = strcat(new_str, other.str);
        delete [] str;
        str = new_str;
        new_str = nullptr;
        return *this;
    }
    else if (*str=='\0' && *other.str!='\0')
    {
        char * new_str = new char [strlen(other.str)];
        new_str = strcpy(new_str, other.str);
        delete [] str;
        str = new_str;
        new_str = nullptr;
        return *this;
    }
    else
    {
        return *this;
    }

}
MyString& MyString::operator+(const MyString & other)
{
    if (*str!='\0' && *other.str!='\0')
    {
        char * new_str = new char [strlen(str)+strlen(other.str)+1];
        new_str = strcpy(new_str, str);
        new_str = strcat(new_str, other.str);
        MyString * new_string = new MyString(new_str);
        return *new_string;
    }
    else if (*str=='\0' && *other.str!='\0')
    {
        char * new_str = new char [strlen(other.str)];
        new_str = strcpy(new_str, other.str);
        MyString * new_string = new MyString(new_str);
        return *new_string;
    }
    else if (*str!='\0' && *other.str=='\0')
    {
        char * new_str = new char [strlen(str)];
        new_str = strcpy(new_str, str);
        MyString * new_string = new MyString(new_str);
        return *new_string;
    }
    else
    {
        MyString * new_string = new MyString();
        return *new_string;
    }

}
MyString& MyString::operator+(const char & c)
{
    push_back(c);
    return *this;
}

MyString& MyString::operator=(MyString & source) {
    if (this == &source)
    {
        return *this;
    }
    delete [] str;
    if (source.size()>1 )
    {
        str = new char [strlen(source.str)];
        strcpy(str,source.str);
        //std::cout <<str<<" copy-assigned" << std::endl;
        
    }
    else if (source.size() == 1)
    {
        str = new char[2]; 
        str[0] = source.str[0];
        str[1] = '\0';
        
    }
    else
    {
        str = new char[1]; 
        str[0] = '\0';
    }
    return *this;

}
MyString& MyString::operator=(MyString && source) {
    if (this == &source)
    {
        return *this;
    }
    delete [] str;
    str = source.str;
    source.str = nullptr;
    //std::cout <<str<<" move-assigned" << std::endl;
    return *this;
}

bool MyString::operator==(MyString &source)
{
    if (strcmp(str,source.str) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool MyString::operator==(MyString &&source)
{
    if (strcmp(str,source.str) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}