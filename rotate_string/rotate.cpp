#include <iostream>

using namespace std;


// 第一种方式 time o(n*n)  space o(1)

void LeftShiftOne(char *s, int n) {
	char t = s[0];
	for (int i = 1; i < n; i++) {
		s[i-1] = s[i];
	}

	s[n-1] = t;
}

void LeftRotateString(char *s, int n, int m) {
	while(m--) {
		LeftShiftOne(s, n);
	}
}

// 第二种方式 time O(n) space O(1)
void ReverseString(char *s, int from, int to) {
	while(from < to) {
		char temp = s[from];
		s[from++] = s[to];
		s[to--] = temp;
	}
}

void LeftRotateString2(char *s, int n, int m) {
	m = m % n;
	ReverseString(s, 0, m - 1);
	ReverseString(s, m, n-1);
	ReverseString(s, 0, n-1);
}





int main() {
	
	int n;
	int m;
	cin >> n;
	
	char str[n];

  cin >> str;
	cin >> m;
	//LeftRotateString(str, n, m);
	LeftRotateString2(str, n, m);
	cout << str << endl;
	return 0;
}

