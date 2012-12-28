#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

/**
 *  @author zhaoyou.xt@gmail.com
 */
using namespace std;

string make(int a, int b) {

  string result = "";
  if (a == b) {
    return "";
  }

  if ( a > b) {
    //stringstream t1;
    //t1 << b  << "/" << a - b;
    result.append("R");
    result.append(make(b, a-b));
  } else if (a < b) {
   // stringstream t2;
   // t2 << (b -a) << "/" << a;
    result.append("L");
    result.append(make(b-a, a));
  }
  return result;
}

int main() {
  string input;
  int number;
  cin >> number;
  for(int i = 0; i < number; i++) {
    string input;
    cin >> input;
    int a;
    int b;
    size_t sp = input.find("/");
    stringstream(input.substr(0, int(sp))) >> a;
    stringstream(input.substr(int(sp) + 1, input.size())) >> b;

    cout << make(a, b) << endl;
  }
}
