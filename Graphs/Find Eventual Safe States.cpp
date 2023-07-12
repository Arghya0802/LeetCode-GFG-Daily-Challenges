// Link:  https://leetcode.com/problems/find-eventual-safe-states/description/

class Solution {
private:

bool dfs(int node , vector<int> &visited , vector<vector<int>> &adj)
{
    if(visited[node] == 2)  return true ;

    if(visited[node] == 1)  return false ;

    visited[node] = 1 ;  bool isSafe = true ;

    for(int neigh : adj[node])  
    {
        if(dfs(neigh , visited , adj) == false) return false ;

        // isSafe = isSafe && isOkay ; 
    }

    visited[node] = 2 ;

    return true ;
}

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int n = graph.size() ;  vector<vector<int>> adj(n) ;
        
        vector<int> visited(n , 0) ;

        for(int node = 0 ; node < n ; node++)
        {
            if(graph[node].size() == 0)  visited[node] = 2 ;
        }

        for(int node = 0 ; node < n ; node++)
        {
            if(!visited[node])  dfs(node , visited , graph) ;
        }

        vector<int> ans ;

        for(int node = 0 ; node < n ; node++)
        {
            if(visited[node] == 2)  ans.push_back(node) ;
        }

        return ans ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
