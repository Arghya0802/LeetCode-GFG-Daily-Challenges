// Link:  https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/

class Solution {
public:
    bool search(vector<int>& nums, int target) 
    {
        int low = 0 ;  int high = nums.size() - 1 ;

        while(low <= high)
        {
            int mid = low + (high - low) / 2 ;

            if(nums[mid] == target)  return true ;

            if(nums[low] == nums[high]) low += 1 ;

            else if(nums[low] <= nums[mid])
            {
                if(nums[low] <= target && target < nums[mid] )  high = mid - 1 ;

                else low = mid + 1 ;
            }

            else
            {
                if(nums[mid] < target && target <= nums[high] )  low = mid + 1 ;

                else high = mid - 1 ;
            }
        }    

        return false ;
    }
};

// Time Complexity:  O(Log N) [Amortized]
// Space Complexity: O(1)
