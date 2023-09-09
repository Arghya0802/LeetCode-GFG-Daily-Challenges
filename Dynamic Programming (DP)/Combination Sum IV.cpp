// Link:

class Solution {
private:
vector<int> dp ;

int solve(int ind , int target , vector<int> &nums)
{
    if(target == 0)  return 1 ;

    // if(ind >= nums.size() )  return 0 ;

    if(dp[target] != -1)  return dp[target] ;

    int ans = 0 ;

    for(int i = ind ; i < nums.size() ; i++)
    {
        if(target - nums[i] >= 0)  ans += solve(0 , target - nums[i] , nums) ;
    }

    return dp[target] = ans ;
}

public:
    int combinationSum4(vector<int>& nums, int target) 
    {
        // dp.resize(nums.size() + 1 , vector<int> (target + 1 , -1) ) ;

        dp.resize(target + 1 , -1) ;

        return solve(0 , target , nums) ;    
    }
};

// Time Complexity:  O(Target)
// Space Complexity: O(Target)
