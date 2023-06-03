// Link:

using pp = pair<int , int> ;

class Solution {
private:

int bfs(int n , int src , vector<int> &inform , vector<vector<int>> &adj)
{
    queue<pp> q ;  vector<int> visited(n , 0) ;

    q.push({inform[src] , src}) ;  visited[src] = 1 ;

    int minTime = 0 ;

    while(!q.empty() )
    {
        int time = q.front().first ;
        int node = q.front().second ; q.pop() ;

        minTime = max(minTime , time) ;

        for(int neigh : adj[node])
        {
            if(!visited[neigh])
            {
                q.push( {time + inform[neigh] , neigh} ) ;  visited[neigh] = 1 ;
            }
        }
    }

    return minTime ;
}

public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) 
    {
        vector<vector<int>> adj(n) ;

        for(int node = 0 ; node < n ; node++)
        {
            if(manager[node] == -1)  continue ;

            adj[manager[node]].push_back(node) ;
        }    

        return bfs(n , headID , informTime , adj) ;
    }
};

// Time Complexity:  O(N + M)
// Space Complexity: O(N + M)
