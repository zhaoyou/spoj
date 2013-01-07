#include <iostream>
#include <string>
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <math.h>

using namespace std;


int buildPrimeBoolResult(bool *source, int max_count, int *sourceNumber, int *source_square) {

  //for(int k = 2; k < max_count; k++) {
  //  source[k] = true;
  //}

  memset(source, true, max_count * sizeof(bool));

  int inner_len = (int) sqrt(max_count);
  for (int i = 2; i <= inner_len; i++) {
    if (source[i]) {
      for (int j = i*i; j < max_count; j = j + i) {
        source[j]  = false;
      }
    }
  }

  int index = 0;
  for(int p = 2 ; p < max_count; p++) {
    if (source[p]) {
      sourceNumber[index] = p;
      source_square[index] = p * p;
      index ++;
    }
  }

  return index;
}


void display(long start, long end, bool *source, int *sourceNumber, int len, int *source_square) {
  long i = start;
  long j = end;

  if (i == 1 || i == 2) {
    cout << 2 << endl;
  }

  if (i%2==0) {
    i++;
  }
  for (; i <= j; i = i + 2) {
    bool flag = true;
    if (i == 1) {
      continue;
    }

    for(int k = 0; k < len; k++) {
      if (i % sourceNumber[k]  == 0 && i != sourceNumber[k]) {
        flag = false;
        break;
      }

      if (i < source_square[k]) {
        break;
      }
    }

    if (flag) {
      cout << i << endl;
    }
  }
}


int main() {
  int max_count = 31630; //31622
  int sourceNumber[max_count];
  int source_square[max_count];
  bool source[max_count];
  int  prime_count = buildPrimeBoolResult(source, max_count, sourceNumber, source_square);
  //cout << "prime count" << prime_count << endl;

  char *word;
  int number;
  cin >> number;

  for(int i = 0; i < number; i++) {
    long start, end;
    scanf("%ld %ld", &start, &end);
    display(start, end, source, sourceNumber, prime_count, source_square);
    if (i != number -1) {
      cout << endl;
    }
  }
}
