// Link: https://leetcode.com/problems/valid-parentheses/description/

class Solution {
    
private :
    
int findOpenRank(char ch)
{
    if(ch == '(')
    return 1 ;
    
    else if(ch == '{')
    return 2 ;
    
    else
    return 3 ;
}
    
int findCloseRank(char ch)
{
    if(ch == ')')
    return 1 ;
    
    else if(ch == '}')
    return 2 ;
    
    else
    return 3 ;
}
    
public: 
    bool isValid(string &s) {
        
    stack<char> st ;
    
    for(int i = 0 ; i < s.size() ; i++)
    {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
        st.push(s[i]) ;
        
        else
        {
            if(st.empty() == true)
            return false ;
            
            int rank1 = findOpenRank(st.top()) ;
            int rank2 = findCloseRank(s[i]) ;
            
            if(rank1 != rank2)
            return false ;
            
            st.pop() ;
        }
    }
    
    return st.empty() ;
}
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
