// Link: https://leetcode.com/problems/as-far-from-land-as-possible/description/

// The only edge case we need to handle is that if our Max-Steps-Count is still 0, it means all the cells have land so we return -1

class Solution {
private:

bool isValid(int currRow , int currCol , int n , vector<vector<int>> &visited)
{
    if(currRow < 0 || currRow >= n || currCol < 0 || currCol >= n)
        return false ;

    if(visited[currRow][currCol] == 1)
        return false ;

    return true ;
}

public:
    int maxDistance(vector<vector<int>>& grid)
    {
        int n = grid.size() ;

        vector<vector<int>> visited(n , vector<int> (n , 0) ) ;

        queue<pair<int , pair<int , int>> > q ;

        for(int row = 0 ; row < n ; row++)
        {
            for(int col = 0 ; col < n ; col++)
            {
                if(grid[row][col] == 1)
                {
                    q.push( {0 , {row , col} } ) ;

                    visited[row][col] = 1 ;
                }
            }
        }
        
        int maxCnt = 0 ;
        
        int x[] = {-1 , +1 , 0 , 0} ;
        int y[] = {0 , 0 , -1 , +1} ;

        while(!q.empty() )
        {
            int steps = q.front().first ;
            int row = q.front().second.first  ;
            int col = q.front().second.second ;
            q.pop() ;
            
            maxCnt = max(maxCnt , steps) ;

            for(int i = 0 ; i < 4 ; i++)
            {
                int nRow = row + x[i] ;
                int nCol = col + y[i] ;

                if(isValid(nRow , nCol , n , visited) == true)
                {
                    q.push( {steps + 1 , {nRow , nCol} } ) ;

                    visited[nRow][nCol] = 1 ;
                }
            }
        }

        return maxCnt == 0 ? -1 : maxCnt ;    
    }
};

// Time Complexity:  O(N ^ 2)
// Space Complexity: O(N ^ 2)
