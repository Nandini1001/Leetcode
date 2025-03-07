class MyStack {
private:
    //queue<int>q;
    queue<int>q1;
    queue<int>q2;
public:
    MyStack() {
    }
    
    void push(int x) {
        q2.push(x);
        while(!q1.empty())
        {
            int n=q1.front();
            q1.pop();
            q2.push(n);
        }
        swap(q1,q2);
        /*int s=q.size();
        q.push(x);
        for(int i=0;i<s;i++)
        {
            q.push(q.front());
            q.pop();
        }*/
    }
    
    int pop() {
        /*int x=q.front();
        q.pop();
        return x;*/
        int x=q1.front();
        q1.pop();
        return x;
    }
    
    int top() {
        //return q.front();
        return q1.front();
    }
    
    bool empty() {
        /*int s=q.size();
        return !s;*/
        return q1.empty();
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