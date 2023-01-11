// Link:  https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/description/

// The question is more of a Recursion question than it's a graph question
// We need to traverse all the way till the nodes at the last level and check if they are apples or not
// If yes, then we will update total as total += child + 2
// Or if any of the DFS call return a value > 0, it means we have encountered an apple, then also we increment total as total + 2
// Otherwise, we keep total as it is

class Solution {
private:

// To avoid infinite loop, we have to keep track of both (Node, Parent)
int dfs(int node , int parent , vector<bool> &apples , vector<vector<int>> &adj)
{
    int child = 0 , total = 0 ;

    for(int neighbor : adj[node]) // We traverse over all the Neighbors first
    {
        if(parent == neighbor) // We need to avoid going back to parent 
            continue ;

        child = dfs(neighbor , node , apples , adj) ; // We ask recursion to check for the children

        if(child > 0 || (apples[neighbor] == true) ) // If we encounter any call whose value > 0 or any neighbor actually contains apple
            total += (child + 2) ; // We increment total as total + 2        
    }

    return total ; // At the end, we return total
}

public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) 
    {
        vector<vector<int>> adj(n) ; // To traverse over the graph, we need to create our Adjacency List first

        for(vector<int> &curr : edges)
        {
            int u = curr[0] ;
            int v = curr[1] ;

            adj[u].push_back(v) ;

            adj[v].push_back(u) ;

        }

        int ans = dfs(0 , -1 , hasApple , adj) ;

        return ans ;    
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N) [ Recursive Stack Space + Adjacency List]
