// Link:  https://practice.geeksforgeeks.org/problems/mother-vertex/1

class Solution 
{
    private:
    
    void dfs(int node , vector<int> &vis , vector<int> adj[] )
    {
        vis[node] = 1 ;
        
        for(auto neigh : adj[node])
        {
            if(!vis[neigh] ) dfs(neigh , vis , adj) ;
        }
        
        return ;
    }
    
    public:
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	    vector<int> visited(V) ;  int lastNode = -1 ;
	    
	    for(int node = 0 ; node < V ; node++)
	    {
	        if(!visited[node] )
	        {
	            dfs(node , visited , adj) ;
	            
	            lastNode = node ;
	        }
	    }
	    
	    vector<int> vis(V) ;  dfs(lastNode , vis , adj) ;
	    
	    for(auto it : vis)
	    {
	        if(it == 0)  return -1 ;
	    }
	    
	    return lastNode ;
	}

};

// Time Complexity:  O(V + E)
// Space Complexity: O(V)
