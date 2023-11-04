// problem: https://leetcode.com/problems/3sum/

/*
    Given int array, return all unique triplets that sum to 0
    Ex. nums = [-1,0,1,2,-1,-4] -> [[-1,-1,2],[-1,0,1]]

    Sort, for each i, have j & k go outside in, check for 0 sums

    Time: O(n^2)
    Space: O(n)
*/

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

vector<vector<int>> threeSum(vector<int> &nums) {
  vector<vector<int>> results;
  int len = nums.size();

  if(len < 3) return results;

  sort(nums.begin(), nums.end());

  for(int i=0;i<len;i++) {
    if(i > 0 && nums[i] == nums[i-1]) continue;

    int start = i + 1;
    int end = len - 1;
    while(start < end) {
      int threeSum = nums[i] + nums[start] + nums[end];
      
      if(threeSum > 0 ) end--;
      else if(threeSum < 0) start++;
      else {
        results.push_back({ nums[i], nums[start], nums[end] });
        start++;

        while(start < end && nums[start] == nums[start - 1]) start++;
      }
    }
  }

  return results;
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

  vector<vector<int>> result = threeSum(nums);

  for(vector<int> triplet: result) {
    for(int n: triplet) {
      cout<<n<<" ";
    }
  }
  
  return 0;
}
