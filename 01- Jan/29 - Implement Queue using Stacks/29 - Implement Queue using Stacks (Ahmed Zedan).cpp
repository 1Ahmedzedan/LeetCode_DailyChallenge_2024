//author : Ahmed Zedan

class MyQueue {
public:
    stack<int>stk1,stk2 ; 
    MyQueue() {
        
    }
    // 1 2 4 5
    // stk1 -> 
    // stk2 -> 1 2  
    void push(int x) {
        while(1){
            if(stk2.empty()) break ; 
            else{
                stk1.push(stk2.top()) ; 
                stk2.pop() ; 
            }
        }
        stk1.push(x) ; 
        while(1){
            if(stk1.empty()) break ; 
            else{
                stk2.push(stk1.top()) ; 
                stk1.pop() ; 
            }
        }

    }
    
    int pop() {
        int z=0 ; 
        if(!stk2.empty()){
            z = stk2.top() ; 
            stk2.pop() ;   
        }
        return z ; 
    }
    int peek() {
        return stk2.top() ; 
    }
    
    bool empty() {
        return stk2.empty() ; 
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */