// Link: https://leetcode.com/problems/summary-ranges/description/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) 
    {
        int n = nums.size() ;  if(n == 0)  return {} ;

        vector<string> ans ;      

        int cnt = nums[0] ; int start = nums[0] ;

        for(int i = 1 ; i < n ; i++)
        {
            if(nums[i] == cnt + 1)  cnt++ ;

            else
            {
                if(cnt == start)  
                {
                    ans.push_back(to_string(cnt) ) ;  
                }

                else
                {
                    string range = to_string(start) + "->" + to_string(cnt) ;

                    ans.push_back(range) ;
                }

                start = nums[i] ; cnt = nums[i] ;
            }
        }

        if(start == cnt)  ans.push_back(to_string(cnt)) ;

        else
        {
            string range = to_string(start) + "->" + to_string(cnt) ;

            ans.push_back(range) ;
        }

        return ans ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
