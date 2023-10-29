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

vector<vector<string>> groupAnagrams(vector<string> &strs) {
  map<vector<int>, vector<string>> myMap;

  for(string str: strs) {
    vector<int> myVector(26, 0);

    for(char ch: str) {
      myVector[int(ch) - int('a')]++;
    }
    myMap[myVector].push_back(str);
  }

  vector<vector<string>> result;
  map<vector<int>, vector<string>>::iterator key;

  for(key = myMap.begin(); key != myMap.end(); key++) {
    result.push_back(key->second);
  }

  return result;
}

int main() {
  int n;
  cout<<"enter n: ";
  cin>>n;

  vector<string> strs;
  string str;

  for(int i=0;i<n;i++) {
    cin>>str;
    strs.push_back(str);
  }

  vector<vector<string>> result = groupAnagrams(strs);

  for(vector<string> vec: result) {
    for(string str: vec) {
      cout<<str<<", ";
    }
  }

  return 0;
}
