// Link: https://leetcode.com/problems/longest-cycle-in-a-graph/description/

class Solution {
private:

void dfs(int node , vector<int> &visited , vector<vector<int>> &adj , int &cnt)
{
    visited[node] = 1 ;
    cnt++ ;

    for(int neigh : adj[node])
    {
        if(!visited[neigh])
            dfs(neigh , visited , adj , cnt) ;
    }

    return ;
}

public:
    int longestCycle(vector<int>& edges) 
    {
        int n = edges.size() ;

        vector<vector<int>> adj(n) ;
        vector<int> visited(n , 0) ;
        vector<int> inDegree(n , 0) ;

        for(int u = 0 ; u < n ; u++)
        {
            int v = edges[u] ;

            if(v == -1)
                continue ;

            adj[u].push_back(v) ;
            inDegree[v] += 1 ;
        }    

        queue<int> q ;

        for(int node = 0 ; node < n ; node++)
        {
            if(inDegree[node] == 0)
            {
                q.push(node) ;
                visited[node] = 1 ;
            }
        }

        while(!q.empty() )
        {
            int node = q.front() ;
            q.pop() ;

            for(int neigh : adj[node])
            {
                if(visited[neigh] == 1)
                    continue ;

                inDegree[neigh] -= 1 ;

                if(inDegree[neigh] == 0)
                {
                    q.push(neigh) ;
                    visited[neigh] = 1 ;
                }
            }
        }

        int maxCnt = -1 ;

        for(int node = 0 ; node < n ; node++)
        {
            if(!visited[node])
            {
                int cnt = 0 ;

                dfs(node , visited , adj , cnt) ;

                maxCnt = max(maxCnt , cnt) ;
            }
        }

        return maxCnt ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
