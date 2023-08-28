// Link:  https://leetcode.com/problems/implement-stack-using-queues/description/

class MyStack {
private:
queue<int> Q ;

public:
    MyStack() {}
    
    void push(int x) 
    {
        int size = Q.size() ;

        queue<int> newQ ;

        while(!Q.empty() ) 
        {
            int top = Q.front() ;  newQ.push(top) ;
            Q.pop() ;
        }

        Q.push(x) ;

        while(!newQ.empty() ) 
        {
            int top = newQ.front() ;  newQ.pop() ;    

            Q.push(top) ;
        }

        return ;
    }
    
    int pop() 
    {
        int x = top() ;  Q.pop() ;

        return x ;
    } 
    
    int top() 
    {
        return Q.front() ;    
    }
    
    bool empty() 
    {
        return Q.size() == 0 ;    
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

// Time Complexity:  O(N) for push() and rest O(1)
// Space Complexity: O(N) 
