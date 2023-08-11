// Link:  https://leetcode.com/problems/coin-change-ii/description/

class Solution {
private:
vector<vector<int>> dp ;

int coinChange(int ind , int sum , vector<int> &coins)
{
    if(sum == 0)  return 1 ;

    if(ind >= coins.size() )  return 0 ;

    if(dp[ind][sum] != -1)  return dp[ind][sum] ;
    
    int skip = coinChange(ind + 1 , sum , coins) ; int pick = 0 ;

    if(coins[ind] <= sum)  pick = coinChange(ind , sum - coins[ind] , coins) ;

    return dp[ind][sum] = pick + skip ;
}

public:
    int change(int amount, vector<int>& coins) 
    {
        dp.resize(coins.size() + 1 , vector<int> (amount + 1 , -1) ) ;

        return coinChange(0 , amount , coins) ;    
    }
};

// Time Complexity:  O(N * Sum)
// Space Complexity: O(Sum)
