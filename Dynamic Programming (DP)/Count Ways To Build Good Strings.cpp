// Link:  https://leetcode.com/problems/count-ways-to-build-good-strings/description/

using ll = long long int ;

class Solution {
private:

ll countGoodStrings(int ind , int low , int high , int zero , int one , vector<ll> &dp)
{
    if(ind > high)  return 0 ;

    if(dp[ind] != -1)  return dp[ind] ;

    ll MOD = 1e9 + 7 ;
    ll ans = ind >= low ? 1 : 0 ;

    ans += countGoodStrings(ind + zero , low , high , zero , one , dp) % MOD ;

    ans += countGoodStrings(ind + one , low , high , zero , one , dp) % MOD ;

    return dp[ind] = ans % MOD ;
}

public:
    int countGoodStrings(int low, int high, int zero, int one) 
    {
        vector<ll> dp(high + 1 , -1) ;

        return (int) countGoodStrings(0 , low , high , zero , one , dp) ;        
    }
};

// Time Complexity:  O(High)
// Space Complexity: O(High)
