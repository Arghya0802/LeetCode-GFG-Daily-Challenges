// Link:  https://leetcode.com/problems/01-matrix/description/

class Solution {
private:

bool isOkay(int nRow , int nCol , vector<vector<int>> &vis)
{
    if(nRow < 0 || nCol < 0 || nRow >= vis.size() || nCol >= vis[0].size() )   return false ;

    if(vis[nRow][nCol] == 1)  return false ;

    return true ;
}

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int m = mat.size() ; int n = mat[0].size() ;

        queue<pair<int , pair<int , int>>> q ;  

        vector<vector<int>> visited(m , vector<int> (n , 0) ) ;
        vector<vector<int>> minDist(m , vector<int> (n , 0) ) ;

        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push(make_pair(0 , make_pair(i , j) ) ) ;  visited[i][j] = 1 ;
                }
            }
        }    

        int x[] = {-1 , +1 , 0 , 0} ;  int y[] = {0 , 0,  -1 , +1} ;

        while(!q.empty() )
        {
            int row = q.front().second.first ;  int col = q.front().second.second ;
            int dist = q.front().first ; q.pop() ;

            minDist[row][col] = dist ;

            for(int i = 0 ; i < 4 ; i++)
            {
                int nRow = row + x[i] ;  int nCol = col + y[i] ;

                if(isOkay(nRow , nCol , visited) )
                {
                    q.push({ dist + 1 , {nRow , nCol} } ) ;  visited[nRow][nCol] = 1 ;
                }
            }
        } 

        return minDist ;
    }
};

// Time Complexity:  O(M * N)
// Space Complexity: O(M * N)
