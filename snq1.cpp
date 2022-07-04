class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int a;
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        a=s2.top();
        s2.pop();
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return a;
    }
    
    int peek() {
        int a;
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        a=s2.top();
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return a;
    }
    
    bool empty() {
        if(s1.empty())
            return true;
        else 
            return false;
    }
    
private:
    stack<int> s1,s2;
};















class MyQueue {
public:
    stack <int> st1,st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        int y;
        if(st2.empty()) {
            while(!st1.empty()){
                y=st1.top();
                st1.pop();
                st2.push(y);
            }
        }
        int temp=st2.top();
        st2.pop();
        return temp;
    }
    
    int peek() {
        int y;
        if(st2.empty()) {
            while(!st1.empty()){
                y=st1.top();
                st1.pop();
                st2.push(y);
            }
        }
        return st2.top();
    }
    
    bool empty() {
        return st1.empty() && st2.empty();
    }
};

















#include<vector>
class MyQueue {
public:
    vector<int> stack1;
    vector<int> stack2;
    MyQueue() {
        
    }
    
    void push(int x) {
        stack1.push_back(x);
    }
    
    int pop() {
        if(stack2.empty()) {
            while(!stack1.empty()) {
                stack2.push_back(stack1.back());
                stack1.pop_back();
            }
        }
        int temp = stack2.back();
        stack2.pop_back();
        return temp;
    }
    
    int peek() {
        if(stack2.empty()) {
            while(!stack1.empty()) {
                stack2.push_back(stack1.back());
                stack1.pop_back();
            }
        }
        return stack2.back();
    }
    
    bool empty() {
        return stack2.empty() && stack1.empty();
    }
};

























Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
Notes:

You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.
 

Example 1:

Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]

Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
 

Constraints:

1 <= x <= 9
At most 100 calls will be made to push, pop, peek, and empty.
All the calls to pop and peek are valid.
