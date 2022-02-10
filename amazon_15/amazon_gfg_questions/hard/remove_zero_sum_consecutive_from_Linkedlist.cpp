#include<bits/stdc++.h>
using namespace std;


//   Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 

/*
Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.

After doing so, return the head of the final linked list.  You may return any such answer.

 

(Note that in the examples below, all sequences are serializations of ListNode objects.)

Example 1:

Input: head = [1,2,-3,3,1]
Output: [3,1]
Note: The answer [1,2,1] would also be accepted.

Approach: 
Take a pointer ptr pointing towards head;
Take integer variable sum initialize it as 0.
now iterate the linked list through pointer ptr and on each iteration add value of node in sum.
check if sum becomes zero or not, if it become zero then make head next to ptr pointer and again make sum to zero and continue the interation.
After this call the removeZeroSumSublists function and give next node of head as parameter.
the return value from the recursive call will store in next node of head.
The recursive call will be continue until the head become NULL.
*/
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
          
        if(head==NULL){
            return head;
        }
        struct ListNode* ptr=head;
        int sum=0;
        while(ptr!=NULL){
            sum+=(ptr->val);
            if(sum==0){
                head=ptr->next;
                sum=0;
                // break;
            }
            ptr=ptr->next;
        }
         if(head!=NULL)
        head->next=removeZeroSumSublists(head->next);
        return head;
    }
};