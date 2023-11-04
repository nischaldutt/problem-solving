//problem: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

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

vector<int> twoSum2(vector<int> &numbers, int target) {
  vector<int> result;
  int start = 0;
  int end = numbers.size() - 1;

  while(start < end) {
    int sum = numbers[start] + numbers[end];

    if(sum > target) end--;
    else if (sum < target) start++;
    else {
      result.push_back(start+1);
      result.push_back(end+1);
      break;
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


  vector<int> result = twoSum2(nums, target);
  for(int n: result) {
    cout<<n<<" ";
  }
  return 0;
}
