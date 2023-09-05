// Link:  https://practice.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1

class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) 
    {
        vector<vector<int>> adj(V) ;
        
        for(auto it : edges)
        {
            int u = it.first ; int v = it.second ;
            
            adj[u].push_back(v) ;  adj[v].push_back(u) ;
        }
        
        return adj ;
    }
};

// Time Complexity:  O(V + E)
// Space Complexity: O(V)  
