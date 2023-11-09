// problem: https://leetcode.com/problems/search-in-rotated-sorted-array/

/*
  *find index of an element in a rotated sorted array
  * input: enter array length: 8
  * 11 12 15 18 2 5 6 8
  * output: 2
  * time complexity: O(logn) + O(logn) + O(logn) = O(logn)
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

int binarySearch(vector<int> &nums, int start, int end, int target) {
  int len = nums.size();

  while(start <= end) {
    int mid = start + ((end - start) / 2);

    if(nums[mid] == target) return mid;
    else if(nums[mid] > target) end = mid - 1;
    else start = mid + 1;
  }

  return -1;
}

int findMin(vector<int> &nums) {
  int len = nums.size();
  int start = 0;
  int end = len - 1;

  while(start <= end) {
    if(nums[start] <= nums[end]) return start;

    int mid = start + ((end - start) / 2);
    int prev = (mid + len - 1) % len;
    int next = (mid + 1) % len;

    if(nums[mid] < nums[prev] && nums[mid] < nums[next]) return mid;
    
    if(nums[start] <= nums[mid]) start = mid + 1;
    else if(nums[mid] <= nums[end]) end = mid - 1;
  }
  return -1;
}

int search(vector<int> &nums, int target) {
  int len = nums.size();
  int minIndex = findMin(nums);
  cout<<minIndex;
  if(nums[minIndex] == target) return minIndex;

  int leftIndex = binarySearch(nums, 0, (minIndex + len - 1) % len, target);
  int rightIndex = binarySearch(nums, (minIndex + 1) % len, len - 1, target);

  int result = -1;
  if(leftIndex != -1) result = leftIndex;
  if(rightIndex != -1) result = rightIndex;

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

  int result = search(nums, target);
  cout<<result;

  return 0;
}