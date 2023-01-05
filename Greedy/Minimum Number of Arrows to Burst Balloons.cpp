// Link: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/

class Solution {
public:
    
      // We will use Greedy Approach to solve the question just like yesterday's problem
     // We need to sort our given array such that we always take the common region by counting the Number of Overlapping Regions
     // Our overlapping region between any 2 pairs will be taken as the maximum of their start time and minimum of their end time
  
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        sort(points.begin() , points.end() ) ; // We sort the vector in ascending order

        int n = points.size() ;
        
        // We initialise our Start and End points with points[0][0] and points[0][1] respectively
      
        int start = points[0][0] ;
        int end = points[0][1] ;

        int cnt = 1 ; // If our array has only one point, we will definetly need one arrow to brust it

        for(int i = 1 ; i < n ; i++)
        {
            int currStart = points[i][0] ;
            int currEnd = points[i][1] ;

            if(currStart >= start && currStart <= end) // If our Current-Start point lies in the range
            {
                // We update our (start, end) as stated above
              
                start = max(start , currStart) ;

                end = min(end , currEnd) ;
            }

            else if(currEnd >= start && currEnd <= end) // Else If our Current-End point lies in the range
            {
                // We also update our (start,end) respectively
                start = max(start , currStart) ;

                end = min(end , currEnd) ;
            }

            else // Otherwise,we won't be having any overlapped region
            {
                cnt += 1 ; // So we increment our counter by 1

                start = currStart ; // We re-initalised our start with Current-Start

                end = currEnd ; // We re-initlised our end with Current-End
            }
        }

        return cnt ;    
    }
};

// Time Complexity:  O(N * Log N)
// Space Complexity: O(1)
