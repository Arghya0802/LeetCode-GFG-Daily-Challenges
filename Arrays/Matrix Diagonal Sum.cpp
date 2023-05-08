// Link: https://leetcode.com/problems/matrix-diagonal-sum/description/

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) 
    {
        int n = mat.size() ;

        int primary = 0 , secondary = 0 ;

        for(int i = 0 ; i < n ; i++)
        {
            primary += mat[i][i] ;

            secondary += mat[i][n - 1 - i] ;
        }    

        int mid = (n - 1) / 2 ;

        return n % 2 == 1 ? primary + secondary - mat[mid][mid] : primary + secondary ;
    }
};

// Time Complexity:  O(N) 
// Space Complexity: O(1)
