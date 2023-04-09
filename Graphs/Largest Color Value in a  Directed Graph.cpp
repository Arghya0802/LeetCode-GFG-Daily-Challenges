// Link:  https://leetcode.com/problems/largest-color-value-in-a-directed-graph/description/

class Solution {
private:

int dfs(int node , string &colors , vector<int> &visited , vector<int> &pathVisit , vector<vector<int>> &adj , vector<vector<int>> &colorCnt)
{
    if(pathVisit[node] == 1)  return -1 ;
    
    if(visited[node] == 1)  return 0 ;

    visited[node] = 1 , pathVisit[node] = 1 ;

    int index = colors[node] - 'a' ;

    colorCnt[node][index] = 1 ;

    for(int neigh : adj[node])
    {
        if(dfs(neigh , colors , visited , pathVisit , adj , colorCnt) == -1)
            return -1 ;

        for(int i = 0 ; i < 26 ; i++)
        {
            if(i == index)  
                colorCnt[node][i] = max(colorCnt[node][i] , colorCnt[neigh][i] + 1) ;

            else
                colorCnt[node][i] = max(colorCnt[node][i] , colorCnt[neigh][i]) ;
        }
    }

    pathVisit[node] = 0 ;
    int ans = 0 ;

    for(int i = 0 ; i < 26 ; i++)
        ans = max(ans , colorCnt[node][i]) ;

    return ans ;
}

public:
    int largestPathValue(string &colors, vector<vector<int>>& edges) 
    {
        int n = colors.size() ;  

        vector<vector<int>> adj(n) ;

        for(auto  edge : edges)
        {
            int u = edge[0] , v = edge[1] ;
            adj[u].push_back(v) ;
        }  

        int maxCnt = 0 ;

        vector<int> visited(n , 0) ;
        vector<int> pathVisit(n , 0) ;

        vector<vector<int>> colorCnt(n , vector<int> (26 , 0) ) ;

        for(int node = 0 ; node < n ; node++)
        {
            if(!visited[node])
            {
                int cnt = dfs(node , colors , visited , pathVisit , adj , colorCnt) ;

                if(cnt == -1)  return -1 ;

                maxCnt = max(maxCnt , cnt) ;
            }
        }

        return maxCnt ;
    }
};

// Time Complexity:  O(M + N)
// Space Complexity: O(N)
