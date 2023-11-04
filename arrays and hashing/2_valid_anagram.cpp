//problem: https://leetcode.com/problems/valid-anagram

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

bool isAnagram(string s, string t) {
  int slen= s.size();
  int tlen = t.size();
  if(slen != tlen) return false;

  unordered_map<char, int> myMap;
  for(int i=0;i<slen;i++) {
    myMap[s[i]]++;
  }

  for(int j=0;j<tlen;j++) {
    if(!myMap[t[j]]) return false;
    else {
      if(myMap[t[j]] == 0) return false;
      else {
        myMap[t[j]]--;
      }
    }
  }
  return true;
}

int main() {
  string s, t;

  cout<<"enter s: ";
  cin>>s;

  cout<<"enter t: ";
  cin>>t;

  bool result = isAnagram(s, t);
  string str = result == true ? "true" : "false";
  cout<<str;

  return 0;
}
