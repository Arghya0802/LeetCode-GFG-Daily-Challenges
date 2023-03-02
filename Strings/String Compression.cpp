// Link: https://leetcode.com/problems/string-compression/description/

class Solution {
public:
    int compress(vector<char>& chars) 
    {
        int n = chars.size() ;

        if(n == 1)
            return n ;

        char prev = chars[0] ;
        int  cnt  = 1 ;

        string ans = "" ;

        for(int i = 1 ; i < n ; i++)
        {
            if(prev == chars[i])
                cnt += 1 ;

            else
            {
                ans += prev ;

                if(cnt > 1)
                    ans += to_string(cnt) ;

                prev = chars[i] ;
                cnt  = 1 ;
            }
        }
        
        ans += prev ;

        if(cnt > 1)
            ans += to_string(cnt) ;

        int len = ans.size() ;

        for(int i = 0 ; i < len ; i++)
            chars[i] = ans[i] ;

        return len ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
