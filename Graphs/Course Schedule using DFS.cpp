// Link:  https://leetcode.com/problems/course-schedule/description/
// -----------------------------------------------------------------

class Solution {
private:

bool hasCycle(int node , vector<int> &visited , vector<vector<int>>&adj)
{
    visited[node] = 2 ;

    for(auto neigh : adj[node])
    {
        if(!visited[neigh])
        {
            if(hasCycle(neigh , visited , adj) == true)  return true ;
        }
        
        else if(visited[neigh] == 2)  return true ;
    }

    visited[node] = 1 ; return false ;
}

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        int n = numCourses ;

        vector<vector<int>> adj(n) ;     

        for(auto it : prerequisites)
        {
            int u = it[0] ; int v = it[1] ;

            adj[u].push_back(v) ;  
        }

        vector<int> visited(n , 0) ;

        for(int node = 0 ; node < n ; node++)
        {
            if(!visited[node])
            {
                if(hasCycle(node , visited , adj) == true)  return false ;
            }
        }

        return true ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
