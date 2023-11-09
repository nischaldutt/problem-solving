// problem: https://leetcode.com/problems/valid-parentheses/

/*
    Given s w/ '(, ), {, }, [, ]', determine if valid
    Ex. s = "()[]{}" -> true, s = "(]" -> false

    Stack of opens, check for matching closes & validity

    Time: O(n)
    Space: O(n)
*/

#include <bits/stdc++.h>

#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <unordered_set>
#include <unordered_map>

#define null nullptr
#define fori for (int i = 0; i < n; i++)
#define forj for (int j = 0; j < m; j++)
#define fork for (int k = 0; k < o; k++)

using namespace std;

typedef pair<int, int> pi;
typedef pair<int, pair<int, int>> ppi;

bool isValid(string s) {
  stack<char> openBracketsStack;
  unordered_map<char, char> myMap = {
    { ')', '(' },
    { ']', '[' },
    { '}', '{' }
  };

  for(char ch: s) {
    if(myMap.find(ch) != myMap.end()) {
      if(openBracketsStack.empty()) return false;

      if(myMap[ch] == openBracketsStack.top()) openBracketsStack.pop();
      else return false;
    } else {
      openBracketsStack.push(ch);
    }
  }
  return openBracketsStack.empty();
}

int main() {
  string s;
  cout<<"enter string: ";
  cin>>s;

  bool result = isValid(s);
  string str = result == true ? "true" : "false";
  cout<<str;

  return 0;
}
