// Link: https://practice.geeksforgeeks.org/problems/surround-the-1s2505/1

class Solution
{
    private int countNeighborZeros(int row , int col , int [][] grid)
    {
        int cnt = 0 ;  int m = grid.length ; int n = grid[0].length ;
        
        int [] x = {-1 , +1 , 0 , 0 , -1 , -1 , +1 , +1} ;  int [] y = {0 , 0 , -1 , +1 , -1 , +1 , -1 , +1} ;
        
        for(int i = 0 ; i < 8 ; i++)
        {
            int nRow = row + x[i] ;  int nCol = col + y[i] ;
            
            if(nRow >= 0 && nCol >= 0 && nRow < m && nCol < n)   cnt += grid[nRow][nCol] == 0 ? 1 : 0 ;
        }
        
        return cnt == 0 || cnt % 2 == 1 ? 0 : 1 ;
    }
    
    public int  Count(int[][] matrix)
    {
        int m = matrix.length ;  int n = matrix[0].length ;
        
        int cnt = 0 ;
        
        for(int row = 0 ; row < m ; row++)
        {
            for(int col = 0 ; col < n ; col++)
            {
                if(matrix[row][col] == 0)  continue ;
                
                int ans = countNeighborZeros(row , col , matrix) ;
                
                // System.out.println(row + " " + col + " " + ans) ;
                
                cnt += ans ;
            }
        }
        
        return cnt ;
    }
}

// Time Complexity:  O(M * N)
// Space Complexity: O(1)
