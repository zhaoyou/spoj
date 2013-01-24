#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <limits>
#include <climits>
#include <cmath>
#include <list>
#include <map>
#include <cmath>

#define  LETTER_LEN 10

using namespace std;

int int_infinity = INT_MAX >> 1;

void readTestCase() {
  int test_case = 1;
  while(true) {

    int n,c,r;
    scanf("%d %d %d", &n, &c, &r);
    if (n == 0 && c == 0 && r == 0) {
      break;
    }


    int dist[n][n];

    // init.
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if ( i == j ) {
          dist[i][j] = 0;
        } else {
          dist[i][j] = int_infinity;
        }
      }
    }

    string car[c];
    string city[n];
    char start[11];
    scanf("%s", start);
    //cout << "start: " << start << endl;

    for (int i = 0; i < c; i++) {
      char w[11];
      scanf("%s", &w);
      car[i] = w;
      //cout << w << " " ;
    }
    //cout << endl;

    int index = 1;
    map<string, int> citymap;
    citymap[start] = 0;
    map<string, int>::iterator it;

    bool start_direct = false;
    bool end_direct = false;

    for(int i = 0; i < r; i++) {
      char start_city[11];
      char start_direct;
      int v;
      char end_city[11];
      char end_direct;

      scanf("%s %c-%d-%c %s", &start_city, &start_direct, &v, &end_direct, &end_city);


      it = citymap.find(start_city);
      if (it == citymap.end()) {
        citymap[start_city] = index++;
      }

      it = citymap.find(end_city);
      if (it == citymap.end()) {
        citymap[end_city] = index++;
      }


      //cout << start_city << start_direct << v << end_direct << end_city<< endl;

      int start_index = citymap[start_city];
      int end_index = citymap[end_city];

      if (start_direct == '<') {
        if (v < dist[end_index][start_index]) {
          dist[end_index][start_index] = v;
        }
      }

      if (end_direct  == '>') {
        if (v < dist[start_index][end_index]) {
          dist[start_index][end_index] = v;
        }
      }

    }


    for(int k = 0; k < n; k++) {
      for(int i = 0; i < n ;i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][k] + dist[k][j] < dist[i][j]) {
              dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
      }
    }

    int total = 0;
    for (int i = 0; i < c; i++) {
      index = citymap[car[i]];
      //cout << "index: " << index << " start: " << dist[0][index] << " end: " << dist[index][0] << endl;
      total +=  dist[0][index];
      total +=  dist[index][0];
    }

    cout << test_case++ << ". "  << total << endl;
  }

}

int main() {

  readTestCase();
  return 0;
}

