// Link: https://leetcode.com/problems/number-of-zero-filled-subarrays/description/

using ll = long long int ;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) 
    {
        int n = nums.size() ;

        ll cnt = 0 ;
        ll maxCnt = 0 ;

        for(int i = 0 ; i < n ; i++)
        {
            if(nums[i] == 0)
                cnt += 1 ;

            else
                cnt = 0 ;

            if(cnt > 0)
                maxCnt += cnt ;
        }

        return maxCnt ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(1)
