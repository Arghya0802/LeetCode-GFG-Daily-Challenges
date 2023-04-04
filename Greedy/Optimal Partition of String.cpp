// Link: https://leetcode.com/problems/optimal-partition-of-string/description/

class Solution {
public:
    int partitionString(string &s) 
    {
        int n = s.size() ;    

        int freq[26] = {0} ;

        int cnt = 1 ;

        for(int i = 0 ; i < n ; i++)
        {
            char ch = s[i] ;

            // freq[ch - 'a'] += 1 ;

            if(freq[ch - 'a'] > 0)
            {
                cnt += 1 ;
                
                for(int k = 0 ; k < 26 ; k++)
                    freq[k] = 0 ;
            }

            freq[ch - 'a'] = 1 ;
        }

        return cnt ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(1)
