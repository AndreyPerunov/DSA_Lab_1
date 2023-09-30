// Sort coins by Market Value
#include <iostream>
#include <fstream>
#include <string>

const int NUMBER_OF_ELEMENTS = 100;

int main() {
  std::string coins[NUMBER_OF_ELEMENTS];

  std::ifstream file("coins.data");

  if (!file) {
    std::cout << "Unable to open file." << std::endl;
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