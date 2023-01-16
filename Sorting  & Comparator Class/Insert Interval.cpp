// Link: https://leetcode.com/problems/insert-interval/description/

// The question is pretty straightforward. We have been given sorted ranges of intervals[][] 2D vector.
// After inserting the newInterval[], we need to find the new merged interval and return an ans[][] vector
// In short, we need to merge overlapping intervals

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        intervals.push_back(newInterval) ; // We insert the newInterval[], into our intervals[][] vector

        sort(intervals.begin() , intervals.end() ) ; // We sort the intervals[][] vector so that we could merge overlapping intervals
        
        // We take the first (start , end) initially
        int start = intervals[0][0] ;
        int end = intervals[0][1] ;

        int n = intervals.size() ;

        vector<vector<int>> ans ;

        for(int i = 1 ; i < n ; i++) // We iterate from 1st Index till the Last
        {
            int newStart = intervals[i][0] ;
            int newEnd  = intervals[i][1] ;

            if(newStart >= start && newStart <= end) // If our Current-Start lies within our (start , end) range
            {
                // It means we have found an Overlapping Interval which need to be merged
              
                start = min(start , newStart) ; // Start is updated as the Minimum of our startTillNow & Current-Start

                end = max(end , newEnd) ; // Similarly, End is updated as the Maximum of our endTillNow & Current-End
            
            }

            else // Otherwise the intervals are non-overlapping
            {
                ans.push_back( {start , end} ) ; // So we push (Start , End) into our ans[][] vector
                
                // And reset the value of start and end to Current-Start and Current-End respectively
                start = newStart ; 
                end = newEnd ;
            }                

        }        

        ans.push_back({start , end}) ; // Before returning, we need to ensure that we have enterted the lastStart , lastEnd into our ans[][]

        return ans ;
    }
};

// Time Complexity:  O(N * Log N) [N is the number of intervals present in 2D vector]
// Space Complexity: O(N) [In worst case, we might not have any overlapping intervals]
