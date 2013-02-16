#include <iostream>
#include <cstdio>

using namespace std;

void getOverlay2(string pattern, int *overlay_function) {
    const int pattern_length = pattern.size();
    int index;
    overlay_function[0] = -1;
    for(int i=1;i<pattern_length;++i)
    {
        index = overlay_function[i-1];

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
    //for(int i = 0; i < pattern_length; i++) {
    //  printf("%d\n", overlay_function[i]);
    //}
}

void calc(char *pattern, int *p, int pattern_len) {

  int pattern_index = 0;
  int index = 1;

  char c;
  scanf("%c", &c);

  while(c != '\n') {

    while(c != pattern[pattern_index] && pattern_index > 0 ) {
      pattern_index = p[pattern_index - 1] + 1;
    }
    if (c == pattern[pattern_index]) {
      pattern_index++;
    }

    if (pattern_index == pattern_len) {
      printf("%d\n", index -pattern_index);
      pattern_index = p[pattern_index-1] + 1;
    }

    index++;
    scanf("%c", &c);
  }
  printf("\n");
}


int main() {

  int pattern_len;

  while(scanf("%d\n", &pattern_len) == 1) {
    char pattern[pattern_len + 1];
    scanf("%s\n", &pattern);

    int p[pattern_len];
    getOverlay2(pattern, p);
    calc(pattern, p, pattern_len);
  }
}
