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

bool isMidValid(vector<int> nums, int k, int max) {
  int len = nums.size();
  int count = 1;
  int sum = 0;
  for(int i=0; i<len; i++) {
    sum += nums[i];
    if(sum > max) {
      count++;
      sum = nums[i];
    }
    if(count > k) return false;
  }
  return true;
}

int allocateMinNumOfPages(vector<int> nums, int k) {
  int len = nums.size();
  int result = -1;
  if(len < k) return result;

  int start = *max_element(nums.begin(), nums.end());
  int end = 0;
  for(int i=0;i<len;i++) end += nums[i];

  while(start <= end) {
    int mid = start + ((end-start) / 2);
    if(isMidValid(nums, k, mid) == true) {
      result = mid;
      end = mid -1;
    } else {
      start = mid + 1;
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

  int k;
  cout<<"enter k: ";
  cin>>k;

  int result = allocateMinNumOfPages(nums, k);
  cout<<result;

  return 0;
}