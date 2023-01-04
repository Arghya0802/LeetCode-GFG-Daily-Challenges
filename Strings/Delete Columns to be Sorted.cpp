// Link: https://leetcode.com/problems/delete-columns-to-make-sorted/description/

class Solution {
public:
    int minDeletionSize(vector<string>& words) 
    {
        int m = words.size() ;
        int n = words[0].size() ;

        int ans = 0 ;

        for(int col = 0 ; col < n ; col++)
        {
            int prevVal = -1 ;

            for(int row = 0 ; row < m ; row++)
            {
                int val = (int) words[row][col] ;

                if(row == 0 && col == 0)
                    prevVal = val ;

                else if(prevVal > val)
                {
                    ans += 1 ;
                    break ;
                }

                else
                    prevVal = val ;
            }
        }

        return ans ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(1)
