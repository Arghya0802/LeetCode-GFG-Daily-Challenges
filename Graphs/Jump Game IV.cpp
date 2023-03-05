// Link: https://leetcode.com/problems/jump-game-iv/description/

class Solution {
public:
    int minJumps(vector<int>& arr) 
    {
        int n = arr.size() ;

        unordered_map<int , vector<int>> map ;

        for(int i = 0 ; i < n ; i++)
        {
            int val = arr[i] ;

            map[val].push_back(i) ;
        }

        vector<int> visited(n , 0) ;

        queue<pair<int , int>> q ;

        q.push( {0 , 0} ) ;

        visited[0] = 1 ;

        int minDist = 0 ;

        while(!q.empty() )
        {
            int node = q.front().first ;
            int steps = q.front().second ;
            q.pop() ;
            
            minDist = max(minDist , steps) ;

            if(node == n - 1)
                return minDist ;

            int val = arr[node] ;
            vector<int> &index = map[val] ;

            index.push_back(node - 1) ;
            index.push_back(node + 1) ;

            for(int ind : index)
            {
                if(ind >= 0 && ind < n && !visited[ind])
                {
                    q.push( {ind , steps + 1} ) ;

                    visited[ind] = 1 ;
                }
            }

            map.erase(val) ;
        }

        return -1 ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
