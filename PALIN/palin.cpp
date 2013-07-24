#include <iostream>
#include <string>
#include <sstream>


/**
 * @author zhaoyou.xt@gmail.com (zhaoyou)
 */

using namespace std;

void display(string *source, int size);



bool isAll9(string source) {
  bool flag = true;
  for (int i = 0; i < source.size(); i++) {
    if (source[i] != '9') {
      flag = false;
      break;
    }
  }
  return flag;
}



string doAddOne(string source) {
  for (int j = source.size()-1; j >=0; j--) {
    if (source[j] == '9') {
      source[j] = '0';
      //return doAddOne(source, index - 1);
    } else {
      int ss = source[j];
      ss++;
      source[j] = ss;
      return source;
    }
  }

}


string addOne(string source) {
  if (isAll9(source)) {
      string tt = "1";
      for (int j = 0; j < source.size(); j++) {
        tt.append("0");
      }
      return tt;
  }
  return doAddOne(source);
}


string makePalindrome(string source) {
  int size = source.size();
  for (int i = 0; i < (size/2); i++) {
    source[size - i -1] = source[i];
    //source.replace(size - 1 -i, 1, source.substr(i, 1));
  }
  return source;
}

void test(string *source,  int size) {
  for (int i = 0; i < size; i++) {
    string s;
    // get add 1.
    string newsource;
    newsource = addOne(source[i]);

    int inner_size = newsource.size();

    bool flag = true;
    for (int j = (inner_size/2 -1) ;j >= 0; j--) {
      if ( newsource[j] != newsource[inner_size - j -1]) {
        int s;
        int t;
        stringstream(newsource.substr(j, 1)) >> s;
        stringstream(newsource.substr(inner_size - j -1, 1)) >> t;
        if (s > t) {
          source[i]  = makePalindrome(newsource);
        } else {


          string need = newsource.substr(0, (inner_size/2 + inner_size%2));
          string newprefix = addOne(need);
          newsource.replace(0, need.size(), newprefix);
          source[i]  = makePalindrome(newsource);

        }
        flag = false;
        break;
      }
    }

    if (flag) {
      source[i] = newsource;
    }

  }
}

int main() {

  int number;
  int i = 0;

  cin >> number;

  string source[number];

  while(i < number) {
    cin >> source[i];
    i++;
  }

 test(source, number);
 display(source, number);
 return 0;
}


void display(string *source, int size) {
  for (int i = 0; i < size; i++) {
    cout << source[i] << endl;
  }
}
