// Link: https://leetcode.com/problems/jump-game-ii/description/

class Solution {
private:

int jumpGame(int currIndex , int target , vector<int> &nums , vector<int> &dp)
{
    if(currIndex == target)
        return 0 ;

    if(currIndex > target)
        return 10000 ;

    if(dp[currIndex] != -1)
        return dp[currIndex] ;

    int jump = nums[currIndex] ;
    int ans = 100000 ;

    for(int i = 1 ; i <= jump ; i++)
    {
        int currAns = 1 + jumpGame(currIndex + i , target , nums , dp) ;

        ans = min(ans , currAns) ;
    }

    return dp[currIndex] = ans ;
}

public:
    int jump(vector<int>& nums) 
    {
        int n = nums.size() ;
        
        vector<int> dp(n + 1 , -1) ;

        int ans = jumpGame(0 , n - 1 , nums , dp) ;

        return ans ;    
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
