//We can either use 2 stacks, or simply one stack with recursion as below


class MyQueue {
public:
    stack<int> s;
    /** Initialize your data structure here. */
    MyQueue()=default;
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if (s.empty())
        {
            s.push(x);
            return;
        }
        int ele=s.top();
        s.pop();
        push(x);
        s.push(ele);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int x=s.top();
        s.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        int x=pop();
        s.push(x);
        return x;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
