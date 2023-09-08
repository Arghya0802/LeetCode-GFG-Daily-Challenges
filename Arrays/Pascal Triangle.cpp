// Link:  https://leetcode.com/problems/pascals-triangle/

class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> ans ;  ans.push_back({1}) ;

        if(numRows == 1)  return ans ;

        for(int row = 1 ; row < numRows ; row++)
        {
            vector<int> prevRow = ans[row - 1] ;
            
            vector<int> currRow ;  currRow.push_back(1) ;

            for(int i = 0 ; i < prevRow.size() - 1 ; i++)  
            {
                int val = prevRow[i] + prevRow[i + 1] ;

                currRow.push_back(val) ;
            }

            currRow.push_back(1) ;  ans.push_back(currRow) ;
        }

        return ans ;
    }
};

// Time Complexity:  O(N ^ 2)
// Space Complexity: O(N)
