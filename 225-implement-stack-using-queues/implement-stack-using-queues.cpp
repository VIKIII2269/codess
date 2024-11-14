class MyStack {
public:
queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        int c=q.size();
        q.push(x);
        for (int i=0;i<c;i++)
        {
            q.push(q.front());
            q.pop();
        }
        
    }
    
   int pop() {
        int val = q.front();
        q.pop();
        return val;
    }
    
    int top() {
       return q.front();
        
    }
    
    bool empty() {
        int a=q.size();
        if (a==0)
        return true;
        return false;
        
        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */