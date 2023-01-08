// Link:

// The Approach is very simple, we calculate the number of lines passing through any given point using O(N ^ 2)
// To avoid the edge case with parallel lines, we will seperately calculate the Number of Lines passing through it using a Hash-Map
// We should be wary of x1 == x2 edge case also, [Infinity Slope]

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
    
    int n = points.size() ;
        
    int ans = 0 ;
        
    for(int i = 0 ; i < n ; i++)
    {
        unordered_map<double , int> map ; // Map is used to store the Count
        
        // For each point, we seperately calculate the No-Of-Lines passing through it
        double x1 = points[i][0] ;
        double y1 = points[i][1] ;
        
        for(int j = i + 1 ; j < n ; j++)
        {
            double x2 = points[j][0] ;
            double y2 = points[j][1] ;
            
            if(x1 == x2) // Infinite Slope
                map[INT_MAX] += 1 ;
            
            else // Otherwise, we calculate Slope 
            {
                double slope = (y2 - y1) / (x2 - x1) ;
                
                map[slope] += 1 ;
            }
            
        }
        
        for(auto &x : map)
        {
            int currPoints = x.second ;
            
            ans = max(ans , currPoints) ;
        }
        
    }
    
    return ans + 1  ; // We return (ans + 1) to avoid the Edge Case of a Single Point
}
};

// Time Complexity:  O(N ^ 2)
// Space Complexity: O(N)
