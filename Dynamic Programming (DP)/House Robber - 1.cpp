// Link: https://leetcode.com/problems/house-robber/description/

class Solution {
private:

int houseRobber(int currentIndex , int n , vector<int> &nums , vector<int> &dp)
{
    if(currentIndex >= n)
        return 0 ;

    if(dp[currentIndex] != -1)
        return dp[currentIndex] ;

    int robbed = houseRobber(currentIndex + 2 , n , nums , dp) + nums[currentIndex] ;
    int notRobbed = houseRobber(currentIndex + 1 , n , nums , dp) ;

    return dp[currentIndex] = max(robbed , notRobbed) ;
}

public:
    int rob(vector<int>& nums) 
    {
        int n = nums.size() ;

        vector<int> dp1(n + 1 , -1) ;
        vector<int> dp2(n + 1 , -1) ;

        int ans = houseRobber(0 , n , nums , dp1) ;

        return ans ;    
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
