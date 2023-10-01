// Sort coins by Market Value
#include <iostream>
#include <fstream>
#include <string>

const int NUMBER_OF_ELEMENTS = 10;

void print(int array[]) {
  for (int i = 0; i < NUMBER_OF_ELEMENTS; ++i) {
    std::cout << array[i] << "; ";
  }
  std::cout<<std::endl;
}

int findSmallest(int array[], int skip) {
  int smallestIndex = skip;
  for (int i = skip + 1; i < NUMBER_OF_ELEMENTS; ++i) {
    if (array[i] < array[smallestIndex]) {
      smallestIndex = i;
    }
  }
  return smallestIndex;
}

void readData(std::string filename, int arr[]) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return;
    }

    std::string line;
    int count = 0;

     while (count < NUMBER_OF_ELEMENTS && getline(file, line)) {
        try {
            arr[count] = std::stoi(line);
            count++;
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error reading line number " << count + 1 << std::endl << std::endl;
        }
    }

    file.close();
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void insertionSort(int array[]){
  for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {
    swap(array[i], array[findSmallest(array, i)]);
  }
}

int main() {
  int coins[NUMBER_OF_ELEMENTS] = {0};
  readData("coins.txt", coins);
  insertionSort(coins);
  return 0;
}