#include <catch2/catch_test_macros.hpp>
#include <bubble/bubble_sort.hpp>

TEST_CASE("test bubble sort") {

  std::vector<int> vec1 = {5, 2, 8, 1, 3};
  bubbleSort(vec1.begin(),vec1.end());
  std::vector<int> vec2 = {1, 2, 100, 0, -5,-70};
  bubbleSort(vec2.begin(),vec2.end());
  std::vector<int> vec3 = {10};
  bubbleSort(vec3.begin(),vec3.end());
  std::vector<int> vec4 = {};
  bubbleSort(vec4.begin(),vec4.end());
  std::vector<int> vec5 = {0,5,0,2346,0,-2,0};
  bubbleSort(vec5.begin(),vec5.end());
  CHECK(vec1 == std::vector<int>{8,5,3,2,1});
  CHECK(vec2 == std::vector<int>{100,2,1,0,-5,-70});
  CHECK(vec3 == std::vector<int>{10});
  CHECK(vec4 == std::vector<int>{});
  CHECK(vec5 == std::vector<int>{2346,5,0,0,0,0,-2});
}