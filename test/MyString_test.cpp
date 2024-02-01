#include <catch2/catch_test_macros.hpp>
#include <mystring/MyString.hpp>

TEST_CASE("test MyString") {
    MyString a ;
    MyString b('B');

//default constructor
    CHECK(strcmp(a.c_str(), "") == 0);
    CHECK(a.front() == '\0');
    CHECK(a.back() == '\0');
    CHECK(a.empty() == true);
    CHECK(a.size() == 0);  
    // CHECK_THROWS_AS(
    //     a.substr(1, 2),
    //     "String is empty"
    // );
    CHECK(a.starts_with(b) == false);
    CHECK(a.ends_with(b) == false);
    CHECK(a == MyString());
    CHECK((a += a) == MyString());
    CHECK(a + a == MyString());
    a.push_back('M');
    CHECK(a == MyString('M')); 
    a = b;
    CHECK(a == MyString('B')); 
}
TEST_CASE("test MyString_1"){
    MyString a;
    MyString b('B');
    a = b;
// char constructor
    char x = 'B';
    CHECK((b.c_str()[0] == x));
    CHECK(b.front() == 'B');
    CHECK(b.back() == 'B');
    CHECK(b.empty() == false);
    CHECK(b.size() == 1);  
    CHECK(b.substr(0,1) == MyString());
    CHECK(b.starts_with(b) == true);
    CHECK(b.ends_with(b) == true);
    CHECK((b += b) == "BB");
    CHECK(b + b == "BBBB");
    b.push_back('M');
    CHECK(b == "BBM"); 
    b = a;
    CHECK(b == MyString('B')); 
}

TEST_CASE("test MyString_2"){
    MyString numbers ("0123456789");
// MyString constructor
    const char * check_str = "0123456789";
    CHECK(strcmp(numbers.c_str(), check_str) == 0);
}
TEST_CASE("test MyString_3"){
    MyString numbers ("0123456789");
// MyString constructor
    CHECK(numbers.front() == '0');
    CHECK(numbers.back() == '9');
}
TEST_CASE("test MyString_4"){
    MyString numbers ("0123456789");
// MyString constructor
    MyString start ("012");
    MyString end("789");
    CHECK(numbers.empty() == false);
    CHECK(numbers.size() == 10);  
    CHECK(numbers.substr(0,2) == "01");
    CHECK(numbers.starts_with(start) == true);
    CHECK(numbers.ends_with(end) == true);
}
TEST_CASE("test MyString_5"){
    MyString b('B');
    MyString numbers ("0123456789");
    CHECK((numbers += numbers) == "01234567890123456789");
    MyString result = numbers+numbers;
    CHECK(result == "0123456789012345678901234567890123456789");
    //numbers.push_back('M');
    //CHECK(numbers == "01234567890123456789M"); 
    //numbers = b;
    //CHECK(numbers == MyString('B')); 
}
