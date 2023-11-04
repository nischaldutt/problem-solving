//problem: https://leetcode.com/problems/two-sum/

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

vector<int> twoSum(vector<int> &nums, int target) {
  vector<int> result;
  unordered_map<int, int> myMap;
  int len = nums.size();

  for(int i=0;i<len;i++) {
    int currentValue = nums[i];
    int neededValue = target - currentValue;

    if(myMap.find(neededValue) == myMap.end()) {
      myMap[currentValue] = i;
    } else {
      result.push_back(myMap[neededValue]);
      result.push_back(i);
      return result;
    }
  }
  return result;
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

  int target;
  cout<<"enter target: ";
  cin>>target;


  vector<int> result = twoSum(nums, target);
  for(int n: result) {
    cout<<n<<" ";
  }
  return 0;
}
