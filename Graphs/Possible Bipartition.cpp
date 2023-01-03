// Link: https://leetcode.com/problems/possible-bipartition/description/

// The only trick in this question is that we need to create a Un-Directed Graph instead of Directed Graph
// This is to say, [a ,b ] --> a and b both mutually hate one another

class Solution {
private:

void buildGraph(int n , vector<int> adj[] , vector<vector<int>> &dislikes)
{
    for(vector<int> &edge : dislikes)
    {
        int u = edge[0] ;
        int v = edge[1] ;

        adj[u].push_back(v) ;
        adj[v].push_back(u) ;
    }

    return ;
}

bool bfs(int source , vector<int> &visited , int &group , vector<int> adj[])
{
    queue<pair<int , int>> q ;

    q.push( {source , group} ) ;

    while(q.empty() == false)
    {
        int node  = q.front().first  ;
        int grp = q.front().second ;
        q.pop() ;
        group = grp ;

        if(visited[node] != 0)
        {
            if(group != visited[node])
                return false ;

            continue ;
        }
            
        visited[node] = group ;
        int rivalGroup = 1 ;

        if(group == 1)
            rivalGroup = 2 ;

        for(int neigh : adj[node])
            q.push( {neigh , rivalGroup} ) ;
    }

    return true ;
}

public:
    bool possibleBipartition(int n , vector<vector<int>>& dislikes) 
    {
        vector<int> adjList[n + 1] ;
        
        // vector<vector<int>> adjList(n + 1) ;

        vector<int> visited(n + 1 , 0) ;

        buildGraph(n , adjList , dislikes) ;

        int group = 1 ;

        for(int node = 1 ; node <= n ; node++)
        {
            if(visited[node] == 0)
            {
                if(bfs(node , visited , group , adjList) == false)
                    return false ;
            }
        }

        return true ;  
    }
};

// Time Complexity:  O(V + E)
// Space Complexity: O(V)
