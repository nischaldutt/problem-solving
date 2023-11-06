// problem: https://leetcode.com/problems/longest-substring-without-repeating-characters/

/*
    Given string, find longest substring w/o repeating chars
    Ex. s = "abcabcbb" -> 3 "abc", s = "bbbbb" -> 1 "b"

    Sliding window, expand if unique, contract if duplicate

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

int lengthOfLongestSubstring(string s) {
  int result = 0;
  unordered_set<char> mySet;
  int left = 0;
  int right = 0;
  int len = s.size();

  while(right < len) {
    if(mySet.find(s[right]) == mySet.end()) {
      mySet.insert(s[right]);
      result = max(result, right - left + 1);
      right++;
    } else {
      mySet.erase(s[left]);
      left++;
    }
  }
  return result;
}

int main() {
  string s;
  cout<<"enter string: ";
  cin>>s;

  int result = lengthOfLongestSubstring(s);
  cout<<result;
  
  return 0;
}
