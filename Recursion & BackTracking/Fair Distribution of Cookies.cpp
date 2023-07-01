// Link: https://leetcode.com/problems/fair-distribution-of-cookies/description/

class Solution {
private:
int k , n ;
int minUnfair = INT_MAX ;

void solve(int ind , int n , vector<int> &dp , vector<int> &cookies)
{
    if(ind >= n)
    {
        int sum = 0 ;

        for(int nums : dp)  sum = max(sum , nums) ;

        minUnfair = min(minUnfair , sum) ;

        return ;
    }

    for(int i = 0 ; i < k ; i++)
    {
        dp[i] += cookies[ind] ;

        solve(ind + 1 , n , dp , cookies) ;

        dp[i] -= cookies[ind] ;
    }

    return ;
}

public:
    int distributeCookies(vector<int>& cookies, int k) 
    {
        n = cookies.size() ; this -> k = k ;

        vector<int> dp(k , 0) ;

        solve(0 , n , dp , cookies) ;

        return minUnfair ;
    }
};

// Time Complexity:  O(Exponential)
// Space Complexity: O(K + N) [Recursive Stack Space]
