// Link: https://leetcode.com/problems/spiral-matrix/description/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        vector<int> ans ;
        
        int m = matrix.size() ; int n = matrix[0].size() ;

        int total = m * n ; int cnt = 0 ;

        int startRow = 0 , startCol = 0 ;
        int endRow = m - 1 , endCol = n - 1 ;

        while(cnt < total)
        {
            for(int index = startCol ; index <= endCol ; index++)
            {
                if(cnt == total)  break ;

                ans.push_back(matrix[startRow][index]) ;  cnt++ ;
            }

            startRow++ ;

            for(int index = startRow ; index <= endRow ; index++)
            {
                if(cnt == total)  break ;

                ans.push_back(matrix[index][endCol]) ;  cnt++ ;
            }

            endCol-- ;

            for(int index = endCol ; index >= startCol ; index--)
            {
                if(cnt == total)  break ;

                ans.push_back(matrix[endRow][index]) ; cnt++ ;
            }

            endRow-- ;

            for(int index = endRow ; index >= startRow ; index--)
            {
                if(cnt == total)  break ;

                ans.push_back(matrix[index][startCol]) ;  cnt++ ;
            }

            startCol++ ;
        }    

        return ans ;
    }
};

// Time Complexity:  O(M * N)
// Space Complexity: O(M * N) [Ans[] vector ]
