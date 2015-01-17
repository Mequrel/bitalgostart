/**

  Zadanie K: Inwersje.
  Autor: Bartłomiej Szczepanik

  Rozwiązanie wzorcowe.

  Złożoność rozwiązania: O(n lg n)

**/

#include <cstdio>
#include <vector>

typedef long long int64;

using namespace std;

int64 merge_and_count(int* first_part, int first_part_size, int* second_part, int second_part_size, int* destination) {
  int merged_size = first_part_size + second_part_size;
  int* merged = new int[merged_size];
  
  int first_index = 0, second_index = 0, i = 0;

  int64 inversions = 0;

  while(first_index < first_part_size && second_index < second_part_size) {
    if(first_part[first_index] <= second_part[second_index]) {
      merged[i++] = first_part[first_index++];
      inversions += second_index; // add number of elements from the second part that were already processed
    }
    else {
      merged[i++] = second_part[second_index++];
    }
  }

  while(first_index < first_part_size) {
    merged[i++] = first_part[first_index++];
    inversions += second_part_size; // was bigger than every element from the second part
  }

  while(second_index < second_part_size) {
    merged[i++] = second_part[second_index++];
  }

  for(int i=0; i < merged_size; ++i) {
    destination[i] = merged[i];
  }

  delete merged;

  return inversions;
}

int64 count_inversions(int* data, int size) {
  if(size <= 1) {
    return 0;
  }

  int first_part_size = size / 2;
  int second_part_size = size - first_part_size;

  int* first_part = data;
  int* second_part = data + first_part_size;

  int64 inversions = 0;

  inversions += count_inversions(first_part, first_part_size);
  inversions += count_inversions(second_part, second_part_size);

  inversions += merge_and_count(first_part, first_part_size, second_part, second_part_size, data);

  return inversions;
}

int main() {
  int n;
  scanf("%d", &n);

  int* numbers = new int[n];

  for(int i=0; i<n; ++i) {
    scanf("%d", &numbers[i]);
  }

  int64 inversions = count_inversions(numbers, n);

  printf("%lld", inversions);

  delete numbers;

  return 0;
}