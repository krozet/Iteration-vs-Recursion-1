#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#define SIZE 10000

void initArray(int* array);

int main(int argc, char const** argv) {
  int array[SIZE];
  initArray(array);
  for (int i = 0; i < SIZE; i++) {
    printf("%d\n", array[i]);
  }
  return 0;
}

int binarySearchIteration(int* array, int) {

}

int binarySearchRecursion() {

}

void initArray(int* array) {
  int rd;
  array[0] = 1;
  for (int i = 1; i < SIZE; i++) {
    rd = (rand() % 5);
    array[i] = array[i-1] + rd;
  }
}
