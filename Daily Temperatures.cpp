// Link: https://leetcode.com/problems/daily-temperatures/description/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) // Monotonic Stack
    {
        int n = temperatures.size() ;

        vector<int> ans(n , 0) ;

        stack<int> st ; // Increasing from Top to Bottom
        stack<int> index ;

        st.push(temperatures[n - 1]) ;
        index.push(n - 1) ;

        for(int i = n - 2 ; i >= 0 ; i--)
        {
            int currTemp = temperatures[i] ;

            while(st.empty() == false && (currTemp >= st.top() ) )
            {
                st.pop() ;
                index.pop() ;
            }
            
            if(st.empty() == false)
            {
                int days = index.top() - i ;

                ans[i] = days ;
            }

            st.push(currTemp) ;
            index.push(i) ;
        }

        return ans ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
