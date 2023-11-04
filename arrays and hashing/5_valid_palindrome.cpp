//problem: https://leetcode.com/problems/valid-palindrome/

#include <bits/stdc++.h>

#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include<map>
#include<unordered_map>

#define null nullptr
#define fori for (int i = 0; i < n; i++)
#define forj for (int j = 0; j < m; j++)
#define fork for (int k = 0; k < o; k++)

using namespace std;

typedef pair<int, int> pi;
typedef pair<int, pair<int, int>> ppi;

bool isPalindrome(string s) {
  int left = 0;
  int right = s.size() - 1;

  while(left < right) {
    while(left < right && !isalnum(s[left])) left += 1;
    while(left < right && !isalnum(s[right])) right -= 1;
    if(tolower(s[left]) != tolower(s[right])) return false;
    left += 1;
    right -= 1;
  }
  return true;
}

int main() {
  string s;
  cout<<"enter string: ";
  cin>>s;

  bool result = isPalindrome(s);
  string str = result == true ? "true" : "false";
  cout<<str;

  return 0;
}
