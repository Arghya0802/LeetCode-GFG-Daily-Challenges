// Link:  https://leetcode.com/problems/minimum-size-subarray-sum/description/
// --------------------------------------------------------------------------

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int n = nums.size() ;  int end = 0 ;
        int minCnt = INT_MAX ;  int sum = 0 ;

        for(int start = 0 ; start < n ; start++)
        {
            sum += nums[start] ;

            while(end <= start && sum >= target)
            {
                minCnt = min(minCnt , start - end + 1) ;

                sum -= nums[end] ;  end++ ;
            }
        }

        return minCnt == INT_MAX ? 0 : minCnt ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(1)
