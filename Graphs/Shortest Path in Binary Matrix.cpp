// Link: https://leetcode.com/problems/shortest-path-in-binary-matrix/description/

using pp = pair<int , pair<int , int>> ;

class Solution {
private:
int n ;

bool isValid(int nRow , int nCol , vector<vector<int>> &visited , vector<vector<int>> &grid)
{
    if(nRow < 0 || nRow >= n || nCol < 0 || nCol >= n)  return false ;

    if(visited[nRow][nCol] == 1 || grid[nRow][nCol] == 1)  return false ;

    return true ;
}

int bfs(int row , int col , vector<vector<int>> &grid)
{
    vector<vector<int>> visited(n , vector<int> (n , 0) ) ;

    queue<pp> q ;  

    q.push({1 , {row , col} }) ;  visited[row][col] = 1 ;

    int x[] = {-1 , -1 , -1 , 0 , 0 , +1 , +1 , +1} ;
    int y[] = {-1 , 0 , +1 , -1 , +1 , -1 , 0 , +1} ;

    int minCnt = 0 ;

    while(!q.empty() )
    {
        int steps = q.front().first ;
        int row = q.front().second.first ; int col = q.front().second.second ;
        q.pop() ;

        minCnt = max(minCnt , steps) ;

        if(row == n - 1 && col == n - 1)  return minCnt ;

        for(int i = 0 ; i < 8 ; i++)
        {
            int nRow = row + x[i] ; int nCol = col + y[i] ;

            if(isValid(nRow , nCol , visited , grid) )
            {
                q.push({steps + 1 , {nRow , nCol} } ) ;  visited[nRow][nCol] = 1 ;
            }
        }
    }

    return -1 ;
}

public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        n = grid.size() ;

        return grid[0][0] == 1 ? -1 : bfs(0 , 0 , grid) ;    
    }
};

// Time Complexity:  O(N ^ 2)
// Space Complexity: O(N ^ 2)
