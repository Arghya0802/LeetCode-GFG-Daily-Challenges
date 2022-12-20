// Link: https://leetcode.com/problems/climbing-stairs/description/

class Solution {
private:

int countStairs(int currentIndex , int n , vector<int> &dp)
{
    if(currentIndex == n)
        return 1 ;

    if(currentIndex > n)
        return 0 ;

    if(dp[currentIndex] != -1)
        return dp[currentIndex] ;

    int oneJump  = countStairs(currentIndex + 1 , n , dp) ;
    int twoJumps = countStairs(currentIndex + 2 , n , dp) ;

    return dp[currentIndex] = oneJump + twoJumps ;
}

public:
    int climbStairs(int n) 
    {
        vector<int> dp(50 , -1) ; // Dp[] of size 50 is used to Memoize our Recursive Code

        int ans = countStairs(0 , n , dp) ; // Recursive Function which returns the number of ways possible

        return ans ;    
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
