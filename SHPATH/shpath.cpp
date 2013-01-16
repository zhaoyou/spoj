#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <limits>
#include <cmath>
#include <list>
#include <map>
#include <cmath>
using namespace std;

int getLowbit(int number) {
  int lowbit = number&(-number);
  while (number != lowbit) {
    number = number + lowbit;
    lowbit = number&(-number);
  }
  return lowbit;
}

int getMin(int *dist, int *visted, int count) {
  int index = -1;
  int min = numeric_limits<int>::max();
  for (int i = 0; i < count; i++) {
    if (visted[i] == 0 && dist[i] < min) {
      index = i;
      min = dist[i];
    }
  }
  return index;
}

void getShortPath(vector<pair<int, int> > *weight, int start, int end, int city_count) {


  // cout << " get ShortPath " << start << end << endl;
  int visted[city_count];
  int dist[city_count];

  // TODO zhaoyou max, min infinity.
  int int_infinity = numeric_limits<int>::max() ;
  memset(visted, 0, city_count * sizeof(int));
  memset(dist,  int_infinity, city_count * sizeof(int));

  for(int i = 0; i < city_count; i++) {
    dist[i] = int_infinity;
  }



  list<int> source;
  for(int i = 0; i < city_count; i++) {
    source.push_back (i);
  }

  dist[start] = 0;

  while(!source.empty()) {
    int u = getMin(dist, visted, city_count);
    if (u == -1) {
      break;
    }

    if (u == end) {
      cout << dist[end] << endl;
      return;
    }
    source.remove(u);
    visted[u] = 1;

    vector<pair<int, int> > v = weight[u];


    for (int j = 0; j < v.size(); j++) {
      // v[j].first has not yet been removed
      int index = v[j].first - 1;
      int cost = v[j].second;
      if (visted[index] == 0) {
        int alt = dist[u] + cost;
        if (alt < dist[index]) {
          dist[index] = alt;
        }
      }
    }
  }

  cout << dist[end] << endl;
  //cout << "***********************" << endl;
  //for (int i = 0 ; i < city_count; i++) {
  //  cout << dist[i] << endl;
  //}

}

void readFindCase(vector<pair<int, int> > *weight, map<string, int> city_map, int city_count) {

  int find_count;
  scanf("%d", &find_count);
  for (int i = 0; i < find_count; i++) {
    char start[50];
    char end[50];
    scanf("%s %s", &start, &end);
    getShortPath(weight, city_map[start], city_map[end], city_count);
  }
}

void readInput() {

    int city_count;
    scanf("%d", &city_count);


    vector<pair<int,int> > weight[city_count];

    map<string, int> city_map;
    for (int j = 0; j < city_count; j++) {
      string city;
      int neighbour_count;
      cin >> city;
      cin >> neighbour_count;
      city_map[city] = j;

      vector<pair<int, int> > v;
for (int k = 0; k < neighbour_count; k++) {
        pair<int, int> item;
        int index, cost;
        scanf("%d %d", &index, &cost);
        item.first= index;
        item.second = cost;
        v.push_back (item);
      }

      weight[j] = v;
    }

    //for(int i = 0; i < city_count; i++) {
    //  vector<pair<int, int> > v2 = weight[i];
    //  for (int j = 0; j < v2.size(); j++) {
    //    cout << v2[j].first << ":" << v2[j].second << endl;
    //  }
    //  cout << "*****" << endl;
    //}

    readFindCase(weight, city_map, city_count);

}

void updateWinerTree(int *all, int all_count, int index) {
  while(index != 0) {
    int min = all[index];

    int neighbour = 0;
    if (index%2 ==0) {
      neighbour = all[index -1];
    } else {
      neighbour = all[index + 1];
    }

    if (min > neighbour) {
      min = neighbour;
    }
    //cout << index << " " << all[index] << ">>" << neighbour << " min: " << min << endl;
    if (index%2 == 0) {
      all[(index - 2) / 2] = min;
      index = (index - 2) / 2;
    } else {
      all[(index - 1 ) / 2] = min;
      index = (index - 1 ) / 2;
    }
  }
}

int getIndex(int *all, int all_count) {
  int index = 0;
  int limit_index = all_count / 2;
  while (index < limit_index) {
    if (all[index * 2 + 1] == all[index]) {
      index = (index * 2) + 1;
    } else {
      index = (index * 2) + 2;
    }
  }
  return index - limit_index;
}

void buildWinerTree(int *dist, int count) {
  int int_max = numeric_limits<int>::max();
  int lowbit = getLowbit(count);
  int all_count = 2 * lowbit -1;


  int all[all_count];
  for (int i = 0; i < all_count; i++) {
    all[i] = int_max;
  }

  int c = lowbit;

  for(int i = 0; i <c; i++) {
      if ( i < count) {
        all[i + c - 1] = dist[i];
        //cout << (i + c -1) << endl;
        int calcIndex =  i + c -1;
        //if (i%2 != 0) {
        //  calcIndex = i + c -2;
        //}
          updateWinerTree(all, all_count, calcIndex);
      }
  }


  //cout << "**** all element: ***" << endl;
  //for(int i = 0; i < all_count; i++) {
  //  cout << all[i] << endl;
  //}
  cout << "min: " << all[0] << endl;
  cout << "index: " << getIndex(all, all_count) << endl;
}

int main() {
  //int test_count;
  //scanf("%d", &test_count);
  //for (int i = 0; i < test_count; i++) {
  //  readInput();
  //}
  int count;
  int dist[count];
  scanf("%d", &count);
  for (int i = 0; i < count; i++) {
    cin >> dist[i];
  }

  //int a = log2(7);
  //cout << a << "********" << endl;
  //int b = pow(2, 3);
  //cout << b << "********" << endl;
  buildWinerTree(dist, count);
  //unsigned int value = 5;
  //cout << (value >> 1) << endl;
  //cout << (value << 1) << endl;
  //int lowbit = 4 & 1;
  //cout << lowbit <<endl;
  //int number;
  //scanf("%d", &number);
  //int lowbit = number&(-number);
  //while (number != lowbit) {
  //  number = number + lowbit;
  //  lowbit = number&(-number);
  //}

  //cout << lowbit << endl;
}
