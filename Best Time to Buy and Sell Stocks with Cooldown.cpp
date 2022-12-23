// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/

// This question is a classic variant of the famous Buy and Sell Stocks range of questions

class Solution {
private:

// We define the Recursive function which tells us the max amount we can get from buying and selling stocks
  
int buyAndSell(int currentIndex , int n , int canBuy , vector<int> &prices , vector<vector<int>> &dp)
{
    if(currentIndex >= n)
        return 0 ;

    if(dp[currentIndex][canBuy] != -1) // If we have already encountered that state, we return the memoized value
        return dp[currentIndex][canBuy] ;
    
    int ans = 0 ;

    if(canBuy == 1) // If CanBuy is 1, it signals we call Buy the Stock on that Day
    {
        // We have two choice- either to Buy the stock at that day or don't buy the stock at that day, i.e, remain Idle
      
        int idle = buyAndSell(currentIndex + 1 , n , canBuy , prices , dp) ; 

        int buy = buyAndSell(currentIndex + 1 , n , 0 , prices , dp) - prices[currentIndex] ; // If we are buying a stock, then we need to pay the money of the stock at i-th day

        ans = max(idle , buy) ; // We storet the maximum into our ans variable
    }

    else
    {
        // Simiarly, for selling we have two options- either to Sell the Stock and attain the 1-Day Cooldown period or remain Idle
      
        int idle = buyAndSell(currentIndex + 1 , n , canBuy , prices , dp) ;
        
        // As we are remaining Selling the Stock, we cannot buy it exactly on the next day, we have to attain the CoolDown Period of 1-Day
      
        int sell = buyAndSell(currentIndex + 2 , n , 1 , prices , dp) + prices[currentIndex] ; // We get the money by selling the stock at i-th day

        ans = max(idle , sell) ; // We store the maximum possible amount into our ans variable
    }

    return dp[currentIndex][canBuy] = ans ; // We memoized the our Dp[][] array and return ans
}

public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size() ;
        
        vector<vector<int>> dp(n + 1 , vector<int> (2 , -1) ) ;
    
        int ans = buyAndSell(0 , n , 1 , prices , dp) ; // CanBuy is initally 1 because we can Buy stocks at the beginning without any hindrance

        return ans ;    
    }
};

// Time Complexity:  O(N * 2) [CanBuy stores Two Values :(0,1) ]
// Space Complexity: O(N * 2) [Size of 2D Dp[][] array ]
