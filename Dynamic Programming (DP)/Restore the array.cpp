// Link:  https://leetcode.com/problems/restore-the-array/description/

using ll = long long int ;

class Solution {
private:

ll totalWays(int currIndex , int n , int k , string &s , vector<ll> &dp)
{
    if(currIndex >= n)  return 1 ;

    if(dp[currIndex] != -1)  return dp[currIndex] ;

    ll MOD = 1e9 + 7 ;
    ll prefix = 0 ;
    ll ans = 0 ;

    for(int i = currIndex ; i < n ; i++)
    {
        prefix *= 10 ;
        prefix += s[i] - '0' ;

        if(prefix > 0 && prefix <= k)  
        {
            ll cnt = totalWays(i + 1 , n , k , s , dp)  % MOD ;

            ans += cnt ;
            ans %= MOD ;
        }

        else  break ;

        prefix %= MOD ;
    }

    return dp[currIndex] = ans ;
}

public:
    int numberOfArrays(string &s , int k) 
    {
        int n = s.size() ;    

        vector<ll> dp(n + 1 , -1) ;

        return  (int) totalWays(0 , n , k , s , dp) ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
