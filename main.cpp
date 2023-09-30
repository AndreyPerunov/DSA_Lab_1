// Sort coins by Market Value
#include <iostream>
#include <fstream>
#include <string>

const int NUMBER_OF_ELEMENTS = 100;

void print(std::string coins[]) {
  for (int i = 0; i < NUMBER_OF_ELEMENTS; ++i) {
    std::cout << coins[i] << std::endl;
  }
}

int linearSearch(std::string coin, std::string coins[]) {
  for (int i = 0; i < NUMBER_OF_ELEMENTS; ++i) {
    if (coins[i] == coin) {
      return i;
    }
  }
  throw std::runtime_error("Element not found.");
}

int main() {
  std::string coins[NUMBER_OF_ELEMENTS];

  std::ifstream file("coins.data");

  if (!file) {
    std::cerr << "Unable to open file." << std::endl;
    return 1;
  }

  int lineCount = 0;
  std::string line;

  while (std::getline(file, line)) {
    if (lineCount < NUMBER_OF_ELEMENTS) {
      coins[lineCount] = line;
      lineCount++;
    } else {
      break;
    }
  }

  file.close();

  return 0;
}