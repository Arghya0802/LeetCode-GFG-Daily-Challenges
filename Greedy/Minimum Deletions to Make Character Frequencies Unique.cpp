// Link:  https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/

class Solution {
public:
    int minDeletions(string s) 
    {
        vector<int> freq(26 , 0) ;  int n = s.size() ;
            
        for(int i = 0 ; i < n ; i++)
        {
            int index = s[i] - 'a' ;
            
            freq[index]++ ;
        }

        unordered_set<int> set ;  int ans = 0 ;
            
        for(int i = 0 ; i < 26 ; i++)
        {
            int count = freq[i] ;
            
            if(set.find(count) != set.end() )
            {
                int size = count ;
                for(int i = 0 ; i < size ; i++)
                {
                    ans++ ;
                    count-- ;
                    
                    if(set.find(count) == set.end() )  break ;
                }
            }
            
            set.insert(count) ;
        }
        
        return ans ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
