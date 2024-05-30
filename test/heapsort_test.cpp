#include <catch2/catch_test_macros.hpp>
#include <heapsort/heapsort.hpp>

TEST_CASE("sort empty vector") {
  std::vector <int> empty_vec {};
  CHECK(heapsort(empty_vec) == std::vector<int>{});
}
TEST_CASE("sort 1 element vector") {
  std::vector <int> vec {100};
  CHECK(heapsort(vec) == std::vector<int>{100});
}

TEST_CASE("sort 2 element vector") {
  std::vector <int> vec {100,1};
  CHECK(heapsort(vec) ==std::vector<int>{100,1});
}

TEST_CASE("sort positive nums vector") {
  std::vector <int> vec {99,11,88,77,22,33,55,44,66};
  CHECK(heapsort(vec) == std::vector<int>{99,88,77,66,55,44,33,22,11});
}
TEST_CASE("sort negative nums vector") {
  std::vector <int> vec {-99,-11,-88,-77,-22,-33,-55,-44,-66};
  CHECK(heapsort(vec) == std::vector<int>{-11,-22,-33,-44,-55,-66,-77,-88,-99});
}
TEST_CASE("sort mixed nums vector") {
  std::vector <int> vec {-99,11,-88,77,-22,33,-55,44,-66};
  CHECK(heapsort(vec) == std::vector<int>{77,44,33,11,-22,-66,-88,-99});
}

TEST_CASE("sort same nums vector") {
  std::vector <int> vec {0,0,0,0,0,0};
  CHECK(heapsort(vec) == std::vector<int>{0,0,0,0,0,0});
}

