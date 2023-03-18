// Link: https://leetcode.com/problems/design-browser-history/description/

class BrowserHistory {
private:
list<string> linkedList ;
list<string> :: iterator it ;

public:
    BrowserHistory(string homepage) 
    {
        linkedList.push_back(homepage) ;

        it = linkedList.begin() ;    
    }
    
    void visit(string url) 
    {
        list<string> :: iterator next = it ;
        next++ ;

        linkedList.erase(next , linkedList.end() ) ;    

        linkedList.push_back(url) ;
        it++ ;
    }
    
    string back(int steps) 
    {
        while(steps--)
        {
            if(it == linkedList.begin() )
                break ;

            it-- ;
        }    

        return *it ;
    }
    
    string forward(int steps) 
    {
        list<string> :: iterator prev = it ;

        while(steps--)
        {
            if(it == linkedList.end() )
                break ;

            prev = it ;
            it++ ;
        }    

        if(it == linkedList.end() )
            it = prev ;

        return *it ;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

// Time Complexity:  O(N)
// Space Complexity: O(N)
