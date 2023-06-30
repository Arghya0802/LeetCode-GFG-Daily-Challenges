// Link: https://leetcode.com/problems/path-with-maximum-probability/description/

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) 
    {
        vector<double> dist(n , INT_MIN) ;  

        vector<pair<int , double>> adj[n] ;

        for(int i = 0 ; i < edges.size() ; i++)
        {
            int u = edges[i][0] ; int v = edges[i][1] ; double x = succProb[i] ;

            adj[u].push_back( make_pair(v , x) ) ; 
            adj[v].push_back( make_pair(u , x) ) ; 
        }

        priority_queue<pair<int , double>> maxQ ;  maxQ.push(make_pair(start , 1.0) ) ;

        while(!maxQ.empty() )
        {
            int node = maxQ.top().first ; double prob = maxQ.top().second ;
            maxQ.pop() ;

            for(auto neighbors : adj[node])
            {
                int neigh = neighbors.first ;  double nextProb = neighbors.second ;

                if(prob * nextProb > dist[neigh] )
                {
                    maxQ.push(make_pair(neigh , nextProb * prob) ) ;  
                    dist[neigh] = nextProb * prob ;
                }
            }
        }

        return dist[end] == INT_MIN ? 0.0 : dist[end] ;
    }
};

// Time Complexity:  O(N * Log N)
// Space Complexity: O(N)
