// Link: https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/description/

using ll = long long int ;

class Solution {
private:
ll dp[51][51][11] ;
ll mod ;

ll totalWays(int currRow , int currCol , int k , int m , int n , vector<string> &pizza)
{
    if(k == 0)
    {
        bool flag = false ;

        for(int row = currRow ; row < m ; row++)
        {
            for(int col = currCol ; col < n ; col++)
            {
                if(pizza[row][col] == 'A')
                {
                    flag = true ;
                    break ;
                }
            }

            if(flag == true) return 1 ;
        }

        return 0 ;
    }

    if(dp[currRow][currCol][k] != -1)
        return dp[currRow][currCol][k] ;

    ll ans = 0 ;

    for(int nRow = currRow + 1 ; nRow < m ; nRow++)
    {
        bool flag ; 
        ll horizontalCut ;

        for(int row = currRow ; row < nRow ; row++)
        {
            flag = false ;
            horizontalCut = 0 ;

            for(int col = currCol ; col < n ; col++)
            {
                if(pizza[row][col] == 'A')
                {
                    flag = true ;
                    break ;
                }    
            }

            if(flag)
                break ;
        }

        if(flag)
            horizontalCut = totalWays(nRow , currCol , k - 1 , m , n , pizza) % mod ;

        ans += horizontalCut ;
    }

    ans %= mod ;

    for(int nCol = currCol + 1 ; nCol < n ; nCol++)
    {
        bool flag ;
        ll verticalCut ;

        for(int col = currCol ; col < nCol ; col++)
        {
            flag = false ;
            verticalCut = 0 ;

            for(int row = currRow ; row < m ; row++)
            {
                if(pizza[row][col] == 'A') 
                {
                    flag = true ;
                    break ;
                }
            }

            if(flag) break ;
        }

        if(flag)
            verticalCut = totalWays(currRow , nCol , k - 1 , m , n , pizza) % mod ;

        ans += verticalCut ;
    }

    ans %= mod ;

    return dp[currRow][currCol][k] = ans ;
}

public:
    int ways(vector<string>& pizza, int k) 
    {
        int m = pizza.size() ;
        int n = pizza[0].size() ;

        mod = 1e9 + 7 ;
        memset(dp , -1 , sizeof(dp)) ;

        ll ans = totalWays(0 , 0 , k - 1 , m , n , pizza) ;        

        return (int) (ans % mod) ;
    }
};

// Time Complexity:  O(M * N * K)
// Space COmplexity: O(M * N * K)
