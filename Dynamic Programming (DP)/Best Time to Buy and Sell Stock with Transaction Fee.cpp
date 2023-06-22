// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/

class Solution {
private:

int buyAndSell(int ind , int n , bool canBuy , int fee , vector<int> &prices , vector<vector<int>> &dp)
{
    if(ind >= n)  return 0 ;

    if(dp[ind][canBuy] != -1)  return dp[ind][canBuy] ;
    
    int idle = buyAndSell(ind + 1 , n , canBuy , fee , prices , dp) ;
    
    int buy = 0 ; int sell = 0 ;

    if(canBuy == true) buy = buyAndSell(ind + 1 , n , false , fee , prices , dp) - prices[ind] ;

    else sell = buyAndSell(ind + 1 , n , true , fee , prices , dp) + prices[ind] - fee ;

    return dp[ind][canBuy] = max({ idle , buy , sell }) ;
}

public:
    int maxProfit(vector<int>& prices, int fee) 
    {
        int n = prices.size() ;
        vector<vector<int>> dp(n + 1 , vector<int> (2 , -1) ) ;

        return buyAndSell(0 , n , true , fee , prices , dp) ;    
    }
};

// Time Complexity:  O(N * 2)
// Space Complexity: O(N * 2)
