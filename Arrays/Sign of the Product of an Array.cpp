// Link: https://leetcode.com/problems/sign-of-the-product-of-an-array/description/

class Solution {
public:
    int arraySign(vector<int>& nums) 
    {
        int cntNeg = 0 ;

        for(int val : nums)
        {
            if(val == 0)  return 0 ;

            if(val < 0)  cntNeg += 1 ;
        }    

        return cntNeg % 2 == 0 ? 1 : -1 ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(1)
