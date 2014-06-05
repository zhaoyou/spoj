#include <cstdio>
#include <iostream>
#include <limits>


using namespace std;

int main() {
	int number;
	cin >> number;
	int array[number + 1];
	int weight[3] = {1, 3, 5};
	int imax = std::numeric_limits<int>::max(); 

	array[0] = 0;

  for(int j = 1 ; j <= number; j++) {
  	array[j] = imax;
  	for (int k = 0 ; k < 3; k++) {
       if (weight[k] <= j && array[(j - weight[k])] + 1 < array[j])
       		array[j] = array[(j - weight[k])]  + 1;
  	}
  }



	cout << array[number] << endl;
	return 0;
}
