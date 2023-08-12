// Link:  https://leetcode.com/problems/unique-paths-ii/description/

class Solution {
private:
vector<vector<int>> dp ;

int uniquePaths(int row , int col , vector<vector<int>> &grid)
{
    if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() )  return 0 ;

    if(grid[row][col] == 1)  return 0 ;

    if(dp[row][col] != -1)  return dp[row][col] ;

    if(row == grid.size() - 1 && col == grid[0].size() - 1 )   return 1 ;

    int down  = uniquePaths(row + 1 , col , grid) ;
    int right = uniquePaths(row , col + 1 , grid) ;

    return dp[row][col] = down + right ;
}

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        dp.resize(obstacleGrid.size() + 1 , vector<int> (obstacleGrid[0].size() + 1 , -1)); 
        
        return uniquePaths(0 , 0 , obstacleGrid) ;    
    }
};

// Time Complexity:  O(M * N)
// Space Complexity: O(M * N)
