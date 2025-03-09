class MinStack {
private:
    stack<long> st;
    long min;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty())
        {
            st.push(val);
            min=val;
        }
        else if(min>val)
        {
            long newval=2l*val-min;
            min=val;
            st.push(newval);
        }
        else    
            st.push(val);
    }
    
    void pop() {
        if(st.empty()) return;
        long x=st.top();
        st.pop();
        if(x<min)
            min=2l*min-x;
    }
    
    int top() {
        if(st.empty()) return -1;
        long x=st.top();
        if(x<min) return min;
        return x;
    }
    
    int getMin() {
        if(st.empty()) return -1;
        return min;
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