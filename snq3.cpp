class MyStack {
public:
    queue <int> q1, q2;
    MyStack() {}
    
    void push(int x) {
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
    }
    
    int pop() {
        int n = q2.front();
        q2.pop();
        return n;
    }
    
    int top() {
        return q2.front();
    }
    
    bool empty() {
        return q2.empty();
    }
};

















queue<int> q;
    MyStack() {
    }
    
    void push(int x) {
        if(q.empty()){
            q.push(x);
        }else{
            int n = q.size();
            q.push(x);
            while(n--){
                q.push(q.front());
                q.pop();
            }
        }
    }
    
    int pop() {
        int res = q.front();
        q.pop();
        return res;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }



















  int size_queue = 0;
queue<int>first;

class MyStack {
public:
    MyStack() {
        size_queue = 0;
        first = queue<int>();
        
    }
    
    void push(int x) {
        first.push(x);
        size_queue++;
    }
    
    int pop() {
        int top;
        if(size_queue < 1) return -1;
        for(int i =0;i<size_queue;i++){
            top = first.front();
            first.pop();
            if(i != size_queue - 1){
                first.push(top);
            }
        }
        size_queue--;
        return top;
        
    }
    
    int top() {
        int top;
        if(size_queue < 1) return -1;
        for(int i =0;i<size_queue;i++){
            top = first.front();
            first.pop();            
            first.push(top);            
        }
        
        return top;
    }
    
    bool empty() {
        return first.empty();
    }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

Implement the MyStack class:

void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.
Notes:

You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.
Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.
 

Example 1:

Input
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 2, 2, false]

Explanation
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False
 

Constraints:

1 <= x <= 9
At most 100 calls will be made to push, pop, top, and empty.
All the calls to pop and top are valid.
 
  
  
  
  

};
