#include <catch2/catch_test_macros.hpp>
#include <bubble/bubble_sort.hpp>

TEST_CASE("Random vector") {
  std::vector<int> vec1 = {5, 2, 8, 1, 3};
  bubbleSort(vec1.begin(),vec1.end());
  CHECK(vec1 == std::vector<int>{8,5,3,2,1});
}
TEST_CASE("Sorted vector in descending order") {
  std::vector<int> vec1 = {8,5,3,2,1};
  bubbleSort(vec1.begin(),vec1.end());
  CHECK(vec1 == std::vector<int>{8,5,3,2,1});
}

TEST_CASE("Sorted vector in ascending order") {
  std::vector<int> vec1 = {1,2,3,5,8};
  bubbleSort(vec1.begin(),vec1.end());
  CHECK(vec1 == std::vector<int>{8,5,3,2,1});
}

TEST_CASE("Empty vector") {
  std::vector<int> vec1 = {};
  bubbleSort(vec1.begin(),vec1.end());
  CHECK(vec1 == std::vector<int>{});
}
TEST_CASE("1 element vector") {
  std::vector<int> vec1 = {10};
  bubbleSort(vec1.begin(),vec1.end());
  CHECK(vec1 ==std::vector<int>{10});
}
TEST_CASE("negative numbers") {
  std::vector<int> vec1 = {-5,-10,-15,-100,-1};
  bubbleSort(vec1.begin(),vec1.end());
  CHECK(vec1 == std::vector<int>{-1,-5,-10,-15,-100});
}
TEST_CASE("Repeated numbers") {
  std::vector<int> vec1 = {-5,-5,10,0,0,500,-500,-5};
  bubbleSort(vec1.begin(),vec1.end());
  CHECK(vec1 == std::vector<int>{500,10,0,0,-5,-5,-5,-500});
}
