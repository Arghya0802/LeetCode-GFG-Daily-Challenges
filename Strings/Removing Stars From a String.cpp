// Link: https://leetcode.com/problems/removing-stars-from-a-string/

class Solution {
public:
    string removeStars(string &s) 
    {
        int n = s.size() ;
        stack<char> st ;

        for(int i = 0 ; i < n ; i++)
        {
            char ch = s[i] ;

            if(!st.empty() && ch == '*')
                st.pop() ;

            else
                st.push(ch) ;
        }

        string ans = "" ;

        while(!st.empty() )
        {
            ans += st.top() ;
            st.pop() ;
        }

        reverse(ans.begin() , ans.end() ) ;

        return ans ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
