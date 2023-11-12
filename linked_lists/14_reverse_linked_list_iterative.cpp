// problem: https://leetcode.com/problems/reverse-linked-list/

/*
    Given the head of a singly linked list, reverse list & return
    Ex. head = [1,2,3,4,5] -> [5,4,3,2,1], head = [1,2] -> [2,1]

    Maintain prev, curr pointers, iterate thru & reverse

    Time: O(n)
    Space: O(1)
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

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void insertAthead(ListNode*& head, int data) {
  ListNode* n = new ListNode(data);
  n->next = head;
  head = n;
}

ListNode* insertAtEnd(ListNode*& prev, int data) {
  ListNode* n = new ListNode(data);
  if(prev != NULL) {
    prev->next = n;
  }
  n->next = NULL;
  return n;
}

void printLinkedList(ListNode*& head) {
  ListNode* itr = head;
  while(itr != NULL) {
    cout<<itr->val<<" ";
    itr = itr->next;
  }
}

ListNode* reverseList(ListNode* head) {
  ListNode* prev = NULL;
  ListNode* curr = head;
  ListNode* temp = NULL;

  while(curr != NULL) {
    temp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = temp;
  }

  return prev;
}

int main() {
  int n;
  cout<<"enter n: ";
  cin>>n;

  ListNode* head = NULL;
  ListNode* tail = NULL;
  int x;

  for(int i=0;i<n;i++) {
    cin>>x;
    tail = insertAtEnd(tail, x);
    if(i == 0) head = tail;
  }

  // printLinkedList(head);
  head = reverseList(head);
  printLinkedList(head);
  return 0;
}
