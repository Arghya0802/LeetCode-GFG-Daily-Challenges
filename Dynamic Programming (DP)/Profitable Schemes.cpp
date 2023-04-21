// Link: https://leetcode.com/problems/profitable-schemes/description/

using ll = long long int ;
using pp = pair<int , int> ;

class Solution {
private:

ll dp[101][101][101] ;

ll choose_Profitable_Schemes(int currIndex , int n , int minProfit , int maxCnt , vector<pp> &nums)
{
    if(maxCnt < 0)  return 0 ;

    minProfit = minProfit < 0 ? 0 : minProfit ;

    if(currIndex >= n)  return minProfit == 0 ? 1 : 0 ;

    if(dp[currIndex][minProfit][maxCnt] != -1)  return dp[currIndex][minProfit][maxCnt] ;

    ll MOD = 1e9 + 7 ;
    ll ans = 0 ;

    ll notConsider = choose_Profitable_Schemes(currIndex + 1 , n , minProfit , maxCnt , nums) % MOD ;

    ans += notConsider ;
    ans %= MOD ;

    int profit = nums[currIndex].first ;
    int cnt = nums[currIndex].second ;

    ll consider = choose_Profitable_Schemes(currIndex + 1 , n , minProfit - profit , maxCnt - cnt , nums) % MOD ;

    ans += consider ;
    ans %= MOD ;

    return dp[currIndex][minProfit][maxCnt] = ans ;
}

public:
    static bool cmp(pp &A , pp &B)
    {
        if(A.first > B.first)  return true ;

        else if(A.first == B.first && A.second < B.second)  return true ;

        return false ;
    }

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) 
    {
        int len = group.size() ;
        vector<pp> nums ;

        for(int i = 0 ; i < len ; i++)
            nums.push_back({profit[i] , group[i]}) ;

        sort(nums.begin() , nums.end() , cmp) ;

        for(int i = 0 ; i < 101 ; i++)
        {
            for(int j = 0 ; j < 101 ; j++)
            {
                for(int k = 0 ; k < 101 ; k++)
                    dp[i][j][k] = -1 ;
            }
        }

        return (int) choose_Profitable_Schemes(0 , len , minProfit , n , nums) ;
    }
};

// Time Complexity:  O(Len * N * minProfit) [Len -> Profit.size() ; N -> Total Peoples ; minProfit -> Minimum Profit required ]
// Space Complexity: O(Len * N * minProfit)
