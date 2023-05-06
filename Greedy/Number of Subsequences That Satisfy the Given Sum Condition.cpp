// Link: https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/description/

using ll = long long int ;

class Solution {

public:
    int numSubseq(vector<int>& nums, int target) 
    {
        int n = nums.size() ;
        ll MOD = 1e9 + 7 ;

        sort(nums.begin() , nums.end() ) ;

        vector<ll> powOf2(n , 1) ;

        for(int i = 1 ; i < n ; i++)  powOf2[i] = (2 * powOf2[i - 1]) % MOD ;
        
        ll ans = 0 ;

        int low = 0 , high = n - 1 ;

        while(low <= high)
        {
            if(nums[low] + nums[high] <= target)
            {
                ans += powOf2[high - low] ;
                ans %= MOD ;
                low++ ;
            }

            else  high-- ;
        }

        return (int) ans ;
    }
};

// Time Complexity:  O(N * Log N)
// Space Complexity: O(N)
