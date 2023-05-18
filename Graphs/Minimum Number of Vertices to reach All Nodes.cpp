// Link: https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/description/

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) 
    {
        vector<int> inDegree(n , 0) ;

        for(auto &edge : edges)
        {
            int u = edge[0] , v = edge[1] ;

            inDegree[v] += 1 ;
        }    

        vector<int> ans ;

        for(int node = 0 ; node < n ; node++)
        {
            if(inDegree[node] == 0)  ans.push_back(node) ;
        }

        return ans ;
    }
};

// Time Complexity:  O(V + E)
// Space Complexity: O(V + E)
