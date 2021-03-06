/*
155. Min Stack

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/

class MinStack {
public:
    void push(int x) {
        s.push(x);
        if(minInt.empty()) {
            minInt.push(x);
        } else if(minInt.top() >= x) {
            minInt.push(x);
            return;
        }
    }
    
    void pop() {
        if(!s.empty()) {
            if(minInt.top() == s.top()) {
                s.pop();
                minInt.pop();
            }
            else {
                s.pop();
            }
        }
        return;
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minInt.top();
    }
    
private:
    stack<int> s;
    stack<int> minInt;
};
