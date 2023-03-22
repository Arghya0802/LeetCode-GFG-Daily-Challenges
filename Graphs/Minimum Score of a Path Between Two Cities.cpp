// Link: https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/description/

using pp = pair<int , int> ;

class Solution {
private:

int bfs(int src , vector<int> &visited , vector<vector<pp>> &adj)
{
    int minDist = INT_MAX ;

    queue<int> q ;
    q.push(src) ;

    visited[src] = 1 ;

    while(!q.empty() )
    {
        int node = q.front() ;
        q.pop() ;

        for(pp &neighbor : adj[node])
        {
            int neigh = neighbor.first ;
            int dist = neighbor.second ;

            minDist = min(minDist , dist) ;

            if(!visited[neigh])
            {
                q.push(neigh) ;

                visited[neigh] = 1 ;
            }
        }
    }

    return minDist ;
}

public:
    int minScore(int n, vector<vector<int>>& roads) 
    {
        vector<vector<pp>> adj(n + 1) ;    

        for(vector<int> &edge : roads)
        {
            int u = edge[0] ;
            int v = edge[1] ;
            int dist = edge[2] ;

            adj[u].push_back({v , dist}) ;
            adj[v].push_back({u , dist}) ;
        }

        vector<int> visited(n + 1 , 0) ;

        for(int node = 1 ; node <= n ; node++)
        {
            if(!visited[node])
            {
                int minDist = bfs(node , visited , adj) ;

                if(visited[1] && visited[n])
                    return minDist ;
            }
        }

        return -1 ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
