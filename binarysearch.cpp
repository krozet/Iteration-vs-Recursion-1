#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits>

#define SIZE 89999
#define K 300

typedef std::numeric_limits< double > dbl;

void initArray(int* array);
void printArray(int* array);
int binarySearchIteration(int* array, int n, int i);
int binarySearchRecursion(int* array, int left, int n, int i);
void bsTimeMeasurement(int* array, int n);

int main(int argc, char const** argv) {
  int array[SIZE];
  initArray(array);
  bsTimeMeasurement(array, SIZE);

  return 0;
}

int binarySearchIteration(int* array, int n, int i) {
  int mid, left = 0;
  while (n >= left) {
    mid = left + (n-left)/2;
    //value is in the middle
    if (array[mid] == i)
      return mid;
    //value is less than the middle
    if (array[mid] < i)
      left = mid + 1;
    //value is greater than the middle
    else
      n = mid - 1;
  }
  //element not found
  return -1;
}

int binarySearchRecursion(int* array, int left, int n, int i) {
  int mid = left + (n - left)/2;
  if (n >= left) {
    //value in the middle
    if (array[mid] == i)
      return mid;
    //value greater than middle
    if (array[mid] > i)
      return binarySearchRecursion(array, left, mid-1, i);
    //value less than middle
    return binarySearchRecursion(array, mid+1, n, i);
  }
  //element not found
  return -1;
}

void initArray(int* array) {
  int rd;
  // array[0] = 1;
  for (int i = 0; i < SIZE; i++) {
    //ascending sorted array
    array[i] = i;
    //random sorted array
    // array[i] = array[i-1] + (rand() % 2);
  }
}

void printArray(int* array) {
  for (int i = 0; i < SIZE; i++) {
    printf("%d\n", array[i]);
  }
}

void bsTimeMeasurement(int* array, int n) {
  int j, m;
  //first test binarySearchIteration
  clock_t begin = clock();
  for(j = 0; j < K; j++)
    for(m = 0; m < n; m++)
      binarySearchIteration(array, n, m);
  clock_t end = clock();
  double bsI_elapsed_secs = double(end - begin)/CLOCKS_PER_SEC;
  std::cout.precision(dbl::max_digits10);
  std::cout << "Binary Search Iteration at K= " << K <<": " << std::fixed << bsI_elapsed_secs << " seconds." << std::endl;

  //second test binarySearchRecursion
  clock_t begin2 = clock();
  for(j = 0; j < K; j++)
      for(m = 0; m < n; m++)
          binarySearchRecursion(array, 0, n, m);
  clock_t end2 = clock();
  double bsR_elapsed_secs = double(end2 - begin2)/CLOCKS_PER_SEC;
  std::cout.precision(dbl::max_digits10);
  std::cout << "Binary Search Recursion at K= " << K <<": " << std::fixed << bsR_elapsed_secs << " seconds." << std::endl;
  }
