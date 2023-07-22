// Link:  https://leetcode.com/problems/knight-probability-in-chessboard/description/

using ll = long long int ;

class Solution {
private:
vector<vector<vector<double>>> dp ;

vector<pair<int , int>> dir = {make_pair(-2 , 1) , make_pair(-2 , -1) , make_pair(-1 , -2) , make_pair(-1 , 2) , make_pair(2 , -1) , make_pair(2 , 1) , make_pair(1 , 2) , make_pair(1 , -2) } ;

double solve(int row , int col , int n , int k)
{
    if(row < 0 || row >= n || col < 0 || col >= n)  return 0.0 ;

    if(k == 0)  return 1.0 ;

    if(dp[row][col][k] != -1.0)  return dp[row][col][k] ;

    double ans = 0.0 ;

    for(auto it : dir)
    {
        int nRow = row + it.first ;  int nCol = col + it.second ;
        ans += solve(nRow , nCol , n , k - 1) ;
    }

    return dp[row][col][k] = ans ;
}

public:
    double knightProbability(int n, int k, int row, int column) 
    {
        dp.resize(n + 1 , vector<vector<double>> (n + 1 , vector<double> (k + 1 , -1.0) ) );
 
        double K = k ;
        double validMoves = solve(row , column , n , k) ;
        double totalMoves = pow(8.0 , K) ;
        
        return validMoves / totalMoves ;
    }
};

// Time Complexity:   O(N * N * K)
// Space Complexity:  O(N * N * K)
