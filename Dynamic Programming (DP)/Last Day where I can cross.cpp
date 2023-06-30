// Link:  https://leetcode.com/problems/last-day-where-you-can-still-cross/description/

class Solution {
int m , n ;

bool isOkay(int nRow , int nCol , vector<vector<int>> &grid , vector<vector<int>> &vis)
{
    if(nRow < 0 || nCol < 0 || nRow >= m || nCol >= n)  return false ;

    if(vis[nRow][nCol] == 1 || grid[nRow][nCol] == 1 )  return false ;

    return true ;
}

int bfs(int ind , vector<vector<int>> &cells)
{
    vector<vector<int>> grid(m , vector<int> (n , 0) ) ;
    vector<vector<int>> vis(m , vector<int> (n , 0) ) ;

    for(int i = 0 ; i <= ind ; i++) 
    {
        int x = cells[i][0] - 1 ; int y = cells[i][1] - 1 ;

        grid[x][y] = 1 ;
    }

    queue<pair<int , int>> q ;

    for(int col = 0 ; col < n ; col++)
    {
        if(grid[0][col] == 0)
        {
            q.push(make_pair(0 , col) ) ; vis[0][col] = 1 ;
        }
    }   

    int x[] = {-1 , +1 , 0 , 0} ; int y[] = {0 , 0 , -1 , +1} ;

    while(!q.empty() )
    {
        int row = q.front().first ; int col = q.front().second ;
        q.pop() ;

        if(row == m - 1)  return 1 ;

        for(int i = 0 ; i < 4 ; i++)
        {
            int nRow = row + x[i] ;  int nCol = col + y[i] ;

            if(isOkay(nRow , nCol , grid , vis) )
            {
                vis[nRow][nCol] = 1 ;  q.push(make_pair(nRow , nCol)) ;
            }
        } 
    }

    return 0 ;
}

public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) 
    {
        m = row ; n = col ;    

        int low = 0 ; int high = cells.size() - 1 ; int ans = -1 ;

        while(low <= high)
        {
            int mid = low + (high - low) / 2 ;

            if( bfs(mid , cells) == 1 )
            {
                ans = mid ; low = mid + 1 ;
            }

            else high = mid - 1 ;
        }

        return (ans + 1) ;
    }
};

// Time Complexity:  O(M * N * Log K) [ K is the size of Cells[][] ]
// Space Complexity: O(M * N)
