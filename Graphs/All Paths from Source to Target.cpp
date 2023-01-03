// Link: https://leetcode.com/problems/all-paths-from-source-to-target/description/

class Solution {
private:

// Although this question can be solved by BFS as well, but DFS looks more intuitve to me as it has Backtracking invovled as well
// We won't go into any infinite loop as the graph is Directed Acyclic [DAG]
// This is the reason we won't need any visited[] array
// Our source is always fixed[0]
  
void dfs(int node , int n , vector<int> &path , vector<vector<int>> &adj , vector<vector<int>> &ans)
{
    if(node == n - 1) // Everytime we reach the (N - 1) or Last Node  or Vertex
    {
        ans.push_back(path) ; // We put the Current path into our 2D ans[][] vector
        return ; // And simply return back as we don't have any more vertices to explore
    }

    for(int neigh : adj[node]) // Otherwise we explore all the Neighbors of the Current Node
    {
        path.push_back(neigh) ; // We push that into our current path[] vector

        dfs(neigh , n , path , adj , ans) ; // We call dfs() and ask it to solve for rest of the neighbors

        path.pop_back() ; // We need to backtrack and undo the change as well
    }

    return ;
}

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        int n = graph.size() ;

        vector<vector<int>> ans ; // Stores our final ans[][] path

        vector<int> currPath ; // Stores the Current-Path

        currPath.push_back(0) ; // We are starting from 0 everytime, so we put that into our Current-Path[] vector initally

        dfs(0 , n , currPath , graph , ans) ;    

        return ans ;
    }
};

// Time Complexity:  O(2 ^ N)
// Space Complexity: O(N) [Not sure]
