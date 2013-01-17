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


int int_infinity = numeric_limits<int>::max();

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


void displayWinerTree(int *all, int all_count) {
  cout << "**** all element: ***" << endl;
  for(int i = 0; i < all_count; i++) {
    cout << all[i] << endl;
  }
  cout << "***************" << endl;
}

int getLowbit(int number) {
  int lowbit = number&(-number);
  while (number != lowbit) {
    number = number + lowbit;
    lowbit = number&(-number);
  }
  return lowbit;
}


void updateWinerTree(int *all, int all_count, int index, int data) {

  all[index] = data;

  // if top max's index is current index, should be recalc max.
  if (data == int_infinity) {
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
     // cout << index << " " << all[index] << ">>" << neighbour << " min: " << min << endl;
      all[(index - 1) / 2] = min;
      index = (index - 1) / 2;
    }
  } else {
    while(index != 0) {
      int min = all[index];

      if (all[(index -1)/2] <= min) {
        break;
      }
      all[(index - 1) / 2] = min;
      index = (index - 1) / 2;
    }
  }

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
        int calcIndex =  i + c -1;
        updateWinerTree(all, all_count, calcIndex, dist[i]);
      }
  }


  cout << "min: " << all[0] << endl;
  cout << "index: " << getIndex(all, all_count) << endl;
}


void getShortPath(vector<pair<int, int> > *weight, int start, int end, int city_count) {


  // cout << " get ShortPath " << start << end << endl;
  bool visted[city_count];
  int dist[city_count];

  // get winer tree array.
  int lowbit = getLowbit(city_count);
  int all_count = 2 * lowbit -1;
  int winer_tree[all_count];
  for (int i = 0; i < all_count; i++) {
    winer_tree[i] = int_infinity;
  }

  //cout << "start: " << start << " end: " << end << " winer_tree count: " << all_count << endl;

  // TODO zhaoyou max, min infinity.
  memset(visted, false, city_count * sizeof(false));

  for(int i = 0; i < city_count; i++) {
    dist[i] = int_infinity;
  }





  dist[start] = 0;
  updateWinerTree(winer_tree, all_count, start + lowbit -1, 0);

  //displayWinerTree(winer_tree, all_count);

  //int j = 0;
  while(true) {
    int u = getIndex(winer_tree, all_count); //getMin(dist, visted, city_count);
    //if (u == -1) {
    //  break;
    //}

    // TODO zhaoyou marked element infinity if which if minest.
    //winer_tree[u + lowbit -1] = int_infinity;
    updateWinerTree(winer_tree, all_count, u + lowbit -1, int_infinity);

    //cout << "u: " << u  << endl;
    //displayWinerTree(winer_tree, all_count);
    //if ( j == 9) {
    //  return;
    //}
    //j++;

    //cout << u << endl;

    //if (u != 0) {
    //  return;
    //}

    if (u == end) {
      cout << dist[end] << endl;
      return;
    }
    visted[u] = true;

    vector<pair<int, int> > v = weight[u];


    for (int j = 0; j < v.size(); j++) {
      // v[j].first has not yet been removed
      int index = v[j].first - 1;
      int cost = v[j].second;
      if (!visted[index]) {
        int alt = dist[u] + cost;
        if (alt < dist[index]) {
          dist[index] = alt;
   //       cout << "index: " << index << " value: " << alt << " all_index: " << (index + lowbit - 1) << endl;
          updateWinerTree(winer_tree, all_count, index + lowbit -1, alt);
    //      displayWinerTree(winer_tree, all_count);
        }
      }
    }
  }
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
  readFindCase(weight, city_map, city_count);
}



int main() {
  int test_count;
  scanf("%d", &test_count);
  for (int i = 0; i < test_count; i++) {
    readInput();
  }
}
