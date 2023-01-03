// Link: https://leetcode.com/problems/jump-game/

// We can solve the question greedily and we don't need Dynammic Progammming (DP)

class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int n = nums.size() ;
        
        // We start from the end and check if we could reach Last Index
        int target = n - 1 ;  
        
        // We start from i = n - 2 and check if we could reach the 0th Index or not
        for(int i = n - 2 ; i >= 0 ; i--)
        {   
            // We update our target only when (i + nums[i]) >= target which means we can reach that Target Index
            if(i + nums[i] >= target)
                target = i ;
        }
        
        // If at the end, we could reach 0-th Index, it means we have acheived what we have been looking for
        return target == 0 ? true : false ;    
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(1)
