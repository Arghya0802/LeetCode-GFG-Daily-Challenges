// Link:  https://leetcode.com/problems/equal-row-and-column-pairs/description/

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) 
    {
        int n = grid.size() ; int cnt = 0 ;

        unordered_map<string , int> colMap ;

        for(int col = 0 ; col < n ; col++)
        {
            string curr = "" ;

            for(int row = 0 ; row < n ; row++)  curr += to_string(grid[row][col]) + "-" ;

            colMap[curr] += 1 ;
        }    

        for(int row = 0 ; row < n ; row++)
        {
            string curr = "" ;

            for(int col = 0 ; col < n ; col++)  curr += to_string(grid[row][col]) + "-" ;

            if(colMap.find(curr) != colMap.end() )  cnt += colMap[curr] ;
        }

        return cnt ;
    }
};

// Time Complexity:  O(M * N)
// Space Complexity: O(N)
