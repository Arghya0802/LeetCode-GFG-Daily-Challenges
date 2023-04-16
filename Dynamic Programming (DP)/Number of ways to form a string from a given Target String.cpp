// Link: https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/description/

using ll = long long int ;

class Solution {
private:
int n , m , len ;

ll totalUniqueWays(int ind , int j , string &s , vector<vector<ll>> &freq , vector<vector<ll>> &dp)
{
    if(j >= n)    return 1 ;

    if(ind >= len)  return 0 ;

    if(dp[ind][j] != -1)  return dp[ind][j] ;
    
    ll MOD = 1e9 + 7 ;
    ll ans = 0 ;

    char ch = s[j] ;

    ll cnt = freq[ind][ch - 'a'] ;

    if(cnt > 0)
    {
        ll consider = cnt * totalUniqueWays(ind + 1 , j + 1 , s , freq , dp) % MOD ;
        
        ans += consider ;
        ans %= MOD ;
    }

    ll notConsider = totalUniqueWays(ind + 1 , j , s , freq , dp) % MOD ;

    ans += notConsider ;
    ans %= MOD ;

    return dp[ind][j] = ans ;
    
}

public:
    int numWays(vector<string>& words, string &target) 
    {
        n = target.size() ;
        m = words.size() ;
        len = words[0].size() ;

        vector<vector<ll>> dp(len + 1 , vector<ll> (n + 1 , -1) ) ;
        vector<vector<ll>> freq(len , vector<ll> (26 , 0) ) ;

        for(int i = 0 ; i < len ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                char ch = words[j][i] ;

                freq[i][ch - 'a'] += 1 ;
            }
        }

        return (int) totalUniqueWays(0 , 0 , target , freq , dp) ;
    }
};

// Time Complexity:  O(N * Len)
// Space Complexity: O(N * Len)
