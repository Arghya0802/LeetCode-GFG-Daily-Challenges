// Link:  https://leetcode.com/problems/soup-servings/description/

class Solution {
    private double dp[][] ;

    private double solve(int a , int b)
    {
        if(a <= 0 && b <= 0)  return 0.5 ;

        if(a <= 0)  return 1.0 ;

        if(b <= 0)  return 0.0 ;  

        if(dp[a][b] != -1) return dp[a][b] ;

        double ans = 0.0 ;

        ans += solve(a - 100 , b) ;

        ans += solve(a - 75 , b - 25) ;

        ans += solve(a - 50 , b - 50) ;

        ans += solve(a - 25 , b - 75) ;

        return dp[a][b] = ans * 0.25 ;
    }

    public double soupServings(int n) 
    {
        if(n > 10000)  return 1.0 ;

        dp = new double[n + 1][n + 1] ;

        for(double [] A : dp)
        {
            Arrays.fill(A ,  -1.0) ;
        }

        return solve(n , n) ;    
    }
}

// Time Complexity:  O(N ^ 2)
// Space Complexity: O(N ^ 2)
