#include <iostream>
#include <string>
#include <sstream>
#include <fstream>


/**
 * @author zhaoyou.xt@gmail.com (zhaoyou)
 */

using namespace std;


string transToC(string input) {
  string s = "";
  for(int i = 0; i < input.size(); i++) {
    if (input[i] >= 'A' && input[i] <= 'Z') {
      char upchar = input[i] + 32;
      stringstream ss;
      ss << upchar;

      s.append("_");
      s.append(ss.str());
    } else {
      stringstream ss;
      ss << input[i];
      s.append(ss.str());
    }
  }
  return s;
}

string transToJava(string input) {
  string s = "";
  // to Upper case.
  for(int i = 0; i < input.size(); i++) {
    if (input[i] == '_') {
      stringstream ss;

      input[i+1] = input[i+1] - 32;
      ss << input[i + 1];
      i++;
      s.append(ss.str());
    } else {
      stringstream ss;
      ss << input[i];
      s.append(ss.str());
    }
  }

  // remove '_' char.
  //replace(input.begin(), input.end(), '_', '');
  return s;
}

bool checkIsJava(string input) {
  for(int i = 0; i < input.size(); i++) {
    if (input[i] >= 'A' && input[i] <= 'Z') {
      return true;
    }
  }
  return false;
}


bool checkIsC(string input) {
  string pattern ("_");
  size_t found;
  found = input.find(pattern);
  if (found != string::npos) {
    //cout << int(found);
    return true;
  } else {
    return false;
  }
}

bool checkFirstChar(string input) {
  if ((input[0] >= 'a' && input[0] <= 'z')) {
    return true;
  } else {
    return false;
  }
}

bool checkLastChar(string input) {
  int size = input.size();
  if ((input[size -1] >= 'a' && input[size-1] <= 'z' ) ||
      (input[size-1] >= 'A' && input[size-1] <= 'Z')) {
    return true;
  }
  return false;
}


bool checkValid(string input) {
  // check first char.
  if (checkFirstChar(input) && checkLastChar(input)) {
    bool javaFlag = false;
    int c_count = 0;
    for (int i = 0; i < input.size(); i++) {
      // check char is a-z, A-Z, or _.
      if ((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z') || input[i] == '_' ) {

        if (input[i] == '_' && input[i-1] == '_') return false;
        if (input[i] == '_') c_count++;


        if(input[i] >= 'A' && input[i] <= 'Z') {
          javaFlag = true;
        }

      } else {
        return false;
      }
    }

    if (c_count != 0 && javaFlag) {
      return false;
    } else {
      return true;
    }
  } else {
    return false;
  }
}

string trans(string input) {

  if (checkValid(input)) {
      //cout  << input << " is not single" << endl;
      if (checkIsC(input)) {
        //cout  << input << " is a c var" << endl;
        return transToJava(input);
      } else if (checkIsJava(input)) {
        //cout  << input << " is a java var" << endl;
        return transToC(input);
      } else {
        return input;
      }
  } else {
    //cout  << input << " is not valid" << endl;
    return "Error!";
  }
}

int main() {
  string word;
  while(cin >>  word) {
    string s = trans(word);
    cout << s << endl;
  }
  return 0;
}
