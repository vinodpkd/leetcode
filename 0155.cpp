class MinStack {
    	std::stack<int> st;
	int min;
	int size {0};
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
		size++;
		if(0 == size)
			min = val;
		else
		{
			if(val < min)
				min = val;
		}
    }
    
    void pop() {
        st.pop();
		size--;
    }
    
    int top() {
		if(0 != size)
			return st.top();
		else
			return -1;
    }
    
    int getMin() {
        //if(0 != size)
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
