// Link:  https://leetcode.com/problems/excel-sheet-column-title/description/

class Solution {
public:
    string convertToTitle(int columnNumber) 
    {
        string ans = "" ; 

        while(columnNumber > 0)
        {
            int ind = columnNumber % 26 == 0 ? 26 : columnNumber % 26 ;

            ans += (char) (ind - 1 + 'A') ;

            if(ind == 26)  columnNumber-- ;

            columnNumber /= 26 ;  
        }    
        
        reverse(ans.begin() , ans.end() ) ;

        return ans ;
    }
};

// Time Complexity:  O(Log N)
// Space Complexity: O(N) [For the ans string]
