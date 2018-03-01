#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#define SIZE 100

void initArray(int* array);
void printArray(int* array);
int binarySearchIteration(int* array, int n, int i);
int binarySearchRecursion(int* array, int left, int n, int i);

int main(int argc, char const** argv) {
  int array[SIZE];
  initArray(array);
  printf("Iteration: %d\tRecursion: %d\n", binarySearchIteration(array, SIZE, 10),
                                           binarySearchRecursion(array, 0, SIZE, 10));
  // binarySearchIteration(array, SIZE, 10);
  // binarySearchRecursion(array, 0, SIZE, 10);
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
      n = mid + 1;
  }
  //element not found
  return -1;
}

int binarySearchRecursion(int* array, int left, int n, int i) {
  int mid = left + (n - left)/2;
  if (n > 0) {
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
  array[0] = 1;
  for (int i = 1; i < SIZE; i++) {
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
