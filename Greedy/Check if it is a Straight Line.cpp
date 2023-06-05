// Link:  https://leetcode.com/problems/check-if-it-is-a-straight-line/description/

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) 
    {
        int n = coordinates.size() ;

        if(n <= 2)  return true ;

        double x = coordinates[0][0] ;  double y = coordinates[0][1] ;

        double x1 = coordinates[1][0] ; double y1 = coordinates[1][1] ;
        
        double slope ;

        if(x == x1 && x == 0)  slope = INT_MAX ;  // For (x = 0 , x1 = 0, we assume our slope as INT_MAX)

        else slope = (y1 - y) / (x1 - x) ;

        for(int i = 2 ; i < n ; i++)
        {
            x1 = coordinates[i][0] ; y1 = coordinates[i][1] ; double s ;

            if(x == x1 && x == 0 )  s = INT_MAX ;  // Similarly, we need to check for s whether any points are having Infinity as Slope

            else s = (y1 - y) / (x1 - x) ;

            if(s != slope)  return false ;
        }

        return true ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(1)
