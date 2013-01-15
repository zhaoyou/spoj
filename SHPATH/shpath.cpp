#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <limits>
#include <map>

using namespace std;

void getShortPath(vector<vector<int> > weight, int start, int end) {


  //cout << " get ShortPath " << start << end << endl;
  int city_count = weight.size();
  int visted[city_count];
  int dist[city_count];
  memset(visted, 0, city_count * sizeof(int));
  memset(dist,  0, city_count * sizeof(int));

  // set start index visted as 1, dist cost as 0.
  visted[start] = 1;
  dist[start] = 0;

  for (int count = 1; count < city_count; count++) {
    int min_cost = numeric_limits<int>::max();
    int k = -1;

    for (int i = 0; i < city_count; i++) {
       if (visted[i] == 0 && weight[start][i] < min_cost) {
          min_cost = weight[start][i];
          k = i;
       }
    }

    dist[k] = min_cost;
    visted[k] = 1;

    for (int j = 0; j < city_count; j++) {
      if (weight[start][k] != numeric_limits<int>::max() && weight[k][j] != numeric_limits<int>::max()) {
        if (visted[j] == 0 && weight[start][k] + weight[k][j] < weight[start][j]) {
          weight[start][j] = weight[start][k] + weight[k][j];
        }
      }
    }

  }

  //cout << " resut: "  << endl;
  cout << dist[end] << endl;
  //for (int i = 0 ; i < city_count; i++) {
  //  cout << dist[i] << endl;
  //}

}

void readFindCase(vector<vector<int> > weight, string *city_array, map<string, int> city_map) {

  //for(int i = 0;i < weight.size();++i) {
  //  for(int j = 0;j < weight[i].size();++j) {
  //      cout << weight[i][j] << endl;
  //  }
  //}
  int find_count;
  scanf("%d", &find_count);
  for (int i = 0; i < find_count; i++) {
    char start[50];
    char end[50];
    scanf("%s %s", &start, &end);
    getShortPath(weight, city_map[start], city_map[end]);
  }

}

void readInput() {

    int city_count;
    scanf("%d", &city_count);

    // init.
    vector<vector<int> > dynamicArray(city_count, vector<int>(city_count));
    for(int i = 0;i < dynamicArray.size();++i) {
      for(int j = 0;j < dynamicArray[i].size();++j) {
           dynamicArray[i][j] = numeric_limits<int>::max();
      }
    }

    string city_array[city_count];
    map<string, int> city_map;
    for (int j = 0; j < city_count; j++) {
      string city;
      int neighbour_count;
      //scanf("%s", &city);
      //scanf("%d", &neighbour_count);
      cin >> city_array[j];
      cin >> neighbour_count;
      city_map[city_array[j]] = j;

      for (int k = 0; k < neighbour_count; k++) {
        int index, cost;
        scanf("%d %d", &index, &cost);
        dynamicArray[j][index - 1] = cost;
      }
      dynamicArray[j][j] = 0;
    }



    readFindCase(dynamicArray, city_array, city_map);

}

int main() {

  int test_count;
  scanf("%d", &test_count);
  // get test cases.
  for (int i = 0; i < test_count; i++) {
    readInput();
  }
}
