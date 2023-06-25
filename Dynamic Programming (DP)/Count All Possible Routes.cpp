// Link: https://leetcode.com/problems/count-all-possible-routes/description/

using ll = long long int ;
const ll MOD = 1e9 + 7 ;

class Solution {
private:
vector<vector<ll>> dp ;
// ll dp[101][201][1000] = {0} ;

ll solve(int ind , int target , int fuel , vector<int> &locations)
{
    if(fuel == 0)  return ind == target ? 1 : 0 ;

    if(dp[ind][fuel] != -1)  return dp[ind][fuel] ;

    ll ans = ind == target ? 1 : 0 ;

    for(int i = 0 ; i < locations.size() ; i++)
    {
        int reqFuel = i != ind ? abs(locations[i] - locations[ind]) : 500 ;

        if(i != ind && reqFuel <= fuel)  
        {
            ll pick = solve(i , target , fuel - reqFuel , locations) % MOD ;

            ans += pick ;  ans %= MOD ;  
        }

    }

    return dp[ind][fuel] = (ans % MOD) ;
}

public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) 
    {
        int n = locations.size() ;
        dp.resize(n + 1 , vector<ll> (fuel + 1 , -1) ) ;

        // memset(dp , -1 , sizeof(dp) ) ;

        return (int) solve(start , finish , fuel , locations) % MOD ;    
    }
};

// Time Complexity:  O(N * Fuel)
// Space Complexity: O(N * Fuel)
