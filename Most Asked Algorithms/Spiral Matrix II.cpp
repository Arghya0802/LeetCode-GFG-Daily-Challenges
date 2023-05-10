// Link: https://leetcode.com/problems/spiral-matrix-ii/description/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        vector<vector<int>> ans(n , vector<int> (n , 0) ) ;

        int cnt = 0 ;
        int total = n * n ;

        int startRow = 0 , endRow = n - 1 ;
        int startCol = 0 , endCol = n - 1 ;

        while(cnt < total)
        {
            for(int index = startCol ; index <= endCol ; index++)
            {
                if(cnt == total)  break ;

                ans[startRow][index] = cnt + 1 ;  cnt++ ;
            }

            startRow++ ;

            for(int index = startRow ; index <= endRow ; index++)
            {
                if(cnt == total)  break ;

                ans[index][endCol] = cnt + 1 ;  cnt++ ;
            }

            endCol-- ;

            for(int index = endCol ; index >= startCol ; index--)
            {
                if(cnt == total)  break ;

                ans[endRow][index] = cnt + 1 ;  cnt++ ;
            }

            endRow-- ;

            for(int index = endRow ; index >= startRow ; index--)
            {
                if(cnt == total)  break ;

                ans[index][startCol] = cnt + 1 ;  cnt++ ;
            }

            startCol++ ;
        }    

        return ans ;
    }
};

// Time Complexity:  O(N * N)
// Space Complexity: O(N * N) [For ans[][] vector we require extra space]
