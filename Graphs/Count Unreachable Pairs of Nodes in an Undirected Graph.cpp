// Link: https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/description/

using ll = long long int ;
class Solution {
private:

ll bfs(int src , vector<int> &visited , vector<vector<int>> &adj)
{
    ll cnt = 1 ;
    queue<int> q ;

    q.push(src) ;
    visited[src] = 1 ;

    while(!q.empty()) 
    {
        int node = q.front() ;
        q.pop() ;

        for(int neigh : adj[node])
        {
            if(!visited[neigh])
            {
                cnt += 1 ;

                q.push(neigh) ;
                visited[neigh] = 1 ;
            }
        }
    }

    return cnt ;
}

public:
    long long countPairs(int n, vector<vector<int>>& edges) 
    {
        ll N = n ;
        ll total = (N * (N - 1)) / 2 ;

        vector<vector<int>> adj(n) ;
        vector<int> visited(n , 0) ;

        for(vector<int> &connect : edges)
        {
            int u = connect[0] ;
            int v = connect[1] ;

            adj[u].push_back(v) ;
            adj[v].push_back(u) ;
        }    

        ll cnt = 0 ;

        for(int node = 0 ; node < n ; node++)
        {
            if(!visited[node])
            {
                ll components = bfs(node , visited , adj) ;

                cnt += (components * (components - 1)) / 2 ;
            }
        }  

        return total - cnt ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
