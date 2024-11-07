#include<vector>

class MyQueue {
	size_t size{0};
	std::vector<int> queue;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        queue.push_back(x);
		size++;
    }
    
    int pop() {
        int top = queue[0];
		std::vector<int>::iterator it = queue.begin();
		queue.erase(it);
		size--;
		return top;
    }
    
    int peek() {
        return queue[0];
    }
    
    bool empty() {
        if(0 == size)
			return true;
		else
			return false;
    }
};
