// Link: https://leetcode.com/problems/k-radius-subarray-averages/description/

using ll = long long int ;

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) 
    {
        int n = nums.size() ;  vector<int> ans(n , -1) ;
        
        if(2 * k >= n)  return ans ;

        int start = 0 ; int end = 0 ;  int i = k ; 
        ll sum = 0 ;  ll radius = 2 * k + 1 ;

        while(start < radius)
        {
            sum += nums[start] ; start++ ;
        }
         
        ans[i++] = sum / radius ;

        for(; start < n ; start++)
        {
            sum -= nums[end] ;  end++ ;
            sum += nums[start] ;

            ans[i++] = sum / radius ;
        }

        return ans ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(1)
