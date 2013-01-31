#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdlib>

using namespace std;

int BFMatch(char *s,char *p)
{
    int i,j;
    i=0;
    while(i<strlen(s))
    {
        j=0;
        while(s[i]==p[j]&&j<strlen(p))
        {
            i++;
            j++;
        }
        if(j==strlen(p)) {
          cout << "i: " << i <<  " j: " << j << " strlen(p): " << strlen(p) << endl;
            return i-strlen(p);
        }
        i=i-j+1;                //指针i回溯
    }
    return -1;
}

int main() {
  char source[10];
  char pattern[5];
  scanf("%s", source);
  scanf("%s", pattern);
  cout << "result: " << BFMatch(source, pattern) << endl;
  return 0;
}
