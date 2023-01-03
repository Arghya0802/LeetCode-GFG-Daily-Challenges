// Link: https://leetcode.com/problems/implement-queue-using-stacks/description/

class MyQueue {

stack<int> st ;

public:
    MyQueue() {}
    
    void push(int x) 
    {
        st.push(x) ;
        return ;
    }
    
    int pop() 
    {
        vector<int> vec ;

        while(st.empty() == false)
        {
            vec.push_back(st.top() ) ;
            st.pop() ;
        }

        int n = vec.size() ;

        int x = vec[n - 1] ;

        for(int i = n - 2 ; i >= 0 ; i--)
            st.push(vec[i]) ;

        return x ;
    }
    
    int peek() 
    {
        vector<int> vec ;

        while(st.empty() == false)
        {
            vec.push_back(st.top() ) ;
            st.pop() ;
        }

        int n = vec.size() ;

        int x = vec[n - 1] ;

        for(int i = n - 1 ; i >= 0 ; i--)
            st.push(vec[i]) ;

        return x ;

    }
    
    bool empty() 
    {
        return st.size() == 0 ? true : false ;    
    }
};

// Time Complexity:  O(1) [Amortized or Average]
// Space Complexity: O(N)
