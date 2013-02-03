#include <iostream>
#include <cstdio>

using namespace std;

void getOverlay(string pattern, int *p) {

  int m = pattern.size();

  p[0] = -1;

  for (int i = 0; i < m ;i++) {
    int index = -1;

    string sub = pattern.substr(0, i+1);

    int sub_size  = sub.size();
    for(int j = 1; j < sub_size; j++) {
      if (sub.substr(0, sub_size - j ) == sub.substr(j , sub_size)) {
        index = sub_size - j -1;
        break;
      }
    }
    p[i] = index;

    //cout << "substring: " << sub << " index: " << index << endl;
  }
}

void getOverlay2(string pattern, int *overlay_function) {
    const int pattern_length = pattern.size();
    int index;
    overlay_function[0] = -1;
    for(int i=1;i<pattern_length;++i)
    {
        index = overlay_function[i-1];
        //store previous fail position k to index;

        while(index>=0 && pattern[i]!=pattern[index+1])
        {
            index = overlay_function[index];
        }
        if(pattern[i]==pattern[index+1])
        {
            overlay_function[i] = index + 1;
        }
        else
        {
            overlay_function[i] = -1;
        }
    }
    //for(int i=0;i<pattern_length;++i)
    //{
    //    cout<<overlay_function[i]<<endl;
    //}
    //delete[] overlay_function;
}

int main() {

  int pattern_len;

  while(cin >> pattern_len) {
    string pattern;
    cin >> pattern;

    int p[pattern_len];
    //getOverlay(pattern, p);
    getOverlay2(pattern, p);
    int pattern_index = 0;
    int index = 0;


    char c;
    scanf("%c", &c);
    scanf("%c", &c);
    //cout << "len: " << pattern_len << " pattern: " << pattern << " c: " << c << endl;
    while(c != '\n') {
      while(c == pattern[pattern_index] && pattern_index < pattern_len) {
        pattern_index ++;
        index ++;
        scanf("%c", &c);
      }

      if (pattern_index == pattern_len) {
         cout << index - pattern_len << endl;
         pattern_index = p[pattern_len -1] + 1;
      } else if(pattern_index == 0) {
        index++;
        scanf("%c", &c);
      } else {
        pattern_index = p[pattern_index] + 1;
      }
    }
    cout << endl;
  }
}

