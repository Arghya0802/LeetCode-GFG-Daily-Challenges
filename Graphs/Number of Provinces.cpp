// Link:

class Solution {
private:

void dfs(int node , vector<int> &visit , vector<vector<int>> &adj)
{
    visit[node] = 1 ;

    for(int neigh : adj[node])
    {
        if(!visit[neigh])  dfs(neigh , visit , adj) ;
    }

    return ;
}

public:
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n = isConnected.size() ; int maxCnt = 0 ;

        vector<vector<int>> adj(n) ; vector<int> visit(n , 0) ;  

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(i == j || isConnected[i][j] == 0)  continue ;

                adj[i].push_back(j) ; adj[j].push_back(i) ;
            }
        }

        for(int node = 0 ; node < n ; node++)
        {
            if(!visit[node])
            {
                dfs(node , visit , adj) ;  maxCnt++ ;
            }
        }

        return maxCnt ;
    }
};

// Time Complexity:  O(N ^ 2)
// Space Complexity: O(N ^ 2)
