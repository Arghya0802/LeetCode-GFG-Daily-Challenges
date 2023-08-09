// Link:  https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/description/

class Solution {
private:

bool isOkay(int maxDiff , vector<int> &nums , int p)
{
    int cnt = 0 ;

    for(int i = 0 ; i < nums.size() - 1 ; i++)
    {
        if(nums[i + 1] - nums[i] <= maxDiff)  
        {
            cnt++ ;  i++ ;
        }
    }
    
    return cnt >= p ;
}

public:
    int minimizeMax(vector<int>& nums, int p) 
    {
        sort(nums.begin() , nums.end() ) ;

        int low = 0 ;  int high = nums.back() - nums[0] ;
        int ans = 0 ;

        while(low <= high)
        {
            int mid = low + (high - low) / 2 ;

            if(isOkay(mid , nums , p) )
            {
                ans = mid ;  high = mid - 1 ;
            }

            else low = mid + 1 ;
        }    

        return ans ;
    }
};

// Time Complexity:  O(N * Log N)
// Space Complexity: O(1)
