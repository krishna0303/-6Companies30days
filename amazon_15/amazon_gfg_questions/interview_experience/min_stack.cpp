
#include <bits/stdc++.h>
using namespace std;

/*

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.


*/

class MinStack
{
public:
    stack<int> s1, s2;
    MinStack()
    {
    }

    void push(int val)
    {
        s1.push(val);
        if (s2.empty() || s2.top() >= val)
        {
            s2.push(val);
        }
    }

    void pop()
    {
        if (s1.top() == s2.top())
        {
            s2.pop();
        }
        s1.pop();
    }

    int top()
    {
        return s1.top();
    }

    int getMin()
    {
        return s2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

/*

/*
    Using link-list to implement min stack. Each node has next pointer and the current min value.
    Once a node is poped, the current_min will be updated automatically.
    Time complexity: O(1)
    Space complexity: O(n)

class Node {
public:
    int val;
    Node* next;
    int current_min;
};

class MinStack {
public:
    MinStack() {
        head = NULL;
    }

    void push(int val) {
        Node* tmp = new Node();
        tmp->val = val;
        tmp->next = head;
        if(head)
            tmp->current_min = min(val, head->current_min);
        else
            tmp->current_min = val;
        head = tmp;
    }

    void pop() {
        head = head->next;
    }

    int top() {
        return head->val;
    }

    int getMin() {
        return head->current_min;
    }
private:
    Node* head;
};


*/

/*

I am surprised how no one has actually mentioned this solution. Here is my approach:

Maintain a vector of pairs. First element in the pair represents the actual value. The second element in the pair is the minimum value encountered so far.
If the vector is empty or if the new value to be pushed into the stack is smaller than the second element(smallest value encountered so far) of the last element of the vector, then push {new value, new value} into the vector, else push {new value, second element of the last element of vector} into the vector.
To get the min element, simply return the second element of the last element of the vector
To get the top element, simply return the first element of the last element of the vector.
Time Complexity : O(1) for all operations
Space Complexity: O(n) for saving the vector of pairs

class MinStack {
public:
    vector<pair<int,int > > vec;
    MinStack() {

    }

    void push(int val) {
        if(vec.size()==0 || val<vec[vec.size()-1].second) {
            vec.push_back({val, val});
        } else {
            vec.push_back({val, vec[vec.size()-1].second});
        }
    }


    void pop() {
        vec.pop_back();
    }

    int top() {
        return vec[vec.size()-1].first;
    }

    int getMin() {
        return vec[vec.size()-1].second;
    }
};

*/