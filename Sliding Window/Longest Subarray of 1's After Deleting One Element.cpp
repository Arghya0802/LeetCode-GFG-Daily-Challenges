// LeetCode Link: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/

class Solution {
public:
    int longestSubarray(vector<int>& nums) 
    {
        int n = nums.size() ;

        int maxCnt = 0 ; int end = 0 ; 
        int cnt = 0 ;

        for(int start = 0 ; start < n ; start++)
        {
            int accept = nums[start] ;

            if(accept == 0)  cnt++ ;

            while(end <= start && cnt > 1)
            {
                int discard = nums[end] ;  end++ ;

                if(discard == 0)  cnt-- ;
            }

            maxCnt = max(maxCnt , start - end + 1) ;
        }

        return (maxCnt - 1) ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(1)
