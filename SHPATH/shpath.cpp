#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <vector>
#include <limits>
#define COUNT  2

using namespace std;

int main() {
  int test_count;
  scanf("%d", &test_count);
  // get test cases.
  for (int i = 0; i < test_count; i++) {
    int city_count;

    scanf("%d", &city_count);
    vector<vector<int> > dynamicArray(city_count, vector<int>(city_count));
    for(int i = 0;i < dynamicArray.size();++i) {
      for(int j = 0;j < dynamicArray[i].size();++j) {
           dynamicArray[i][j] = numeric_limits<int>::max();
      }
    }

    string city_array[city_count];

    // get per test city counts.
    //cout << city_count << endl;
    for (int j = 0; j < city_count; j++) {
      string city;

      int neighbour_count;
      //scanf("%s", &city);
      //scanf("%d", &neighbour_count);
      cin >> city_array[j];
      cin >> neighbour_count;
      for (int k = 0; k < neighbour_count; k++) {
        int index, cost;
        scanf("%d %d", &index, &cost);
      }
    }
  }
}
