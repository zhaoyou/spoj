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

bool isSingle(string input) {
  if (input.size() == 1) {
    return checkFirstChar(input);
  } else {
    for (int i = 0; i < input.size(); i++) {
      if ((input[i] == '_' && (i != input.size() -1)) || (input[i] >= 'A' && input[i] <= 'Z')) {
        return false;
      }
    }
    return true;
  }
}

bool checkValid(string input) {
  // check first char.
  if (checkFirstChar(input) && checkLastChar(input)) {
    bool javaFlag = false;
    bool cFlag = false;
    for (int i = 0; i < input.size(); i++) {

      if ((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z') || input[i] == '_' ) {

        if (input[i] == '_') {
          if (cFlag) {
            return false;
          }

          cFlag = true;
        }

        if(input[i] >= 'A' && input[i] <= 'Z') {
          javaFlag = true;
        }

      } else {
        return false;
      }
    }

    if (javaFlag && cFlag) {
      return false;
    } else {
      return true;
    }
  } else {
    return false;
  }
}

string trans(string input) {
  // check valid.
  if (checkValid(input)) {
    // check is single .
    if (isSingle(input)) {
      //cout  << input << " is a single" << endl;
      return input;
    } else {

      //cout  << input << " is not single" << endl;
      // is c++ var
      if (checkIsC(input)) {

        //cout  << input << " is a c var" << endl;
        return transToJava(input);
      } else { // is java var.

        //cout  << input << " is a java var" << endl;
        return transToC(input);
      }
    }
  } else {
    //cout  << input << " is not valid" << endl;
    return "Error!";
  }
}

int main() {
  string word;
  while(cin >>  word) {
    //cout << checkIsC(word) << endl;
    string s = trans(word);
    //string s2 = trans(s);
    //if ( s2 == word) {
      cout << s  << endl;
    //} else {
    //  cout << "Error!" << endl;
    //}
  }
  return 0;
}
