// Link: https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/description/

class Solution {
private:

int dfs(int currIndex , int n , int k , vector<vector<int>> &piles , vector<vector<int>> &dp)
{
    if(k == 0 || currIndex >= n)  return 0 ;

    if(dp[currIndex][k] != -1 )  return dp[currIndex][k] ;

    int notConsider = dfs(currIndex + 1 , n , k , piles , dp) ;

    int ans = 0 ;
    int size = piles[currIndex].size() ;

    int sumOfPiles = 0 ;

    for(int i = 0 ; i < k ; i++)
    {
        if(i == size)  break ;

        sumOfPiles += piles[currIndex][i] ;
        
        int consider = dfs(currIndex + 1 , n , k - (i + 1) , piles , dp) + sumOfPiles ;

        ans = max(ans , consider) ;
    }

    return dp[currIndex][k] = max(ans , notConsider) ;
}

public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) 
    {
        int n = piles.size() ;

        vector<vector<int>> dp(n + 1 , vector<int> (k + 1 , -1) ) ;

        return dfs(0 , n , k , piles , dp) ;     
    }
};

// Time Complexity:  O(N * K)
// Space Complexity: O(N * K)
