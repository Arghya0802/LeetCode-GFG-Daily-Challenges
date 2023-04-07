// Link: https://leetcode.com/problems/number-of-enclaves/description/
 
using pp = pair<int , int> ;

class Solution {
private:

bool isValid(int nRow , int nCol , int m , int n , vector<vector<int>> &visited , vector<vector<int>> &grid)
{
    if(nRow < 0 || nRow >= m || nCol < 0 || nCol >= n)  return false ;

    if(visited[nRow][nCol] == 1)  return false ;

    if(grid[nRow][nCol] == 0)   return false ;

    return true ;
}

int bfs(int startRow , int startCol , int m , int n , vector<vector<int>> &visited , vector<vector<int>> &grid)
{
    int cnt = 0 ;
    queue<pp> q ;

    q.push({startRow , startCol}) ;
    visited[startRow][startCol] = 1 ;
    cnt++ ;

    int x[] = {-1 , +1 , 0 , 0} ;
    int y[] = {0 , 0 , -1 , +1} ;

    while(!q.empty() ) 
    {
        int row = q.front().first ;
        int col = q.front().second ;
        q.pop() ;
        
        for(int i = 0 ; i < 4 ; i++)
        {
            int nRow = row + x[i] ;
            int nCol = col + y[i] ;

            if(isValid(nRow , nCol , m , n , visited , grid) == true)
            {
                cnt += 1 ;
                
                q.push({nRow , nCol}) ;
                visited[nRow][nCol] = 1 ;
            }
        }
    }

    return cnt ;
}

int Traverse_In_Boundary(int cell , bool isRow , int m , int n , vector<vector<int>> &visited, vector<vector<int>> &grid)
{
    int ans = 0 ;

    if(isRow == true)
    {
        for(int col = 0 ; col < n ; col++)
        {
            if(!visited[cell][col] && grid[cell][col] == 1)
            {
                int cnt = bfs(cell , col , m , n , visited , grid) ;

                ans += cnt ;
            }
        }
    }

    else
    {
        for(int row = 0 ; row < m ; row++)
        {
            if(!visited[row][cell] && grid[row][cell] == 1)
            {
                int cnt = bfs(row , cell , m , n , visited , grid) ;

                ans += cnt ;
            }
        }
    }

    return ans ;
}

public:
    int numEnclaves(vector<vector<int>>& grid) 
    {
        int m = grid.size() ;
        int n = grid[0].size() ;

        vector<vector<int>> visited(m , vector<int> (n , 0) ) ;

        int boundaryCnt = 0 ;

        boundaryCnt += Traverse_In_Boundary(0 , true , m , n , visited , grid) ;
        boundaryCnt += Traverse_In_Boundary(m - 1 , true , m , n , visited , grid) ;

        boundaryCnt += Traverse_In_Boundary(0 , false , m , n , visited , grid) ;
        boundaryCnt += Traverse_In_Boundary(n - 1 , false , m , n , visited , grid) ;

        int maxCnt = 0 ;

        for(int row = 0 ; row < m ; row++)
        {
            for(int col = 0 ; col < n ; col++)
            {
                if(!visited[row][col] && grid[row][col] == 1)
                {
                    // int cnt = bfs(row , col , m , n , visited , grid) ;
                    maxCnt += 1 ;
                }
            }
        }    

        return maxCnt ;
    }
};

// Time Complexity:  O(M * N)
// Space Complexity: O(M * N)
