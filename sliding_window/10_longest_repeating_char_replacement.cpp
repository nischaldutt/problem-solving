// problem: https://leetcode.com/problems/longest-repeating-character-replacement/

/*
    Given a string s & an int k, can change any char k times:
    Return length of longest substring containing same letter
    Ex. s = "ABAB" k = 2 -> 4 "AAAA", s = "AABABBA" k = 1 -> 4

    Sliding window, expand if can change char, contract if > k

    Time: O(n)
    Space: O(26)
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

int characterReplacement(string s, int k) {
  int len = s.size();
  if(len == 1) return 1;

  int maxWindowSize = 0;
  int maxFreqCharCount = 0;
  int start = 0;
  vector<int> frequencies(26, 0);
  

  for(int end=0;end<len;end++) {
    frequencies[s[end] - 'A']++;
    maxFreqCharCount = max(maxFreqCharCount, frequencies[s[end] - 'A']);

    while(end - start + 1 - maxFreqCharCount > k) {
      frequencies[s[start] - 'A']--;
      start++;
    }
    maxWindowSize = max(maxWindowSize, end - start + 1);
  }
  return maxWindowSize;
}

int main() {
  string s;
  cout<<"enter string: ";
  cin>>s;

  int k;
  cout<<"enter k: ";
  cin>>k;

  int result = characterReplacement(s, k);
  cout<<result;
  
  return 0;
}
