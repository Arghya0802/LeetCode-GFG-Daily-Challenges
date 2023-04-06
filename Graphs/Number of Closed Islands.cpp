// Link: https://leetcode.com/problems/number-of-closed-islands/description/

using pp = pair<int , int> ;

class Solution {
private:

bool isValid(int nRow , int nCol , int m , int n , vector<vector<int>> &visited , vector<vector<int>> &grid)
{
    if(nRow < 0 || nRow >= m || nCol < 0 || nCol >= n)  return false ;

    if(visited[nRow][nCol] == 1)   return false ;

    if(grid[nRow][nCol] == 1)  return false ;

    return true ;
}

void bfs(int startRow , int startCol , int m , int n , vector<vector<int>> &visited , vector<vector<int>> &grid)
{
    queue<pp> q ;

    q.push({startRow , startCol}) ;
    visited[startRow][startCol] = 1 ;

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
                q.push({nRow , nCol}) ;
                visited[nRow][nCol] = 1 ;
            }
        }
    }

    return ;
}

int Traverse_in_Boundary(int cell , bool isRow , int m , int n , vector<vector<int>> &visited , vector<vector<int>> &grid)
{
    int cnt = 0 ;

    if(isRow == true)
    {
        for(int col = 0 ; col < n ; col++)    
        {
            if(!visited[cell][col] && grid[cell][col] == 0)
            {
                cnt += 1 ;
                bfs(cell , col , m , n , visited , grid) ;
            }
        }
    }

    else
    {
        for(int row = 0 ; row < m ; row++)
        {
            if(!visited[row][cell] && grid[row][cell] == 0)
            {
                cnt += 1 ;

                bfs(row , cell , m , n , visited , grid) ;
            }
        }
    }

    return cnt ;
}

public:
    int closedIsland(vector<vector<int>>& grid) 
    {
        int m = grid.size() ;
        int n = grid[0].size() ;

        vector<vector<int>> visited(m , vector<int> (n , 0) ) ;
        
        int maxCnt = 0 ;
        int boundaryCnt = 0 ;

        boundaryCnt += Traverse_in_Boundary(0 , true , m , n , visited , grid) ;
        boundaryCnt += Traverse_in_Boundary(0 , false , m , n , visited , grid) ;
        boundaryCnt += Traverse_in_Boundary(m - 1 , true , m , n , visited , grid) ;
        boundaryCnt += Traverse_in_Boundary(n - 1 , false , m , n , visited , grid) ;

        for(int row = 0 ; row < m ; row++)
        {
            for(int col = 0 ; col < n  ; col++)
            {
                if(!visited[row][col] && grid[row][col] == 0)
                {
                    bfs(row , col , m , n , visited , grid) ;
                    maxCnt += 1 ;
                }
            }
        }    

        
        // cout << boundaryCnt << " " << maxCnt << endl ;

        return maxCnt ;
    }
};

// Time Complexity:  O(M * N)
// Space Complextiy: O(M * N)
