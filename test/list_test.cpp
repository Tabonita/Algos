#include <catch2/catch_test_macros.hpp>
#include <my_list/list.hpp>

// Необходимо реализовать List, свой аналог std::list - двусвязный список, в публичный интерфейс которого входят следующие методы:

// push_front()/push_back()
// front()/back()
// empty()/size()
// begin()/end() (возвращать они должны не std::iterator, а свой вручную написанный ListIterator)
// erase()/pop_front()/pop_back()
// В итоге List должен уметь хранить любые виды данных (т.е. стать шаблоном List<T>). Но первую реализацию лучше сделать простой - хранить только данные одного типа (например std::string), без шаблонов.

TEST_CASE("empty list 1") {
  MyList list_1{};
  Iterator it_1 = list_1.begin();
  Iterator new_it = list_1.end();
  CHECK((*it_1) == 0);
  CHECK((it_1 == new_it) == 1);
  CHECK(list_1.size() == 0);
  CHECK(list_1.empty() == 1);
  CHECK(list_1.front() == 0);
  CHECK(list_1.back() == 0);
  // CHECK(list_1.pop_back() == "List is empty");
  // CHECK(list_1.pop_front() == "List is empty");
  //CHECK(list_1.erase(it_1) == it_1);
  CHECK(list_1.begin() == it_1);
  CHECK(list_1.end() == it_1);
  list_1.push_front(1000);
  list_1.push_back(9000);
  it_1 = list_1.begin();
  CHECK((*it_1) == 1000);
  ++it_1;
  CHECK((*it_1) == 9000);
  new_it = list_1.end();
  --new_it;
  CHECK((it_1 != new_it) == 0);
  it_1 = it_1+20;
  CHECK((*it_1) == 2);
  it_1 = it_1-2;
  CHECK((*it_1) == 1000);
}
TEST_CASE("empty list 2") {
  MyList list_2;
  Iterator it_2 = list_2.begin();
  Iterator new_it = list_2.end();
  CHECK((*it_2) == 0);
  CHECK((it_2 == new_it) == 1);
  CHECK(list_2.size() == 0);
  CHECK(list_2.empty() == 1);
  CHECK(list_2.front() == 0);
  CHECK(list_2.back() == 0);
  // list_2.pop_back();
  // list_2.pop_front();
  // Iterator it_tmp_1 = list_2.begin();
  // Iterator it_tmp_2 = list_2.begin();
  // ++it_tmp_1;
  // it_tmp_2 = list_2.erase(it_tmp_1);
  //CHECK( it == it_2);
  it_2 = list_2.begin();;
  CHECK(list_2.begin() == it_2);
  CHECK(list_2.end() == it_2);
  list_2.push_front(1000);
  list_2.push_back(9000);
  it_2 = list_2.begin();
  CHECK((*it_2) == 1000);
  ++it_2;
  CHECK((*it_2) == 9000);
  new_it = list_2.end();
  --new_it;
  CHECK((it_2 != new_it) == 0);
  it_2 = it_2+20;
  CHECK((*it_2) == 2);
  it_2 = it_2-2;
  CHECK((*it_2) == 1000);
}
TEST_CASE("1 arg list") {
  MyList list_3{555};
  Iterator it_3 = list_3.begin();
  Iterator new_it = list_3.end();
  CHECK((*it_3) == 555);
  CHECK((it_3 == new_it) == 0);
  CHECK(list_3.size() == 1);
  CHECK(list_3.empty() == 0);
  CHECK(list_3.front() == 555);
  CHECK(list_3.back() == 555);
  CHECK(list_3.begin() == (--new_it));
  CHECK(list_3.end() == (++it_3));
  list_3.push_front(1000);
  list_3.push_back(9000);
  it_3 = list_3.begin();
  CHECK((*it_3) == 1000);
  ++it_3;
  CHECK((*it_3) == 555);
  new_it = list_3.end();
  --new_it;
  CHECK((it_3 != new_it) == 1);
  CHECK((it_3 == new_it) == 0);
  it_3 = it_3+2;
  CHECK((*it_3) == 3);
  it_3 = it_3-2;
  CHECK((*it_3) == 555);
  list_3.pop_back();
  list_3.pop_front();
  list_3.pop_back();
  CHECK(list_3.empty() == 1);
  it_3 = list_3.begin();
  // Iterator it_tmp_1 = list_3.begin();
  // Iterator it_tmp_2 = list_3.begin();
  // ++it_tmp_1;
  // it_tmp_2 = list_3.erase(it_tmp_1);
  // CHECK(*it == 555);

}
TEST_CASE("many args list") {
  MyList list_4{88,99,22,33};
  Iterator it_4 = list_4.begin();
  Iterator new_it = list_4.end();
  CHECK((*it_4) == 88);
  CHECK((it_4 == new_it) == 0);
  CHECK(list_4.size() == 4);
  CHECK(list_4.empty() == 0);
  CHECK(list_4.front() == 88);
  CHECK(list_4.back() == 33);
  CHECK(list_4.begin() == new_it - 4);
  CHECK(list_4.end() == it_4+4);
  // Iterator it_tmp_1 = list_4.begin();
  // Iterator it_tmp_2 = list_4.begin();
  // ++it_tmp_1;
  // it_tmp_2 = list_4.erase(it_tmp_1);
 // CHECK(*it == 4);
  list_4.push_front(1000);
  list_4.push_back(9000);
  it_4 = list_4.begin();
  CHECK((*it_4) == 1000);
  ++it_4;
  CHECK((*it_4) == 88);
  new_it = list_4.end();
  --new_it;
  CHECK((it_4 != new_it) == 1);
  CHECK((it_4 == new_it) == 0);
}
