#include <argparse/argparse.hpp>
#include <iostream>

int main(int argc, char** argv) {
  argparse::ArgumentParser program("generate_sequence");
  program.add_description(
      "Generate a Fibonacci sequence up to the given number of terms.");
  program.add_argument("n").help("The number of terms").scan<'i', int>();

  try {
    program.parse_args(argc, argv);
  } catch (const std::exception& err) {
    std::cerr << err.what() << std::endl;
    std::cerr << program;
    return 1;
  }

  std::cout << std::endl;

  return 0;
}
