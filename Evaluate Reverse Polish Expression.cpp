// Link: https://leetcode.com/problems/evaluate-reverse-polish-notation/description/

class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<long long int> st ;

        for(string nums : tokens)
        {
            if(nums == "+")
            {
                long long int x = st.top() ; st.pop() ;
                long long int y = st.top() ; st.pop() ;

                st.push(y + x) ;
            }

            else if(nums == "-")
            {
                long long int x = st.top() ; st.pop() ;
                long long int y = st.top() ; st.pop() ;

                st.push(y - x) ;
            }

            else if(nums == "*")
            {
                long long int x = st.top() ; st.pop() ;
                long long int y = st.top() ; st.pop() ;

                st.push(y * x) ;
            }

            else if(nums == "/")
            {
                long long int x = st.top() ; st.pop() ;
                long long int y = st.top() ; st.pop() ;

                st.push(y / x) ;
            }

            else 
                st.push(stoi(nums)) ;
        }

        return (int) st.top() ;    

    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
