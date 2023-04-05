// Link: https://leetcode.com/problems/minimize-maximum-of-array/description/

using ll = long long int ;

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) 
    {
        int n = nums.size() ;

        ll ans = nums[0] ;

        ll sum = nums[0] ;   
        int len = 1 ;

        for(int i = 1 ; i < n ; i++)
        {
            sum += nums[i] ;
            len++ ;

            if(sum % len == 0)
                ans = max(ans , sum / len) ;

            else
                ans = max(ans , (sum / len) + 1) ;
                
        } 

        return (int) ans ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(1)
