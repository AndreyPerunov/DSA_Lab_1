#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

const int NUMBER_OF_ELEMENTS = 9999;

void print(int array[]) {
  for (int i = 0; i < NUMBER_OF_ELEMENTS; ++i) {
    std::cout << "  " << array[i] << "; ";
  }
  std::cout<<std::endl;
}

int findSmallest(int array[], int skip, int &comparisons) {
  int smallestIndex = skip;
  for (int i = skip + 1; i < NUMBER_OF_ELEMENTS; ++i) {
    comparisons++;
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
      std::cerr << "Error reading line number " << count + 1 << std::endl;
    }
  }

  file.close();
}

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

void insertionSort(int array[], int &transpositions, int &comparisons){
  for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {
    swap(array[i], array[findSmallest(array, i, comparisons)]);
    transpositions++;
  }
}

int partition(int array[], int low, int high, int &transpositions, int &comparisons) {
  int pivot = array[low];
  int leftwall = low;

  for (int i = low + 1; i <= high; i++) {
    comparisons++;
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

void quickSort(int array[], int low, int high, int &transpositions, int &comparisons){
  comparisons++;
  if (low < high) {
    int pivotLocation = partition(array, low, high, transpositions, comparisons);
    quickSort(array, low, pivotLocation, transpositions, comparisons);
    quickSort(array, pivotLocation + 1, high, transpositions, comparisons);
  }
}

int main() {
  int coins1[NUMBER_OF_ELEMENTS] = {0};
  int coins2[NUMBER_OF_ELEMENTS] = {0};
  int transpositions;
  int comparisons;
  readData("coins.txt", coins1);
  readData("coins.txt", coins2);
  
  std::cout << std::endl << "Insertions Sort: " << std::endl;
  transpositions = 0;
  comparisons = 0;
  auto start1 = std::chrono::high_resolution_clock::now();
  insertionSort(coins1, transpositions, comparisons);
  auto end1 = std::chrono::high_resolution_clock::now();
  std::cout << "Number of Transpositions: " << transpositions << std::endl;
  std::cout << "Number of Comparisons: " << comparisons << std::endl;
  std::chrono::duration<float> duration1 = end1 - start1;
  std::cout << "Time: " << duration1.count()*1000 << "ms" << std::endl << std::endl;
  
  
  std::cout << "Quick Sort: " << std::endl;
  transpositions = 0;
  comparisons = 0;
  auto start2 = std::chrono::high_resolution_clock::now();
  quickSort(coins2, 0, NUMBER_OF_ELEMENTS - 1, transpositions, comparisons);
  auto end2 = std::chrono::high_resolution_clock::now();
  std::cout << "Number of Transpositions: " << transpositions << std::endl;
  std::cout << "Number of Comparisons: " << comparisons << std::endl;
  std::chrono::duration<float> duration2 = end2 - start2;
  std::cout << "Time: " << duration2.count()*1000 << "ms" << std::endl << std::endl;

  return 0;
}