// Link: https://leetcode.com/problems/solving-questions-with-brainpower/description/

using ll = long long int ;

class Solution {
private:

ll maxPoints(int currIndex , int n , vector<vector<int>> &ques , vector<ll> &dp)
{
    if(currIndex >= n)  return 0 ;

    if(dp[currIndex] != -1)  return dp[currIndex] ;
    
    int points = ques[currIndex][0] ;
    int power = ques[currIndex][1] ;

    ll consider = maxPoints(currIndex + power + 1 , n , ques , dp) + points ;

    ll notConsider = maxPoints(currIndex + 1 , n , ques , dp) ;

    return dp[currIndex] = max(consider , notConsider) ;
}

public:
    long long mostPoints(vector<vector<int>>& questions)
    {
        ll n = questions.size() ;
        vector<ll> dp(n + 1 , -1) ;

        return maxPoints(0 , n , questions , dp) ;        
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
