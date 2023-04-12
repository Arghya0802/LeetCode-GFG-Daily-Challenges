// Link: https://leetcode.com/problems/simplify-path/description/

class Solution {
public:
    string simplifyPath(string &path) 
    {
        path += "/" ;

        stack<string> st ;
        string curr = "" ;

        for(char ch : path)
        {
            if(ch == '/')
            {
                if(!st.empty() && curr == "..") 
                    st.pop() ;

                else if(curr != ".." && curr != "." && curr != "")
                    st.push(curr) ;

                curr = "" ;
            }

            else
                curr += ch ;
        }    

        string ans = "" ;

        while(!st.empty()) 
        {
            string s = st.top() ;
            st.pop() ;

            reverse(s.begin() , s.end() ) ;

            ans += s + "/" ;
        }

        reverse(ans.begin() , ans.end() ) ;

        return ans.size() == 0 ? "/" : ans ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
