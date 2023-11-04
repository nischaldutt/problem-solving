//problem: https://leetcode.com/problems/contains-duplicate/

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

bool containsDuplicate(vector<int> &nums) {
  if(nums.size() == 1) return false;

  unordered_map<int, int> myMap;
  for(int n: nums) {
    if(!myMap[n]) {
      myMap[n]++;
    } else {
      return true;
    }
  }
  return false;
}

int main() {
  int n;
  cout<<"enter n: ";
  cin>>n;

  vector<int> nums;
  int x;

  for(int i=0;i<n;i++) {
    cin>>x;
    nums.push_back(x);
  }

  bool result = containsDuplicate(nums);
  string str = result == true ? "true" : "false";
  cout<<str;

  return 0;
}
