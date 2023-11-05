// problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

/*
    Given array prices, return max profit w/ 1 buy & 1 sell
    Ex. prices = [7,1,5,3,6,4] -> 5 (buy at $1, sell at $6)

    For each, get diff b/w that & min value before, store max

    Time: O(n)
    Space: O(1)
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

int maxProfit(vector<int> &prices) {
  int result = 0;
  int len = prices.size();

  if(len < 2) return result;

  int left = 0;
  int right = 1;
  while(left < right && (right < len)) {
    if(prices[left] > prices[right]) left = right;
    else if(prices[left] < prices[right]) result = max(result, prices[right] - prices[left]);
    right++;
  }
  return result;
}

int main() {
  int n;
  cout<<"enter n: ";
  cin>>n;

  vector<int> prices;
  int x;

  for(int i=0;i<n;i++) {
    cin>>x;
    prices.push_back(x);
  }

  int result = maxProfit(prices);
  cout<<result;
  
  return 0;
}
