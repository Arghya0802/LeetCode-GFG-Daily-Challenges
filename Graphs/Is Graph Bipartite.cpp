// Link: https://leetcode.com/problems/is-graph-bipartite/description/

class Solution {
private:

bool dfs(int node , int color , vector<int> &colors , vector<vector<int>> &adj)
{
    if(colors[node] != -1)  return colors[node] == color ;

    colors[node] = color ;

    for(auto neigh : adj[node])
    {
        if(dfs(neigh , !color , colors , adj) == false)   return false ;
    }

    return true ;
}

public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n = graph.size() ;

        vector<int> visited(n , -1) ;

        for(int node = 0 ; node < n ; node++)
        {
            if(visited[node] != -1)  continue ;

            if(dfs(node , 0 , visited , graph) == false)   return false ;
        }    

        return true ;
    }
};

// Time Complexity:  O(V + E)
// Space Complexity: O(V) 
