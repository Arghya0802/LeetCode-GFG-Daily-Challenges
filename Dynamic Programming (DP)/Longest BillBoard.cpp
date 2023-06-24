// Link: https://leetcode.com/problems/tallest-billboard/description/

class Solution {
private:
int dp[21][10010] = {0} ;

int solve(int ind , int n , int diff , vector<int> &rods)
{
    if(ind >= n)  return diff == 0 ? 0 : -5002;

    int index = diff + 5002 ;

    if(dp[ind][index] != -1)  return dp[ind][index] ;

    int skip = solve(ind + 1 , n , diff , rods) ;
    
    int pickL = rods[ind] + solve(ind + 1 , n , diff - rods[ind] , rods) ;
    int pickR = rods[ind] + solve(ind + 1 , n , diff + rods[ind] , rods) ;

    return dp[ind][index] = max( {skip , pickL , pickR} ) ;
}

public:
    int tallestBillboard(vector<int>& rods) 
    {
        int n = rods.size() ;
        memset(dp , -1 , sizeof(dp) ) ;

        return solve(0 , n , 0 , rods) / 2 ;    
    }
};

// Time Complexity:  O(N * Sum)
// Space Complexity: O(N * Sum)
