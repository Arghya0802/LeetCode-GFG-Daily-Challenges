// Link:  https://leetcode.com/problems/search-a-2d-matrix/description/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int m = matrix.size() ;   int n = matrix[0].size() ;

        int row = 0  ;  int col = n - 1 ;

        while(row < m && col >= 0)
        {
            if(matrix[row][col] == target)  return  true ;

            if(matrix[row][col] < target) row++ ;

            else col-- ;
        }

        return false ;
    }
};

// Time Complexity:  O(M + N)
// Space Complexity: O(1)
