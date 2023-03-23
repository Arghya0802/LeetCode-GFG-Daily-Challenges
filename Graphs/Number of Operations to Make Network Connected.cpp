// Link: https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/

class Solution {
private:

void bfs(int src , vector<int> &visited , vector<vector<int>> &adj)
{
    queue<int> q ;

    q.push(src) ;
    visited[src] = 1 ;

    while(!q.empty() )
    {
        int node = q.front() ;
        q.pop() ;

        for(int neigh : adj[node])
        {
            if(!visited[neigh])
            {
                q.push(neigh) ;

                visited[neigh] = 1 ;
            }
        }
    } 

    return ;
}

public:
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        if(connections.size() < n - 1)
            return -1 ;

        vector<vector<int>> adj(n) ;

        for(vector<int> &edge : connections)
        {
            int u = edge[0] ;
            int v = edge[1] ;
            
            adj[u].push_back(v) ;
            adj[v].push_back(u) ;
        }

        vector<int> visited(n , 0) ;
        int components = 0 ;

        for(int node = 0 ; node < n ; node++)    
        {
            if(!visited[node])
            {
                bfs(node , visited , adj) ;
                components++ ;
            }
        }

        return components - 1 ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
