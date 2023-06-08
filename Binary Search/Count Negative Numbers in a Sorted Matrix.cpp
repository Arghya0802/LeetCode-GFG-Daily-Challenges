// Link: https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/description/

class Solution {
private:

int binarySearch(vector<int> &nums , int n)
{
    int low = 0 ; int high = n - 1 ;

    int ans = -1 ;

    while(low <= high)
    {
        int mid = low + (high - low) / 2 ;

        if(nums[mid] >= 0)
        {
            ans = mid ; low = mid + 1 ;
        }

        else high = mid - 1 ;
    }

    return ans ;
}

public:
    int countNegatives(vector<vector<int>>& grid) 
    {
        int m = grid.size() ;  int n = grid[0].size() ;
        
        int maxCnt = 0 ;

        for(int row = 0 ; row < m ; row++)
        {
            int ind = binarySearch(grid[row] , n) ;

            maxCnt += (n - (ind + 1) ) ;
        }    

        return maxCnt ;
    }
};

// Time Complexity:  O(M * Log N)
// Space Complexity: O(1)
