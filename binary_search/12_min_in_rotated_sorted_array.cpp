// problem: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

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

int findMin(vector<int> &nums) {
  int result = nums[0];
  int len = nums.size();
  int start = 0;
  int end = len - 1;

  while(start <= end) {
    if(nums[start] < nums[end]) {
      result = min (result, nums[start]);
      return result;
    }

    int mid = start + ((end - start) / 2);
    result = min(result, nums[mid]);

    if(nums[start] > nums[mid]) end = mid - 1;
    else start = mid + 1;
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

  int result = findMin(nums);
  cout<<result;

  return 0;
}
