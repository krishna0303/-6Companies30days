
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // watch striver video for beter understanding greta explanation
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL)
        {
            return NULL;
        }
        ListNode *temp = head, *temp1 = head, *prev;
        int count = 0;
        while (temp != NULL)
        {
            count += 1;
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        k = k % count;
        temp = head;
        int count1 = 0;
        while (temp != NULL)
        {
            count1 += 1;
            if (count1 == (count - k))
            {
                head = temp->next;
                temp->next = NULL;
                break;
            }
            temp = temp->next;
        }
        return head;
    }
};