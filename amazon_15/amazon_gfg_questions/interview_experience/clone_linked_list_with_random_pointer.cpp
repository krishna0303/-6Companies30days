#include <bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

/*

A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.

for better understanding watch stribver videos (Copy List with Random Pointer-- search this on youtube)

*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {

        // follow striver approach

        // step1- inserting a new cclone node between nodes
        Node *curr = head, *front = head;
        while (curr != NULL)
        {
            front = curr->next;
            Node *temp = new Node(curr->val);
            curr->next = temp;
            temp->next = front;
            curr = front;
        }

        // step2 assign random pointer value
        curr = head;
        while (curr != NULL)
        {
            if (curr->random != NULL)
            {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        // step3 seperate orginal linked list and cloned linked list

        Node *dummy = new Node(-1);
        Node *copy = dummy;
        curr = head;
        front = head;
        while (curr != NULL)
        {
            front = curr->next->next;
            copy->next = curr->next;
            curr->next = front;
            copy = copy->next;
            curr = curr->next;
        }
        return dummy->next;
    }
};