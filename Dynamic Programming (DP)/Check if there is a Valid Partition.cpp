// Link:  https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/description/

class Solution {
private:
vector<int> dp ;

bool dfs(int ind , vector<int> &nums)
{
    if(ind >= nums.size() )   return true ;

    if(ind == nums.size() - 1)  return false ;

    if(ind == nums.size() - 2)  return nums[ind] == nums[ind + 1] ? true : false ;

    if(dp[ind] != -1)  return dp[ind] ;

    if(nums[ind] == nums[ind + 1] ) 
    {
        if(dfs(ind + 2 , nums) )  return true ;
    }

    if(nums[ind] == nums[ind + 1] && nums[ind] == nums[ind + 2] )
    {
        if(dfs(ind + 3 , nums) )  return true ;
    }

    if(nums[ind] + 1 == nums[ind + 1] && nums[ind + 1] + 1 == nums[ind + 2] )
    {
        if(dfs(ind + 3 , nums) )  return true ;
    }

    return dp[ind] = false ;
}

public:
    bool validPartition(vector<int>& nums) 
    {
        dp.resize(nums.size() + 1 , -1) ;
        
        return dfs(0 , nums) ;    
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
