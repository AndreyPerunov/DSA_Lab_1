#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

const int NUMBER_OF_ELEMENTS = 10;

void printSelectionSort(int array[], int green, int red, int yellow) {
  for (int i = 0; i < NUMBER_OF_ELEMENTS; ++i) {
    if (i == green) {
      std::cout << "\033[1;32m " << array[i] << "\033[0m; ";
    } else if (i == red) {
      std::cout << "\033[1;31m " << array[i] << "\033[0m; ";
    } else if (i == yellow) {
      std::cout << "\033[1;33m " << array[i] << "\033[0m; ";
    } else {
      std::cout << "  " << array[i] << "; ";
    }
  }
  std::cout<<std::endl;
}

void printQuickSort(int array[], int green, int red, int blue) {
  for (int i = 0; i < NUMBER_OF_ELEMENTS; ++i) {
    if (i == green) {
      std::cout << "\033[1;32m " << array[i] << "\033[0m; ";
    } else if (i == red) {
      std::cout << "\033[1;31m " << array[i] << "\033[0m; ";
    } else if (i == blue) {
      std::cout << "\033[1;34m " << array[i] << "\033[0m; ";
    } else {
      std::cout << "  " << array[i] << "; ";
    }
  }
  std::cout<<std::endl;
}

int findSmallest(int array[], int skip, int &comparisons) {
  int smallestIndex = skip;
  for (int i = skip + 1; i < NUMBER_OF_ELEMENTS; ++i) {
    comparisons++;
    printSelectionSort(array, skip - 1, i, smallestIndex);
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

void selectionSort(int array[], int &transpositions, int &comparisons){
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
    printQuickSort(array, low, i, leftwall);
    if (array[i] < pivot) {
      leftwall++;
      swap(array[i], array[leftwall]);
      transpositions++;
    }
  }

  swap(array[low], array[leftwall]);
  printQuickSort(array, leftwall, 99999999, 99999999);
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
  int transpositions1 = 0;
  int comparisons1 = 0;
  int transpositions2 = 0;
  int comparisons2 = 0;
  readData("coins.txt", coins1);
  readData("coins.txt", coins2);
  
  std::cout << std::endl << "Insertions Sort: " << std::endl;
  auto start1 = std::chrono::high_resolution_clock::now();
  selectionSort(coins1, transpositions1, comparisons1);
  auto end1 = std::chrono::high_resolution_clock::now();
  std::chrono::duration<float> duration1 = end1 - start1;

  std::cout << std::endl << "Quick Sort: " << std::endl;
  auto start2 = std::chrono::high_resolution_clock::now();
  quickSort(coins2, 0, NUMBER_OF_ELEMENTS - 1, transpositions2, comparisons2);
  auto end2 = std::chrono::high_resolution_clock::now();
  std::chrono::duration<float> duration2 = end2 - start2;


  std::cout << std::endl << "Selection Sort Benchmark: " << std::endl;
  std::cout << "  Number of Transpositions: " << transpositions1 << std::endl;
  std::cout << "  Number of Comparisons: " << comparisons1 << std::endl;
  std::cout << "  Time: " << duration1.count()*1000 << "ms" << std::endl << std::endl;
  
  std::cout << "Quick Sort Benchmark: " << std::endl;
  std::cout << "  Number of Transpositions: " << transpositions2 << std::endl;
  std::cout << "  Number of Comparisons: " << comparisons2 << std::endl;
  std::cout << "  Time: " << duration2.count()*1000 << "ms" << std::endl << std::endl;


  std::cin.get();

  return 0;
}