// Link:  https://leetcode.com/problems/non-overlapping-intervals/description/

class Solution {
static bool cmp(vector<int> &A , vector<int> &B)
{
    if(A[1] < B[1] )  return true ;

    else if(A[1] == B[1] && A[0] < B[0] )  return true ;

    return false ;
}

public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin() , intervals.end() , cmp) ; int n = intervals.size() ;      

        int cnt = 0 ;  int prevIndex = 0 ;

        for(int i = 1 ; i < n ; i++)
        {
            int prev_End = intervals[prevIndex][1] ;  int curr_Start = intervals[i][0] ;

            if(curr_Start < prev_End)  cnt++ ;

            else prevIndex = i ;
        }

        return cnt ;
    }
};

// Time Complexity:  O(N * Log N)
// Space Complexity: O(1) 
