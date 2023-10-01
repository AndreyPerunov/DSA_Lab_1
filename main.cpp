#include <iostream>
#include <fstream>
#include <string>

const int NUMBER_OF_ELEMENTS = 1000;

void print(int array[]) {
  for (int i = 0; i < NUMBER_OF_ELEMENTS; ++i) {
    std::cout << "  " << array[i] << "; ";
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

void insertionSort(int array[], int &transpositions){
  for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {
    swap(array[i], array[findSmallest(array, i)]);
    transpositions++;
  }
}

int partition(int array[], int low, int high, int &transpositions) {
  int pivot = array[low];
  int leftwall = low;

  for (int i = low + 1; i <= high; i++) {
    if (array[i] < pivot) {
      leftwall++;
      swap(array[i], array[leftwall]);
      transpositions++;
    }
  }

  swap(array[low], array[leftwall]);
  transpositions++;
  return leftwall;
}

void quickSort(int array[], int low, int high, int &transpositions){
  if (low < high) {
    int pivotLocation = partition(array, low, high, transpositions);
    quickSort(array, low, pivotLocation, transpositions);
    quickSort(array, pivotLocation + 1, high, transpositions);
  }
}

int main() {
  int coins1[NUMBER_OF_ELEMENTS] = {0};
  int coins2[NUMBER_OF_ELEMENTS] = {0};
  int transpositions;
  readData("coins.txt", coins1);
  readData("coins.txt", coins2);
  
  std::cout << "Insertions Sort: " << std::endl;
  transpositions = 0;
  insertionSort(coins1, transpositions);
  std::cout << "Number of Transpositions: " << transpositions << std::endl << std::endl;
  
  std::cout << "Quick Sort: " << std::endl;
  transpositions = 0;
  quickSort(coins2, 0, NUMBER_OF_ELEMENTS - 1, transpositions);
  std::cout << "Number of Transpositions: " << transpositions << std::endl;

  return 0;
}