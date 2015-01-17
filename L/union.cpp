/**

  Zadanie L: Suma zbiorów.
  Autor: Bartłomiej Szczepanik

  Rozwiązanie wzorcowe.

  Złożoność rozwiązania: O(n lg n + m lg m)

**/

#include <cstdio>
#include <vector>

using namespace std;

void merge(int* first_part, int first_part_size, int* second_part, int second_part_size, int* destination) {
  int merged_size = first_part_size + second_part_size;
  int* merged = new int[merged_size];
  
  int first_index = 0, second_index = 0, i = 0;

  while(first_index < first_part_size && second_index < second_part_size) {
    if(first_part[first_index] <= second_part[second_index]) {
      merged[i++] = first_part[first_index++];
    }
    else {
      merged[i++] = second_part[second_index++];
    }
  }

  while(first_index < first_part_size) {
    merged[i++] = first_part[first_index++];
  }

  while(second_index < second_part_size) {
    merged[i++] = second_part[second_index++];
  }

  for(int i=0; i < merged_size; ++i) {
    destination[i] = merged[i];
  }

  delete merged;
}

void merge_sort(int* data, int size) {
  if(size <= 1) {
    return;
  }

  int first_part_size = size / 2;
  int second_part_size = size - first_part_size;

  int* first_part = data;
  int* second_part = data + first_part_size;

  merge_sort(first_part, first_part_size);
  merge_sort(second_part, second_part_size);

  merge(first_part, first_part_size, second_part, second_part_size, data);
}

bool is_different(int next_index, int* merged, int element) {
  return (next_index == 0) || (merged[next_index-1] != element);
}

void merge_union(int* first_part, int first_part_size, int* second_part, int second_part_size, int* merged, int* final_size) {
  int first_index = 0, second_index = 0, i = 0;

  while(first_index < first_part_size && second_index < second_part_size) {
    if(first_part[first_index] <= second_part[second_index]) {
      if(is_different(i, merged, first_part[first_index])) {
        merged[i++] = first_part[first_index];
      }
      first_index++;
    }
    else {
      if(is_different(i, merged, second_part[second_index])) {
        merged[i++] = second_part[second_index];
      }
      second_index++;
    }
  }

  while(first_index < first_part_size) {
    if(is_different(i, merged, first_part[first_index])) {
      merged[i++] = first_part[first_index];
    }
    first_index++;
  }

  while(second_index < second_part_size) {
    if(is_different(i, merged, second_part[second_index])) {
      merged[i++] = second_part[second_index];
    }
    second_index++;
  }

  *final_size = i;
}

int main() {
  int first_size, second_size;
  scanf("%d %d", &first_size, &second_size);

  int* first_numbers = new int[first_size];
  int* second_numbers = new int[second_size];

  for(int i=0; i<first_size; ++i) {
    scanf("%d", &first_numbers[i]);
  }

  for(int i=0; i<second_size; ++i) {
    scanf("%d", &second_numbers[i]);
  }

  merge_sort(first_numbers, first_size);
  merge_sort(second_numbers, second_size);

  int *unioned = new int[first_size + second_size];
  int union_size;
  merge_union(first_numbers, first_size, second_numbers, second_size, unioned, &union_size);

  for(int i=0; i<union_size; ++i) {
    printf("%d ", unioned[i]);
  }

  delete first_numbers;
  delete second_numbers;
  delete unioned;

  return 0;
}