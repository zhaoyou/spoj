#include <iostream>
#include <string>
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <math.h>

using namespace std;

int main() {
  int input;
  cin >> input;
  int m = input % 10;
  if (m == 0) {
    cout << "2" << endl;
  } else {
    cout << "1" << endl;
    cout << m << endl;
  }
  return 0;
}

