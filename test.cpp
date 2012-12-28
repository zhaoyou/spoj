#include <iostream>
#include <string>

using namespace std;

int main() {
  string word;
  while(cin >> word) {
    if (word == "42") {
      return 0;
    }
    cout << word << endl;
  }
}
