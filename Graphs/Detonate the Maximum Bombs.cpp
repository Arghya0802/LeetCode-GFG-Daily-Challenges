// Link: https://leetcode.com/problems/detonate-the-maximum-bombs/description/

using ll = long double ;

class Solution {
private:

int dfs(int node , vector<vector<int>> &adj , vector<int> &visit)
{
    if(visit[node] == 1)  return 0 ;

    visit[node] = 1 ; int res = 1 ;

    for(int neigh : adj[node])  res += dfs(neigh , adj , visit) ;

    return res ;
}

public:
    int maximumDetonation(vector<vector<int>>& bombs) 
    {
        int n = bombs.size() ;  vector<vector<int>> adj(n) ;    

        for(int i = 0 ; i < n ; i++)
        {
            ll x = bombs[i][0] ; ll y = bombs[i][1] ; ll r = bombs[i][2] ;

            for(int j = i + 1 ; j < n ; j++)
            {
                ll x1 = bombs[j][0] ; ll y1 = bombs[j][1] ;  ll r1 = bombs[j][2] ;

                ll sum = (x1 - x) * (x1 - x)  +  (y1 - y) * (y1 - y)  ;

                ll dist = sqrt(sum) ;

                if(dist <= r)   adj[i].push_back(j) ;

                if(dist <= r1)  adj[j].push_back(i) ;    
            }
        }

        int maxCnt = 0 ;

        for(int node = 0 ; node < n ; node++)
        {
            vector<int> visit(n , 0) ;

            int cnt = dfs(node , adj , visit) ;  maxCnt = max(maxCnt , cnt) ;
        }

        return maxCnt ;
    }
};

// Time Complexity:  O(N ^ 3)
// Space Complexity: O(N ^ 2)
