// Link: https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/description/

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) 
    {

        vector<vector<int>> adj(n) ;
        vector<vector<int>> back(n) ;
        
        for(vector<int> &edge : connections)
        {
            int u = edge[0] ;
            int v = edge[1] ;

            adj[u].push_back(v) ;
            back[v].push_back(u) ;
        }
        
        vector<int> visited(n , 0) ;

        queue<int> q ;
        
        q.push(0) ;
        visited[0] = 1 ;

        int cnt = 0 ;

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

            for(int neigh : back[node])
            {
                if(!visited[neigh])
                {
                    q.push(neigh) ;
                    visited[neigh] = 1 ;
                }
            }
        }
            
        return cnt ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
