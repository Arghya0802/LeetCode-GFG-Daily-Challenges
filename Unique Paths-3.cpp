// Link: https://leetcode.com/problems/unique-paths-iii/description/

class Solution {
    
private :
  
// This question is a Backtracking and recursion problem- not a DP problem
// Using DP we would get wrong answer, we need to explore all the possible paths from any cell (i , j)

int totalUniquePaths(int currRow , int currCol , int m , int n , int currCount , int total ,vector<vector<int>> &visited , vector<vector<int>> &grid)
{
    if(currRow < 0 || currRow >= m || currCol < 0 || currCol >= n) // Checking for validity of the cell
        return 0 ;

    if(grid[currRow][currCol] == -1) // Checking if we have encountered any obstacles or not
        return 0 ;

    if(visited[currRow][currCol] == 1) // Checking if we have already visited the cell or not
        return 0 ;

    if(grid[currRow][currCol] == 2) // If we have reached the Target Cell, we need to check if we have covered all the Empty-Cells or not
        return currCount == total ? 1 : 0 ;
    
    // We mark the cell as visited and increment our Count-of-Empty Cells by 1
    visited[currRow][currCol] = 1 ;
    currCount += 1 ;

    int ans = 0 ;
    
    // X[] and Y[] arrays will help us to traverse in 4-directions: Up , Down , Left , Right
    int x[] = {-1 , +1 , 0 , 0} ;
    int y[] = {0 , 0 , -1 , +1} ;

    for(int i = 0 ; i < 4 ; i++)
    {
        int nRow = currRow + x[i] ;
        int nCol = currCol + y[i] ;

        ans += totalUniquePaths(nRow , nCol , m , n , currCount , total , visited , grid) ;
    }
     
     // We need to backtrack and undo the change we have done before so that we can explore all possible paths
    visited[currRow][currCol] = 0 ;
    currCount -= 1 ;

    return ans ;  
}
    
public:
    int uniquePathsIII(vector<vector<int>>& grid) 
    {
    
        int m = grid.size() ;
        int n = grid[0].size() ;

        vector<vector<int>> visited(m , vector<int> (n , 0) ) ; // help us to keep track of the cells we are visited else we would get struck in an infinite loop

        int startRow = -1 , startCol = -1 ; // We store the StartRow and StartCol in seperate variables
        int totalEmptyCells = 0 ; // We initally Count the Number of Empty Cells in the grid
        
        for(int row = 0 ; row < m ; row++)
        {
            for(int col = 0 ; col < n ; col++)
            {
                if(grid[row][col] == 1)
                {
                    startRow = row ;
                    startCol = col ;
                }

                if(grid[row][col] == 0)
                    totalEmptyCells += 1 ;
            }
        }
        
        int ans = totalUniquePaths(startRow , startCol , m , n , -1 , totalEmptyCells , visited , grid) ;
    
        return ans ;
    
    }
};

// Time Complexity:  O(Exponential) [ We are exploring all possible paths so Time Complexity will be Exponential ]
// Space Complexity: O(M * N) [Recursive stack space ; If we start from (0,0) and end at (m - 1 , n - 1), in worst case we would cover almost (M * N) cells, which is the size of our Recursive Stack Space]
